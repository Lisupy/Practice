#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<numeric>
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, k; scanf("%d%d", &n, &k);
  vector<vector<int> > A(k);
  for (int i = 0; i < n; i++) {
    int t; scanf("%d", &t);
    A[i%k].push_back(t);
  }
  for (auto &a: A) {
    sort(a.begin(), a.end());
  }
  vector<int> B;
  for (int i = 0; i < n; i++) {
    B.push_back(A[i%k][i/k]);
  }
  cout << (is_sorted(B.begin(), B.end())?"YES":"NO") << endl;
}