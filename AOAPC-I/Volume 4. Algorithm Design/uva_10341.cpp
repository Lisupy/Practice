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
double p, q, r, s, t, u;

double expValue(double x){
  return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double solve(){
  double L = 0, R = 1;
  //double best = - 1;
  if (expValue(L) * expValue(R) > 0)return -1;
  if (expValue(L) == 0){
    return 0;
  }
  if (expValue(R) == 0){
    return 1;
  }
  while (L < R && L +  1e-10 < R){
    double mid = (L + R) / 2;
    double v = expValue(mid);
    if (v == 0){
      return mid;
    }
    if (v > 0){
      L = mid;
    }
    if (v < 0){
      R = mid;
    }
  }
  return L;
}

int main(){
  while (cin >> p >> q >> r >> s >> t >> u){
    double ans = solve();
    if (ans < 0){
      cout << "No solution" << endl;
    }else{
      printf("%.4lf\n", ans);
    }
  }
}
