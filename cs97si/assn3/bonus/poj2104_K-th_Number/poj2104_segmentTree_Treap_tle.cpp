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
namespace Treap{
  extern struct Node* nil;
  struct Node{
    Node* ch[2];
    int key;
    int prior;
    int sz;
    Node(int _key): key(_key), prior(rand()%INF), sz(1){ch[0] = ch[1] = nil;}
    Node(int _key, int _prior): key(_key), prior(_prior), sz(0){ ch[0] = ch[1] = nil;}
    void renew(){
      sz = ch[0]->sz + ch[1]->sz + 1;
    }
  };
  struct Node* nil = new Node(-INF, INF);
  void rotate(Node* &o, int d){
    Node* u = o->ch[d^1];
    o->ch[d^1] = u->ch[d]; o->renew();
    u->ch[d] = o; u->renew();
    o = u;
  }
  void insert(Node* &o, int key){
    //printf("insert(%d %d %d)\n", key);
    if (o == nil) o = new Node(key);
    else{
      int d = key < o->key ? 0: 1;
      insert(o->ch[d], key); o->renew();
      if (o->ch[d]->prior < o->prior) rotate(o, d^1);
    }
  }
  // kth in [0....)
  int getRank(Node* o, int key){
    if (o == nil) return 0;
    //printf("getRank(%d, %d, %d)\n", key, o->key, o->ch[0]->sz);
    if (key <= o->key) return getRank(o->ch[0], key);
    else return o->ch[0]->sz + 1 + getRank(o->ch[1], key);
  }
};
const int maxnode = 128 * 1024 * 2;
int a[maxnode];
int n;
struct SegmentTree{
  struct Node{
    int o, L, R;
    int m() const { return (L + R) / 2; }
    int lo() const { return o * 2;}
    int ro() const { return o * 2 + 1; }
    Node(int _o, int _L, int _R): o(_o), L(_L), R(_R){}
    Node lch() const { return Node(lo(), L, m());}
    Node rch() const { return Node(ro(), m() + 1, R);}
    bool isLeaf() const { return L == R; }
  };
  int qL, qR;
  Treap::Node* treap[maxnode];
  bool overlap(const Node &no){return qL <= no.R && no.L <= qR;}
  bool contain(const Node &no){return qL <= no.L && no.R <= qR;}
  int getRank(const Node &no, int key){
    if (!overlap(no)) return 0;
    if (contain(no)){
      int total = Treap::getRank(treap[no.o], key);
      //printf("getRank(%d, %d: %d %d, %d\n", key, no.o, no.L, no.R, total); 
      return total;
    }else{
      int total = 0;
      total += getRank(no.lch(), key);
      total += getRank(no.rch(), key);
      return total;
    }
  }
  void init(const Node& no){
    treap[no.o] = Treap::nil;
    if (no.isLeaf()){
      Treap::insert(treap[no.o], a[no.L]);
      //printf("\n");
    }else{
      init(no.lch());
      init(no.rch());
      for (int i = no.L; i <= no.R; i++){
        Treap::insert(treap[no.o], a[i]);
      }
      //printf("\n");
    }
  }
  SegmentTree& gao(int L, int R){
    qL = L, qR = R;
    return *this;
  }
};
SegmentTree tree;
int Min ;
int Max ;
int getKth(int from, int to, int k){
  SegmentTree::Node root(1, 0, n - 1); 
  int lo = Min, hi = Max;
  while (lo < hi){
    int m = (lo + hi + 1) / 2;
    int less_than_m = tree.gao(from, to).getRank(root, m);
    //printf("%d: %d %d, %d\n", m, lo, hi, less_than_m); 
    if (less_than_m > k) hi = m - 1;
    else lo = m;
  }
  return lo;
};
int main(){
  //Treap::Node* test = Treap::nil;
  //Treap::insert(test, 1);
  //cout << Treap::getRank(test, 2) << endl;
  scanf("%d", &n);
  int m; scanf("%d", &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  Min = *min_element(a, a + n);
  Max = *max_element(a, a + n);
  SegmentTree::Node root(1, 0, n - 1); 
  tree.init(root);
  while (m--){
    int i, j, k; scanf("%d %d %d", &i, &j, &k);
    printf("%d\n", getKth(i - 1, j - 1, k - 1));
  }
}




