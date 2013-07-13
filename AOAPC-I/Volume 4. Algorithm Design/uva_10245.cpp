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
const double INF = 10000.0 * 10000.0;
const int MAXN = 10000;
double x[MAXN];
double y[MAXN];
double dist2(double x1, double y1, double x2, double y2){
  return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int N;

double solve(){
  double closest = INF;
  for (int i = 0; i < N; i++){
    for (int j = i + 1; j < N; j++){
      double d = dist2(x[i], y[i], x[j], y[j]);
      closest = min(closest, d);
    }
  }
  return closest;
}


int main(){
  while (scanf("%d", &N) && N){
    for (int i = 0; i < N; i++){
      scanf("%lf %lf", &x[i], &y[i]);
    }
    double closest = solve();
    if (closest == INF){
      printf("INFINITY\n");
    }else{
      printf("%.04lf\n", sqrt(closest));
    }
  }
}
