#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; scanf("%d", &N);
  queue<int> S;
  while (N--) {
    char op[10]; scanf("%s", op);
    if (op[0] == '+') {
      int x; scanf("%d", &x);
      S.push(x);
    } else {
      printf("%d\n", S.front());
      S.pop();
    }
  }
}