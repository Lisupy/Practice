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
const int MAXN = 1024;
int V;
int color[MAXN];
vector<int> edges[MAXN];

bool dfs(int u, int c){
  if (color[u] != 0) return color[u] == c;
  color[u] = c;
  for (size_t i = 0; i < edges[u].size(); i++){
    int v = edges[u][i];
    if (!dfs(v, 3 - c)) return false;
  }
  return true;
}

bool isBipartite(){
  for (int i = 1; i <= V; i++){
    if (!color[i]){
      if(!dfs(i, 1)) return false;
    }
  }
  return true;
}


int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (cin >> V && V){
    for (int i = 0; i <= V; i++) edges[i].clear();
    memset(color, 0, sizeof(color));
    int u, v;
    int cnt = 0;
    while (cin >> u >> v && u){
      cnt++;
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    if (isBipartite()) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}

