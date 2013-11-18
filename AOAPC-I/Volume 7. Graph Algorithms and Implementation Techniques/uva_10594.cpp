//Clibrary:
#include<cassert>
#include<cctype>
#include<cerrno>
//#include<cfenv>
#include<cfloat>
//#include<cinttypes>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
//#include<cstdbool>
#include<cstddef>
//#include<cstdint>
#include<cstdio>
#include<cstdlib>
#include<cstring>
//#include<ctgmath>
#include<ctime>
//#include<cuchar>
#include<cwchar>
#include<cwctype>
//Containers:
//#include<array>
#include<bitset>
#include<deque>
//#include<forward_list>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
//#include<unordered_map>
//#include<unordered_set>
#include<vector>
//Input/Output:
#include<fstream>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<ostream>
#include<sstream>
#include<streambuf>
//Other:
#include<algorithm>
//#include<chrono>
//#include<codecvt>
#include<complex>
#include<exception>
#include<functional>
//#include<initializer_list>
#include<iterator>
#include<limits>
#include<locale>
#include<memory>
#include<new>
#include<numeric>
//#include<random>
//#include<ratio>
//#include<regex>
#include<stdexcept>
#include<string>
//#include<system_error>
//#include<tuple>
//#include<typeindex>
#include<typeinfo>
//#include<type_traits>
#include<utility>
#include<valarray>
using namespace std;

typedef long long i64;
typedef unsigned long long u64;
const double PI = acos(-1);
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
const i64 MAX_V = 128;
const i64 INF = 1000000000000001ll;
i64 N, M;
i64 D, K;
typedef pair<i64, int> P;

struct edge{i64 to, cap, cost, rev; };

int V;
vector<edge> G[MAX_V];
i64 h[MAX_V];
i64 dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

void reset(){
  for (int i = 0; i < MAX_V; i++){
    G[i].clear();
  }
}

void add_edge(int from, int to, i64 cap, i64 cost){
  G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
  G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
}

i64 min_cost_flow(int s, int t, i64 f){
  i64 res = 0;
  fill(h, h + V, 0);
  while(f > 0){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(dist, dist + V, INF);
    dist[s] = 0;
    que.push(P(0, s));
    while (!que.empty()){
      P p = que.top(); que.pop();
      int v = p.second;
      if (dist[v] < p.first) continue;
      for (size_t i = 0; i < G[v].size(); i++){
        edge &e = G[v][i];
        if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
          prevv[e.to] = v;
          preve[e.to] = i;
          que.push(P(dist[e.to], e.to));
        }
      }
    }
    if (dist[t] == INF) return -1;
    for (int v = 0; v < V; v++) h[v] += dist[v];
    /*
    fill(dist, dist + V, INF);
    dist[s] = 0;
    bool update = true;
    while (update){
      update = false;
      for (int v = 0; v < V; v++){
        if (dist[v] == INF) continue;
        for (size_t i = 0; i < G[v].size(); i++){
          edge &e = G[v][i];
          if (e.cap > 0 && dist[e.to] > dist[v] + e.cost){
            dist[e.to] = dist[v] + e.cost;
            prevv[e.to] = v;
            preve[e.to] = i;
            update = true;
          }
        }
      }
    }
    */
    if (dist[t] == INF) return -1;

    i64 d = f;
    for (int v = t; v != s; v = prevv[v]){
      d = min(d, G[prevv[v]][preve[v]].cap);
    }
    f -= d;
    //res += d * dist[t];
    res += d * h[t];
    for (int v = t; v != s; v = prevv[v]){
      edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
  }
  return res;
}

const int MAXM = 1024 * 5;
i64 us[MAXM];
i64 vs[MAXM];
i64 cs[MAXM];

i64 TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (scanf("%lld%lld", &N, &M) != EOF){
    reset();
    for (int i = 0; i < M; i++){
      scanf("%lld%lld%lld", &us[i], &vs[i], &cs[i]);
    }
    scanf("%lld%lld", &D, &K);
    for (int i = 0; i < M; i++){
      add_edge(us[i], vs[i], K, cs[i]);
      add_edge(vs[i], us[i], K, cs[i]);
    }
    V = N + 1;
    i64 ans = min_cost_flow(1, N, D);
    if (ans == -1) printf("Impossible.\n");
    else printf("%lld\n", ans);
  }
}

