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
const int maxnode = 128 * 1024;
const int bsz = 32 * 8;
int bnum;
int n;
struct MergeTree{
  int a[maxnode];
  int sa[maxnode];// sorted a
  void _init(){
    memcpy(sa, a, sizeof(int) * n);
    for (int from = 0; from < n; from += bsz){
      int to = min(n, from + bsz);
      sort(sa + from, sa + to);
    }
    //for (int i = 0; i < n; i++) printf("%d ", sa[i]); printf("\n");
    //for (int i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
  }
  //[from, to)
  int query(int from, int to, int v){
    int total = 0;
    int from_i = from / bsz;
    int to_i = to / bsz;
    if (from_i == to_i){
      for (int i = from; i < to; i++) if (a[i] < v) total++;
      return total;
    }else{
      for (int i = from; i < (from_i + 1)* bsz; i++) if (a[i] < v) total++;
      for (int i = (from_i + 1); i < to_i; i++){
        int* A = sa + i * bsz;
        total += lower_bound(A, A + bsz, v) - A;
      }
      for (int i = to_i * bsz; i < to; i++) if (a[i] < v) total++;
      return total;
    }
  } 
};
int Min, Max;
int m;
MergeTree tree;
int bsolve(int from, int to, int k){
  //MergeTree::Node root(1, 0, n - 1);
  int lo = Min, hi = Max; //[lo,hi]
  while (lo < hi){
    int mid = (lo + hi + 1) / 2;
    int less_than_mid_cnt = tree.query(from, to + 1, mid);
    //printf("%d: %d\n", mid, less_than_mid_cnt);
    if (less_than_mid_cnt > k) hi = mid - 1;
    else if (less_than_mid_cnt <= k) lo = mid; 
  }
  return lo;
}
int TestNum;
int main(){
  scanf("%d", &TestNum);
  while (TestNum--){
    scanf("%d %d", &n, &m);
    bnum = n / bsz;
    for (int i = 0; i < n; i++) scanf("%d", &tree.a[i]);
    Min = *min_element(tree.a, tree.a + n);
    Max = *max_element(tree.a, tree.a + n);
    tree._init();
    while (m--){
      int i, j, k; scanf("%d %d %d", &i, &j, &k);
      printf("%d\n", bsolve(i - 1, j - 1, k - 1));
    }
  }
}

