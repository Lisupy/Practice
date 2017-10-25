#include<iostream>
#include<queue>
#include<cstdio>
#include<stack>
#include<string>
#include<numeric>
#include<map>
#include<deque>
using namespace std;
struct Container {
  int idx;
  deque<int> q[2];
  Container() {
    idx = 0;
  }
  void add(int x) {
    q[1-idx].push_back(x);
    balance();
  }
  void take() {
    q[1-idx].pop_back();
    balance();
  }
  void mum() {
    idx = 1 - idx;
    balance();
  }
  void balance() {
    while (int(q[idx].size()) > int(q[1-idx].size())) {
      int x = q[idx].back(); q[idx].pop_back();
      q[1-idx].push_front(x);
    }
    while (int(q[idx].size()) < int(q[1-idx].size()) - 1) {
      int x = q[1-idx].front(); q[1-idx].pop_front();
      q[idx].push_back(x);
    }
  }
  void output() {
    printf("%d\n", q[idx].size() + q[1-idx].size());
    bool isFirst = true;
    for (auto i: q[idx]) {
      if (isFirst) isFirst = false;
      else printf(" ");
      printf("%d", i);
    }
    for (auto i: q[1 - idx]) {
      if (isFirst) isFirst = false;
      else printf(" ");
      printf("%d", i);
    }
    printf("\n");
  }
};
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; scanf("%d", &N);
  Container S;
  while (N--) {
    char op[10]; scanf("%s", op);
    if (op[0] == 'a') {
      int x; scanf("%d", &x);
      S.add(x);
    } else if (op[0] == 't') {
      S.take();
    } else if (op[0] == 'm') {
      S.mum();
    }
    // S.output();
  }
  S.output();
}