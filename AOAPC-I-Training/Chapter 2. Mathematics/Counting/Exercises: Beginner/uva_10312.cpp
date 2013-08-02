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

long long cache[32][32];

long long f(int n, int d){
  if (d < 0) return 0;
  if (d == 0) return 1;
  if (n - 2 < d) return 0;
  long long &total = cache[n][d];
  if (total != 0) return total;
  total += f(n - 1, d) + f(n - 1, d - 1);
  for (int m = 2; m < n; m++){
    for (int i = 0; i < d; i++){
      total += f(m, i) * (f(n - m, d - i - 1) + (n - m >= 2 ? f(n - m, d - i - 2) : 0) );
    }
  }
  return total;
}
long long solve(int n){
  long long total = 0;
  for (int i = 0; i <= n - 3; i++){
    total += f(n, i);
  }
  return total;
}
int TestNum;
int main(){
  int n;
  while (cin >> n) {
    cout << solve(n) << endl;
  }
}

