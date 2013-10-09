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
const int maxn = 20 * 1024;
int in0[maxn], out0[maxn];

vector<int> G[maxn], rG[maxn];
vector<int> S;
int vis[maxn], sccno[maxn], scc_cnt;


void dfs(int u){
  if (vis[u]) return;
  vis[u] = 1;
  for (size_t i = 0; i < G[u].size(); i++) dfs(G[u][i]);
  S.push_back(u);
}
void rdfs(int u){
  if (sccno[u]) return;
  sccno[u] = scc_cnt;
  for (size_t i = 0; i < rG[u].size(); i++) rdfs(rG[u][i]);
}

void find_scc(int n){
  scc_cnt = 0;
  S.clear();
  memset(sccno, 0, sizeof(sccno));
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++) dfs(i);
  for (int i = n - 1; i >= 0; i--){
    if (!sccno[S[i]]){
      scc_cnt++;
      rdfs(S[i]);
    }
  }
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int T, n, m;
  scanf("%d", &T);
  while (T--){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)G[i].clear(), rG[i].clear();

    for (int i = 0; i < m; i++) {
      int u, v; scanf("%d%d", &u, &v);
      u--, v--;
      G[u].push_back(v);
      rG[v].push_back(u);
    }

    find_scc(n);

    for (int i = 1; i<= scc_cnt; i++) in0[i] = out0[i] = 1;
    for (int u = 0; u < n; u++){
      for (size_t i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if (sccno[u] != sccno[v]) in0[sccno[v]] = out0[sccno[u]] = 0;
      }
    }
    int a = 0, b = 0;
    for (int i = 1; i <= scc_cnt; i++){
      if(in0[i]) a++;
      if(out0[i]) b++;
    }
    int ans = max(a, b);
    if (scc_cnt == 1) ans = 0;
    printf("%d\n", ans);
  }
}

