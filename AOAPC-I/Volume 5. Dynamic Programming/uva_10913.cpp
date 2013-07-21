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
const int MAXN = 128;
const int MAXK = 8;
const int INF = (int)0x9f9f9f9fu;
int N;
int k;
int a[MAXN][MAXN];
int sa[MAXN][MAXN];
int isNegative[MAXN][MAXN];
int sIsNeg[MAXN][MAXN];
int dp[MAXN][MAXN][MAXK];
int TestNum;
int getNegCnt(int line, int from, int to){
  if (from > to) swap(from, to);
  return sIsNeg[line][to] - sIsNeg[line][from - 1];
}
int sum(int line, int from, int to){
  if (from > to) swap(from, to);
  return sa[line][to] - sa[line][from - 1];
}
int main(){
  while (cin >> N >> k && N){
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> a[i][j];
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) isNegative[i][j] = a[i][j] < 0;
    for (int i = 1; i <= N; i++) partial_sum(a[i] + 1, a[i] + N + 1, sa[i] + 1);
    for (int i = 1; i <= N; i++) partial_sum(isNegative[i] + 1, isNegative[i] + N + 1, sIsNeg[i] + 1);
    //for (int i = 1; i <= N; i++, printf("\n")) for (int j = 1; j <= N; j++) printf("%10d", sIsNeg[i][j]); 

    memset(dp, 0x9f, sizeof(dp));
    dp[0][1][0] = 0;
    for (int k1 = 0; k1 <= k; k1++){
      //printf("======%d\n", k1);
      //for (int i = 1; i <= N; i++)printf("%13d", dp[0][i][k1]);printf("\n");
      for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
          int &target = dp[i][j][k1];
          for (int l = 1; l <= N; l++){
            int lastK = k1 - getNegCnt(i, j, l);
            //printf("(%d)", lastK);
            if (lastK >= 0){
              if (dp[i - 1][l][lastK] != INF){
                target = max(target, dp[i - 1][l][lastK] + sum(i, j, l));
              }
            }
          }
          //printf("%13d", target);
        }
        //printf("\n");
      }
    }
    int best = INF;
    for (int k1 = 0; k1 <= k; k1++) best = max(best, dp[N][N][k1]);
    if (best == INF){
      printf("Case %d: impossible\n", ++TestNum);
    }else{
      printf("Case %d: %d\n", ++TestNum, best);
    }
  }
}
        


