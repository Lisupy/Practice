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


const int MAXN = 1 << 16;
vector<int> primes;
void primes_init(){
  vector<bool> isPrime(MAXN, true);
  for (int n = 2; n < MAXN; n++) {
    if (isPrime[n]) primes.push_back(n);
    for (size_t i = 0; i < primes.size(); i++) {
      int p = primes[i];
      int s = n * p;
      if (s >= MAXN || s < 0) break;
      isPrime[s] = false;
      if (n % p == 0) break;
    }
  }
}

long long solve(int N){
  if (N == 1) return 2;
  long long total = 0;
  int factorCnt = 0;
  for (size_t i = 0; i < primes.size(); i++) {
    int p = primes[i];
    int s = 1;
    while (N % p == 0) N /= p, s *= p;
    //cout << p << ", " << s << endl;
    if (s != 1) total += s, factorCnt++;
  }
  if (N != 1) total += N, factorCnt++;
  if (factorCnt == 1) total++;
  return total;
}

int TestNum;
int main(){
  primes_init();
  //for (auto i : primes) cout << i << ", "; cout << endl;
  int N;
  while (cin >> N && N) {
    printf("Case %d: %lld\n", ++TestNum, solve(N));
  }
}

