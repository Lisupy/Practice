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
const int MAXN = 128*1024;
int N;

extern struct Node* Nil;
struct Node{
  Node* fa;
  Node* ch[2];
  int sz;
  bool rev;
  int key;
  Node():fa(Nil), sz(1), rev(false), key(0){ ch[1] = ch[0] = Nil;}
  explicit Node(int _sz): fa(Nil), sz(_sz), rev(false), key(0) { ch[1] = ch[0] = this; }
  void pushDown(){
    if (this == Nil) return;
    if (rev){
      swap(ch[0], ch[1]);
      rev = false;
      ch[0]->rev ^= 1;
      ch[1]->rev ^= 1;
    }
  }
  void pushUp(){
    if (this == Nil) return;
    sz = ch[0]->sz + ch[1]->sz + 1;
  }
  void debug(string s = "") const {
    if (this == Nil) return;
    ch[0]->debug(s + "  ");
    printf("%s key: %d, sz: %d, rev:%d\n", s.c_str(), key, sz, rev);
    ch[1]->debug(s + "  ");
  }
};
Node *Nil = new Node(0);
Node nodes[MAXN];
int a[MAXN];
int ra[MAXN];
Node* root;
Node* buildTree(Node* fa, int l, int r){
  if (l > r) return Nil;
  int m = (l + r) / 2;
  int key = a[m];
  Node* o = &nodes[key];
  o->key = key;
  o->sz = 0;
  o->rev = false;
  o->fa = fa;
  o->ch[0] = buildTree(o, l, m - 1);
  o->ch[1] = buildTree(o, m + 1, r);
  o->pushUp();
  return o;
}
void clearReverse(Node* o){
  o->pushDown();
  if (o == root) return;
  clearReverse(o->fa);
  o->pushDown();
}

void rotate(Node* &o, int d){
  assert(!o->rev);
  Node* u = o->ch[d^1];
  Node* fo = o->fa;   o->ch[d^1] = u->ch[d];  u->ch[d]->fa = o;
  u->ch[d] = o;           o->fa = u;
  o->pushUp();
  u->pushUp();
  swap(o, u);             o->fa = fo;
}
int getKth(Node* o){
  assert(o != Nil);
  if (o == root) return o->ch[0]->sz; 
  if (o->fa->ch[0] == o) return getKth(o->fa) - o->ch[1]->sz - 1;
  else return getKth(o->fa) + o->ch[0]->sz + 1;
}
void findKth(Node* &o, int k){
  assert(k >= 0);
  if (o == Nil) return;
  o->pushDown();
  if (k == o->ch[0]->sz) return;  
  int d = o->ch[0]->sz < k;
  if (d) k -= o->ch[0]->sz + 1;
  Node* &p = o->ch[d];
  p->pushDown();
  if (p->ch[0]->sz != k){
    int d2 = p->ch[0]->sz < k;
    if (d2) k -= p->ch[0]->sz + 1;
    findKth(p->ch[d2], k);
    if (d == d2) rotate(o, d^1); 
    else rotate(o->ch[d], d2^1);
  }
  rotate(o, d^1);
}
void gao(){
  ra[N + 1] = N + 1;
  a[N + 1] = N + 1;
  root = buildTree(Nil, 1, N + 1);
  for (int i = 1; i <= N; i++){
    clearReverse(&nodes[i]);
    int k = getKth(&nodes[i]);
    if (i != 1) printf(" ");
    printf("%d", k + i);
    findKth(root, k + 1);
    root->pushDown();
    root->ch[0]->rev ^= 1;
    findKth(root, 0);
    root = root->ch[1];
    //getchar();
  }
  printf("\n");
}
bool rankLess(int lhs, int rhs){
  if (a[lhs] != a[rhs] ) return a[lhs] < a[rhs];
  return lhs < rhs;
}
void preProcess(){
  for (int i = 1; i <= N; i++) ra[i] = i;
  sort(ra + 1, ra + 1 + N, rankLess);
  //for (int i = 1; i <= N; i++) cout << ra[i] << endl;
  for (int i = 1; i <= N; i++) a[ra[i]] = i;
}
int TestNum;
int main(){
  //cout << Nil->sz << endl;
  while (scanf("%d", &N) && N) {
    for (int i = 1; i <= N; i++)  scanf("%d", &a[i]); 
    preProcess();
    gao();
  }
}

