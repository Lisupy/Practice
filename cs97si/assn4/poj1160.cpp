#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


const int MAXV = 512;
const int MAXP = 32;

int X[MAXV];
int dp[MAXV][MAXP];
int S[MAXV];
int CAL_helper(int l, int r, int m){
  if (l > r)
    return 0;
  return abs((S[r]-S[l-1])-(r-l+1)*X[m]);
}
int CAL(int l, int r){
  int m = (l+r)/2;
  return CAL_helper(l, m, m)+CAL_helper(m+1, r, m);
}
int DP(int V, int P){
  if (dp[V][P] != -1)
    return dp[V][P];
  int s = 0x7ffffff;// This is !! Very Very Dangerous!!
  if (P > 0){
    for (int i = 0; i < V; i++){
      s = min(s, DP(i, P-1) + CAL(i+1, V)); 
    }
  }
  return dp[V][P] = s;
}
int main(){
  int V, P;
  scanf("%d%d", &V, &P);
  for (int i = 1; i <= V; i++)
    scanf("%d", X+i);
  
  for (int i = 1; i <= V; i++)
    S[i] = X[i]+S[i-1];

  for (int i = 0; i < MAXV; i++)
    for (int j = 0; j < MAXP; j++)
      dp[i][j] = -1;
  for (int j = 0; j < MAXP; j++)
    dp[0][j] = 0;

  printf("%d\n", DP(V,P));
}
