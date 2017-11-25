#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int N, M;
vector<vector<int>> G;
vector<int> low;
vector<int> num;
vector<vector<int>> scc;
vector<int> current;
vector<int> idx;
vector<int> S;

vector<int> sccDegree;
vector<int> sccNum;  

int counter = 0;
void dfs(int s) {
  low[s] = num[s] = counter++;
  S.push_back(s);
  current[s] = 1;
  for (auto t: G[s]) {
    if (num[t] == -1) dfs(t);
    if (current[t]) low[s] = min(low[s], low[t]);
  }
  if (low[s] == num[s]) {
    scc.push_back({});
    while (1) {
      int t = S.back(); S.pop_back(); current[t] = 0;
      idx[t] = scc.size() - 1;
      scc.back().push_back(t);
      if (s == t) break;
    }
  }
}


int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  //read
  cin >> N >> M;
  G.resize(N + 1);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
  }

  //scc
  num.resize(N + 1, -1);
  low.resize(N + 1);
  current.resize(N + 1);
  idx.resize(N + 1);
  for (int i = 1; i <= N; i++) if (num[i] == -1) dfs(i);

  //topoloy sort
  sccDegree.resize(scc.size());
  sccNum.resize(scc.size());
  for (int s = 1; s <= N; s++) {
    for (auto t: G[s]) if (idx[t] != idx[s]) {
      sccDegree[idx[t]]++;
    }
  }
  counter = 0;
  queue<int> Q;
  for (int i = 0; i < scc.size(); i++) if (sccDegree[i] == 0) Q.push(i);
  while (!Q.empty()) {
    auto s = Q.front(); Q.pop();
    sccNum[s] = counter++;
    for (auto ss: scc[s]) {
      for (auto t: G[ss]) if (idx[t] != s) {
        if (--sccDegree[idx[t]] == 0) Q.push(idx[t]);
      }
    }
  }
  //output
  cout << scc.size() << endl;
  for (int i = 1; i <= N; i++) {
    cout << sccNum[idx[i]] + 1;
    if (i == N) cout << endl;
    else cout << " ";
  }
}