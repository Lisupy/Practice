#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
double next(double a, double b) {
  return 2 * a + 2 - b;
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N, K; cin >> N >> K;
  vector<long long> A(N); for (auto &a: A) cin >> a;
  sort(A.begin(), A.end());
  int lo = 0, hi = A[0] + 1;
  while ((hi - lo) > 1) {
    int mid = (lo + hi) / 2;

    int x = mid;
    long long cur = 0;
    for (auto a: A) cur = max(a, cur + x);
    if (cur <= K) lo = mid;
    else hi = mid;
  }
  cout << lo << endl;
}