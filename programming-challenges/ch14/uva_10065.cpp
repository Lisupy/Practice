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
const double EPS = 1e-6;
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
struct P{
  double x, y;
};
bool operator<(const P &a, const P &b){
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}
P p0 = {0, 0};
double area2(P &a, P &b, P &c){
  return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}
double ccw(P &a, P &b, P &c){
  return area2(a, b, c) > EPS;
}
double total_area(vector<P> &ps){
  double tot = 0;
  for (size_t i = 0; i < ps.size(); i++){
    tot += area2(p0, ps[i], ps[(i + 1) % ps.size()]);
  }
  return fabs(tot / 2);
}
vector<P> convex_hull(vector<P> ps){
  sort(ps.begin(), ps.end());
  vector<P> tmp(ps.size() * 2);
  int sz = 0;
  for (size_t i = 0; i < ps.size(); i++){
    while (sz - 2 >= 0 && !ccw(tmp[sz - 2], tmp[sz - 1], ps[i])) sz--;
    tmp[sz++] = ps[i];
  }
  for (int i = ps.size() - 2, tsz = sz; i >= 0; i--){
    while (sz > tsz && !ccw(tmp[sz - 2], tmp[sz - 1], ps[i])) sz--;
    tmp[sz++] = ps[i];
  }
  tmp.resize(sz - 1);
  return tmp;
}

int N;
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (cin >> N && N){
    vector<P> ps(N);
    for (int i = 0; i < N; i++) cin >> ps[i].x >> ps[i].y;
    printf("Tile #%d\n", ++TestNum);
    double area1 = total_area(ps);
    vector<P> chull = convex_hull(ps);
    double carea = total_area(chull);
    printf("Wasted Space = %.02lf %%\n\n", (1.0 - area1 / carea) * 100.0);
  }
}

