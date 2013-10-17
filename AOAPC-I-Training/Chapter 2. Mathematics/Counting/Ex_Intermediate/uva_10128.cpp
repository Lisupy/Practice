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

i64 C_cache[16][16];
i64 C(int n, int k){
  if (n < k) return 0;
  if (k < 0) return 0;
  if (k == 0) return 1;
  i64 &total = C_cache[n][k];
  if (total != 0) return total;
  total = C(n - 1, k) + C(n - 1, k - 1);
  return total;
}
i64 Fact_cache[16];
i64 Fact(int n){
  if (n == 0) return 1;
  if (Fact_cache[n] != 0) return Fact_cache[n];
  return Fact_cache[n] = Fact(n - 1) * n;
}
i64 F_cache[16][16];
i64 F(int n, int k){
  if (n < k) return 0;
  if (n == 0) return k == 0;
  if (k == 0) return 0;
  i64 &total = F_cache[n][k];
  if (total != 0) return total;
  for (int i = 1; i <= n; i++) {
    total += C(n - 1, i - 1) * Fact(n - i) * F(i - 1, k - 1); 
  }
  return total;
}
i64 solve(int N, int B, int E){
  i64 total = 0;
  for (int i = 1; i <= N; i++) {
    total += C(N - 1, i - 1) * F(i - 1, B - 1) * F(N - i, E - 1); 
  }
  return total;
}
int TestNum;
int main(){
  cin >> TestNum;
  while (TestNum--) {
    int N, B, E; cin >> N >> B >> E;
    cout << solve(N, B, E) << endl;
  }

}

