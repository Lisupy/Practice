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
 * (1 << (31 - __builtin_clz(100) ) == 64;
 */
const int MAXN = 128 * 1024;
const int INF = 0x1f1f1f1f;
struct Point{
  int x, y, z;
};

Point points[MAXN];
bool graterByZ(const Point &a, const Point &b){
  return a.z > b.z;
}
struct Diag{
  map<int, int> M; 
  i64 area;
  Diag():M(), area(0){
    M[-1] = INF;
    M[INF] = -1;
  }
  void insert(int x, int y){
    //printf("insert(%d, %d)\n", x, y);
    map<int, int>::iterator it = M.upper_bound(x - 1);
    if (it->second >= y) return;
    int last_y = it->second;
    int last_x = x;
    it--;
    while (it->second < y){
      area += (last_x - it->first) * (y - last_y);
      last_x = it->first, last_y = it->second;
      it = M.erase(it); 
      it--;
    }
    area += (last_x - it->first) * (y - last_y);
    M[x] = y; 
    //cout << area << endl;
  }
};
int n, m;
int TestNum;
int main(){
  while (scanf("%d %d", &n, &m) && n){
    for (int i = 0; i < n; i++) {
      Point &p = points[i];
      scanf("%d%d%d", &p.x, &p.y, &p.z);
      p.x--, p.y--, p.z--;
    }
    points[n].x = 0, points[n].y = 0, points[n].z = -1;
    n++;
    sort(points, points + n, graterByZ);
    Diag di;
    i64 total = 0;
    for (int i = 0; i < n; i++){
      if (i != 0) total += di.area * (points[i - 1].z - points[i].z);
      di.insert(points[i].x, points[i].y);
      //cout << total << endl;
    }
    i64 m3 = (i64) m * (i64)m * (i64)m;
    //printf("%lld %lld\n", m3 ,total);
    printf("%lld\n", m3 - total);
  }
}

