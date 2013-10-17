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
const int MAXN = 128 * 1024;
vector<int> G[MAXN], rG[MAXN];
int sccno[MAXN];
int scc_cnt;
vector<int> S;
void dfs(int u){
  if (sccno[u]) return;
  sccno[u] = 1;
  for (size_t i = 0; i < G[u].size(); i++){
    int v = G[u][i];
    dfs(v);
  }
  S.push_back(u);
}
void rdfs(int u, int scc_id){
  if (sccno[u]) return;
  sccno[u] = scc_id;
  for (size_t i = 0; i < rG[u].size(); i++){
    int v = rG[u][i];
    rdfs(v, scc_id);
  }
}
int find_scc(int n){
  memset(sccno, 0, sizeof(sccno));
  S.clear();
  for (int i = 0; i < n; i++) if (!sccno[i]) dfs(i);

  memset(sccno, 0, sizeof(sccno));
  scc_cnt = 0;
  for (int i = n - 1; i >= 0; i--){
    int u = S[i];
    if (!sccno[u]) rdfs(u, ++scc_cnt);
  }
  return scc_cnt;
}
int inDeg[MAXN];
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  cin >> TestNum;
  while (TestNum--){
    for (int i = 0; i < MAXN; i++) G[i].clear(), rG[i].clear();
    int n, m; cin >> n >> m;
    while (m--){
      int u, v; cin >> u >> v;
      u--, v--;
      G[u].push_back(v);
      rG[v].push_back(u);
    }
    find_scc(n);
    memset(inDeg, 0, sizeof(inDeg));
    //for (int u = 0; u < n; u++) printf("%3d", sccno[u]); printf("\n");
    for (int u = 0; u < n; u++){
      int su = sccno[u];
      for (size_t i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        int sv = sccno[v];
        if (su != sv) inDeg[sv]++;
      }
    }
    int ans = count(inDeg + 1, inDeg + scc_cnt + 1, 0);
    cout << ans << endl;
  }
}

