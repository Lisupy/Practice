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
const double eps = 1e-8;
const double pi = acos(-1.0);
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 */
struct Pos{
  double x, y;
  double angle;
  bool operator<(const Pos &other) const{
    return angle < other.angle;
  }
};

i64 C(i64 n, i64 k){
  if (n < k) return 0;
  i64 total = 1;
  for (i64 i = 1; i <= k; i++) {
    total *= n - i + 1;
    total /= i;
  }
  return total;
}
i64 calc(vector<Pos> ps){
  sort(ps.begin(), ps.end());
  i64 total = 0;
  for (size_t i = 0; i < ps.size(); i++) {
    Pos p = ps[i];
    Pos t1 = p, t2 = p;
    i64 n;
    if (p.angle <= -pi / 2){
      t1.angle += pi / 2 - eps;
      t2.angle += pi * 3 / 2 + eps;
      n = upper_bound(ps.begin(), ps.end(), t2) - lower_bound(ps.begin(), ps.end(), t1);
    }else if (p.angle > pi / 2){
      t1.angle -= pi * 3 / 2 + eps;
      t2.angle -= pi / 2 - eps;
      n = upper_bound(ps.begin(), ps.end(), t2) - lower_bound(ps.begin(), ps.end(), t1);
    }else{
      t1.angle += pi / 2 - eps;
      t2.angle -= pi / 2 - eps;
      n = (ps.end() - lower_bound(ps.begin(), ps.end(), t1)) + (upper_bound(ps.begin(), ps.end(), t2) - ps.begin());
    }
    //cout << "===" << i << ": " << n << ", " << p.angle << endl;
    total += n;
  }
  assert(total % 2 == 0);
  return total / 2;
}
#if 0
i64 calc2(vector<Pos> ps){
  sort(ps.begin(), ps.end());
  size_t len = ps.size();
  for (size_t i = 0; i < len; i++) {
    ps.push_back(ps[i]);
    ps.back().angle += pi * 2;
  }
  i64 total = 0;
  for (size_t l = 0; l < ; l++) {
    
  }
#endif
int TestNum;
int main(){
  int n;
  while (cin >> n && n) {
    vector<Pos> ps(n);
    for (int i = 0; i < n; i++) {
      cin >> ps[i].x >> ps[i].y;
    }
    i64 total = 0;
    for (int i = 0; i < n; i++) {
      vector<Pos> tmp(ps);
      tmp.erase(tmp.begin() + i);
      for (size_t j = 0; j < tmp.size(); j++) {
        tmp[j].angle = atan2(tmp[j].y - ps[i].y, tmp[j].x - ps[i].x);
      }
      total += calc(tmp);
      //cout << i << ": " << total << endl;
    }
    //cout << C(n, 3) << endl;
    printf("Scenario %d:\n", ++TestNum);
    printf("There are %lld sites for making valid tracks\n", C(n, 3) - total);
  }
}

