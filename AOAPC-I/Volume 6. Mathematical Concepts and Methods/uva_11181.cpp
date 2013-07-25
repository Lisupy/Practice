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

int TestNum;

double T(vector<double> &ps, int start, int r){
  int len = ps.size();
  if (r < 0) return 0;
  if (len - start < r){
    return 0;
  }
  if (len == start){
    if (r == 0) return 1;
    else return 0;
  }
  return T(ps, start + 1, r) * (1 - ps[start]) + T(ps, start + 1, r - 1) * ps[start];
}

double solve(vector<double> ps, int k, int r){
  double p = ps[k];
  ps.erase(ps.begin() + k);
  double s1 = p * T(ps, 0, r - 1);
  double s2 = (1 - p) * T(ps, 0, r);
  return s1 / (s1 + s2);
}

int main(){
  int N, r;
  while (cin >> N >> r && N){
    printf("Case %d:\n", ++TestNum);
    vector<double> p(N);
    for (int i = 0; i < N; i++) cin >> p[i];
    for (int i = 0; i < N; i++){
      printf("%.06lf\n", solve(p, i, r));
    }
  }
}


