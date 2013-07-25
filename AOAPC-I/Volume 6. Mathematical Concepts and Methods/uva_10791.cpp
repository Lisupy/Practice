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
int TestNum;
const int MAXN = 1024 * 64;
vector<int> primes;
void primes_init(){
  vector<bool> isPrime(MAXN, true);
  for (int n = 2; n < MAXN; n++){
    if (isPrime[n]) primes.push_back(n);
    for (size_t i = 0; i < primes.size(); i++) {
      int p = primes[i];
      int s = n * p;
      if (s >= MAXN) break;
      isPrime[s] = false;
      if (n % p == 0) break;
    }
  }
}

int main(){
  primes_init();
  int N;
  while (cin >> N && N){
    long long total = 0;
    if (N == 1) total = 1;
    int cnt = 0;
    for (size_t i = 0; i < primes.size() && N != 1; i++){
      int p = primes[i];
      int s = 1;
      while (N != 1 && N % p == 0) N /= p, s *= p;
      if (s != 1) total += s, cnt++;
    }  
    if (N != 1) total += N, cnt++;
    if (cnt <= 1) total++;
    printf("Case %d: %lld\n", ++TestNum, total);
  }
}
