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

const int MAXN = 32;
const int MAXX = 256;
unsigned long long cache[MAXN][MAXX];
bool visited[MAXN][MAXX];
unsigned long long T(int n, int x){
  unsigned long long &res = cache[n][x];
  if (visited[n][x]) return res;
  visited[n][x] = true;
  if (n == 1){
    if (1 <= x && x <= 6){
      res = 1;
    }else{
      res = 0;
    }
  }else{
    res = 0;
    for (int i = 1; i <= 6; i++){
      res += T(n - 1, x - i);
    }
  }
  return res;
}

unsigned long long powll(unsigned long long p, unsigned long long x){
  long long s = 1;
  while (x){
    if (x % 2) s *= p;
    p *= p;
    x /= 2;
  }
  return s;
}

unsigned long long gcd(unsigned long long a, unsigned long long b){
  return b == 0 ? a : gcd(b, a % b);
}

int main(){
  unsigned long long n, x;
  while (cin >> n >> x && n){
    unsigned long long up = 0;
    while (T(n, x) != 0 || x <= n){
      up += T(n, x);
      x++;
    }
    unsigned long long down = powll(6, n);
    unsigned long long g = gcd(up, down);
    if (up == down){
      cout << "1" << endl;
    }else if (up == 0){
      cout << "0" << endl;
    }else{
      printf("%llu/%llu\n", up / g, down / g);
    }
  }
}
    
