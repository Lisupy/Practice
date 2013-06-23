/*
 * Algorithm:   Euler Cycle
 * Complexity:  O(N)
 * IndexBased:  1
 * Trick:
 * LayOut:
 *    euler_cycle(vector<int> &path);
 *    dfs(int k, vector<int> &path);
 */

#include<algorithm>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;


const int MAXN = 64;
int graph[MAXN][MAXN];
int degree[MAXN];

void dfs(int s, vector<pair<int, int> > &path){
  for (int i = 0; i < MAXN; i++){
    if (graph[s][i]){
      graph[s][i]--;
      graph[i][s]--;
      degree[i]--;
      degree[s]--;
      dfs(i, path);
      path.push_back(make_pair(i, s));
    }
  }
}

int euler_cycle(vector<pair<int, int> > &path){
  memset(degree, 0, sizeof(degree));
  for (int i = 1; i < MAXN; i++){
    for (int j = 1; j < MAXN; j++){
      degree[i] += graph[i][j];
    }
  }
  for (int i = 1; i < MAXN; i++){
    if (degree[i] % 2 == 1){
      return -1;
    }
  }

  int s = 0;
  for (int i = 1; i < MAXN; i++){
    if (degree[i] > 0){
      s = i;
      break;
    }
  }

  dfs(s, path);
  for (int i = 1; i < MAXN; i++){
    if (degree[i] > 0){
      return -1;
    }
  }
  return 0;
}

int main(){
  int T;
  cin >> T;
  for (int ti = 1; ti <= T; ti++){
    cout << "Case #" << ti << endl;
    memset(graph, 0, sizeof(graph));
    int N;
    cin >> N;
    while (N--){
      int s, t;
      cin >> s >> t;
      graph[s][t]++;
      graph[t][s]++;
    }
    vector<pair<int, int> > path;
    int res = euler_cycle(path);
    if (res == -1){
      cout << "some beads may be lost" << endl;
    }else{
      for (size_t i = 0; i < path.size(); i++){
        cout << path[i].first << " " << path[i].second << endl;
      }
    }
    if (ti != T){
      cout << endl;
    }
  }
}

