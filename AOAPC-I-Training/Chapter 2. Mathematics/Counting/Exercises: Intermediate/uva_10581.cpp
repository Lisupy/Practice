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

i64 f[256][16];
i64 F(int n, int k){
  if (n < 0) return 0;
  if (k == 1) return 1;
  if (n == 0) return 1;
  if (k <= 0) return 0;
  i64 &total = f[n][k];
  if (total != -1) return total;
  total = 0;
  total = F(n, k - 1) + F(n - k, k);
  return total;
}

i64 T(int n, int k){
  return F(n, k) - F(n, k - 1);
}

void solve(int m, int n, i64 k){
  int adjust = 0;
  while (n != 1){
    int t = 1;
    i64 total = 0;
    //i64 valid = 0;
    //printf("debug1: %d %d %lld %d %d\n", m, n, k, t, adjust);
    while (true) {
      //getchar();
      i64 s = T(m - t - (n - 1) * (t - 1), n - 1);
      total = total + s; 
      //printf("s: %lld, total : %lld\n", s, total);
      if (total >= k){
        total -= s;
        break;
      }
      t++;
    }
    //printf("debug: %d %d %lld %d %d\n", m, n, k, t, adjust);
    printf("%d\n", t + adjust);
    k -= total;
    m -= t + (n - 1) * (t - 1);
    adjust += (t - 1);
    n--;
  }
  printf("%d\n", m + adjust);
}

int TestNum;
int main(){
  memset(f, -1, sizeof(f));
  //cout << T(7, 2) << endl;
  cin >> TestNum;
  while (TestNum--) {
    int m, n;
    i64 k;
    cin >> m >> n >> k;
    solve(m, n, k);
  }
}

