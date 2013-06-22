/*
 * Algorithm:   MST, sort, union-find
 * Complexity:
 * IndexBased:  0
 * Trick:       
 * LayOut:
 *  reset();
 *  input();
 *  struct Edge{
 *    int u, v, w;
 *    };
 *  solve();
 */

#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;


const int MAXN = 128;

struct Edge{
  int u, v, w;
};

bool operator<(const Edge &a, const Edge &b){
  return a.w > b.w;
}

int p[MAXN];
int find(int u){
  return p[u] == u ? u : ( p[u] = find(p[u]));
}

void join(int u, int v){
  int pu = find(u);
  int pv = find(v);
  if (pu != pv){
    p[pu] = pv;
  }
}

vector<Edge> edges;

void reset(){
  edges.clear();
  for (int i = 0; i < MAXN; i++){
    p[i] = i;
  }
}


int slove(int s, int t){
  if (find(s) == find(t)){
    return 0;
  }
  sort(edges.begin(), edges.end());
  for (size_t i = 0; i < edges.size(); i++){
    int u = edges[i].u;
    int v = edges[i].v;
    int w = edges[i].w;
    join(u, v);
    if (find(s) == find(t)){
      return w;
    }
  }
  return -1;
}


int main(){
  int sceNum = 0;
  while (true){
    reset();
    int N, R;
    cin >> N >> R;
    if (N == 0){
      break;
    }
    edges.resize(R);
    for (int i = 0; i < R; i++){
      cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    int S, D, T;
    cin >> S >> D >> T;
    int load = slove(S, D);
  //  cout << load << endl;
    cout << "Scenario #" << ++sceNum << endl;
    cout << "Minimum Number of Trips = " << (int)ceil((double(T)) / (load - 1)) << endl;
    cout << endl;
  }
}
