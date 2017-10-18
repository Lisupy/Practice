#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  vector<vector<int>> P(3, vector<int>(3));
  for (auto &p: P) {
    for (auto &i: p) cin >> i;
  }
  vector<int> C{0, 1, 2};
  int ans = 0;
  do {
    int tot = 0;
    for (int i = 0; i < 3; i++) tot += P[i][C[i]] * P[i][C[i]];
    ans = max(ans, tot);
  } while(next_permutation(C.begin(), C.end()));
  printf("%.06lf\n", sqrt(ans));

}