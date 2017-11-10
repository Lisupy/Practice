#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<numeric>
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; scanf("%d", &N);
  vector<int> A(N+1);
  for (int i = 1; i <= N; i++) {
    A[i] = i;
    if (i > 2) swap(A[i], A[(1+i)/2]);
  }
  for (int i = 1; i <= N; i++) {
    printf("%d", A[i]);
    if (i == N) printf("\n");
    else printf(" ");
  }
}