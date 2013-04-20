//dp[n][k][3] = min(dp[n-1][k][3]+d(k)*2, 
//                  dp[n-1][k-1][1-3]+2)
//dp[n][k][1-2] = min(dp[n-1][k][1-3]+2, dp[n-1][k][1-3]+d(k)*cost(1-3))
//cost(1) = cost(2) = 1
//cost(3) = 3
//
#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<utility>
using namespace std;
using namespace std::rel_ops;


const int MAXN = 1024;
const int MAXK = 1024;
const int MAX_DP = 0xffffff;
int N, KK, B;

struct Cow{
  int x; 
  int y;
};

bool operator<(const Cow &a, const Cow &b){
  if (a.x < b.x) return true;
  if (a.x > b.x) return false;
  if (a.y < b.y) return true;
  if (a.y > b.y) return false;
  return false;
}


Cow cows[MAXN];
int cows_n;
int dp[MAXN][MAXK][4];

int dis(int pos){
  return cows[pos].x - cows[pos-1].x;
}
int main(){
  scanf("%d%d%d", &N, &KK, &B);
  for (int i = 1; i <= N; i++){
    scanf("%d%d", &cows[i].y, &cows[i].x);
  }
  sort(cows+1, cows+N+1);
  cows_n = 1; 
  for (int i = 1; i <= N; i++){
    if (i + 1 <= N && cows[i].x == cows[i+1].x){
      cows[cows_n].x = cows[i].x;
      cows[cows_n].y = 3;
      cows_n++;
      i++;
    }else{
      cows[cows_n++] = cows[i];
    }
  }
  cows[0].x = cows[1].x - 1;
  for (int i = 1; i < cows_n; i++){
    dp[i][0][0] = dp[i][0][1] = dp[i][0][2] = dp[i][0][3] = MAX_DP;
  }
  for (int i  = 1; i < cows_n; i++){
    for (int k = 1; k <= KK; k++){
      Cow &cow = cows[i];
      if (cow.y == 1 || cow.y == 2){
        dp[i][k][cow.y] = min(dp[i-1][k][0] + dis(i), 
                            min(dp[i-1][k][cow.y]+dis(i), 
                              min(dp[i-1][k-1][1]+1, 
                                min(dp[i-1][k-1][2]+1, 
                                    dp[i-1][k-1][3]+1)))); 
        dp[i][k][3-cow.y] = MAX_DP;
      }
      if (cow.y == 3){
        dp[i][k][1] = MAX_DP;
        dp[i][k][2] = MAX_DP;
      }
      dp[i][k][3] = min(dp[i-1][k][3]+dis(i)*2,
                        min(dp[i-1][k-1][0] + 2,
                          min(dp[i-1][k-1][1] + 2,
                            min(dp[i-1][k-1][2] + 2, 
                              dp[i-1][k-1][3] + 2))));
      dp[i][k][0] = min((i>1?dp[i-1][k][0]:MAX_DP)+dis(i)*2,
                      min((k>1?dp[i-1][k-2][0]:MAX_DP) + 2,
                        min((k>1?dp[i-1][k-2][1]:MAX_DP) + 2,
                          min((k>1?dp[i-1][k-2][2]:MAX_DP) + 2,
                            min((k>1?dp[i-1][k-2][3]:MAX_DP) + 2,
                              min((i>1?dp[i-1][k-1][1]:MAX_DP)+dis(i)+1,
                                  (i>2?dp[i-1][k-1][2]:MAX_DP)+dis(i)+1))))));

    }
  }
  int ans = MAX_DP;
  for (int k = 1; k <= KK; k++){
    ans = min(ans, dp[cows_n-1][k][0]);
    ans = min(ans, dp[cows_n-1][k][1]);
    ans = min(ans, dp[cows_n-1][k][2]);
    ans = min(ans, dp[cows_n-1][k][3]);
  }
  printf("%d\n", ans);
}
