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
const int maxn = 64 * 1024; 
int pre[maxn], iscut[maxn], bccno[maxn], dfs_clock, bcc_cnt;
vector<int> G[maxn], bcc[maxn];

struct Edge{
  int u, v;
};

stack<Edge> S;

int dfs(int u, int fa){
  int lowu = pre[u] = ++dfs_clock;
  int child = 0;
  for (size_t i = 0; i < G[u].size(); i++){
    int v = G[u][i];
    if (!pre[v]){
      S.push({u, v});
      child++;
      int lowv = dfs(v, u);
      lowu = min(lowu, lowv);
      if (lowv >= pre[u]){
        iscut[u] = true;
        bcc[++bcc_cnt].clear();
        while (true){
          Edge x = S.top(); S.pop();
          if (bccno[x.u] != bcc_cnt){
            bcc[bcc_cnt].push_back(x.u);
            bccno[x.u] = bcc_cnt;
          }
          if (bccno[x.v] != bcc_cnt){
            bcc[bcc_cnt].push_back(x.v);
            bccno[x.v] = bcc_cnt;
          }
          if (x.u == u && x.v == v) break;
        }
      }
    }else if (pre[v] < pre[u] && v != fa){
      S.push({u, v});
      lowu = min(lowu, pre[v]);
    }
  }
  if (fa < 0 && child == 1) iscut[u] = 0;
  return lowu;
}

void find_bcc(int n){
  memset(pre, 0, sizeof(pre));
  memset(iscut, 0, sizeof(iscut));
  memset(bccno, 0, sizeof(bccno));
  dfs_clock = bcc_cnt = 0;
  for (int i = 0; i < n; i++){
    if (!pre[i]) dfs(i, -1);
  }
}


int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int m;
  while (scanf("%d", &m) && m){
    for (int i = 0; i < maxn; i++) G[i].clear();
    int n = 0;
    while (m--){
      int u, v; scanf("%d%d", &u, &v);
      n = max(n, max(u, v));
      u--, v--;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    find_bcc(n);
    i64 ans1 = 0, ans2 = 1;
    for (int i = 1; i <= bcc_cnt; i++){
      int cut_cnt = 0;
      for (size_t j = 0; j < bcc[i].size(); j++){
        if (iscut[bcc[i][j]]) cut_cnt++;
      }
      if (cut_cnt == 1){
        ans1++;
        ans2 *= (i64)(bcc[i].size() - cut_cnt);
      }
    }
    if (bcc_cnt == 1){
      ans1 = 2;
      ans2 = bcc[1].size() * (bcc[1].size() - 1) / 2;
    }
    printf("Case %d: %lld %lld\n", ++TestNum, ans1, ans2);
  }
}

