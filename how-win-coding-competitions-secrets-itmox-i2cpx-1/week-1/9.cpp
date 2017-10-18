#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
typedef long long ll;
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; cin >> N;
  vector<int> T(N); for (auto &t: T) cin >> t;
  sort(T.begin(), T.end());
  partial_sum(T.begin(), T.end(), T.begin());
  cout << distance(T.begin(), upper_bound(T.begin(), T.end(), 300*60)) << endl;
}