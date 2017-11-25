#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<string>
using namespace std;
const int INF = 1000 * 1000 * 1000 + 10;
struct Container{
  set<pair<int, int>> M;
  map<int, int> idx;
  void A(int x, int id) {
    M.insert({x, id});
    idx[id] = x;
  }
  int X() {
    if (M.empty()) return INF;
    auto it = M.begin();
    int x = it->first;
    int id = it->second;
    M.erase(it);
    return x;
  }
  void D(int x, int y) {
    int v = idx[x];
    M.erase({v, x});
    idx[x] = y;
    M.insert({y, x});
  }
};
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; scanf("%d", &N);
  Container C;
  for (int i = 1; i <= N; i++) {
    char op[20]; scanf("%s", op);
    if (op[0] == 'A') {
      int x; scanf("%d", &x);
      C.A(x, i);
    } else if (op[0] == 'X') {
      int t = C.X();
      if (t == INF) printf("*\n");
      else printf("%d\n", t);
    } else if (op[0] == 'D') {
      int x, y; scanf("%d%d", &x, &y);
      C.D(x, y);
    }
  }
}