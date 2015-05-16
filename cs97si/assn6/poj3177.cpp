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

typedef long long               ll;
typedef long double             ld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef pair<int, int>          pii;
typedef vector<pii>             vii; // vector of integer pairs
typedef set<int>                si;
typedef map<string, int>        msi;

const double PI = acos(-1);

/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
const int MAXN = 5010;
vector<int> G[MAXN];
int pre[MAXN];
int low[MAXN];
int dfs_clock;
int dfs(int u, int fa) {
  int lowu = pre[u] = ++dfs_clock;
  for (size_t i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    if (!pre[v]) lowu = min(lowu, dfs(v, u));
    else if (pre[v] < pre[u]) lowu = min(lowu, pre[v]);
  }
  low[u] = lowu;
  return lowu;
}
vector<int> G2[MAXN];
int F, R;
int TestNum;
int main() {
  ios_base::sync_with_stdio(false); 
  cin >> F >> R;
  {
    set<pair<int, int> > S;
    while (R--) {
      int u, v; cin >> u >> v;
      if (u < v) swap(u, v);
      if (S.count(make_pair(u, v))) continue;
      S.insert(make_pair(u, v));
      G[u].push_back(v);
      G[v].push_back(u);
    }
  }
  for (int i = 1; i <= F; i++) if (!low[i]) dfs(i, -1);
  {
    map<int, int> M;
    int Count = 0;
    for (int i = 1; i <= F; i++) {
      if (!M.count(low[i])) M[low[i]] = Count++;
    }
    //set<pair<int, int> > S2;
    for (int s = 1; s <= F; s++) {
      for (size_t i = 0; i < G[s].size(); i++) {
        int t = G[s][i];
        int u = M[low[s]], v = M[low[t]];
        if (u == v) continue;
        //if (S2.count(make_pair(u, v))) continue;
        G2[u].push_back(v);
      }
    }
    int tot = 0;
    for (int i = 0; i < Count; i++) {
      if (G2[i].size() == 1) tot++;
    }
    cout << (tot + 1) / 2 << endl;
  }
}

