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
const int INF = 0x1f1f1f1f;
struct Rect{
  int x, y, z;
};
bool greaterByZ(const Rect &a, const Rect &b){
  return a.z > b.z;
}
int n; 
int m;
vector<Rect> rects;


struct Cover{
  i64 area;
  map<int, int> M;
  Cover():area(0), M(){
    M[0] = INF;
    M[m + 1] = 0;
  }
  void insert(int x, int y){
    map<int, int>::iterator it = M.lower_bound(x);
    map<int, int>::iterator last = it;
    if (it->second >= y) return;
    i64 last_x = x;
    i64 last_y = it->second;
    if (it->first != x) it--;
    if (it->first == x && it->second >= y) return;
    while (it->second < y){
      area += (y - last_y) * (last_x - it->first); 
      last_y = it->second, last_x = it->first;
      it--;
    }
    area += (y - last_y) * (last_x - it->first); 
    it++;
    M.erase(it, last); 
    M[x] = y;
    //for (auto i : M) cout << i.first << ", " << i.second << endl;
  }
  i64 query(){
    return area;
  }
};
int TestNum;
int main(){
  while (scanf("%d%d", &n, &m) && n){
    rects.resize(n + 1);
    for (int i = 0; i < n; i++){
      Rect &r = rects[i];
      scanf("%d %d %d", &r.x, &r.y, &r.z);
    }
    rects[n] = {0, 0, 0};
    sort(rects.begin(), rects.end(), greaterByZ);
    Cover cover;
    i64 total = 0;
    for (int i = 0; i <= n; i++){
      Rect &r = rects[i];
      if (i != 0){
        i64 s = cover.query();
        total += s * (rects[i - 1].z - rects[i].z);
        //printf("%d: %lld, %lld\n", i, s, total);
      }
      //printf("%d: %d %d %d\n", i, r.x, r.y, r.z); 
      cover.insert(r.x, r.y);
    }
    i64 mmm = (i64)m * (i64)m * (i64)m;
    //printf("%lld\n", mmm - total);
    cout << mmm - total << endl;
  }
}

