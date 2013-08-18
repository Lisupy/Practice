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

typedef pair<int, int> Interval;
const int max_node = 1 << 17;
struct IntervalTree{
  int add_v[max_node]; 
  int set_v[max_node];
  bool needSet[max_node];
  int _max[max_node];
  int _min[max_node];
  int _sum[max_node];
  int qL, qR, qLen;
  void reset(){
    memset(add_v, 0, sizeof(add_v));
    memset(set_v, 0, sizeof(set_v));
    memset(needSet, 0, sizeof(needSet));
    memset(_max, -0x1f1f1f1f, sizeof(_max));
    memset(_min, 0x1f1f1f1f, sizeof(_min));
    memset(_sum, 0, sizeof(_sum));
  }
  //intersect
  bool valid(int L, int R){
    return qL <= R && L <= qR;
  }
  void PushUp(int o, int /*L*/, int /*M*/, int /*R*/, int lo, int ro){
    _max[o] = max(_max[lo], _max[ro]);
    _min[o] = min(_min[lo], _min[ro]);
    _sum[o] = _sum[lo] + _sum[ro];
  }
  void PushDown(int o, int L, int M, int R, int lo, int ro){
    if (needSet[o]){
      Set(lo, L,     M, set_v[o], true);
      Set(ro, M + 1, R, set_v[o], true);
      needSet[o] = false;
      //PushUp(o, L, M, R, lo, ro);
    }
    if (add_v[o]){
      Add(lo, L,     M, add_v[o], true);
      Add(ro, M + 1, R, add_v[o], true);
      add_v[o] = 0;
      //PushUp(o, L, M, R, lo, ro);
    }
  }
  void Add(int o, int L, int R, int v, bool isPush){
    if (!isPush && !valid(L, R)) return;
    int M = (L + R) / 2;
    int lo = o * 2, ro = o * 2 + 1;
    if (isPush || (qL <= L && R <= qR)){
      add_v[o] += v;
      _max[o] += v;
      _min[o] += v;
      _sum[o] += v * (R - L + 1);
      return ;
    }else{
      PushDown(o, L, M, R, lo, ro);
      //PushUp(o, L, M, R, lo, ro);
      Add(lo, L,     M,  v, false);
      Add(ro, M + 1, R,  v, false);
      PushUp(o, L, M, R, lo, ro);
    }  
  }
  void Set(int o, int L, int R, int v, bool isPush){
    if (!isPush && !valid(L, R)) return;
    int M = (L + R) / 2;
    int lo = o * 2, ro = o * 2 + 1;
    if (isPush || (qL <= L && R <= qR)){
      add_v[o] = 0;
      _max[o] = v;
      _min[o] = v;
      _sum[o] = v * (R - L + 1);
      set_v[o] = v;
      needSet[o] = true;
      return ;
    }else{
      PushDown(o, L, M, R, lo, ro);
      //PushUp(o, L, M, R, lo, ro);
      Set(lo, L,     M,  v, false);
      Set(ro, M + 1, R,  v, false);
      PushUp(o, L, M, R, lo, ro);
    }  
  }
  int queryMax(int o, int L, int R){
    if (!valid(L, R)) return -0x6ffffff;
    int M = (L + R) / 2;
    int lo = o * 2, ro = o * 2 + 1;
    if (qL <= L && R <= qR){
      return _max[o];
    }else{
      PushDown(o, L, M, R, lo, ro);
      PushUp(o, L, M, R, lo, ro);
      int lMax = queryMax(lo, L,     M);
      int rMax = queryMax(ro, M + 1, R);
      return max(lMax, rMax);
    }
  }
  int queryMin(int o, int L, int R){
    if (!valid(L, R)) return 0x6fffffff;
    int M = (L + R) / 2;
    int lo = o * 2, ro = o * 2 + 1;
    if (qL <= L && R <= qR){
      return _min[o];
    }else{
      PushDown(o, L, M, R, lo, ro);
      PushUp(o, L, M, R, lo, ro);
      int lMin = queryMin(lo, L,     M);
      int rMin = queryMin(ro, M + 1, R);
      return min(lMin, rMin);
    }
  }
  int querySum(int o, int L, int R){
    if (!valid(L, R)) return 0;
    int M = (L + R) / 2;
    int lo = o * 2, ro = o * 2 + 1;
    if (qL <= L && R <= qR){
      return _sum[o];
    }else{
      PushDown(o, L, M, R, lo, ro);
      PushUp(o, L, M, R, lo, ro);
      int lSum = querySum(lo, L,     M);
      int rSum = querySum(ro, M + 1, R);
      return lSum + rSum;
    }
  }
};
int r, c, m;
int TestNum;
IntervalTree its[20];
int main(){
  while (scanf("%d %d %d", &r, &c, &m) != EOF){
    for (int i = 0; i < 20; i++) its[i].reset();
    for (int i = 0; i < 20; i++){
      its[i].qL = 0, its[i].qR = c;
      its[i].Set(1, 0, c, 0, false);
    }
    while (m--){
      int op; scanf("%d", &op);
      if (op == 1){
        int x1, y1, x2, y2, v; scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &v);
        x1--, y1--, x2--, y2--;
        for (int i = x1; i <= x2; i++){
          its[i].qL = y1, its[i].qR = y2;
          its[i].Add(1, 0, c, v, false);
        }
      }else if (op == 2){
        int x1, y1, x2, y2, v; scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &v);
        x1--, y1--, x2--, y2--;
        for (int i = x1; i <= x2; i++){
          its[i].qL = y1, its[i].qR = y2;
          its[i].Set(1, 0, c, v, false);
        }
      }else{
        int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1--, y1--, x2--, y2--;
        int theSum = 0, theMin = 0x7fffffff, theMax = -0x6ffffff;
        for (int i = x1; i <= x2; i++){
          its[i].qL = y1, its[i].qR = y2;
          theSum += its[i].querySum(1, 0, c);
          theMin  = min(theMin, its[i].queryMin(1, 0, c));
          theMax  = max(theMax, its[i].queryMax(1, 0, c));
        }
        printf("%d %d %d\n", theSum,theMin, theMax);
      }
    }
  }
}

