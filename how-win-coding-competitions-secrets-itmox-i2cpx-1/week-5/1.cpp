#include<string>
#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> color;
vector<int> inDegree;
vector<vector<int>> G;
vector<int> DFS(int s, vector<int>& path) {
  color[s] = 1;
  path.push_back(s);
  for (auto t : G[s]) {
    if (color[t] == 2) continue;
    else if (color[t] == 0) {
      auto tmp = DFS(t, path);
      if (tmp.size()) return tmp;
    } else if (color[t] == 1) {
      vector<int> cycle;
      int cur = path.size() - 1;
      while (path[cur] != t) {
        cycle.push_back(path[cur]);
        cur--;
      }
      cycle.push_back(t);
      reverse(cycle.begin(), cycle.end());
      return cycle;
    }
  }
  path.pop_back();
  color[s] = 2;
  return {};
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N, M;
  cin >> N >> M;
  color.resize(N + 1);
  inDegree.resize(N + 1);
  G.resize(N + 1);
  for (int i = 0; i < M; i++) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(t);
  }
  for (int i = 1; i <= N; i++) {
    if (!color[i]) {
      vector<int> tmp;
      auto cycle = DFS(i, tmp);
      if (cycle.size() != 0) {
        cout << "YES" << endl;
        for (size_t i = 0; i < cycle.size(); i++) {
          cout << cycle[i];
          if (i + 1 != cycle.size()) cout << " ";
          else cout << endl;
        }
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}