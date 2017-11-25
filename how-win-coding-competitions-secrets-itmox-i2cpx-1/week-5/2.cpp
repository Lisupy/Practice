#include<string>
#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> color;
vector<vector<int>> G;
bool DFS(int s, int c) {
  color[s] = c;
  for (auto t : G[s]) {
    if (color[t] == 0) {
      if (!DFS(t, 3 - c)) return false;
    } else if (color[t] == c) return false;
  }
  return true;
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N, M;
  cin >> N >> M;
  color.resize(N + 1);
  G.resize(N + 1);
  for (int i = 0; i < M; i++) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }
  for (int i = 1; i <= N; i++) {
    if (!color[i]) {
      if (!DFS(i, 1)) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
}