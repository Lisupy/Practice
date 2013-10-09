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
const int maxn = 1024;
vector<int> G[maxn], rG[maxn];
vector<int> S;
bool visited[maxn];
int sccno[maxn], scc_cnt;
int sccsz[maxn];
void dfs(int u){
  if (visited[u]) return;
  visited[u] = 1;
  for (size_t i = 0; i < G[u].size(); i++) dfs(G[u][i]);
  S.push_back(u);
}

void rdfs(int u){
  if (sccno[u]) return;
  sccno[u] = scc_cnt;
  sccsz[scc_cnt]++;
  for (size_t i = 0; i < rG[u].size(); i++) rdfs(rG[u][i]);
}
void find_scc(int n){
  scc_cnt = 0;
  S.clear();
  memset(sccno, 0, sizeof(sccno));
  memset(sccsz, 0, sizeof(sccsz));
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < n; i++) dfs(i);
  for (int i = n - 1; i >= 0; i--)
    if (!sccno[S[i]]) {
      scc_cnt++;
      rdfs(S[i]);
    }
}
int mat[maxn][maxn];
vector<int> links[maxn];
int dp[maxn];
int inDeg[maxn];
int topologicalDP(){
  queue<int> Q;
  memset(dp, 0, sizeof(dp));
  memset(inDeg, 0, sizeof(inDeg));
  for (int u = 1; u <= scc_cnt; u++){
    for (size_t i = 0; i < links[u].size(); i++){
      int v = links[u][i];
      inDeg[v]++;
    }
  }

  for (int u = 1; u <= scc_cnt; u++){
    if (inDeg[u] == 0) Q.push(u);
  }

  while (Q.size()){
    int u = Q.front(); Q.pop();
    dp[u] += sccsz[u];
    //printf("pop: %d, %d\n", u, dp[u]);
    for (size_t i = 0; i < links[u].size(); i++){
      int v = links[u][i];
      dp[v] = max(dp[v], dp[u]);
      inDeg[v]--;
      if (inDeg[v] == 0) Q.push(v);
    }
  }

  return *max_element(dp + 1, dp + scc_cnt + 1);
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int T; scanf("%d", &T);
  while (T--){
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) G[i].clear(), rG[i].clear();
    while (m--){
      int u, v; scanf("%d%d", &u, &v);
      u--, v--;
      G[u].push_back(v);
      rG[v].push_back(u);
    }

    find_scc(n);
  
    //for (int i = 0; i < n; i++){
      //printf("%3d", sccno[i]);
    //}printf("\n");
    //for (int i = 1; i <= scc_cnt; i++){
      //printf("%3d", sccsz[i]);
    //}printf("\n");

    for (int i = 1; i <= scc_cnt; i++) links[i].clear();
    memset(mat, 0, sizeof(mat));

    for (int u = 0; u < n; u++){
      for (size_t j = 0; j < G[u].size(); j++){
        int v = G[u][j];
        int su = sccno[u], sv = sccno[v];
        if (mat[su][sv]) continue;
        if (su == sv) continue;
        links[su].push_back(sv); 
        mat[su][sv] = 1;
      }
    }
    //for (int u = 1; u <= scc_cnt; u++){
      //printf("\n%d: ", u);
      //for (size_t j = 0; j < links[u].size(); j++){
        //printf("%3d", links[u][j]);
      //}
    //}
    int ans = topologicalDP();
    printf("%d\n", ans);
  }
}

