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
const double PI = acos(-1);
const double EPS = 1e-12;
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */

vector<double> solquadric(double a, double b, double c){
  vector<double> res;
  double tmp = sqrt(b * b - 4 * a * c);
  res.push_back((-b + tmp) / (2 * a));
  res.push_back((-b - tmp) / (2 * a));
  return res;
}


double L, W;
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (cin >> L >> W){
    if (L > W) swap(L, W);
    double largest = 0, largest_x = 0;
    vector<double> candx = solquadric(12, -4 * (L + W), L * W);
    for (size_t i = 0; i < candx.size() ;i++){
      double x = candx[i];
      double volume = (L - 2 * x) * (W - 2 * x) * x;
      if (volume > largest) largest_x = x, largest = volume;
    }


    printf("%.03lf %.03lf %.03lf\n", largest_x + EPS, 0.0, L / 2 + EPS);
  }
}

