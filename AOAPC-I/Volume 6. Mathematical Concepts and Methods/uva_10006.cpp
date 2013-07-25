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
const int MAXN = 1024 * 65;
vector<int> primes;
bool isPrime[MAXN];

void prime_init(){
  fill(isPrime, isPrime + MAXN, true);
  for (int n = 2; n < MAXN; n++){
    if (isPrime[n]) primes.push_back(n);
    for (size_t i = 0; i < primes.size(); i++){
      int p = primes[i];
      int s = n * p;
      if (s >= MAXN) break;
      isPrime[s] = false;
      if (n % p == 0) break;
    }
  }
}

int pow_mod(int p, int n, int mod){
  long long acc = p;
  long long res = 1;
  while (n){
    if (n % 2 == 1) res = (res * acc) % mod;
    acc = (acc * acc) % mod;
    n = n / 2;
  }
  return res;
}

bool FermatTest(int a, int n){
  return pow_mod(a, n, n) == a;
}

bool isCarmichael(int a){
  if (isPrime[a]) return false;
  for (int i = 2; i < a; i++){
    if (!FermatTest(i, a)){
      //cout << i << endl;
      return false;
    }
  }
  return true;
}
bool isCarmichaels[MAXN];
int main(){
  prime_init();
  for (int i = 2; i < MAXN; i++){
    isCarmichaels[i] = isCarmichael(i);
  }

  int n;
  while (cin >> n && n){
    if (isCarmichaels[n]){
      printf("The number %d is a Carmichael number.\n", n);
    }else{
      printf("%d is normal.\n", n);
    }
  }
}
