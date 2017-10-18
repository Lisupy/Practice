#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; cin >> N;
  vector<int> P(N); for (auto &p: P) cin >> p;
  vector<int> T(N); for (auto &t: T) cin >> t;
  int tot = 0;
  bool cp = false, ct = false;
  for (int i = 0; i < N; i++) {
    if (P[i] > T[i]) tot += P[i], cp = true;
    else tot += T[i], ct = true;
  }
  if (!cp) {
    int sum = tot;
    tot = 0;
    for (int i = 0;i < N; i++) {
      int tmp = sum - T[i] + P[i];
      tot = max(tot, tmp);
    }
  } else if (!ct) {
    int sum = tot;
    tot = 0;
    for (int i = 0;i < N; i++) {
      int tmp = sum - P[i] + T[i];
      tot = max(tot, tmp);
    }
  }
  cout << tot << endl;
}