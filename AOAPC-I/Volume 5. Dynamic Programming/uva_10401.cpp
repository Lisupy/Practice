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
const int MAXN = 32;
long long dp[MAXN][MAXN];
string status;
int intFromxdigit(char ch){
  if (isdigit(ch)){
    return ch - '0';
  }else{
    return ch - 'A' + 10;
  }
}
int main(){
  while (cin >> status){
    int len = status.size();
    memset(dp, 0, sizeof(dp));
    if (status[0] == '?'){
      for (int i = 0; i < len; i++){
        dp[0][i] = 1;
      }
    }else{
      int n = intFromxdigit(status[0]) - 1;
      dp[0][n] = 1;
    }
    for (int i = 1; i < len; i++){
      char ch = status[i];
      int  n = intFromxdigit(ch) - 1;
      for (int j = 0; j < len; j++){
        if (ch == '?' || n == j){
          dp[i][j] += j - 1 >= 0 ? accumulate(dp[i - 1], dp[i - 1] + j - 1, 0ll) : 0 ;
          dp[i][j] += j + 2 < len? accumulate(dp[i - 1] + j + 2, dp[i - 1] + len, 0ll) : 0;
        }
        //printf("%6lld", dp[i][j]);
      }
      //printf("\n");
    }
    printf("%lld\n", accumulate(dp[len - 1], dp[len - 1] + len, 0llu));
  }
}

