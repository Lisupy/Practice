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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */

struct Pos{
  double x, y;
};
double dist(Pos a, Pos b){
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
Pos getPos(double n){
  double layer = 0;
  while (n > layer * 2 + 1){
    n -= layer * 2 + 1;
    layer++;
  }
  Pos res;
  res.y = (n - (layer + 1)) * 0.5;
  if ((int)n % 2 == 0){
    res.x = layer * sqrt(3) / 2.0 + sqrt(3) / 6.0; 
  }else{
    res.x = layer * sqrt(3) / 2.0 + sqrt(3) / 3.0;
  }
  //cout << res.x << ", " << res.y << endl;
  return res;
}

int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  double n, m;
  while (scanf("%lf%lf", &n, &m) != EOF){
    Pos pn = getPos(n + 1);
    Pos pm = getPos(m + 1);
    printf("%.03lf\n", dist(pn, pm));
  }
}

