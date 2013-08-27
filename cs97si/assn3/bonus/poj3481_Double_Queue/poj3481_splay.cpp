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
//static splay::Node* nil = NULL;
extern struct SplayNode* nil;
struct SplayNode{
  int key;
  int value;
  SplayNode* ch[2], *father;
  SplayNode(int _key, int _value): key(_key), value(_value), father(nil) { ch[0] = ch[1] = nil; }
  SplayNode():key(0), value(0), father(this) { ch[0] = ch[1] = this; }
  int side(){ return father->ch[0] == this? 0 : 1; }
  SplayNode* zig(){
    //printf("zig(%d)\n", key);
    //getchar();
    int d = side();
    SplayNode* fa = father;
    SplayNode* ffa = father->father;
    ffa->ch[fa->side()] = this; father = ffa;
    fa->ch[d] = ch[d^1]; ch[d^1]->father = fa;
    ch[d^1] = fa; fa->father = this;
    return this;
  }
};
SplayNode *nil = new SplayNode();

struct Splay{
  SplayNode* root;
  Splay(): root(nil) {}
  SplayNode* splay(SplayNode* o){
    if (o->father == nil) return root = o;
    while (o->father != nil){
      if (o->father->father == nil) return root = o->zig();
      if (o->side() == o->father->side()){
        o->father->zig(); o->zig();
        //o->zig(); o->zig();
      }else{
        //o->father->zig(); o->zig();
        o->zig(); o->zig();
      }
    }
    return root = o;
  }
  SplayNode* insert(int key, int value){
    SplayNode* no = new SplayNode(key, value);
    while (true){
      //printf("%p, %p\n", root, nil);
      //getchar();
      if (root == nil) return root = no;
      int d = key <= root->key? 0 : 1;
      if (root->ch[d] == nil){
        root->ch[d] = no; no->father = root;
        return splay(no);
      }else{
        root = root->ch[d];
      }
    }
    assert(0);
  }
  SplayNode* find(int key){
    while (true){
      if (key == root->key) return splay(root);
      int d = key < root->key? 0 : 1;
      if (root->ch[d] == nil) return splay(root);
      else root = root->ch[d];
    }
    assert(0);
  }
  SplayNode* findMin(){
    while (root->ch[0] != nil) root = root->ch[0];
    return splay(root);
  }
  SplayNode* findMax(){
    while (root->ch[1] != nil) root = root->ch[1];
    return splay(root);
  }
  SplayNode* remove(SplayNode* o){
    assert(o == root);
    o->ch[1]->father = nil;
    o->ch[0]->father = nil;
    root = o->ch[1];
    if (o->ch[1] != nil){
      root = findMin();
      root->ch[0] = o->ch[0]; 
      delete o;
      return root;
    }else{
      root = o->ch[0];
      delete o;
      return root;
    }
  }
  bool empty() const { return root == nil; }
};

Splay splay;
int TestNum;
int main(){
  //cout << RAND_MAX << endl;
  //freopen("b.in", "priority", stdin);
  int op;
  int cnt = 0;
  while (scanf("%d", &op) != EOF && op){
    cnt++;
    //cout << "[" << ++cnt << "]" << endl;
    if (op == 1){
      int K, P; scanf("%d%d", &K, &P);
      splay.insert(P, K);
    }else if (op == 2){
      if (splay.empty()) printf("0\n");
      else{
        SplayNode* no = splay.findMax();
        printf("%d\n", no->value);
        splay.remove(no);
      }
    }else{
      if (splay.empty()) printf("0\n");
      else{
        SplayNode* no = splay.findMin();
        printf("%d\n", no->value);
        splay.remove(no);
      }
    }
  }
  //for (int i = 0; i< cnt; i++){
    //splay.findMin(), splay.findMax();
  //}
  //cout << cnt << endl;
}
