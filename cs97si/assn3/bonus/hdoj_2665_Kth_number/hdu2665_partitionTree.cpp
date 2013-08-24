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
const int maxnode = 128 * 1024 * 2;
int a[maxnode/2];
int ra[maxnode/2];
int n;
struct PartitionTree{
  struct Node{
    int o, L, R;
    Node(int _o, int _L, int _R): o(_o), L(_L), R(_R){};
    int m()  const { return (L + R) / 2; }
    int lo() const { return o * 2; }
    int ro() const { return o * 2 + 1 ; }
    int sz() const { return R - L + 1; }
    Node lch() const { return Node(lo(), L, m()); }
    Node rch() const { return Node(ro(), m() + 1, R); }
    bool isLeaf() const { return L == R; }
  };
  int qL, qR;
  vector<int> rnk[maxnode];
  vector<int> sum[maxnode];
  PartitionTree(): qL(0), qR(0){}
  bool overlap(const Node &no){
    return qL <= no.R && no.L <= qR;
  }
  bool contain(const Node &no){
    return qL <= no.L && no.R <= qR;
  }
  void reset(const Node &no){
    rnk[no.o].clear();
    sum[no.o].clear();
    if (no.isLeaf()) return;
    reset(no.lch());
    reset(no.rch());
  }
  void _init(const Node &no){
    if (no.isLeaf()){
      rnk[no.o].push_back(ra[no.L]);
    }else{
      _init(no.lch()); 
      _init(no.rch());
      rnk[no.o].resize(no.sz());
      sum[no.o].resize(no.sz());
      int len = 0;
      int* s = sum[no.o].data();
      int* ns = rnk[no.o].data();
      int llen = rnk[no.lo()].size();
      int* lns = rnk[no.lo()].data();
      int rlen = rnk[no.ro()].size();
      int* rns = rnk[no.ro()].data();
      int l = 0, r = 0;
      while (l < llen && r < rlen){
        if (lns[l] <= rns[r]) s[len] = 1, ns[len++] = lns[l++];
        else ns[len ++] = rns[r++];
      }
      while (l < llen) s[len] = 1, ns[len++] = lns[l++];
      while (r < rlen) ns[len++] = rns[r++];
      for (int i = 1; i < len; i++) s[i] += s[i - 1]; 
    }
  }
  int query(const Node &no, int kth){
    //if (!overlap(no)) return 0;
    if (no.isLeaf()){
      return a[rnk[no.o][0]];
    }else{
      int* s = sum[no.o].data();
      int bToLeft  = qL == no.L ? 0 : s[qL - no.L - 1];
      int bToRight = qL == no.L ? 0 : qL - no.L - s[qL - no.L - 1];
      int toLchCnt = qL == no.L ? s[qR - no.L] : s[qR - no.L] - s[qL - no.L - 1];
      int toRchCnt = qR - qL + 1 - toLchCnt;
      if (kth <= toLchCnt){
        qL = no.L + bToLeft;
        qR = qL + toLchCnt - 1;
        return query(no.lch(), kth); 
      }else{
        qL = no.m() + 1 + bToRight;
        qR = qL + toRchCnt - 1;
        return query(no.rch(), kth - toLchCnt); 
      }
    }
  }
  PartitionTree& gao(int L, int R){
    qL = L, qR = R;
    return *this;
  }
};
int Min, Max;
int m;
PartitionTree tree;
int bsolve(int from, int to, int k){
  PartitionTree::Node root(1, 0, n - 1);
  return tree.gao(from, to).query(root, k);
}
struct LessRank{
  int *arr;
  LessRank(int *_a):arr(_a){};
  bool operator()(const int lhs, const int rhs){
    return arr[lhs] < arr[rhs];
  }
};
int TestNum;
int main(){
  //freopen("16", "r", stdin);
  scanf("%d", &TestNum);
  while(TestNum--){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) ra[i] = i;
    //stable_sort(ra, ra + n, LessRank(a)); 
    sort(ra, ra + n, LessRank(a));
    //for (int i = 0; i < n; i++) printf("%2d", ra[i]); printf("\n");
    //for (int i = 0; i < n; i++) printf("%2d", a[ra[i]]); printf("\n");

    PartitionTree::Node root(1, 0, n - 1);
    Min = *min_element(a, a + n);
    Max = *max_element(a, a + n);  
    tree._init(root);
    while (m--){
      int i, j, k; scanf("%d %d %d", &i, &j, &k);
      printf("%d\n", bsolve(i - 1, j - 1, k));
    }
    tree.reset(root);
  }
}

