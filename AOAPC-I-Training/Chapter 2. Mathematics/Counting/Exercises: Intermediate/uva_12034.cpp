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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 */
const int MAXN = 1024;
const int MOD = 10056;
int f[MAXN][MAXN];
void f_init(){
  f[0][0] = 1;
  for (int n = 1; n < MAXN; n++){
    for (int k = 1; k < MAXN; k++){
      f[n][k] = (f[n - 1][k] + f[n - 1][k - 1]) * k % MOD;
    }
  }
}
int F(int n, int k){
  if (k < 0 || n < 0 || n < k) return 0;
  if (k == 0) return 0;
  if (k == 1) return 1;
  int &res = f[n][k];  
  if (res != 0) return res;
  res = 0;
  res = (F(n - 1, k) + F(n - 1, k - 1)) * k % MOD;
  //printf("F(%d, %d): %lld\n", n, k, res);
  return res;
}
i64 solve(int n){
  i64 total = 0;
  for (int i = 1; i <= n; i++){
    total += f[n][i];
    //total += F(n, i);
    total %= MOD;
  }
  return total % MOD;
}

int TestNum;
int main(){
  f_init();
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    printf("Case %d: %lld\n", ++TestNum, solve(n));
  }
}

