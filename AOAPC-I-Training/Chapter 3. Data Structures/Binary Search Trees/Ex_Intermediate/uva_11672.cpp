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
extern struct Node* Nil;
size_t poolLen = 0;
struct Node{
  Node* ch[2];
  int val;
  i64 sum;
  int sz;
  explicit Node(int _v):val(_v), sum(_v), sz(1){ch[0] = ch[1] = Nil;}
  Node(): val(0), sum(0), sz(0){ ch[0] = ch[1] = this;}  // only for Nil
  void pushUp(){ 
    if (this == Nil) return;
    sum = ch[0]->sum + ch[1]->sum + val;
    sz  = ch[0]->sz  + ch[1]->sz  + 1; 
  }
  void debug(string s = ""){
    if (this == Nil) return;
    ch[0]->debug(s + "  ");
    printf("%s, val: %d, sum %lld, sz %d\n", s.c_str(), val, sum, sz);
    ch[1]->debug(s + "  ");
    if (s == "") printf("==\n");
  }
  void* operator new(size_t sz){
    static Node pool[2100000];
    assert(sz == sizeof(Node));
    assert(poolLen < sizeof(pool) / sizeof(Node));
    return &pool[poolLen++];
  }
};
Node NilS;
Node* Nil = &NilS;//new Node();
void rotate(Node*& o, bool d){
  Node* u = o->ch[d^1];
  o->ch[d^1] = u->ch[d];
  u->ch[d] = o;
  o->pushUp();
  u->pushUp();
  o = u;
}
void splayKth(Node*& o, int k){
  assert(o != Nil);
  if (o->ch[0]->sz == k) return;
  int d = o->ch[0]->sz < k;
  if (d == 1) k -= o->ch[0]->sz + 1;
  Node* &u = o->ch[d];
  if (u->ch[0]->sz != k){
    int d1 = u->ch[0]->sz < k;
    if (d1 == 1) k -= u->ch[0]->sz + 1;
    splayKth(u->ch[d1], k);
    if (d1 == d) rotate(o, d^1);
    else rotate(o->ch[d], d1^1);
  }
  rotate(o, d^1);
}
Node* build(int a[], int l, int r){
  if (l > r) return Nil;
  int m = (l + r) / 2;
  Node* o = new Node(a[m]);
  o->ch[0] = build(a, l, m - 1);
  o->ch[1] = build(a, m + 1, r);
  o->pushUp();
  return o;
}
Node* root = Nil;
i64 sumGao(int i, int j){
  if (i == j){
    splayKth(root, j);
    return root->val;
  }else{
    splayKth(root, j);
    splayKth(root->ch[0], i);
    return root->ch[0]->ch[1]->sum + root->ch[0]->val + root->val;
  }
}
void insertGao(int i, int n, int r, int m, int a, int c, int b[]){
  for (int j = r; j < n; j++){
    b[j] = (b[j - r] * (i64)a + c) % m;
    c = ((b[j - r] * (i64)a + c) / m) % m;
  }
  //int total = 0;
  //for (int j = 0; j < n; j++){
    //printf("%d ", b[j]);
  //}printf("\n");
  //printf("%d\n", total);
  Node* o = build(b, 0, n - 1);
  splayKth(root, i);
  //root->debug();
  splayKth(root->ch[0], root->ch[0]->sz - 1); 
  //root->debug();
  root->ch[0]->ch[1] = o;
  root->ch[0]->pushUp();
  root->pushUp();
  //root->debug();
}
void splayRemove(Node* &o){
  //if (o == Nil) return;
  //splayRemove(o->ch[0]);
  //splayRemove(o->ch[1]);
  o = Nil;
}
void deleteGao(int i, int j){
  splayKth(root, j + 1);
  splayKth(root->ch[0], i - 1);
  splayRemove(root->ch[0]->ch[1]);
  root->ch[0]->pushUp();
  root->pushUp();
}
void initGao(){
  poolLen = 0;
  int a[2] = {0, 0};
  root = build(a, 0, 1); 
}
void clearGao(){
  splayRemove(root);  
}
int b[2100000];
void solve(int C){
  initGao();
  while (C--){
    //root->debug();
    char cmd[32]; scanf("%s", cmd);
    if (!strcmp(cmd, "sum")){
      int i, j; scanf("%d %d", &i, &j);
      printf("%lld\n", sumGao(i + 1, j + 1));
    }else if (!strcmp(cmd, "insert")){
      int i, n, r, m, a, c; scanf("%d %d %d %d %d %d", &i, &n, &r, &m, &a, &c); 
      for (int j = 0; j < r; j++) scanf("%d", b + j);
      insertGao(i + 1, n, r, m, a, c, b);
    }else if (!strcmp(cmd, "delete")){
      int i, j; scanf("%d %d", &i, &j);
      deleteGao(i + 1, j + 1);
    }else assert(0);
    //root->debug();
  }
  clearGao();
}
int TestNum;
int main(){
  int C;
  while (scanf("%d", &C) && C) {
    printf("Scenario %d:\n", ++TestNum);
    solve(C);
    printf("\n");
  }
}

