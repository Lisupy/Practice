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

double dist(double R1, double R2){
  return sqrt((R2 + R1) * (R2 + R1) - (R2 - R1) * (R2 - R1));
}


vector<double> rs;

double calc(){
  vector<double> d(rs.size());
  double ans = 0;
  d[0] = rs[0];
  ans = rs[0] + rs[0];
  for (size_t i = 1; i < rs.size(); i++){
    double longest = rs[i];
    for (size_t j = 0; j < i; j++){
      longest = max(longest, dist(rs[i], rs[j]) + d[j]);
    }
    d[i] = longest;
    ans = max(ans, d[i] + rs[i]);
  }
  return ans;
}


int main(){
  int n;
  cin >> n;
  while (n--){
    int m;
    cin >> m;
    rs.resize(m);
    for (int i = 0; i < m; i++){
      cin >> rs[i];
    }
    double smallest = 1e20;
    sort(rs.begin(), rs.end());
    do {
      smallest = min(smallest, calc()); 
    } while (next_permutation(rs.begin(), rs.end()));
    printf("%.03lf\n", smallest);
  }
}
