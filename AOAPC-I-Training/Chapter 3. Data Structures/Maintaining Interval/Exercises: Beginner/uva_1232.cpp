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
const int maxnode = 1 << 20;
const int MAXN = 100000;
struct IntervalTree{
  int set_v[maxnode];
  int _min[maxnode];
  int _max[maxnode];
  bool needSet[maxnode];
  int qL, qR;
  void reset(){
    memset(set_v, 0, sizeof(set_v));
    memset(needSet, 0, sizeof(needSet));
    memset(_min, 0, sizeof(_min));
    memset(_max, 0, sizeof(_max));
  }
  void pushUp(int o, int L, int R){
    int lo = o * 2, ro = o * 2 + 1;
    _min[o] = min(_min[lo], _min[ro]);
    _max[o] = max(_max[lo], _max[ro]);
    assert(lo < maxnode);
    assert(ro < maxnode);
    assert (L != R);
  }
  void pushDown(int o, int L, int R){
    int M = (L + R) / 2;
    int lo = o * 2, ro = o * 2 + 1;
    assert(lo < maxnode);
    assert(ro < maxnode);
    assert (L != R);
    if (needSet[o]){
      set(lo, L,     M, set_v[o], true);
      set(ro, M + 1, R, set_v[o], true);
      needSet[o] = false;
      pushUp(o, L, R);
    }
  }
  bool valid(int L, int R){
    return qL <= R && L <= qR;
  }
  int query(int o, int L, int R, int v){
    assert(o < maxnode);
    if (!valid(L, R)) return 0;
    int M = (L + R) / 2;
    int lo = o * 2, ro = o * 2 + 1;
    if (_min[o] > v) return 0;
    if (qL <= L && R <= qR){
      int total = 0;
      if (_max[o] <= v){
        return R - L + 1;
      }else{
        assert (L != R);
        pushDown(o, L, R);
        total += query(lo, L,     M, v);
        total += query(ro, M + 1, R, v);
        return total;
      }
    }else{
      if (_max[o] <= v) return max(min(qR, R) - max(qL, L) + 1, 0);
      pushDown(o, L, R);
      int total = 0;
      total += query(lo, L,     M, v);
      total += query(ro, M + 1, R, v);
      return total;
    }
    assert(0);
    return 0;
  }
  void set(int o, int L, int R, int v, bool push){
    if (!push && !valid(L, R)) return ;
    int M = (L + R) / 2;
    int lo = o * 2, ro = o * 2 + 1;
    if (_min[o] >= v) return;
    if (L == R) assert(_min[o] == _max[o]);
    if (push || (qL <= L && R <= qR)){
      if (_max[o] <= v){
        _min[o] = v;
        _max[o] = v;
        needSet[o] = true;
        set_v[o] = v;
      }else{
        assert(!push);
        pushDown(o, L, R);
        set(lo, L,     M, v, false);
        set(ro, M + 1, R, v, false);
        pushUp(o, L, R);
      }
    }else{
      pushDown(o, L, R);
      set(lo, L,     M, v, false);
      set(ro, M + 1, R, v, false);
      pushUp(o, L, R);
    }
  }
  IntervalTree& gao(int L, int R){
    qL = L, qR = R;
    return *this;
  }
};

IntervalTree tree;
int n;
int TestNum;
int main(){
  scanf("%d", &TestNum);
  while(TestNum--){
    tree.reset();
    scanf("%d", &n);
    i64 total = 0;
    while (n--){
      int l, r, h; scanf("%d %d %d", &l, &r, &h);
      assert(tree.gao(l, r - 1).query(1, 0, MAXN, h) <= r - l);
      total += tree.gao(l, r - 1).query(1, 0, MAXN, h);
      //printf("%d\n", total);
      tree.gao(l, r - 1).set(1, 0, MAXN, h, false);
    }
    printf("%lld\n", total);
  }
}

