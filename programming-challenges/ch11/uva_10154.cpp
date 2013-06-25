/*
 * dp[pos_i][j] = min{dp[last_i][j], dp[last_i][j - 1] + w[i] (if m[i] >= w[i] + dp[last_i][j - 1])  }
 */



#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int MAXN = 1024 * 8;
struct Turtle{
  int w, m;
};

bool operator<(const Turtle &a, const Turtle &b){
  if (a.m != b.m) return a.m < b.m;
  return a.w < b.w;
}



int n;
Turtle ts[MAXN];
int dp[2][MAXN];


int main(){
  n = 1;
  while (cin >> ts[n].w >> ts[n].m){
    n++;
  }
  n--;

  sort(ts + 1, ts + n + 1);

  fill(&dp[0][0], &dp[1][MAXN - 1] + 1, 0xffffff);
  dp[0][0] = 0;
  for (int i = 0; i <= n; i++){
 //   printf("ts %d: %d %d\n", i, ts[i].w, ts[i].m);
    int pos_i = i % 2;
    int last_i = (i - 1 + 2) % 2;
    fill(&dp[pos_i][0], &dp[pos_i][MAXN - 1] + 1, 0xffffff);
    for (int j = 0; j <= n; j++){
      if (i == 0 && j == 0){
        dp[pos_i][j] = 0;
      }
      if (i - 1 >= 0){
        dp[pos_i][j] = dp[last_i][j];
      }
      if (i - 1 >= 0 && j - 1 >= 0){
        if (ts[i].m >= ts[i].w + dp[last_i][j - 1]){
          dp[pos_i][j] = min(dp[pos_i][j], ts[i].w + dp[last_i][j - 1]);
        }
      }
  //    cout << dp[pos_i][j] << " ";
    }
   // cout << endl;
  }
  for (int i = n; i >= 0; i--){
    if (dp[n % 2][i] != 0xffffff){
      cout << i << endl;
      break;
    }
  }
}


