#include<string>
#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstdint>
using namespace std;
struct Edge {
  int u, v;
  long long w;
};
const long long INF = (1ll << 63) - 1;
const long long NINF = -2e18 - 1;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N, M, S; cin >> N >> M >> S;
  vector<Edge> edges(M);
  for (auto &e: edges) cin >> e.u >> e.v >> e.w;
  vector<long long> dist(N + 1, INF);
  dist[S] = 0;
  for (int i = 0; i < N; i++) {
     for (auto &e: edges) if (dist[e.u] != INF) {
        long long d = dist[e.u] + e.w;
        if (d < dist[e.v]) {
          dist[e.v] = d;
          if (dist[e.v] < NINF) dist[e.v] = NINF;
        }
     }
  }
  vector<int> state(N + 1); // 0-unvisited, 1-visited, 2-incycle
  state[S] = 1;
  for (int i = 0; i < N; i++) {
     for (auto &e: edges) if (dist[e.u] != INF) {
        long long d = dist[e.u] + e.w;
        if (d < dist[e.v]) {
          dist[e.v] = d;
          if (dist[e.v] < NINF) dist[e.v] = NINF;
          if (state[e.v] == 0) state[e.v] = 1;
          else state[e.v] = 2;
        }
     }
  }
  for (int i = 0; i < N; i++) {
    for (auto &e: edges) {
      if (state[e.u] == 2) {
        state[e.v] = 2;
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    if (dist[i] == INF) cout << "*" << endl;
    else if (state[i] == 2) cout << "-" << endl;
    else cout << dist[i] << endl;
  }
}