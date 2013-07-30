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

const int MAXN = 1024 * 10;
vector<int> primes;
void primes_init(){
  vector<bool> isPrime(MAXN, true);
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
int calc(int n, int p){
  int s = 0;
  while (n){
    s += n / p;
    n /= p;
  }
  return s;
}
int solve(int m, int n){
  int ans = 0xffffff;
  for (size_t i = 0; i < primes.size(); i++){
    int p = primes[i];
    int cnt = 0; while(m % p == 0) m /= p, cnt++;
    if (cnt != 0){
      int k = calc(n, p);
      //cout << p << ", " << k << endl;
      if (k < cnt) return -1;
      ans = min(ans, k / cnt);
    }
  }
  return ans;
}

      
int main(){
  primes_init();
  int TestNum; cin >> TestNum;
  for (int kcase = 1; kcase <= TestNum; kcase++){
    printf("Case %d:\n", kcase);
    int m, n; cin >> m >> n;
    int ans = solve(m, n);
    if (ans == -1) printf("Impossible to divide\n");
    else printf("%d\n", ans);
  }
}
