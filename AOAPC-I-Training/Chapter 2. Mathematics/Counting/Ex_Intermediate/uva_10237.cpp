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
i64 F_cache[32][32 * 32];
i64 F(int L, int K){
  if (K == 0) return 1;
  if (K < 0) return 0;
  if (L <= 0) return K == 0;
  i64 &total = F_cache[L][K];
  if (total != -1ll) return total;
  total = 0;
  total += F(L - 2, K);
  total += F(L - 2, K - 1) * 2 * (L - (K - 1));
  if (K - 2 >= 0){
    total += F(L - 2, K - 2) * (L - (K - 2)) * (L - (K - 2) - 1);
  }
  return total;
}
i64 T1(int L, int K){
  return F(L - 2, K) + F(L - 2, K - 1) * (L - (K - 1));
}
i64 T2(int L, int K){
  return F(L, K);
}
i64 solve(int N, int K){
  i64 total = 0;
  if (N % 2 == 0){
    for (int i = 0; i <= K; i++) {
      total += T1(N, i) * T2(N - 1, K - i);
      //cout << T1(N, i) << ", " << T2(N - 1, K - i) << endl;
      //cout << total << endl;
    }
  }else{
    for (int i = 0; i <= K; i++) {
      total += T1(N, i) * T2(N - 1, K - i);
    }
  }
  return total;
}
int TestNum;
int main(){
  memset(F_cache, -1, sizeof(F_cache));
  int n, k;
  while (cin >> n >> k && n) {
    cout << solve(n, k) << endl;
  }

}

