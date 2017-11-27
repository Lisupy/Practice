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
vector<int> isWin; // 0-unvisited, 1-win, 2-lose
bool dfs(int s) {
  int &res = isWin[s];
  if (res != 0) return res == 1;
  res = 2;
  for (auto t: G[s]) {
    if (!dfs(t)) res = 1;
  }
  return res == 1;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  //read
  int S;
  cin >> N >> M >> S;
  G.resize(N + 1);
  isWin.resize(N + 1);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
  }

  cout << (dfs(S)? "Alice": "Bob") << endl;
}