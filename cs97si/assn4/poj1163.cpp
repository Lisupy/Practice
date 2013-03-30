#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int MAXN = 128;

int n;
int a[MAXN][MAXN];
int dp[MAXN][MAXN];


int DP(int i, int j){
  if (dp[i][j]!=-1)
    return dp[i][j];
  return dp[i][j] = a[i][j]+max(DP(i+1, j), DP(i+1, j+1));
}

int main(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for(int j = 0; j <= i; j++)
      scanf("%d", &a[i][j]);

  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      dp[i][j] = -1;

  for (int i = 0; i < n; i++)
    dp[n-1][i] = a[n-1][i];

  printf("%d\n", DP(0,0));
}
