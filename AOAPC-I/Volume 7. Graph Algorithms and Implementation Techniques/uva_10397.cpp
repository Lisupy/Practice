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

const int MAXN = 1024;
struct Edge{
  int u, v;
  double l;
};
bool operator<(const Edge &a, const Edge &b) { return a.l < b.l;}
int N;
int x[MAXN];
int y[MAXN];
int p[MAXN];
void reset(){
  for (int i = 0; i < MAXN; i++) p[i] = i;
}
int find(int u){
  int pu = p[u];
  while (p[pu] != pu) pu = p[pu];
  while (p[u] != pu){ int next = p[u]; p[u] = pu; u = next; };
  return pu;
}
void join(int u, int v){
  int pu = p[u], pv = p[v];
  if (pu != pv) p[pu] = pv;
}


int main(){
  while (cin >> N){
    reset();
    for (int i = 1; i <= N; i++) cin >> x[i] >> y[i];
    vector<Edge> edges;
    for (int i = 1; i <= N; i++){
      for (int j = i + 1; j <= N; j++){
        edges.push_back({i, j, sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2))});
      }
    }
    sort(edges.begin(), edges.end());
    int M; cin >> M;
    int edgeNum = 0;
    while (M--){
      int u, v; cin >> u >> v;
      if (find(u) != find(v)) edgeNum++;
      join(u, v);
    }
    double total = 0;
    for (size_t i = 0; i < edges.size() && edgeNum < N - 1; i++) {
      Edge &e = edges[i];
      if (find(e.u) == find(e.v)) continue;
      edgeNum++;
      total += e.l;
      join(e.u, e.v);
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << total << endl;
  }
}
