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

int n, m;

struct Edge{
  int u, v;
};
vector<Edge> edges;
vector<Edge> ans;
int mat[MAXN][MAXN];
bool isBrige[MAXN][MAXN];
int pre[MAXN]; 
int dfs_clock;
int dfs(int u, int fa){
  pre[u] = ++dfs_clock;
  int lowu = pre[u];
  //printf("pre[%d]:%d\n", u, pre[u]);
  for (int v = 1; v <= n; v++) if (mat[u][v]){
    if (v == fa) continue;
    if (!pre[v]){
      int lowv = dfs(v, u);
      //printf("%d, low[%d]:%d\n", u, v, lowv);
      if (lowv > pre[u]){
        isBrige[u][v] = true;
        isBrige[v][u] = true;
        ans.push_back({u, v}), ans.push_back({v, u});
        //printf("bridge(%d, %d)\n", u, v);
      }
      lowu = min(lowu, lowv);
    }else{
      lowu = min(lowu, pre[v]);
    }
    //printf("%d, update %d %d\n", u, v, lowu); 
  }
  //printf("%d, return %d\n", u, lowu); 
  return lowu;
}

void find_bridge(){
  memset(pre, 0, sizeof(pre));
  memset(isBrige, 0, sizeof(isBrige));
  dfs_clock = 0;
  for (int i = 1; i <= n; i++){
    if (!pre[i]){
      dfs(i, -1);
    }
  }
}
int visited[MAXN];
int dfs2(int u, int fa){
  visited[u] = true; 
  for (int v = 1; v <= n; v++) if (mat[u][v] && !isBrige[u][v]){
    if (fa == v) continue;
    ans.push_back({u, v});
    //printf("%d %d, %d\n", u, v, fa);
    isBrige[u][v] = isBrige[v][u] = true;
    if (!visited[v]){
      dfs2(v, u);
    }
  }
  return 0;
}
  
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (scanf("%d%d", &n, &m) && n){
    memset(mat, 0, sizeof(mat));
    edges.clear();
    ans.clear();
    while (m--){
      int u, v; scanf("%d%d", &u, &v);
      mat[u][v]++, mat[v][u]++;
    }
    find_bridge();
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        //printf("===%d\n", i);
        dfs2(i, -1);
      }
    }
    printf("%d\n", ++TestNum);
    printf("\n");
    for (size_t i = 0; i < ans.size() ;i++){
      printf("%d %d\n", ans[i].u, ans[i].v);
    }
    printf("#\n");
  }
}

