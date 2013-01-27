#include<cstdio>
#include<cstring>


const int MAXN = 32;

int n;

int dp[MAXN][1<<3];


int DFS(int n, int bits){
  if (dp[n][bits] != -1)
    return dp[n][bits];
  switch(bits){
  case 0:
    dp[n][bits] = DFS(n-1, 7^bits);
    break;
  case 1:
    dp[n][bits] = DFS(n-1, 7^bits);
    break;
  case 2:
    dp[n][bits] = DFS(n-1, 7^bits);
    break;
  case 3:
    dp[n][bits] = DFS(n-1, 7^bits) + DFS(n-1,7);
    break;
  case 4:
    dp[n][bits] = DFS(n-1, 7^bits);
    break;
  case 5:
    dp[n][bits] = DFS(n-1, 7^bits);
    break;
  case 6:
    dp[n][bits] = DFS(n-1, 7^bits) + DFS(n-1,7);
    break;
  case 7:
    dp[n][bits] = DFS(n-1, 3) + DFS(n-1, 6) + DFS(n-1, 0);
    break;
  }
  return dp[n][bits];
}
void init(){
  for (int i = 0; i < MAXN; i++)
    for (int j = 0; j < 1<<3; j++)
      dp[i][j] = -1;
  for (int i = 0;i < 1<<3; i++)
    dp[0][i] = 0;
  dp[0][7] = 1;
  for (int i = 0; i < MAXN; i++){
    DFS(i, 7);
  }
}
int main(){
  init();
  while(scanf("%d", &n) && n!=-1){
    printf("%d\n", dp[n][7]);
  }
}
