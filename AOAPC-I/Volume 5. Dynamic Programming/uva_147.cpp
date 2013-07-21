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

const int MAXN = 301 * 100;
unsigned long long ways[MAXN];
int coins[] = {100*100, 50 * 100, 20 * 100, 10 * 100, 5 * 100, 2 * 100, 1 * 100, 50, 20, 10, 5};
void ways_init(){
  ways[0] = 1;
  reverse(coins, coins + sizeof(coins) / sizeof(coins[0]));
  for (size_t i = 0; i < sizeof(coins) / sizeof(coins[0]); i++){
    for (int j = 1; j < MAXN; j++){
      int last = j - coins[i];
      if (last >= 0){
        ways[j] += ways[last];
      }
    }
  }
}


int main(){
  ways_init();
  double a;
  while (cin >> a && a != 0){
    printf("%6.02lf%17llu\n", a, ways[int(round(a * 100))]);
    //printf("%6.02lf%17llu\n", a, ways[int(a * 100 + 0.5)]);
  }
}
