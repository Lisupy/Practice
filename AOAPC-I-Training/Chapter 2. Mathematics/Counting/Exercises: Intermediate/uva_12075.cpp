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
typedef long long i64;
typedef unsigned long long u64;

const int MAXN = 1024;

int gcd_cache[MAXN][MAXN];
int gcd(int a, int b){
  int &res = gcd_cache[a][b];
  if (res != 0) return res;
  res = b == 0 ? a : gcd(b, a % b);
  return res;
}
i64 C(i64 n, i64 k){
  if (n < k) return 0;
  i64 total = 1;
  for (int i = 1; i <= k; i++) {
    total *= n - i + 1;
    total /= i;
  }
  return total;
}

i64 f_cache[MAXN][MAXN];
i64 F(i64 n, i64 m){
  if (n == 0 || m == 0) return 0;
  i64 &res = f_cache[n][m];
  if (res != 0) return res;
  res = C((n + 1) * (m + 1), 3);
  for (int a = 0; a <= n; a++){
    for (int b = 0; b <= m; b++){
      if (a == 0 && b == 0) continue;
      int g = gcd(a, b);
      i64 cost = (g - 1) * (n - a + 1) * (m - b + 1);
      if (a == 0 || b == 0) res -= cost;
      else res -= cost * 2;
    }
  }
  return res;
}

int TestNum;
int main(){
  i64 n, m;
  while (cin >> n >> m && n) {
    //cout << C((n + 1) * (m + 1), 3 ) << endl;
    i64 ans = F(n, m);
    printf("Case %d: %lld\n", ++TestNum, ans);
  }
}

