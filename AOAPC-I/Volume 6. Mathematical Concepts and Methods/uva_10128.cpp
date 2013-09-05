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
 * (1 << (31 - __builtin_clz(100) ) == 64;
 */

i64 c_cache[16][16];
i64 C(int n, int k){
  if (n == 0) return k == 0;
  if (k == 0) return 1;
  i64 &res = c_cache[n][k];
  if (res != -1) return res;
  res = C(n - 1, k) + C(n - 1, k - 1);
  return res;
}
i64 a_cache[16];
i64 A(int n){
  if (n == 0) return 1;
  i64 &res = a_cache[n];
  if (res != -1) return res;
  return res = n * A(n - 1);
}
i64 f_cache[16][16];
i64 F(int m, int h){
  if (h == 0) return m == 0;
  if (m == 0) return h == 0;
  i64 &res = f_cache[m][h];
  if (res != -1) return res;
  res = 0;
  for (int i = 1; i <= m; i++){
    res += F(i - 1, h - 1) * C(m - 1, i - 1) * A(m - i);
  }
  return res;
}
int TestNum;
int main(){
  memset(c_cache, -1, sizeof(c_cache));
  memset(f_cache, -1, sizeof(f_cache));
  memset(a_cache, -1, sizeof(a_cache));
  int T; cin >> T;
  while (T--){
    int N, P, R; cin >> N >> P >> R;
    i64 total = 0;
    for (int i = 1; i <= N; i++){
      total += F(i - 1, R - 1) * F(N - i, P - 1) * C(N - 1, i - 1);
    }
    cout << total << endl;
  }
}

