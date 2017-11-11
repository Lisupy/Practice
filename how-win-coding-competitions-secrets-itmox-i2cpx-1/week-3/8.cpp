#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<numeric>
#include<map>
using namespace std;
struct Item {
  int i;
  int A, B;
  long long curA, curB;
};
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; scanf("%d", &N);
  vector<Item> items(N);
  for (auto &i: items) scanf("%d", &i.A);
  for (auto &i: items) scanf("%d", &i.B);
  for (int i = 0; i < N; i++) items[i].i = i;
  sort(items.begin(), items.end(), [](Item &l, Item &r) {
    if (l.A - l.B < 0 && r.A - r.B < 0) return l.A < r.A;
    if (l.A - l.B < 0 && r.A - r.B >= 0) return true;
    if (l.A - l.B >= 0 && r.A - r.B < 0) return false;
    return l.B > r.B;
  });
  long long curA = 0;
  long long curB = 0;
  for (auto &i: items) {
    i.curA = curA;
    curA += i.A;
    curB = max(curB, curA);
    i.curB = curB;
    curB += i.B;
  }
  sort(items.begin(), items.end(), [](Item &l, Item &r) {
    return l.i < r.i;
  });
  printf("%lld\n", curB);
  for (int i = 0; i < N; i++) {
    printf("%lld", items[i].curA);
    if (i == N - 1) printf("\n");
    else printf(" ");
  }
  for (int i = 0; i < N; i++) {
    printf("%lld", items[i].curB);
    if (i == N - 1) printf("\n");
    else printf(" ");
  }
}