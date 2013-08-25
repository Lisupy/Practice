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
const int maxnode = 1<<17;
int new_cnt = 0;
int len = 0;
namespace Treap{
  extern struct Node* nil;
  struct Node{
    Node* ch[2];
    int key;
    int prior;
    int sz;
    Node():key(0), prior(0), sz(0){}
    Node(int _key): key(_key), prior(rand()%INF), sz(1){ch[0] = ch[1] = nil;}
    Node(int _key, int _prior): key(_key), prior(_prior), sz(0){ ch[0] = ch[1] = nil;}
    void renew(){
      sz = ch[0]->sz + ch[1]->sz + 1;
    }
    //void* operator new(size_t sz){
      //static Node pool[60* 1024];
      //assert(len < 60 * 1024);
      //assert(sz == sizeof(Node));
      //return &pool[len++];
    //}
    //void operator delete(void* [>p<]){

    //}
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
    if (o == nil){ new_cnt++; o = new Node(key); }
    else{
      int d = key < o->key ? 0: 1;
      insert(o->ch[d], key); o->renew();
      if (o->ch[d]->prior < o->prior) rotate(o, d^1);
    }
  }
  void remove(Node* &o, int key){
    if (o == nil){ assert(0); return; }
    if (key == o->key) {
      if (o->ch[0] == nil && o->ch[1] == nil) { new_cnt--; delete o; o = nil; }
      else {
        int d = o->ch[0]->prior < o->ch[1]->prior? 0 : 1;
        rotate(o, d^1);
        remove(o->ch[d^1], key);
      }
    }else{
      int d = key < o->key? 0: 1;
      remove(o->ch[d], key);
    }
    if (o != nil) o->renew();
  }

  int getRank(Node* o, int key){
    if (o == nil) return 0;
    //printf("getRank(%d, %d, %d)\n", key, o->key, o->ch[0]->sz);
    if (key <= o->key) return getRank(o->ch[0], key);
    else return o->ch[0]->sz + 1 + getRank(o->ch[1], key);
  }
  void clear(Node* &o){
    if (o == nil) return;
    clear(o->ch[0]);
    clear(o->ch[1]);
    new_cnt--;
    delete o;
    o = nil;
  }
};
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
  void update(const Node &no, int old_v, int new_v){
    if (!overlap(no)) return ;
    //printf("update(%d: %d %d, %d %d\n", no.o, no.L, no.R, old_v, new_v);
    Treap::remove(treap[no.o], old_v);
    //printf("update(%d: %d %d, %d %d\n", no.o, no.L, no.R, old_v, new_v);
    Treap::insert(treap[no.o], new_v);
    if (no.isLeaf()) return;
    update(no.lch(), old_v, new_v);
    update(no.rch(), old_v, new_v);
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
  void clear(const Node& no){
    Treap::clear(treap[no.o]);
    if (no.isLeaf()) return;
    clear(no.lch());
    clear(no.rch());
  }
  SegmentTree& gao(int L, int R){
    qL = L, qR = R;
    return *this;
  }
};
SegmentTree tree;
int getKth(int from, int to, int k){
  SegmentTree::Node root(1, 0, n - 1); 
  int lo = 0, hi = 1000*1024*1024; 
  while (lo < hi){
    int m = (lo + hi + 1) / 2;
    int less_than_m = tree.gao(from, to).getRank(root, m);
    //printf("%d: %d %d, %d\n", m, lo, hi, less_than_m); 
    if (less_than_m > k) hi = m - 1;
    else lo = m;
  }
  return lo;
};
int TestNum;
int main(){
  //Treap::Node* test = Treap::nil;
  //Treap::insert(test, 1);
  //cout << Treap::getRank(test, 2) << endl;
  scanf("%d", &TestNum);
  while (TestNum--){
    scanf("%d", &n);
    int m; scanf("%d", &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    SegmentTree::Node root(1, 0, n - 1); 
    tree.init(root);
    while (m--){
      char buf[32]; scanf("%s", buf);
      if (buf[0] == 'Q'){
        int i, j, k; scanf("%d %d %d", &i, &j, &k);
        printf("%d\n", getKth(i - 1, j - 1, k - 1));
      }else{
        int i, t; scanf("%d %d", &i, &t);
        tree.gao(i -1 , i - 1).update(root, a[i - 1], t);
        a[i - 1] = t;
      }
      //printf("new_cnt: %d\n", new_cnt);
    }
    tree.clear(root);
    //printf("new_cnt: %d\n", new_cnt);
    assert(new_cnt == 0);
    //len = 1;
  }
}




