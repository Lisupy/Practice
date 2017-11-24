#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
struct Jewel{
  int v, w, idx;
};
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N, K;
  cin >> N >> K;
  vector<Jewel> A(N);
  for (int i = 0; i < N; i++) {
    A[i].idx = i;
    cin >> A[i].v >> A[i].w;
  }
  double lo = 0, hi = 1000 * 1000;
  vector<int> ans;
  for (int j = 0; j < K; j++) ans.push_back(j);
  while ((hi - lo) > 1e-6) {
    double mid = (lo + hi) / 2;
    sort(A.begin(), A.end(), [mid](auto l, auto r) {
      return l.v - mid * l.w > r.v - mid * r.w;
    });
    double V = 0, W = 0;
    for (int j = 0; j < K; j++) {
      V += A[j].v;
      W += A[j].w;
    }
    if (V / W >= mid) {
      lo = mid;
      ans.clear();
      for (int j = 0; j < K; j++) ans.push_back(A[j].idx);
    }
    else hi = mid;
  }
  for (int i = 0; i < K; i++) {
    cout << ans[i] + 1;
    if (i == K - 1) cout << endl;
    else cout << " ";
  }
}