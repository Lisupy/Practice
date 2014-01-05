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
const double EPS = 1e-3;
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */

struct Pos{
  double x, y;
};
vector<Pos> holes;
double dist(Pos a, Pos b){
  return round(sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2))*1000)/1000;
}
int n;
Pos gopher, dog;
void solve(){
  for (int i = 0; i < n; i++){
    Pos hole = holes[i];
    if (dist(hole, gopher) * 2 < dist(hole, dog)){
      printf("The gopher can escape through the hole at (%.03lf,%.03lf).\n", hole.x, hole.y);
      return;
    }
  }
  printf("The gopher cannot escape.\n");
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (cin >> n >> gopher.x >> gopher.y >> dog.x >> dog.y){
    holes.resize(n);
    for (int i = 0; i < n; i++) cin >> holes[i].x >> holes[i].y;
    solve();
  }
}

