#include<iostream>
#include<queue>
#include<cstdio>
#include<stack>
using namespace std;
template<typename T>
struct MinQueue{
  queue<int> Q;
  deque<int> M;
  MinQueue() {}
  void push(T x) {
    Q.push(x);
    while (!M.empty() && M.back() > x) M.pop_back();
    M.push_back(x);
  }
  int pop() {
    int x = Q.front(); Q.pop();
    if (x == M.front()) M.pop_front();
    return x;
  }
  int min() {
    return M.front();
  }
};
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; scanf("%d", &N);
  MinQueue<int> S;
  while (N--) {
    char op[10]; scanf("%s", op);
    if (op[0] == '+') {
      int x; scanf("%d", &x);
      S.push(x);
    } else if (op[0] == '-') {
      S.pop();
    } else {
      printf("%d\n", S.min());
    }
  }
}