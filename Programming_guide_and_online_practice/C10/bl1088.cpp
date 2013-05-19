// Algorithm => memo+dfs
// Complexity: O(R*C)
// FirstPos: 1
// Trick:
// 
// 
#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 128;


int R, C;
int h[MAXN][MAXN];
int dp[MAXN][MAXN];

int dfs(int x, int y){
  int &ans = dp[x][y];
  if (ans == -1){
    ans = 1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = { 0, 0,-1, 1};
    for (int k = 0; k < 4; k++){
      int tx = x + dx[k];
      int ty = y + dy[k];
      if (1 <= tx && tx <= R && 1 <= ty && ty <= C){
        if (h[tx][ty] < h[x][y]){
          ans = max(ans, dfs(tx, ty) + 1);
        }
      }
    }
  }
  return ans;
}
int main(){
  scanf("%d %d", &R, &C);
  for (int i = 1; i <= R; i++){
    for (int j = 1; j <= C; j++){
      scanf("%d", &h[i][j]);
    }
  }

  fill(&dp[0][0], &dp[MAXN-1][MAXN-1]+1, -1);

  int ans = -1;
  for (int i = 1; i <= R; i++){
    for (int j = 1; j <= C; j++){
      ans = max(ans, dfs(i,j));
    }
  }
  cout << ans << endl;
}


