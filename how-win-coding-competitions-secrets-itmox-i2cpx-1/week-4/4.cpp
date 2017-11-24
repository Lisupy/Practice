#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; cin >> N;
  vector<long long> A(N); for (auto &a: A) cin >> a;
  int K; cin >> K;
  sort(A.begin(), A.end());
  int lo = 0, hi = A.back();
  if (K == 1) cout << A.back() << endl;
  else {
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      long long tot = 0;
      for (auto x: A) {
        if (x <= mid) continue;
        else tot += (x - mid + K - 2) / (K - 1);
      }
      if (tot <= mid) hi = mid;
      else lo = mid + 1;
    }
    cout << lo << endl;
  }
}