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

vector<int> G[MAXN];
vector<vector<int> > bcc;
int pre[MAXN];
int iscut[MAXN];
int bccno[MAXN];
int dfs_clock;
int bcc_cnt;
struct Edge{
  int u, v;
};
stack<Edge> S;
int dfs(int u, int fa){
  int lowu = pre[u] = ++dfs_clock;
  int childNum = 0;
  for (size_t i = 0; i < G[u].size(); i++){
    int v = G[u][i];
    if (!pre[v]){
      //Edge e = {u, v};
      S.push({u, v});
      childNum++;
      int lowv = dfs(v, u);
      lowu = min(lowu, lowv);
      if (lowv >= pre[u]){
        iscut[u] = true;
        bcc.push_back(vector<int>());
        int bccID = bcc.size() - 1;
        while (true){
          Edge x = S.top(); S.pop();
          if (bccno[x.u] != bccID) {
            bcc[bccID].push_back(x.u);
            bccno[x.u] = bccID;
          }
          if (bccno[x.v] != bccID){
            bcc[bccID].push_back(x.v);
            bccno[x.v] = bccID;
          }
          if (x.u == u && x.v == v) break;
        }
      }
    }else if (pre[v] < pre[u] && v != fa){
      //Edge e = {u, v};
      S.push({u, v});
      lowu = min(lowu, pre[v]);
    }
  }
  if (fa < 0 && childNum == 1) iscut[u] = 0;
  return lowu;
}

void find_bcc(int n){
  memset(pre, 0, sizeof(pre));
  memset(iscut, 0, sizeof(iscut));
  memset(bccno, -1, sizeof(bccno));
  dfs_clock = 0;
  for (int i = 0; i < n; i++){
    if (!pre[i]) dfs(i, -1);
  }
}
int odd[MAXN], color[MAXN];
bool bipartite(int u, int b){
  for (size_t i = 0; i < G[u].size(); i++){
    int v = G[u][i]; 
    if (bccno[v] != b) continue;
    if (color[v] == color[u]) return false;
    if (!color[v]){
      color[v] = 3 - color[u];
      if (!bipartite(v, b)) return false;
    }
  }
  return true;
}
int A[MAXN][MAXN];
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int n, m;
  while (scanf("%d%d", &n, &m) && n){
    for (int i = 0; i < n; i++) G[i].clear();

    memset(A, 0, sizeof(A));
    for (int i = 0; i < m; i++){
      int u, v; scanf("%d%d", &u, &v);
      u--, v--;
      A[u][v] = A[v][u] = 1;
    }
    for (int u = 0; u < n; u++){
      for (int v = u + 1; v < n; v++){
        if (!A[u][v]){
          G[u].push_back(v);
          G[v].push_back(u);
        }
      }
    }

    find_bcc(n);

    memset(odd, 0, sizeof(odd));
    for (size_t i = 0; i < bcc.size(); i++){
      memset(color, 0, sizeof(color));
      for (size_t j = 0; j < bcc[i].size(); j++) bccno[bcc[i][j]] = i;

      int u = bcc[i][0];
      color[u] = 1;
      if (!bipartite(u, i)){
        for (size_t j = 0; j < bcc[i].size(); j++) odd[bcc[i][j]] = 1;
      }
    }

    int ans = n - count(odd, odd + n, 1);
    printf("%d\n", ans);
  }
}

