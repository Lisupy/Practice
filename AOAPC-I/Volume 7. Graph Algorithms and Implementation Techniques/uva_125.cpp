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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 */
const int MAXN = 128;
long long M[MAXN][MAXN];
long long d[MAXN][MAXN];
int TestNum;
int n;
const long long INF = 0x1f1f1f1f;
void solve1(){
  for (int i = 0; i <= n; i++){
    for (int s = 0; s <= n; s++){
      for (int t = 0; t <= n; t++){
        d[s][t] += d[s][i] * d[i][t];
      }
    }
  }
  memcpy(M, d, sizeof(M));
  for (int i = 0; i <= n; i++){
    if (d[i][i] > 0){ 
      for (int j = 0; j <= n; j++){
        if(d[i][j]) d[i][j] = INF;
        if(d[j][i]) d[j][i] = INF;
      }
    }
  }
  for (int i = 0; i <= n; i++){
    for (int s = 0; s <= n; s++){
      for (int t = 0; t <= n; t++){
        d[s][t] += d[s][i] * d[i][t];
        if (d[s][t] >= INF){
          d[s][t] = INF;
        }
      }
    }
  }

  for (int i = 0; i <= n; i++){
    for (int j = 0; j <= n; j++){
      if (j != 0) printf(" ");
      if (d[i][j] >= INF) printf("-1");
      else printf("%lld", M[i][j]);
    }
    printf("\n");
  }
}
void solve(){
  for (int i = 0; i <= n; i++){
    for (int s = 0; s <= n; s++){
      for (int t = 0; t <= n; t++){
        d[s][t] += d[s][i] * d[i][t];
      }
    }
  }
  memcpy(M, d, sizeof(M));
  for (int i = 0; i <= n; i++){
    if (d[i][i] > 0) d[i][i] = INF;
  }
  for (int i = 0; i <= n; i++){
    for (int s = 0; s <= n; s++){
      for (int t = 0; t <= n; t++){
        if (d[i][i] == INF && d[s][i] && d[i][t]){
          d[s][t] = INF;
        }
      }
    }
  }

  for (int i = 0; i <= n; i++){
    for (int j = 0; j <= n; j++){
      if (j != 0) printf(" ");
      if (d[i][j] >= INF) printf("-1");
      else printf("%lld", M[i][j]);
    }
    printf("\n");
  }
}
int main(){
  int m;
  while (cin >> m){
    memset(d, 0, sizeof(d));
    n = 0;
    while (m--){
      int u, v; cin >> u >> v;
      d[u][v]++;
      n = max(n, max(u, v));
    }

    printf("matrix for city %d\n", TestNum++);
    solve();
  }
}
