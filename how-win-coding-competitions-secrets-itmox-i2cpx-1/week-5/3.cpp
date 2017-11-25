#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N, M;
vector<int> spells;
vector<bool> visited;
vector<vector<pair<int, int>>> G;
void DFS(int s, int f, int &counter) {
  visited[s] = true;
  for (auto t: G[s]) if (t.first != f && spells[t.second] == 0) {
    spells[t.second] = counter++;
    if (!visited[t.first]) DFS(t.first, s, counter);
  }
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> N >> M;
  G.resize(N + 1);
  visited.resize(N + 1);
  spells.resize(M + 1);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back({v, i});
    G[v].push_back({u, i});
  }
  int numOfLeaf = 0;
  int Root = 0;
  for (int i = 1; i <= N; i++) {
    if (G[i].size() == 1) {
      numOfLeaf++;
      Root = i;
    }
  }
  if (numOfLeaf >= 2) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  int counter = 1;
  DFS(Root, -1, counter);
  for (int i = 1; i <= N; i++) if (!visited[i]) {
    DFS(i, -1, counter);
  }
  for (int i = 0; i < M; i++) {
    cout << spells[i];
    if (i == M - 1) cout << endl;
    else cout << " ";
  }
}