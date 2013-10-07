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
const int maxn = 10 * 1024;
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
    Edge e = {u, v};
    if (!pre[v]){
      S.push(e);
      child++;
      int lowv = dfs(v, u);
      lowu = min(lowu, lowv);
      if (lowv >= pre[u]){
        iscut[u] = true;
        bcc_cnt++;
        bcc[bcc_cnt].clear();
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
      S.push(e);
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
struct Record{
  int val;
  int id;
};
bool operator<(const Record &a, const Record &b){
  if (a.val != b.val) return a.val > b.val;
  return a.id < b.id;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int n, m;
  while (scanf("%d%d", &n, &m) && n){
    for (int i = 0; i < n; i++) G[i].clear();
    {
      int u, v;
      while (scanf("%d%d", &u, &v) && u != -1){
        G[u].push_back(v);
        G[v].push_back(u);
      }
    }
    find_bcc(n);
    vector<Record> res;
    for (int u = 0; u < n; u++){
      if (iscut[u]){
        set<int> s;
        for (size_t i = 0; i < G[u].size(); i++){
          int v = G[u][i];
          s.insert(bccno[v]);
        }
        res.push_back({(int)s.size(), u});
      }else{
        res.push_back({1, u});
      }
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < m; i++){
      printf("%d %d\n", res[i].id, res[i].val);
    }
    printf("\n");
  }
}

