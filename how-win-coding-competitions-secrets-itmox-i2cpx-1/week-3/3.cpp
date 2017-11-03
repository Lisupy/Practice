#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; scanf("%d", &N);
  vector<pair<int, int> > A(N);
  for (auto &e: A) scanf("%d%d", &e.first, &e.second);
  sort(A.begin(), A.end(), [] (auto &l, auto &r) {
    return l.first > r.first;
  });
  int W; scanf("%d", &W);
  long long tot = 0;
  for (auto &e: A) {
    if (W == 0) break;
    int n = min(W, e.second);
    tot += n * e.first;
    W -= n;
  }
  printf("%lld\n", tot);
}