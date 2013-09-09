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
const int MAXN = 1024*1024;
vector<int> primes;
vector<bool> isPrime(MAXN, true);

void primes_init(){
  for (int n = 2; n < MAXN; n++) {
    if (isPrime[n]) primes.push_back(n);
    for (size_t i = 0; i < primes.size(); i++) {
      int p = primes[i];
      int m = n * p;
      if (m >= MAXN) break;
      isPrime[m] = false;
      if (n % p == 0) break;
    }
  }
}
long double fibs[MAXN];
void fibs_init(){
  fibs[1] = 1;
  fibs[2] = 1;
  for (int i = 3; i < MAXN; i++){ 
    fibs[i] = fibs[i - 1] + fibs[i - 2]; 
    if (fibs[i] >= 1e18){
      fibs[i] /= 1000;
      fibs[i - 1] /= 1000;
    }
  }
}
string takeFirstNine(long double f){
  char buf[300000];
  sprintf(buf, "%0.Lf", f);
  buf[9] = 0;
  return buf;
}
int TestNum;
int main(){
  primes_init();
  fibs_init();
  int n;
  while (cin >> n) {
    long double f = n <= 2? n + 1 : fibs[primes[n - 1]]; 
    cout << takeFirstNine(f) << endl;
  }
}

