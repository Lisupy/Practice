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
const int INF = 0x1f1f1f1f;
int N, M;
int P[32];
int dp[128][32][1024];
int main(){
  while (cin >> N >> M && N){
    for (int i = 1; i <= M; i++) cin >> P[i];
    memset(dp, 0x1f, sizeof(dp));
    for (int j = 0; j <= M; j++)
      for (int k = 0; k < 1024; k++) 
        dp[0][j][k] = 0;

    for (int i = 1; i <= N; i++){
      //printf("%d:\n", i);
      for (int j = 1; j <= M; j++){
        //printf("%d=> ", P[j]);
        for (int k = 1000; k >= 0; k--){
          int &target = dp[i][j][k];
          target = k == 0 ? 0 : dp[i][j - 1][k];
          target = min(target, dp[i][j][k + 1]);
          for (int i1 = i - 1; i1 >= 0; i1--){
            if (P[j] >=  k  * (i - i1)){
              if (dp[i1][j - 1][k] != INF){ 
                target = min(target, dp[i1][j - 1][k] + P[j]); 
              }else{
               // break; // WA
              }
            }else break; 
          }
          //printf("%12d", target);
        }
        //printf("\n");
      }
    }
    for (int k = 1000; k >= 0; k--){
      if (dp[N][M][k] != INF){
        cout << k << " " << dp[N][M][k] << endl;
        break;
      }
    }
  }
}


