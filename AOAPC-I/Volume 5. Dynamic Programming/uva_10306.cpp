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
 * sizeof
 */

const int MAXN = 512;
int n;
int m;
int S;
int dp[MAXN][MAXN];

int cv[64];
int iv[64];
const int INF = 0x7f7f7f7f;
int main(){
  scanf("%d", &n);
  while (n--){
    scanf("%d%d", &m, &S);
    for (int i = 0; i < m; i++){
      scanf("%d%d", &cv[i], &iv[i]);
    }
    memset(dp, 0x7f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < m; i++){
      for (int j = 0; j <= S; j++){
        for (int k = 0; k <= S; k++){
          int j1 = j - cv[i], k1 = k - iv[i];
          if (j1 >= 0 && k1 >= 0){
            if (dp[j1][k1] != INF){
              dp[j][k] = min(dp[j][k], dp[j1][k1] + 1);
            }
          }
        }
      }
    }
    int ans = INF;
    for (int i = 0; i <= S; i++){
      for (int j = 0; j <= S; j++){
        //if (dp[i][j] == INF)printf("-1");
        //else printf("%d ", dp[i][j]);
        if (i * i + j * j == S * S){
          ans = min(ans, dp[i][j]);
        }
      }
      //printf("\n");
    }
    if (ans == INF){
      printf("not possible\n");
    }else{
      printf("%d\n", ans);
    }
  }
}



