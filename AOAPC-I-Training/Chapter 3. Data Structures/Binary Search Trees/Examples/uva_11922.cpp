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
 * (1 << (31 - __builtin_clz(100) ) == 64;
 */
extern struct Node* nil;
struct Node{
  int key;
  int sz;
  bool rd;
  Node* ch[2];
  explicit Node(int _c): key(_c), sz(1), rd(false) { ch[0] = ch[1] = nil; }
  explicit Node(int _c, int _sz): key(_c), sz(_sz), rd(false) { ch[0] = ch[1] = this; }
  void pushDown(){
    if (rd){
      swap(ch[0], ch[1]);
      ch[0]->rd ^= 1;
      ch[1]->rd ^= 1;
      rd = false;
    }
  }
  void pushUp(){
    sz = ch[0]->sz + ch[1]->sz + 1;
  }
  void debug(string s){
    if (this == nil) return;
    ch[0]->debug(s + "  ");
    printf("%s%d:%d,%d\n", s.c_str(), key, sz, rd); 
    ch[1]->debug(s + "  ");
  }
};
void rotate(Node* &o, int d){
  Node* u = o->ch[d^1];
  o->pushDown();
  u->pushDown();
  o->ch[d^1] = u->ch[d];
  u->ch[d] = o;
  o->pushUp();
  u->pushUp();
  o = u;
}
Node* nil = new Node(255, 0);
Node* getKth(Node* &no, int kth){
  //printf("%d:%d , %d\n", no->key, no->sz, kth);
  if (no == nil){ printf("FFF"); return no;}
  no->pushDown();
  if (no->ch[0]->sz == kth) return no;
  int d = no->ch[0]->sz < kth;
  //printf("%d: d1: %d\n", no->key, d);
  no->ch[d]->pushDown();
  if (d) kth -= no->ch[0]->sz + 1;
  if (no->ch[d]->ch[0]->sz != kth){
    int d2 = no->ch[d]->ch[0]->sz < kth;
    //printf("%d: d2: %d\n", no->key, d2);
    if (d2) kth -= no->ch[d]->ch[0]->sz + 1;
    getKth(no->ch[d]->ch[d2], kth);
    if (d == d2) rotate(no, d^1); 
    else rotate(no->ch[d], d);
  }
  rotate(no, d^1);
  return no;
}
void gao(Node* &o, int a, int b){
  getKth(o, a - 1);
  //printf("\n");
  //o->debug("");
  getKth(o->ch[1], b - a);
  //printf("\n");
  //o->debug("");
  Node* u = o->ch[1];
  u->pushDown();
  o->ch[1] = u->ch[1];
  u->ch[1] = nil;
  u->pushUp();
  o->pushUp();
  getKth(o, o->sz - 1);
  //printf("\n");

  u->rd ^= 1;
  o->ch[1] = u;
  o->pushUp();
  //u->debug("");
  //printf("\n");
  //o->debug("");
}
void clear(Node* &no){
  if (no == nil) return;
  clear(no->ch[0]);
  clear(no->ch[1]);
  delete no;
  no = nil;
}
Node* build(int l, int r){
  if (l > r) return nil;
  if (l == r) return new Node(l);
  int m = (l + r) / 2;
  Node* o = new Node(m);
  o->ch[0] = build(l, m - 1);
  o->ch[1] = build(m + 1, r);
  o->pushUp();
  return o;
}
void inOrder(Node* o){
  if (o == nil) return;
  o->pushDown();
  inOrder(o->ch[0]);
  if (o->key != 0) printf("%d\n", o->key);
  inOrder(o->ch[1]);
}
Node* root = nil;;
int TestNum;
int main(){
  int n, m;scanf("%d %d", &n, &m);
  root = build(0, n);    
  //root->debug("");
  while (m--){
    int a, b; scanf("%d %d", &a, &b); 
    gao(root, a, b);
    //inOrder(root);
  }
  inOrder(root);
}

