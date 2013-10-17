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

struct DisjointSet{
  vector<int> p;
  DisjointSet(int n): p(n){
    for (int i = 0; i < n; i++) p[i] = i;
  }
  int find(int x){ return p[x] = x == p[x] ? x: find(p[x]);}
  void join(int x, int y){ p[find(x)] = p[find(y)];}
};
struct Edge{
  int u, v;
  double d;
};
bool operator<(const Edge& a, const Edge &b){
  return a.d < b.d;
}
int n;
int x[1024];
int y[1024];
double solve(){
  vector<Edge> edges;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      edges.push_back({i, j, sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2))}); 
    }
  }
  sort(edges.begin(), edges.end());
  DisjointSet ds(n);
  for (size_t i = 0; i < edges.size(); i++){  
    Edge e = edges[i];
    ds.join(e.u, e.v);
    if (ds.find(0) == ds.find(1)) return e.d;
  }
  assert(0);
  return 0;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (cin >> n && n){
    printf("Scenario #%d\n", ++TestNum);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    printf("Frog Distance = %.03lf\n", solve());
    printf("\n");
  }
}

