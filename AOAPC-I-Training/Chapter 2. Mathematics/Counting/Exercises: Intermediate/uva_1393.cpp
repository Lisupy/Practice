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
const int MAXN = 310;

vector<int> primes;
vector<bool> isPrime(MAXN, true);
void primes_init(){
  for (int n = 2; n < MAXN; n++) {
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
double noDividePosbility[MAXN];
void noDividePosbility_init(){
  noDividePosbility[0] = 1;
  noDividePosbility[1] = 1;
  for (int i = 2; i < MAXN; i++) {
    noDividePosbility[i] = noDividePosbility[i - 1];
    if (isPrime[i]){
      noDividePosbility[i] *= 1.0 - 1.0 / i;
    }
  }
}
int gcd_cache[MAXN][MAXN];
int gcd(int a, int b){
  if (gcd_cache[a][b] != 0) return gcd_cache[a][b];
  return gcd_cache[a][b] = (b == 0? a: gcd(b, a % b));
}
//AC
i64 F(i64 m, i64 n){
  i64 total = 0;
  for (i64 a = 0; a <= m; a++){
    for (i64 b = 0; b <= n; b++){
      if (a == 0 || b == 0) continue;
      if (gcd(a, b) != 1) continue;
      i64 t = (m - a + 1) * min(b, n - b + 1) + (n - b + 1) * min(m - a + 1, a) - min(a, m - a + 1) * min(b, n - b + 1);
      total += t * 2;
    }
  }
  return total;
}
//AC
i64 F1(i64 m, i64 n){
  i64 total = 0;
  for (i64 a = 0; a <= m; a++){
    for (i64 b = 0; b <= n; b++){
      if (a == 0 || b == 0) continue;
      int g = gcd(a, b);
      i64 t = (m - a + 1) * (n - b + 1) * 2;
      if (g == 1) total += t;
      if (g == 2) total -= t;
      //cout << a << ", " << b << ": " << total << endl;
    }
  }
  return total;
}
int TestNum;
int main(){
  //primes_init();
  //noDividePosbility_init();
  int n, m;
  while (cin >> n >> m && n) {
    cout << F1(n - 1, m - 1) << endl;
  }
}

