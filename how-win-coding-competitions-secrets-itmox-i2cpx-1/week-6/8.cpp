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
int N;
unsigned int d[1515][1515];
unsigned int d2[1515][1515];
struct Edge{
  int u, v, w;
  Edge(int u, int v, int w): u(u),v(v),w(w){}
};
vector<Edge> mst;
vector<pair<int, int>> G[1515];
bool isSame() {
  for (int i = 1; i <= N; i++) {
    vector<unsigned int> dist(N + 1, (1u<<31) - 1);

    {
      queue<int> Q;
      dist[i] = 0;
      Q.push(i);
      while (!Q.empty()) {
        int  s = Q.front(); Q.pop();
        for (auto t: G[s]) if (dist[t.first] == (1u<<31) - 1) {
          dist[t.first] = dist[s] + t.second;
          Q.push(t.first);
        }
      }
    }

    for (int j = 1; j <= N; j++) {
      if (dist[j] != d2[i][j]) return false;
    }
  }
  return true;
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      scanf("%d", &d[i][j]);
      d2[i][j] = d[i][j];
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == j) d[i][j] = 0;
      else d[i][j] = (1u<<31)-1;
    }
  }

  //mst
  vector<int> pre(1515, (1u<<31) - 1);
  vector<int> dist(1515, (1u<<31) - 1);
  vector<bool> inSet(1515);

  inSet[1] = true;
  for (int i = 1; i <= N; i++) dist[i] = d2[1][i], pre[i] = 1;
  while (mst.size() != N - 1) {
    int idx = -1;
    for (int j = 1; j <= N; j++) if (!inSet[j]) {
      if (idx == -1 || dist[idx] > dist[j]) idx = j;
    }
    inSet[idx] = true;
    d[pre[idx]][idx] = d[idx][pre[idx]] = dist[idx];
    mst.push_back(Edge(idx, pre[idx], dist[idx]));
    G[idx].push_back({pre[idx], dist[idx]});
    G[pre[idx]].push_back({idx, dist[idx]});
    for (int i = 1; i <= N; i++) if (dist[i] > d2[idx][i]) {
      pre[i] = idx;
      dist[i] = d2[idx][i];
    }
  }


  if (!isSame()) {
    printf("NO\n");
    return 0;
  }

  printf("YES\n");
  printf("%d\n", N - 1);
  for (auto e: mst) {
    printf("%d %d %d\n", e.u, e.v, e.w);
  }
}