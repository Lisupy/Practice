//Vertex Biconnectivity Components
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<string>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  string A, B; cin >> A >> B;
  vector<vector<int> > dp(A.size() + 1, vector<int>(B.size() + 1));
  for (int i = 1; i <= A.size(); i++) dp[i][0] = i;
  for (int i = 1; i <= B.size(); i++) dp[0][i] = i;
  for (int i = 1; i <= A.size(); i++) {
    for (int j = 1; j <= B.size(); j++) {
      int a = A[i - 1], b = B[j - 1];
      dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
      dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a != b));
    }
  }
  cout << dp.back().back() << endl;
}