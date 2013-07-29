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

const int MAXP = 512;
int N;
int S, P;
int x[MAXP];
int y[MAXP];

struct Edge{
  int u, v;
  double l;
};
bool operator<(const Edge &a, const Edge &b){ return a.l < b.l;}

int p[MAXP];
void reset(){
  for (int i = 0; i < MAXP; i++) p[i] = i;
}
int find(int u){
  int pu = p[u];
  while (pu != p[pu]) pu = p[pu];
  while (u != pu){ int next = p[u]; p[u] = pu; u = next;};
  return pu;
}
void join(int u, int v){
  int pu = find(u), pv = find(v);
  if (pu != pv) p[pu] = pv;
}
int main(){
  cin >> N;
  while (N--){
    reset();
    cin >> S >> P;
    for (int i = 1; i <= P; i++) cin >> x[i] >> y[i];
    vector<Edge> edges;
    for (int i = 1; i <= P; i++){
      for (int j = i + 1; j <= P; j++){
        edges.push_back({i, j, sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2))});
      }
    }
    int edgeNum = 0;
    double ans = 0;
    sort(edges.begin(), edges.end());
    for (size_t i = 0; i < edges.size() && edgeNum < P - 1 - (S - 1); i++) {
      Edge &e = edges[i];
      if (find(e.u) == find(e.v)) continue;
      join(e.u, e.v);
      ans = e.l;
      edgeNum++;
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
  }
}


