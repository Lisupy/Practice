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
const int MAXN = 128;
int q[MAXN][MAXN];
int d[MAXN][MAXN];
int N;
int n, m;
void input(){
  memset(d, 0x1f, sizeof(d));
  for (int i = 0; i < MAXN; i++) d[i][i] = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++){
    int u, v; scanf("%d%d", &u, &v);
    d[u][v] = d[v][u] = 1;
  }
  memcpy(q, d, sizeof(d));
}

int solve(){
  for (int i = 0; i < n; i++){
    for (int s = 0; s < n; s++){
      for (int t = 0; t < n; t++){
        d[s][t] = min(d[s][t], d[s][i] + d[i][t]);
      }
    }
  }
  int Max = m == 0? 0 : 1; 
  for (int u = 0; u < n; u++){
    for (int v = u + 1; v < n; v++){
      if (d[u][v] == 0x1f1f1f1f) continue;
      int cnt = 0;
      for (int u1 = 0; u1 < n; u1++){
        if (d[u][u1] >= d[u][v]) continue;
        for (int v1 = 0; v1 < n; v1++){
          if (u1 == v1) continue;
          if (d[u][u1] + d[v1][v] + q[u1][v1] == d[u][v]){
            //printf("%d %d %d %d\n", u, v, u1, v1);
            cnt++;
          }
        }
      }
      Max = max(Max, cnt);
    }
  }
  return Max;
}

int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  scanf("%d", &N);
  while (N--){
    input();
    printf("Case #%d: %d\n", ++TestNum, solve());
  }
}

