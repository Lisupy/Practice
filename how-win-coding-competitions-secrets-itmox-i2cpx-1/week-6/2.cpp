#include<string>
#include<functional>
#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstdint>
#include<limits>
using namespace std;
struct Edge {
  int v;
  int w;
};
vector<vector<Edge>> G;
const int INF = numeric_limits<int>::max();
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N, M; cin >> N >> M;
  G.resize(N + 1);
  while (M--) {
    int u, v, w; cin >> u >> v >> w;
    G[u].push_back(Edge{v, w});
    G[v].push_back(Edge{u, w});
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
  vector<int> dist(N + 1, INF);
  dist[1] = 0;
  Q.push(make_pair(0, 1));
  while (!Q.empty()) {
    auto s = Q.top().second; Q.pop();
    for (auto t: G[s]) {
      int d = dist[s] + t.w;
      if (d < dist[t.v]) {
        dist[t.v] = d;
        Q.push({d, t.v});
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    cout << dist[i];
    if (i == N) cout << endl;
    else cout << " ";
  }

}