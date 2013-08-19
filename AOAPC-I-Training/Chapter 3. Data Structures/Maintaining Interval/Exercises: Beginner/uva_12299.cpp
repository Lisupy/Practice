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

const int maxnode = 1 << 18;
const int INF = 0x1f1f1f1f;
int n, q;

struct IntervalTree{
  int _min[maxnode];
  int qL, qR;
  void reset(){
    memset(_min, 0x1f, sizeof(_min));
  }
  bool valid(int L, int R){
    return L <= R && qL <= R && L <= qR;
  }
  int queryMin(int o, int L, int R){
    assert(o < maxnode);
    if (!valid(L, R)) return INF;
    if (qL <= L && R <= qR){
      return _min[o];
    }else{
      int lo = o * 2, ro = o * 2 + 1;
      int M = (L + R) / 2;
      return min(queryMin(lo, L, M), queryMin(ro, M + 1, R));
    }
    assert(0);
  }
  void updateMin(int o, int L, int R, int v){
    assert(o < maxnode);
    if (!valid(L, R)) return;
    assert(qL == qR);
    if (qL <= L && R <= qR){
      _min[o] = v;
    }else{
      int lo = o * 2, ro = o * 2 + 1;
      int M = (L + R) / 2;
      updateMin(lo, L,     M, v);
      updateMin(ro, M + 1, R, v);  
      _min[o] = min(_min[lo], _min[ro]);
    }
  }
  IntervalTree &gao(int L, int R){
    qL = L, qR = R;
    return *this;
  }
};
IntervalTree tree;
int A[100*1024];
int TestNum;
int main(){
  scanf("%d %d", &n, &q);
  tree.reset();
  for (int i = 1; i <= n; i++) scanf("%d", A + i);
  for (int i = 1; i <= n; i++) tree.gao(i, i).updateMin(1, 1, n, A[i]);
  while (q--){
    char buf[256];
    scanf("%s", buf);
    //for (int i = 0; buf[i]; i++) assert(buf[i] != ' ');
    if (buf[0] == 'q'){
      //for (int i = 1; i <= n; i++) printf("%d ", A[i]);printf("\n");
      int from, to; sscanf(buf, "query(%d,%d)", &from, &to);
      printf("%d\n", tree.gao(from, to).queryMin(1, 1, n));
    }else{
      for (int i = 0; buf[i]; i++) if (!isdigit(buf[i])) buf[i] = ' ';
      istringstream iss(buf);
      int shift[300]; int shift_len = 0;
      while (iss >> shift[shift_len]) shift_len++ ; 
      int val[300];
      for (int i = 0; i < shift_len; i++) val[i] = A[shift[(i + 1)%shift_len]]; 
      for (int i = 0; i < shift_len; i++) tree.gao(shift[i], shift[i]).updateMin(1, 1, n, val[i]);
      for (int i = 0; i < shift_len; i++) A[shift[i]] = val[i];
    }
  }
}

