#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; cin >> N;
  vector<int> A(N); for (auto &e: A) cin >> e;
  int m; cin >> m;
  while (m--) {
    int q; cin >> q;
    auto r = equal_range(A.begin(), A.end(), q);
    if (r.first == r.second) cout << -1 << " " << -1 << endl;
    else cout << distance(A.begin(), r.first) + 1 << " " << distance(A.begin(), r.second) << endl;
  }
}