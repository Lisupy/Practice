#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 2048;
const int INF  = 0xFFFFFF;
int t;

int N, X, Y, MAX;

struct Platform{
  int x, y, h;
};

bool operator<(const Platform &a, const Platform &b){
  return a.h < b.h;
}

Platform plats[MAXN];

int dp[MAXN][2];
void reset(){
  fill(&dp[0][0], &dp[MAXN-1][1]+1, INF);
}

int main(){
  scanf("%d", &t);

  while (t--){
    reset();

    scanf("%d %d %d %d", &N, &X, &Y, &MAX);

    for (int i = 0; i < N; i++){
      Platform &p = plats[i];
      scanf("%d %d %d", &p.x, &p.y, &p.h);
    }

    sort(plats, plats + N);
    reverse(plats, plats + N);

    int ans = INF;
    bool find_flag = false;
    for (int i = 0; i < N; i++){
      Platform &p = plats[i];
      if (p.x <= X && X <= p.y && Y - p.h <= MAX){
        dp[i][0] = min(dp[i][0], X - p.x);
        dp[i][1] = min(dp[i][1], p.y - X);
        find_flag = true;
        break;
      }
    }
    if (!find_flag){
      cout << Y << endl;
      continue;
    }

    for (int i = 0; i < N; i++){
      Platform &ps = plats[i];
      for (int k = 0; k < 2; k++){
        int sx = k == 0 ? ps.x : ps.y;
        int sh = ps.h;
        int sv = dp[i][k];
        if (sv != INF){
          int j = 0;
          for (j = i + 1; j < N; j++){
            Platform &p = plats[j];
            if (p.x <= sx && sx <= p.y && sh - p.h <= MAX){
              dp[j][0] = min(dp[j][0], sv + sx - p.x);
              dp[j][1] = min(dp[j][1], sv + p.y - sx); 
              break;
            }
          }
          if (j == N && sh <= MAX){
            ans = min(ans, sv);
          }
        }
      }
    }
    cout << ans + Y << endl;
  }
}

