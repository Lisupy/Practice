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
int n, m;
struct Edge{
  int from, to;
  int w;
};

bool existNegCycle(vector<Edge> edges){
  vector<int> dist(n + 1, 0x1f1f1f1f);
  dist[0] = 0;
  for (int k = 0; k <= n; k++){ 
    bool ok = true;
    for (size_t i = 0; i < edges.size(); i++){
      Edge e = edges[i];
      if (dist[e.from] + e.w < dist[e.to]){
        dist[e.to] = dist[e.from] + e.w;
        ok = false;
      }
    }
    if (ok) return false;
  }
  return true;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (cin >> n >> m){
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++){
      int si, ni, ki;
      string oi;
      cin >> si >> ni >> oi >> ki;
      int v = si + ni, u = si - 1;
      if (oi == "gt") swap(u, v), ki = -ki;
      edges[i] = {u, v, ki - 1};
    }
    if (existNegCycle(edges)) cout << "successful conspiracy" << endl;
    else cout << "lamentable kingdom" << endl;
  }
}

