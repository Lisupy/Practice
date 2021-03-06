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



unsigned long long pow_mod(unsigned long long p, unsigned long long n, unsigned long long mod){
  unsigned long long s = 1;
  while (n){
    if (n % 2) s = (s * p) % mod;
    p = (p * p) % mod;
    n = n / 2;
  }
  return s;
}

//p^n
unsigned long long pow_first(unsigned long long p, unsigned long long n){
  double s1 = n * log10(p);
  s1 -= (int)s1;
  //cout << s1 << endl;
  //cout << fmod(n * log10(p), 1) << endl;
  return pow(10, s1 + 2);
}

int main(){
  int T; cin >> T;
  while (T--){
    unsigned long long n, k; cin >> n >> k;
    printf("%03llu...%03llu\n", pow_first(n, k), pow_mod(n, k, 1000));
  }
}

