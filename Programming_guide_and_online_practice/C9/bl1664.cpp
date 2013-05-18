#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;



const int MAXN = 32;

int dp[MAXN][MAXN];

int main(){
  int t;
  cin >> t;

  while (t--){
    int M, N;
    cin >> M >> N;

    for (int i = 1; i <= N; i++){
      dp[0][i] = 1;
    }

    for (int i = 1; i <= M; i++){
      for (int j = 1; j <= N; j++){
        int s = 0;
        for (int k = 1; k <= j; k++){
          if (i - k >= 0){
            s += dp[i-k][k];
          }
        }
        dp[i][j] = s;
      }
    }
    cout << dp[M][N] << endl;
  }
}
