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
const int INF = 0x1f1f1f1f;
const int MAXN = 20 * 1024;
const int MAXM = 60 * 1024;
const bool dbg = false;
int n, m;
int weight[MAXN];
namespace Treap{
  extern struct Node* nil;
  struct Node{
    int key;
    int sz;
    int prior;
    Node* ch[2];
    explicit Node(int _key): key(_key), sz(1), prior(rand() % INF){ ch[0] = ch[1] = nil; }
    explicit Node(int _key, int _sz, int _prior): key(_key), sz(_sz), prior(_prior){ 
      ch[0] = ch[1] = this; 
    }
    void renew(){
      if (this == nil) return; 
      sz = ch[0]->sz + ch[1]->sz + 1; 
    }
  };
  Node *nil = new Node(-INF, 0, INF);
  void debug(Node* o, string s = ""){
    if (!dbg) return;
    if (o == nil) return;
    debug(o->ch[0], s + " ");
    printf("%s %d :%d, %d\n", s.c_str(), o->key, o->sz, o->prior); 
    debug(o->ch[1], s + " ");
  }
  void rotate(Node* &o, int d){
    Node* u = o->ch[d^1];
    o->ch[d^1] = u->ch[d];
    u->ch[d] = o;
    o->renew();
    u->renew();
    o = u;
  }
  void clear(Node* &o){
    if (o == nil) return;
    clear(o->ch[0]);
    clear(o->ch[1]);
    delete o;
    o = nil;
  }
  void insert(Node* &o, int key){
    if (o == nil) o = new Node(key);
    else{
      int d = o->key < key ? 1 : 0;
      insert(o->ch[d], key);
      if( o->ch[d]->prior < o->prior) rotate(o, d^1);
      else o->renew();
    }
  }
  void remove(Node* &o, int key){
    if (o == nil) return;
    if (o->key == key){
      if (o->ch[0] == nil && o->ch[1] == nil){
        delete o;
        o = nil;
      }else{
        int d = o->ch[0]->prior < o->ch[1]->prior ? 0 : 1;
        rotate(o, d^1);
        remove(o->ch[d^1], key);
        o->renew();
      }
    }else{
      int d = o->key < key ? 1 : 0;
      remove(o->ch[d], key);
      o->renew();
    }
  }
  int findKth(Node* &o, int kth){
    if (o == nil) return 0;
    if (kth == o->ch[0]->sz) return o->key;
    if (kth < o->ch[0]->sz) return findKth(o->ch[0], kth);
    else return findKth(o->ch[1], kth - o->ch[0]->sz - 1);
  }
  void mergeTo(Node* &from, Node* &to){
    if (from == nil) return;
    insert(to, from->key);
    mergeTo(from->ch[0], to);
    mergeTo(from->ch[1], to);
    delete from;
    from = nil;
  }
};

struct DisJointSet{
  int p[MAXN]; 
  int sz[MAXN];
  void init(){
    for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
  }
  int find(int x){
    int root = x; while (root != p[root]) root = p[root];
    while (root != x) { int nx = p[x]; p[x] = root; x = nx; }
    return root;
  }
  void joinTo(int from, int to){
    int pFrom = find(from), pTo = find(to);
    if (pFrom != pTo){
      p[pFrom] = pTo;
      sz[pTo] += sz[pFrom];
    }
  }
  bool inSame(int x, int y){
    return find(x) == find(y);
  }
};

struct Solution{
  DisJointSet djSet;
  Treap::Node* node[MAXN]; 
  void init(){
    djSet.init();
    for (int i = 1; i <= n; i++) node[i] = Treap::nil;
    for (int i = 1; i <= n; i++) Treap::insert(node[i], weight[i]);
  }
  void clear(){
    for (int i = 1; i <= n; i++) Treap::clear(node[i]);
  }
  void join(int x, int y){
    int px = djSet.find(x), py = djSet.find(y);
    if (px != py){
      if (djSet.sz[px] > djSet.sz[py]) swap(px, py);
      djSet.joinTo(px, py);
      Treap::mergeTo(node[px], node[py]);
      //assert(node[px] == Treap::nil);
    }
  }
  int findKth(int x, int kth){
    int px = djSet.find(x);
    if (dbg)     printf("findkth: %d %d\n", x, kth);
    if (kth <= 0 || node[px]->sz < kth) return 0;
    Treap::debug(node[px]);
    return Treap::findKth(node[px], node[px]->sz - kth);
  }
  void update(int X, int v){
    int px = djSet.find(X);
    Treap::remove(node[px], weight[X]);
    weight[X] = v;
    Treap::insert(node[px], weight[X]);
  }
  void debug(){
    if (!dbg) return;
    printf("%s\n", __FUNCTION__);
    for (int i = 1; i <= n; i++){
      if (djSet.find(i) == i){
        Treap::debug(node[i]);
        printf("\n");
      }
    }
  }
};
Solution sol;
pair<int, int> edges[MAXM];
bool edgesDeleted[MAXM];
struct Cmd{
  char op;
  int X, k;
};
const int MAX_CMD_NUM = 600 * 1024 + MAXM;
Cmd cmds[MAX_CMD_NUM];
int cmdLen;
int TestNum;

double solve(){
  int qNum = 0;
  for (int i = 0; i < cmdLen; i++){
    Cmd &c = cmds[i];
    if (c.op == 'Q') qNum++;
    else if (c.op == 'D') edgesDeleted[c.X] = true;
    else swap(weight[c.X], c.k);
  }
  sol.init();
  for (int i = 0; i < m; i++) if (!edgesDeleted[i]){
    sol.join(edges[i].first, edges[i].second);
  }
  sol.debug();
  double qTotal = 0;
  for (int i = cmdLen - 1; i >= 0; i--){
    Cmd &c = cmds[i];
    if (c.op == 'Q'){
      int s = sol.findKth(c.X, c.k);
      if (dbg)  printf("Q: %d\n", s);
      qTotal += s;
    }else if (c.op == 'D'){
      sol.join(edges[c.X].first, edges[c.X].second);
      if (dbg) printf("Join: %d\n", i);
      sol.debug();
    }else{
      sol.update(c.X, c.k);
      if (dbg) printf("Update: %d\n", i);
      sol.debug();
    }
  }
  sol.clear();
  return double(qTotal) / qNum;
}
int input(){
  scanf("%d%d", &n, &m);
  if (n == 0) return 0;
  for (int i = 1; i <= n; i++) scanf("%d", &weight[i]);
  memset(edgesDeleted, 0, sizeof(edgesDeleted));
  for (int i = 1; i <= m; i++) scanf("%d %d", &edges[i].first, &edges[i].second);
  char op[32];
  cmdLen = 0;
  while (scanf("%s", op) && op[0] != 'E'){
    //assert(cmdLen < MAX_CMD_NUM);
    Cmd& c = cmds[cmdLen++];
    c.op = op[0];
    if (op[0] == 'D') scanf("%d", &c.X);
    else scanf("%d%d", &c.X, &c.k);
  }
  return 1;
}
int main(){
  //return 0;
  //dbg = true;
  //Treap::Node* root = Treap::nil;
  //Treap::insert(root, 1);
  //Treap::insert(root, 4);
  //Treap::insert(root, 3);
  //Treap::insert(root, 2);
  //Treap::insert(root, 5);
  //Treap::insert(root, 6);
  //Treap::insert(root, 7);
  //Treap::insert(root, 8);
  //Treap::insert(root, 8);
  //Treap::insert(root, 8);
  //Treap::debug(root);
  //Treap::remove(root, 3);
  //Treap::debug(root);
  srand(time(NULL));
  while(input()){
    printf("Case %d: %.06lf\n", ++TestNum, solve());
  }
}

