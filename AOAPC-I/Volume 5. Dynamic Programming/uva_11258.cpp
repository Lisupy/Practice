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


const int MAXN = 1024;
int N;

char buf[MAXN];
int len;
long long dp[MAXN];
long long LLFromIndex(int from, int to){
  long long n;
  char c = '\0';
  swap(c, buf[to + 1]);
  //printf("(%d %d) => [%s]\n", from, to, buf + from);
  sscanf(buf + from, "%lld", &n);
  swap(c, buf[to + 1]);
  return n;
}


int main(){
  scanf("%d", &N);
  fgets(buf + 1, MAXN, stdin);
  while (N--){
    fgets(buf + 1, MAXN, stdin);
    len = strlen(buf + 1);
    (buf + 1)[--len] = '\0'; 
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= len; i++){
      for (int j = i - 1; j >= 0; j--){
        long long n = LLFromIndex(j + 1, i);
        if (n >= (1ll << 31)) break;
        dp[i] = max(dp[i], dp[j] + n);
      }
    }
    printf("%lld\n", dp[len]);
  }
}
