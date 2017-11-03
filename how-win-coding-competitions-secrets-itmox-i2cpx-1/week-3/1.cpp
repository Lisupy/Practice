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
long long sort(vector<int> &A, vector<int> &B, int from, int to) {
  if (to + 1 - from <= 1) return 0;
  int mid = (from + to) / 2;
  long long tot = 0;
  tot += sort(B, A, from, mid);
  tot += sort(B, A, mid + 1, to);
  tot += merge(A, B, from, mid, to);
  printf("%d %d %d %d\n", from + 1, to + 1, B[from], B[to]);
  return tot;
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; scanf("%d", &N);
  vector<int> A(N); for (auto &e: A) cin >> e;
  vector<int> B(A);
  sort(A, B, 0, N - 1);
  for (size_t i = 0; i < N; i++) {
    printf("%d", B[i]);
    if (i != N - 1) printf(" ");
    else printf("\n");
  }
}