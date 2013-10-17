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

const int MAXK = 16;
const int MAXN = 128;
double f[MAXN][MAXK];

double solve(int k, int n){
  memset(f, 0, sizeof(f));
  for (int i = 0; i <= k; i++) f[1][i] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= k; j++){
      if (j != 0) f[i][j] += f[i - 1][j - 1];
      f[i][j] += f[i - 1][j];
      if (j != k) f[i][j] += f[i - 1][j + 1];
      f[i][j] /= (k + 1);
    }
  }
  double total = 0;
  for (int i = 0; i <= k; i++){
    total += f[n][i];
  }
  total /= (k + 1);
  return total;
 }
int TestNum;
int main(){
  int k, n;
  while (cin >> k >> n) {
    printf("%.05lf\n", solve(k, n) * 100);
  }

}

