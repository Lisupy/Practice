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
//Pick:
//A(P) = I(P) + B(P) / 2 - 1
//A(P) : 面积
//I(P) : 内部的点数
//B(P) : 边界的点数
struct P{
  double x, y;
};
P p0 = {0, 0};
double area(P &a, P &b, P &c){
  return ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) ) / 2;
}
double totalArea(vector<P> ps){
  double tot = 0;
  for (size_t i = 0; i < ps.size(); i++){
    tot += area(p0, ps[i], ps[(i + 1) % ps.size()]);
  }
  return fabs(tot);
}
int calc(P &p1, P &p2){
  int x = abs(p2.x - p1.x), y = abs(p2.y - p1.y);
  int g = __gcd(x, y);
  return g;
}
double countMargin(vector<P> ps){
  int N = ps.size();
  double tot = 0;
  for (int i = 0; i < N; i++){
    tot += calc(ps[i], ps[(i + 1) % N]);
  }
  return tot;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int N;
  while (cin >> N && N) {
    vector<P> ps(N);
    for (int i = 0; i < N; i++) cin >> ps[i].x >> ps[i].y;
    i64 A = totalArea(ps);
    i64 B = countMargin(ps);
    i64 I = A + 1 - B / 2;
    cout << I << endl;
  }
}

