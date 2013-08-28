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
const i64 MOD = 3214567 ;
i64 powMod[400 * 1024];
void powMod_init(){
  powMod[0] = 1;
  for (int i = 1; i < 400 * 1024; i++){
    powMod[i] = (powMod[i - 1] * 13)%MOD;
  }
}

extern struct Node* nil;
struct Node{
  int c;
  i64 has, rhas;
  int sz;
  int rd;
  Node* ch[2];
  explicit Node(int _c): c(_c), has(_c + 1), rhas(_c + 1), sz(1), rd(0){ch[0] = ch[1] = nil; }
  explicit Node(): c(0), has(0), rhas(0), sz(0), rd(0) {ch[0] = ch[1] = this;}
  void pushUp(){
    if (this == nil) return;
    sz = ch[0]->sz + ch[1]->sz + 1;
    has = ch[0]->has * powMod[ch[1]->sz + 1] + (c + 1)* powMod[ch[1]->sz] + ch[1]->has;
    has %= MOD;
    rhas = ch[1]->rhas * powMod[ch[0]->sz + 1] + (c + 1)* powMod[ch[0]->sz] + ch[0]->rhas;
    rhas %= MOD;
  }
  void pushDown(){
    if (rd){
      swap(ch[0], ch[1]);
      ch[0]->rd ^= 1;
      swap(ch[0]->has, ch[0]->rhas);
      ch[1]->rd ^= 1;
      swap(ch[1]->has, ch[1]->rhas);
      rd = 0;
    }
  }
  void debug(string s = ""){
    if (this == nil) return;
    ch[0]->debug(s + "  ");
    printf("%s%d:%d,%d,has(%lld,%lld)\n", s.c_str(), c, sz, rd, has, rhas);
    ch[1]->debug(s + "  ");
  }
};
Node* nil = new Node;

void rotate(Node*& o, int d){
  Node* u = o->ch[d^1];
  o->pushDown();
  u->pushDown();
  o->ch[d^1] = u->ch[d];
  u->ch[d] = o;
  o->pushUp();
  u->pushUp();
  o = u;
}

void findKth(Node*& o, int kth){
  //printf("%d:%d\n", o->sz, kth);
  if (o == nil) return ;
  o->pushDown();
  if (o->ch[0]->sz == kth) return ;
  int d = o->ch[0]->sz < kth;
  if (d) kth -= o->ch[0]->sz + 1;
  Node* u = o->ch[d];
  u->pushDown(); 
  if (u->ch[0]->sz != kth){
    int d2 = u->ch[0]->sz < kth;
    if (d2) kth -= u->ch[0]->sz + 1;
    findKth(u->ch[d2], kth);
    if (d != d2) rotate(o->ch[d], d2^1);
    else rotate(o, d^1);
  }
  rotate(o, d^1);
}

void gao1(Node*& o, int p, int c){
  findKth(o, p);
  //o->debug(""); printf("\n");
  o->pushDown();
  Node* u = new Node(c);
  u->ch[1] = o->ch[1];
  u->pushUp();
  o->ch[1] = u;
  o->pushUp();
}
void gao2(Node*&o, int p){
  findKth(o, p - 1);
  o->pushDown();
  findKth(o->ch[1], 0);
  o->ch[1]->pushDown();
  Node* u = o->ch[1];
  o->ch[1] = o->ch[1]->ch[1];
  o->ch[1]->pushUp();
  o->pushUp();
  delete u;
}
void gao3(Node*&o, int p1, int p2){
  findKth(o, p1 - 1);
  o->pushDown();
  findKth(o->ch[1], p2 - p1 + 1);
  o->ch[1]->pushDown();
  o->ch[1]->ch[0]->rd ^= 1;
  swap(o->ch[1]->ch[0]->has, o->ch[1]->ch[0]->rhas);
  o->ch[1]->pushUp();
  o->pushUp();
}
i64 getPrefix(Node*&o, int p1, int l){
  findKth(o, p1 - 1);
  o->pushDown();
  o->ch[1]->pushDown();
  findKth(o->ch[1], l);
  o->ch[1]->pushDown();
  o->ch[1]->ch[0]->pushDown();
  //printf("prfix(%d, %d)\n", p1, l);
  //o->ch[1]->ch[0]->debug();
  return o->ch[1]->ch[0]->has;
}
bool isValid(Node*&o, int p1, int p2, int l){
  return getPrefix(o, p1, l) == getPrefix(o, p2, l);
}
int gao4(Node*&o, int p1, int p2){
  int lo = 0, hi = o->sz - p2 - 1;
  while (lo < hi){
    int m = (lo + hi + 1) / 2;
    if (isValid(o, p1, p2, m)) lo = m;
    else hi = m - 1;
  }
  return lo;
}
Node* build(char* b, int n){
  //printf("%s %d\n", b, n);
  if (n == 0 || n == -1)return nil;
  Node* o = new Node(b[n / 2] - '0');
  b[n/2] = 0;
  o->ch[0] = build(b, n / 2);
  o->ch[1] = build(b + n / 2 + 1, n - (n / 2 + 1));
  o->pushUp();
  return o;
}
void clear(Node* &o){
  if (o == nil) return;
  clear(o->ch[0]);
  clear(o->ch[1]);
  delete o;
  o = nil;
}
Node* root = nil;
char buf[200*1024] = "0";
int TestNum;
int main(){
  powMod_init();
  //return 0;
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF){
    scanf("%s", buf + 1);
    buf[n + 1] = '0';
    buf[n + 2] = 0;
    root = build(buf, n + 2);
    //root->debug(""); printf("\n");
    while (m--){
      int op; scanf("%d", &op);
      if (op == 1){
        int p, c; scanf("%d %d", &p, &c);
        gao1(root, p, c);
      }else if (op == 2){
        int p; scanf("%d", &p);
        gao2(root, p);
      }else if (op == 3){
        int p1, p2; scanf("%d %d", &p1, &p2);
        gao3(root, p1, p2);
      }else if (op == 4){
        int p1, p2; scanf("%d %d", &p1, &p2);
        printf("%d\n", gao4(root, p1, p2));
      }
      //root->debug(""); printf("\n");
    }
    clear(root);
  }
}

