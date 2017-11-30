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
struct Edge {
  long long v;
  long long w;
};
vector<vector<Edge>> G;
const long long INF = numeric_limits<long long>::max();
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  long long N, S, F; scanf("%lld%lld%lld", &N, &S, &F);
  G.resize(N + 1);
  for (long long i = 1; i <= N; i++) {
    for (long long j = 1; j <= N; j++) {
      long long w; scanf("%lld", &w);
      if (w == -1) continue;
      G[i].push_back(Edge{j, w});
    }
  }
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> Q;
  vector<long long> dist(N + 1, INF);
  dist[S] = 0;
  Q.push(make_pair(0, S));
  while (!Q.empty()) {
    auto s = Q.top(); Q.pop();
    if (s.first != dist[s.second]) continue;
    for (auto t: G[s.second]) {
      long long d = dist[s.second] + t.w;
      if (d < dist[t.v]) {
        dist[t.v] = d;
        Q.push({d, t.v});
      }
    }
  }
  if (dist[F] == INF) cout << -1 << endl;
  else cout << dist[F] << endl;

}