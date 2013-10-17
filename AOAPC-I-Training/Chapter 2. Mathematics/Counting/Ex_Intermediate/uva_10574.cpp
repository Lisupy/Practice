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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 */

struct Pos{
  int x, y;
  bool operator<(const Pos& other) const{
    if (x != other.x) return x < other.x;
    return y < other.y;
  }
};

int calc(vector<Pos> ps){
  int total = 0;
  //set<Pos> S(ps.begin(), ps.end());
  sort(ps.begin(), ps.end());
  //for (auto i : ps) cout << i.x << "," << i.y << endl;
  for (size_t i1 = 0, i2 = 0; i1 < ps.size(); i1 = i2) {
    while (i2 < ps.size() && ps[i2]. x == ps[i1].x) i2++;
    //for (auto i : S) cout << i.x << "," << i.y << endl;
    for (size_t j1 = i2, j2 = i2; j1 < ps.size(); j1 = j2) {
      while (j2 < ps.size() && ps[j2]. x == ps[j1].x) j2++;
      int l = 0;
      size_t ki = i1, kj = j1;
      while (ki < i2 && kj < j2) {
        if (ps[ki].y == ps[kj].y) l++, ki++, kj++;
        else if (ps[ki].y > ps[kj].y) kj++;
        else ki++;
      }
      total += l * (l - 1) / 2;
    }
  }
  return total;
}
int TestNum;
int main(){
  int t; cin >> t;
  while (t--) {
    int n; cin >> n; 
    vector<Pos> ps(n);
    for (int i = 0; i < n; i++) {
      cin >> ps[i].x >> ps[i].y;
    }
    cout << "Case " << ++TestNum << ": " << calc(ps) << endl;
  }
}

