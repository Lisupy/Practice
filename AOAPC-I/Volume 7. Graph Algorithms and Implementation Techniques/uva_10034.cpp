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
int p[MAXN];
int n;
double x[MAXN];
double y[MAXN];
struct Edge{
  int u, v;
  double w;
};

bool operator<(const Edge &a, const Edge& b){
  return a.w < b.w;
}
void reset(){
  for (int i = 0; i < MAXN; i++) p[i] = i;
}

int find(int u){
  return p[u] == u ? u : p[u] = find(p[u]);
}

void join(int u, int v){
  int pu = find(u), pv = find(v);
  if (pu != pv) p[pu] = pv;
}

int main(){
  int TestNum; cin >> TestNum;
  while (TestNum--){
    reset();
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    vector<Edge> edges;
    for (int i = 1; i <= n; i++){
      for (int j = i + 1; j <= n; j++){
        edges.push_back({i, j, sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2))});
      }
    }
    sort(edges.begin(), edges.end());
    double ans = 0;
    int edge_num = 0;
    for (size_t i = 0; i < edges.size() && edge_num < n; i++){
      Edge &e = edges[i];
      if (find(e.u) == find(e.v)) continue;
      ans += e.w;
      join(e.u, e.v);
      edge_num++;
    }
    //printf("%.02lf\n", ans);
    cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
    if (TestNum) cout << endl;
  }
}


