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

int T;
int K;
int N;
int chopsticks[1024*6]; 
int dp[1024 * 6];
int dp1[1024 * 6];
int main(){
  scanf("%d", &T);
  while (T--){
    scanf("%d %d\n", &K, &N);
    K += 8;
    for (int i = 1; i <= N; i++){
      scanf("%d", &chopsticks[i]);
    }
    reverse(chopsticks + 1, chopsticks + N + 1);

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= K; i++){
      //printf("===%3d\n", i);
      memset(dp1, 0x7f, sizeof(dp1));
      for (int j = i * 3; j <= N; j++){
        int cost = chopsticks[j] - chopsticks[j - 1];
        cost *= cost;
        dp1[j] = min(dp1[j - 1], dp[j - 2] + cost);
        //printf("%d,", cost);
        //printf("%4d", dp[j - 1]);
      }
      memcpy(dp, dp1, sizeof(dp));
      //printf("\n");
    }
    printf("%d\n", dp[N]);
  }
}


