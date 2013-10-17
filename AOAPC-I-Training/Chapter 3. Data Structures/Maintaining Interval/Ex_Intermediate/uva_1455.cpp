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
const int maxnode = 1024 * 1024 * 2;
const int maxrange = maxnode / 2 - 1;
const int MAXN = 1024 * 128;
int N;
int x[MAXN], y[MAXN];
struct IntervalTree{
  int qL, qR;
  int cnt[maxnode];
  int delay[maxnode];
  void init(){
    memset(cnt, 0, sizeof(cnt));
    memset(delay, 0, sizeof(delay));
  }
  bool valid(int o, int L, int R){
    assert(o < maxnode);
    return qL <= qR && qL <= R && L <= qR;
  }
  void pushUp(int o, int L, int R){
    assert(L <= R);
    int lo = o * 2, ro = o * 2 + 1;
    cnt[o] = cnt[lo] + cnt[ro];
  }
  void pushDown(int o, int L, int R){
    int lo = o * 2, ro = o * 2 + 1;
    int M = (L + R) / 2;
    if (delay[o]){
      add(lo, L,     M, delay[o], true);
      add(ro, M + 1, R, delay[o], true);
      delay[o] = 0;
      pushUp(o, L, R);
    }
  }
  void add(int o, int L, int R, int v, bool push){
    if (!push && !valid(o, L, R)) return;
    if(push || (qL <= L && R <= qR)){
      cnt[o] += (R - L + 1) * v;
      delay[o] += v;
    }else{
      int lo = o * 2, ro = o * 2 + 1;
      int M = (L + R) / 2;
      pushDown(o, L, R);
      add(lo, L,     M, v, false);
      add(ro, M + 1, R, v, false);
      pushUp(o, L, R);
    }
    //printf("query, %d, (%d,%d) : %d, %d\n", o, L, R, v, cnt[o]);
  }
  int query(int o, int L, int R){
    if (!valid(o, L, R)) return 0;
    //printf("query, %d,%d %d : %d\n", o, L, R, cnt[o]);
    if (qL <= L && R <= qR){
      return cnt[o];
    }else{
      int lo = o * 2, ro = o * 2 + 1;
      int M = (L + R) / 2;
      pushDown(o, L, R);
      int lcnt = query(lo, L,     M); 
      int rcnt = query(ro, M + 1, R);
      return lcnt + rcnt;
    }
  }
  IntervalTree& gao(int L, int R){
    qL = L, qR = R;
    //printf("gao(%d,%d)\n", qL, qR);
    return *this;
  }
};
IntervalTree stateTree, citysTree;
struct DisjoinSet{
  int p[MAXN];
  int _min[MAXN];
  int _max[MAXN];
  int _cnt[MAXN];
  void init(){
    for (int i = 0; i < N; i++){
      p[i] = i;
      _min[i] = y[i];
      _max[i] = y[i];
      _cnt[i] = 1;
    }
  }
  int find(int u){
    int root = u;
    while (root != p[root]) root = p[root];
    while (u != root) {int v = p[u]; p[u] = root; u = v;}
    return root;
  }
  int join(int u, int v){
    int pu = find(u), pv = find(v);
    if (pu != pv){
      p[pu] = pv;
      _min[pv] = min(_min[pu], _min[pv]);
      _max[pv] = max(_max[pu], _max[pv]);
      _cnt[pv] += _cnt[pu];
    }
    return pv;
  }
};
DisjoinSet ds;
int TestNum;
int main(){
  int T; scanf("%d", &T);
  while (T--){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d %d", &x[i], &y[i]);

    ds.init();
    citysTree.init();
    stateTree.init();

    int M; scanf("%d", &M);
    while (M--){
      char cmd[32]; scanf("%s", cmd);
      if (!strcmp(cmd, "road")){
        int A, B; scanf("%d%d", &A, &B);
        int pA = ds.find(A), pB = ds.find(B);
        if (pA != pB){
          citysTree.gao(ds._min[pA], ds._max[pA] - 1).add(1, 0, maxrange, -ds._cnt[pA], false);
          stateTree.gao(ds._min[pA], ds._max[pA] - 1).add(1, 0, maxrange, -1, false);
          citysTree.gao(ds._min[pB], ds._max[pB] - 1).add(1, 0, maxrange, -ds._cnt[pB], false);
          stateTree.gao(ds._min[pB], ds._max[pB] - 1).add(1, 0, maxrange, -1, false);
          //cout  << citysTree.gao(0, maxrange).query(1, 0, maxrange) << endl;
          int pC = ds.join(A, B); 
          //cout << ds._cnt[pC] << ": " << ds._min[pC] << ", " << ds._max[pC] << endl;
          citysTree.gao(ds._min[pC], ds._max[pC] - 1).add(1, 0, maxrange, ds._cnt[pC], false);
          stateTree.gao(ds._min[pC], ds._max[pC] - 1).add(1, 0, maxrange, 1, false);
          //cout  << citysTree.gao(0, maxrange).query(1, 0, maxrange) << endl;
        }
      }else{
        assert(!strcmp(cmd, "line"));
        double dC; scanf("%lf", &dC);
        int C = floor(dC);
        //cout << C << endl;
        int citysNum = citysTree.gao(C, C).query(1, 0, maxrange);
        int stateNum = stateTree.gao(C, C).query(1, 0, maxrange); 
        printf("%d %d\n", stateNum, citysNum);
      }
    }
  }
}

