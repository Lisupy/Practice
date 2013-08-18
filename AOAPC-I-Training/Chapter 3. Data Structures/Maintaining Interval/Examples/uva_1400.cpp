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
const int MAX_N = 500000;
const int MAX_M = 18;
const i64 INF = 0x7fffffffll;
int a[MAX_N];
int n, m;
struct Node{
  int pos, l, r;
  i64 sum, lsum, rsum, msum;
  int lpos, rpos, mpos_l, mpos_r;
  Node lch(){ return {pos * 2,    l,              (l + r) / 2, -INF, -INF, -INF, -INF, 0, (l + r) / 2 + 1, 0, 0}; } 
  Node rch(){ return {pos * 2 + 1,(l + r) / 2 + 1, r         , -INF, -INF, -INF, -INF, (l + r) / 2, 0, 0, 0}; }
  void dbg(){
    printf("pos: %d(%d, %d), sum: %lld, lsum: %lld(%d), rsum: %lld(%d), msum: %lld(%d, %d)\n", 
      pos, l, r, sum, lsum, lpos, rsum, rpos, msum, mpos_l, mpos_r); 
  }
};
i64 msum[1<<MAX_M];
int mpos_l[1<<MAX_M];
int mpos_r[1<<MAX_M];
i64 sum[1<<MAX_M];
i64 lsum[1<<MAX_M];
int lpos[1<<MAX_M];
i64 rsum[1<<MAX_M];
int rpos[1<<MAX_M];
void reset(){
  memset(msum, 0, sizeof(msum));
  memset(mpos_l, 0, sizeof(mpos_l));
  memset(mpos_r, 0, sizeof(mpos_r));
  memset(sum, 0, sizeof(sum));
  memset(lsum, 0, sizeof(lsum));
  memset(rsum, 0, sizeof(rsum));
  memset(lpos, 0, sizeof(lpos));
  memset(rpos, 0, sizeof(rpos));
}
void query(Node &root, int from, int to){
  //printf("%d %d\n", from, to);
  //root.dbg();
  if (root.l > to) return;
  if (root.r < from) return;
  if (from <= root.l && root.r <= to){
    root.msum = msum[root.pos];
    root.mpos_l = mpos_l[root.pos];
    root.mpos_r = mpos_r[root.pos];
    root.sum = sum[root.pos]; 
    root.lsum = lsum[root.pos]; 
    root.lpos = lpos[root.pos]; 
    root.rsum = rsum[root.pos];
    root.rpos = rpos[root.pos];
    //root.dbg();
    return;
  }
  Node lch = root.lch();
  Node rch = root.rch();
  query(lch, from, to);
  query(rch, from, to);
  root.sum = lch.sum + rch.sum;
  if (lch.r >= from) root.lsum = lch.lsum, root.lpos = lch.lpos;
  if (rch.l <= to && root.lsum < lch.sum + rch.lsum){
    root.lsum = lch.sum + rch.lsum;
    root.lpos = rch.lpos; 
  }
  if (rch.l <= to) root.rsum = rch.rsum, root.rpos = rch.rpos;
  if (lch.r >= from && root.rsum <= rch.sum + lch.rsum){
    root.rsum = rch.sum + lch.rsum;
    root.rpos = lch.rpos;
  }
  if (lch.r >= from) root.msum = lch.msum, root.mpos_l = lch.mpos_l, root.mpos_r = lch.mpos_r;
  if (rch.l <= to && (root.msum < lch.rsum + rch.lsum || 
      (root.msum == lch.sum + rch.lsum && (root.mpos_l > lch.rpos || 
                                           (root.mpos_l == lch.rpos && root.mpos_r > rch.lpos)) ))){
    root.msum = lch.rsum + rch.lsum;
    root.mpos_l = lch.rpos, root.mpos_r = rch.lpos;
  }
  if (rch.l <= to && root.msum < rch.msum){
    root.msum = rch.msum;
    root.mpos_l = rch.mpos_l, root.mpos_r = rch.mpos_r;
  }
  //root.dbg();
}
void init(Node &root){
  assert(root.pos < (1 << MAX_M));
  //root.dbg();
  if (root.l == root.r){
    int pos = root.l;
    if (pos >= n) return;
    sum[root.pos] = a[pos];
    lsum[root.pos] = rsum[root.pos] = msum[root.pos] = sum[root.pos];
    lpos[root.pos] = rpos[root.pos] = mpos_l[root.pos] = mpos_r[root.pos] = pos;
    return;
  }
  Node lch = root.lch();
  Node rch = root.rch();
  init(lch);
  init(rch);
  sum[root.pos] = sum[lch.pos] + sum[rch.pos];
  lsum[root.pos] = lsum[lch.pos]; lpos[root.pos] = lpos[lch.pos];
  if (lsum[root.pos] < sum[lch.pos] + lsum[rch.pos]){
    lsum[root.pos] = sum[lch.pos] + lsum[rch.pos];
    lpos[root.pos] = lpos[rch.pos]; 
  }
  rsum[root.pos] = rsum[rch.pos]; rpos[root.pos] = rpos[rch.pos];
  if (rsum[root.pos] <= sum[rch.pos] + rsum[lch.pos]){
    rsum[root.pos] = sum[rch.pos] + rsum[lch.pos];
    rpos[root.pos] = rpos[lch.pos];
  }
  msum[root.pos] = msum[lch.pos]; mpos_l[root.pos] = mpos_l[lch.pos], mpos_r[root.pos] = mpos_r[lch.pos];
  if (msum[root.pos] < rsum[lch.pos] + lsum[rch.pos] ||
    ( msum[root.pos] == rsum[lch.pos] + lsum[rch.pos] &&
      (mpos_l[root.pos] > rpos[lch.pos] || (mpos_l[root.pos] == rpos[lch.pos] && mpos_r[root.pos] > lpos[rch.pos]))  
     )){
    msum[root.pos] = rsum[lch.pos] + lsum[rch.pos];
    mpos_l[root.pos] = rpos[lch.pos], mpos_r[root.pos] = lpos[rch.pos];
  }
  if (msum[root.pos] < msum[rch.pos]){
    msum[root.pos] = msum[rch.pos];
    mpos_l[root.pos] = mpos_l[rch.pos], mpos_r[root.pos] = mpos_r[rch.pos];
  }
}

int TestNum;
int main(){
  while (scanf("%d %d", &n, &m) != EOF){
    //reset();
    //cout << "Case " << ++TestNum << ":" << endl;
    printf("Case %d:\n", ++TestNum);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    Node r = {1, 0, n - 1, -INF, -INF, -INF, -INF, 0, 0, 0, 0};  
    init(r);
    while (m--){
      int A, B; scanf("%d %d", &A, &B);
      Node root = {1, 0, n - 1, -INF, -INF, -INF, -INF, 0, 0, 0, 0};  
      query(root, A - 1, B - 1);
      //cout << root.mpos_l + 1<< " " << root.mpos_r + 1<< endl;
      printf("%d %d\n", root.mpos_l + 1, root.mpos_r + 1);
    }
  }
}

