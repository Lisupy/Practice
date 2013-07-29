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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 */


const int MAXN = 128;
const int INF = 0x1f1f1f1f;
int n;
int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int cost[MAXN][MAXN];
int source, dest;
int totalCost = 0;
int totalFlow = 0;
void reset(){
  memset(cap, 0, sizeof(cap));
  memset(flow, 0, sizeof(flow));
  memset(cost, 0, sizeof(cost));
}
void maxFlowMinCost(){
  totalCost = 0;
  totalFlow = 0;
  while (true){
    vector<int> d(dest + 1, INF);
    vector<int> p(dest + 1);
    d[source] = 0;
    queue<int> q;
    vector<bool> inque(dest + 1);
    q.push(source), inque[source] = true;
    while (!q.empty()){
      int u = q.front(); q.pop(); inque[u] = false;
      for (int v = 0; v <= dest; v++){
        int co = flow[u][v] >= 0? cost[u][v] : -cost[u][v];
        if (cap[u][v] > flow[u][v] && d[v] > d[u] + co){
          d[v] = d[u] + co;
          p[v] = u;
          if (!inque[v]) inque[v] = true, q.push(v);
        }
      }
    }
    if (d[dest] == INF) break;
    int a = INF;
    for (int u = dest; u != source; u = p[u]) a = min(a, cap[p[u]][u] - flow[p[u]][u]);
    for (int u = dest; u != source; u = p[u]) flow[p[u]][u] += a, flow[u][p[u]] -= a;
    //cout << d[dest] << endl;
    totalCost += d[dest] * a;
    totalFlow += a;
  }
  //cout << totalFlow << ", " << totalCost << endl;
}
int main(){
  while (cin >> n && n){
    reset();
    int m; cin >> m;
    while (m--){
      int u, v, c; cin >> u >> v >> c;
      cap[u][v] = 1;
      cost[u][v] = c;
      cap[v][u] = 1;
      cost[v][u] = c;
    }
    source = 0, dest = n;
    cap[source][1] = 2; 
    maxFlowMinCost();
    //cout << totalFlow << ", " << totalCost << endl;
    if (totalFlow < 2){
      cout << "Back to jail" << endl;
    }else{
      cout << totalCost << endl;
    }
  }
}
