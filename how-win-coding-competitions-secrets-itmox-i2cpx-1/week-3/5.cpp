#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<numeric>
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, k1, k2; cin >> n >> k1 >> k2;
  int A, B, C; cin >> A >> B >> C;
  vector<int> seqs(n);
  cin >> seqs[0] >> seqs[1];
  for (int i = 2; i < n; i++) {
    seqs[i] = seqs[i - 2] * A + seqs[i - 1] * B + C;
  }
  nth_element(seqs.begin(), seqs.begin() + k1 - 1, seqs.end());
  nth_element(seqs.begin() + k1 - 1, seqs.begin() + k2 - 1, seqs.end());
  sort(seqs.begin() + k1 - 1, seqs.begin() + k2);
  for (int i = k1 - 1; i < k2; i++) {
    cout << seqs[i];
    if (i != k2 - 1) cout << " ";
    else cout << endl;
  }

}