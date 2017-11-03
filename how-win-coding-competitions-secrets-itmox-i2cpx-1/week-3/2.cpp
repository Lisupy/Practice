#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
typedef vector<int>::iterator vii;
long long merge(vector<int> &A, vector<int> &B, int from, int mid, int to) {
  long long tot = 0;
  int cur = from;
  int l1 = from, l2 = mid + 1;
  while (l1 <= mid && l2 <= to) {
    if (A[l1] <= A[l2]) B[cur++] = A[l1++];
    else tot += mid + 1 - l1, B[cur++] = A[l2++];
  }
  while (l1 <= mid) B[cur++] = A[l1++];
  while (l2 <= to) B[cur++] = A[l2++];
  return tot;
}
//sort A to B
long long getInversion(vector<int> &A, vector<int> &B, int from, int to) {
  if (to + 1 - from <= 1) return 0;
  int mid = (from + to) / 2;
  long long tot = 0;
  tot += getInversion(B, A, from, mid);
  tot += getInversion(B, A, mid + 1, to);
  tot += merge(A, B, from, mid, to);
  return tot;
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; scanf("%d", &N);
  vector<int> A(N); for (auto &e: A) cin >> e;
  vector<int> B(A);
  cout << getInversion(A, B, 0, N - 1) << endl;
}