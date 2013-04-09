#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 512;
const int MAXM = 512;

int M;
int S[MAXM];
int N;
int A[MAXN];

int dp[MAXM][MAXN];
int max_dp[MAXN];
int max_trace[MAXN];
int tracei[MAXM][MAXN];
int tracej[MAXM][MAXN];
int best;
int besti,bestj;
int main(){
  scanf("%d", &M);
  for (int i = 1; i <= M; i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &N);
  for (int i = 1; i <= N; i++){
    scanf("%d", &A[i]);
  }

  for (int i = 1; i <= M; i++){
    int Max = 0;
    int seli = 0;
    int selj = 0;
    for (int j = 1; j <= N; j++){
      if (S[i] == A[j]){
        dp[i][j] = Max + 1;
        tracei[i][j] = seli;
        tracej[i][j] = selj;

        if (best < dp[i][j]){
          besti = i;
          bestj = j;
          best = dp[i][j];
        }

        if (max_dp[j] < dp[i][j]){
          max_dp[j] = dp[i][j];
          max_trace[j] = i;
        }
      }
      else if (S[i] > A[j]){
        if(max_dp[j] > Max){
          Max = max_dp[j];
          selj = j;
          seli = max_trace[j];
        }
      }
    }
  }
  printf("%d\n", best);
  vector<int> ans;
  while(besti){
    ans.push_back(S[besti]);
    int ti = tracei[besti][bestj];
    bestj = tracej[besti][bestj];
    besti = ti;
  }
  for (int i = ans.size() - 1; i >= 0; i--){
    printf("%d ", ans[i]);
  }
}
