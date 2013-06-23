/*
 * Algorithm:   MST, Kruskal
 * Complexiay:  N*N*log(N)
 * IndexBased:  0
 * Trick:
 * LayOut:
 *  struct Edge{};
 *  reset();
 *  input();
 *  solve();
 */


#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;


const int MAXN = 128;
const int MAXN2 = MAXN * MAXN;

int n;

struct Edge{
  int u, v;
  double w;
  void p(){
    cout << u << ", " << v << ": " << w << endl;
  }
};

double x[MAXN];
double y[MAXN];

int p[MAXN];

void p_init(){
  for (int i = 0; i < MAXN; i++){
    p[i] = i;
  }
}

void p_p(){
  for (int i = 0; i < n; i++){
    cout << p[i] << " ";
  }
  cout << endl;
}

int find(int u){
  return (p[u] == u) ? u : (p[u] = find(p[u]));
}

void join(int u, int v){
  int pu = find(u);
  int pv = find(v);
  if (pu != pv){
    p[pu] = pv;
  }
}

vector<Edge> edges;
bool operator<(const Edge &a, const Edge &b){
  return a.w < b.w;
}

double mst(){
  p_init();
  edges.clear();

  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      Edge e = {i, j, sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) )};
      edges.push_back(e);
    }
  }
  sort(edges.begin(), edges.end());

  double cost = 0;
  for (size_t i = 0; i < edges.size(); i++){
    Edge &e = edges[i];
    if (find(e.u) == find(e.v)){
      continue;
    }
 //   cout << find(e.u) << " " << find(e.v) << endl;
 //   e.p();
    cost += e.w;
    join(e.u, e.v);
 //   p_p();
  }
  return cost;
}


void input(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }
}

int main(){
  int TestNum;
  cin >> TestNum;
  while (TestNum--){
    input();
    double res = mst();
    printf("%.02lf\n", res);
    if (TestNum){
      printf("\n");
    }
  }
}
