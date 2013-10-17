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
const int MAXN = 1024 * 1024;
const int maxnode = 1024 * 16; 
const int RANGE = 128;
int N;
vector<bool> Real[maxnode];
int a[MAXN];
struct IntervalTree{
  int cnt[maxnode];
  bool inversed[maxnode];
  bool delaySet[maxnode]; 
  bool setTo[maxnode];
  int qL, qR;
  int len;
  void reset(int o, int L, int R){
    cnt[o] = inversed[o] = delaySet[o] = setTo[o] = 0;
    if (R - L < RANGE){
      Real[o].clear();
    }else{
      int M = (L + R) / 2;
      int lo = o * 2, ro = o * 2 + 1;
      reset(lo, L,     M);
      reset(ro, M + 1, R);
    }
  }
  void init(int o, int L, int R){
    if (R - L < RANGE){
      if (Real[o].size() == 0) Real[o].resize(R - L + 1);
      cnt[o] = 0;
      for (int i = 0; i <= R - L; i++){
        Real[o][i] = a[len++];
        cnt[o] += Real[o][i];
      }
    }else{
      int M = (L + R) / 2;
      int lo = o * 2, ro = o * 2 + 1;
      init(lo, L,     M);
      init(ro, M + 1, R);
      cnt[o] = cnt[lo] + cnt[ro];
    }
  }
  bool valid(int o, int L, int R){
    assert(L <= R);
    assert(o < maxnode);
    return qL <= R && L <= qR;
  }
  void pushUp(int o, int /*L*/, int /*R*/){
    assert(o < MAXN);
    int lo = o * 2, ro = o * 2 + 1;
    cnt[o] = cnt[lo] + cnt[ro];
  }
  void pushDown(int o, int L, int R){
    int M = (L + R) / 2;
    int lo = o * 2, ro = o * 2 + 1;
    if (delaySet[o]){
      delaySet[o] = false;
      set(lo, L,     M, setTo[o], true);
      set(ro, M + 1, R, setTo[o], true);
    }
    if (inversed[o]){
      inversed[o] = false;
      inverse(lo, L,     M, true);
      inverse(ro, M + 1, R, true);
    }
    pushUp(o, L, R);
  }
  int query(int o, int L, int R){
    if (!valid(o, L, R) ) return 0; 
    if (R - L < RANGE){
      if (Real[o].size() == 0) Real[o].resize(R - L + 1);
      int total = 0;
      for (int i = max(L, qL) - L; i <= min(R, qR) - L; i++){
        total += Real[o][i];
      }
      return total;
    }
    if (qL <= L && R <= qR){
      return cnt[o];
    }else{
      int M = (L + R) / 2;
      int lo = o * 2, ro = o * 2 + 1;
      pushDown(o, L, R);    
      int total = 0;
      total += query(lo, L,     M);
      total += query(ro, M + 1, R);
      return total;
    }
  }
  void set(int o, int L, int R, int v, bool push){
    if (!push && !valid(o, L, R)) return;
    if (R - L < RANGE){
      if (Real[o].size() == 0) Real[o].resize(R - L + 1);
      if (push){
        for (size_t i = 0; i < Real[o].size(); i++) Real[o][i] = v;
        cnt[o] = v ? R - L + 1: 0;
      }else{
        for (int i = max(L, qL) - L; i <= min(R, qR) - L; i++){
          cnt[o] += v - Real[o][i]; 
          Real[o][i] = v;
        }
        //cnt[o] = count(Real[o].begin(), Real[o].end(), true);
      }
      return;
    }
    if (push || (qL <= L && R <= qR)){
      inversed[o] = false;
      delaySet[o] = true;
      setTo[o] = v;
      cnt[o] = v?  R - L + 1 : 0;
    }else{
      int M = (L + R) / 2;
      int lo = o * 2, ro = o * 2 + 1;
      pushDown(o, L, R);
      set(lo, L,     M, v, false);
      set(ro, M + 1, R, v, false);
      pushUp(o, L, R);
    }
  }
  void inverse(int o, int L, int R, bool push){
    if (!push && !valid(o, L, R)) return;
    if (R - L < RANGE){
      if (Real[o].size() == 0) Real[o].resize(R - L + 1);
      if (push){
        for (size_t i = 0; i < Real[o].size(); i++) Real[o][i] = !Real[o][i];
        cnt[o] = R - L + 1 - cnt[o];
        //cnt[o] = count(Real[o].begin(), Real[o].end(), true);
      }else{
        for (int i = max(L, qL) - L; i <= min(R, qR) - L; i++){
          if (Real[o][i]) cnt[o]--;
          else cnt[o]++;
          Real[o][i] = !Real[o][i];
        }
        //cnt[o] = count(Real[o].begin(), Real[o].end(), true);
      }
      return;
    }
    if (push || (qL <= L && R <= qR)){
      inversed[o] = !inversed[o];
      cnt[o] = R - L + 1 - cnt[o];
    }else{
      int M = (L + R) / 2;
      int lo = o * 2, ro = o * 2 + 1;
      pushDown(o, L, R);
      inverse(lo, L,     M, false);
      inverse(ro, M + 1, R, false);
      pushUp(o, L, R);
    }
  }
  IntervalTree& gao(int L, int R){
    len = 0;
    qL = L, qR = R;
    return *this;
  }
};
IntervalTree tree;
int TestNum;
int main(){
  int T; scanf("%d", &T);;
  while (T--){
    printf("Case %d:\n", ++TestNum);
    N = 0;
    //memset(a, 0, sizeof(a));
    int M; scanf("%d", &M);;
    while (M--){
      int t; scanf("%d", &t);
      char s[64]; scanf("%s", s);
      while(t--){
        for (size_t i = 0; s[i]; i++) a[N++] = s[i] - '0';
      }
    }
    assert(N < MAXN);
    //cout << N << endl;
    //for (int i = 0; i < N; i++) cout << a[i]; cout << endl;
    //for (int i = 0; i < N; i++) tree.gao(i, i).set(1, 0, MAXN - 1, a[i], false); 
    tree.gao(0, N).init(1, 0, N);
    int Q; scanf("%d", &Q);
    int queryCnt = 0;
    while (Q--){
      char s[32]; scanf("%s", s);
      int from, to; scanf("%d %d", &from, &to);
      if (s[0] == 'F'){
        tree.gao(from, to).set(1, 0, N, 1, false);
      }else if (s[0] == 'E'){
        tree.gao(from, to).set(1, 0, N, 0, false);
      }else if (s[0] == 'I'){
        tree.gao(from, to).inverse(1, 0, N, false);
      }else{
        assert(s[0] == 'S');
        int ans = tree.gao(from, to).query(1, 0, N);
        printf("Q%d: %d\n", ++queryCnt, ans);
      }
    }
    tree.gao(0, N).reset(1, 0, N);
  }
}

