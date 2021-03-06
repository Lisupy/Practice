//Vertex Biconnectivity Components
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
int N, M;
vector<vector<int>> G;
vector<int> low;
vector<int> num;
vector<vector<pair<int, int> >> vbic; // edges
vector<int> idx;
stack<pair<int, int>> S;
vector<int> current;
int counter = 0;
void dfs(int s, int f = -1) {
  // cout << "dfs" << s << endl;
  low[s] = num[s] = ++counter;
  if (G[s].empty()) {
    return;
  }
  for (auto t: G[s]) {
    S.push({s, t});
    if (t == f) continue;
    // cout << "push " << s << " " << t << endl;
    if (num[t] > -1) low[s] = min(low[s], num[t]);
    else {
      dfs(t, s);
      low[s] = min(low[s], low[t]);
      if (low[t] >= num[s]) {
        vbic.push_back({});
        while (true) {
          auto u = S.top();
          S.pop();
          vbic.back().push_back(u);
          if (u == make_pair(s, t)) break;
        }
      }
    }
  }
}
map<pair<int, int>, int> edgeIdx;
vector<pair<int, int>> edges;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  //read
  cin >> N >> M;
  G.resize(N + 1);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
    edgeIdx[{u, v}] = edgeIdx[{v, u}] = i;
    edges.push_back({u, v});
  }

  //scc
  num.resize(N + 1, -1);
  low.resize(N + 1);
  current.resize(N + 1);
  for (int i = 1; i <= N; i++) if (num[i] == -1) dfs(i);

  idx.resize(M);
  for (int i = 0; i < vbic.size(); i++) {
    for (auto t: vbic[i]) idx[edgeIdx[t]] = i; 
  }

  cout << vbic.size() << endl;
  for (int i = 0; i < M; i++) {
    cout << idx[i] + 1;
    if (i == M) cout << endl;
    else cout << " ";
  }
}