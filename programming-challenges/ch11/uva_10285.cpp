/* 
 * Algorithm:  DP, memo
 * Complexity: O(N)
 * IndexBased: 0
 * Trick:      dp implemented by dfs + for
 * LayOut:
 *  N, R, C
 *  height
 *  dp   // init 0
 *  reset()
 *  dp(x, y)
 *  longest_dp()
 *    for x, y in R, C
 *      dp(x, y)
 */


#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

const int MAXRC = 128;

int N;
int R, C;


int height[MAXRC][MAXRC];

int dp[MAXRC][MAXRC];

int DP(int x, int y){
  int &result = dp[x][y];

  if (result != 0){
    return result;
  }

  result = 1;
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  for (int i = 0; i < 4; i++){
    int tx = x + dx[i];
    int ty = y + dy[i];
    if (0 <= tx && tx < R && 0 <= ty && ty < C){
      if (height[tx][ty] < height[x][y]){
        result = max(result, DP(tx, ty) + 1); 
      }
    }
  }
  return result;
}

int longest_dp(){
  int longest = 0;
  for (int i = 0; i < R; i++){
    for (int j = 0; j < C; j++){
      longest = max(longest, DP(i, j));
    }
  }
  return longest;
}

void reset(){
  memset(dp, 0, sizeof(dp));
}

int main(){
  cin >> N;

  while (N--){
    reset();
    string name;
    cin >> name >> R >> C;

    for (int i = 0; i < R; i++){
      for (int j = 0; j < C; j++){
        cin >> height[i][j];
      }
    }

    int longest = longest_dp();
    cout << name << ": " << longest << endl;
  }
}

