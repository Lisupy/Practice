#include<string>
#include<functional>
#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<tuple>
#include<limits>
using namespace std;
const int INF = 0x3f3f3f3f;
int d[511][511];
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      scanf("%d", &d[i][j]);
      if (d[i][j] == -1) d[i][j] = INF;
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int s = 1; s <= N; s++) {
      for (int t = 1; t <= N; t++) {
        d[s][t] = min(d[s][t], d[s][i] + d[i][t]);
      }
    }
  }
  for (int s = 1; s <= N; s++) {
    for (int t = 1; t <= N; t++) {
      if (d[s][t] == INF) printf("%d", -1);
      else printf("%d", d[s][t]);
      if (t == N) printf("\n");
      else printf(" ");
    }
  }
}