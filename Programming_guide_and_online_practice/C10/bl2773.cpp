//Algorithm:  dp, 01-knapsack problem,
//Complexity: C*N
//Trick:      None
//IndexBase:  1


#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


const int MAXT = 1024;
const int MAXM = 128;

int T;
int M;
int t[MAXM];
int v[MAXM];

int dp[MAXM][MAXT];

int main(){
  scanf("%d%d", &T, &M);

  for (int i = 1; i <= M; i++){
    scanf("%d%d", &t[i], &v[i]);
  }

  fill(&dp[0][0], &dp[MAXM-1][MAXT-1], 0);

  for (int i = 1; i <= M; i++){
    for (int j = 0; j <= T; j++){
      int &s = dp[i][j];
      s = dp[i-1][j];
      int last = j - t[i];
      if (last >= 0){
        s = max(s, dp[i-1][last] + v[i]);
      }
    }
  }

  int ans = *max_element(dp[M], dp[M] + T + 1);
  printf("%d\n", ans);
}



