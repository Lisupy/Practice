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
int l, w;
struct P{
  int x, y;
};
bool operator<(const P &a, const P &b){
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}
bool operator==(const P &a, const P &b){
  return a.x == b.x && a.y == b.y;
}
int solve(vector<P> ps){
  if (ps.size() == 0) return l * w;
  int best = 0;
  int N = ps.size();
  for (int rot = 0; rot < 4; rot++){
    sort(ps.begin(), ps.end());
    for (int i = 0; i < N; i++){
      int x1 = ps[i].x, Y = ps[i].y;
      int y1 = 0, y2 = w;
      for (int j = i + 1; j <= N; j++){
        int x = j < N? ps[j].x: l;
        int y = j < N? ps[j].y: w;
        if (x == x1) continue;
        best = max(best, (x - x1) * (y2 - y1));
        if (y == Y) break;
        if (y < Y) y1 = max(y1, y);
        if (y > Y) y2 = min(y2, y);
      }
    }
    for (int i = 0; i < N; i++){
      P p = (P){ps[i].y, l - ps[i].x};
      ps[i] = p;
    }
    swap(l, w);
  }
  return best;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  cin >> TestNum;
  while (TestNum--) {
    cin >> l >> w;
    vector<P> ps;
    int k;
    while (cin >> k && k) {
      if (k == 1){
        int x, y; cin >> x >> y;
        ps.push_back((P){x, y});
      }else{
        int x, y, dx, dy; cin >> x >> y >> dx >> dy;
        for (int i = 0; i < k; i++){
          ps.push_back((P){x + i * dx, y + i * dy});
        }
      }
    }
    cout << solve(ps) << endl;
  }
}

