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

const int MAXN = 64;
const int INF = 0x1f1f1f1f;
const double EPS = 1e-6;
const double DINF = 1e20;
int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
double cost[MAXN][MAXN];

void reset(){
  memset(cap, 0, sizeof(cap));
  memset(flow, 0, sizeof(flow));
  memset(cost, 0, sizeof(cost));
}

void addEdge(int u, int v, int _cap, double _cost){
  cap[u][v] = _cap;
  cost[u][v] = _cost;
  cost[v][u] = -_cost;
}

double maxFlowMinCost(int s, int t){
  queue<int> q;
  vector<double> d(MAXN);
  memset(flow, 0, sizeof(flow));
  int totalFlow = 0;
  double totalCost = 0;
  while (true){
    vector<bool> inq(MAXN);
    vector<int> p(MAXN);
    for (int i = 0; i < MAXN; i++) d[i] = i == s? 0: DINF;
    q.push(s);
    while (!q.empty()){
      int u = q.front(); q.pop();
      inq[u] = false;
      for (int v = 0; v < MAXN; v++) if (cap[u][v] > flow[u][v] && d[v] > d[u] + cost[u][v] + EPS){
        d[v] = d[u] + cost[u][v] + EPS;
        p[v] = u;
        if (!inq[v]) inq[v] = true, q.push(v);
      }
    }
    
    if (d[t] == DINF) break;
    int a = INF;
    for (int u = t; u != s; u = p[u]) a = min(a, cap[p[u]][u] - flow[p[u]][u]);

    for (int u = t; u != s; u = p[u]){
      flow[p[u]][u] += a;
      flow[u][p[u]] -= a;
    }

    totalCost += d[t] * a;
    totalFlow += a;
  }
  return totalCost;
}
int n, m;
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while ( scanf("%d %d", &n, &m ) && n){
    reset();
    for (int i = 1; i <= n; i++) addEdge(0, i, 1, 0);
    for (int j = 1; j <= m; j++) addEdge(j + n, n + m + 1, 1, 0);

    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= m; j++){
        double c; scanf("%lf", &c);
        addEdge(i, j + n, 1, c);
      }
    }
    printf("%.02lf\n", maxFlowMinCost(0, n + m + 1) / n);
  }
}

