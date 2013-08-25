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
//static Treap::Node* nil = NULL;
namespace Treap{
  extern struct Node* nil;
  struct Node{
    Node* ch[2];
    int key;
    int priority;
    int value;
    explicit Node(int _v, int _w): key(_v), priority(rand() % 65535), value(_w){ ch[0] = ch[1] = nil;}
    explicit Node(int _v, int _r, int _w): key(_v), priority(_r), value(_w) { ch[0] = ch[1] = nil;}
  };
  Node *nil = new Node(-INF, INF, 0); 
  static void rotate(Node*& o, int d){
    Node* u = o->ch[d^1]; o->ch[d^1] = u->ch[d]; u->ch[d] = o; o = u;
  }
  static void insert(Node* &o, int key, int value){
    if (o == nil) o = new Node(key, value);
    else{
      int d = key < o->key ? 0 : 1;
      insert(o->ch[d], key, value);
      if (o->ch[d]->priority < o->priority) rotate(o, d^1);
    }
  }
  static void remove(Node* &o, int key){
    if (o->key == key){
      if (o->ch[0] == nil && o->ch[1] == nil){ delete o; o = nil;}
      else{
        int d = o->ch[0]->priority < o->ch[1]->priority? 0 : 1;
        rotate(o, d^1);
        remove(o->ch[d^1], key);
      }
    }else{
      int d = key < o->key ? 0: 1;
      remove(o->ch[d], key);
      assert( !(o->ch[d]->priority < o->priority) );
      if (o->ch[d]->priority < o->priority) rotate(o, d^1);
    }
  }
  static Node* findMax(Node* o){
    return o->ch[1] != nil ? findMax(o->ch[1]) : o;
  }
  static Node* findMin(Node* o){
    return o->ch[0] != nil ? findMin(o->ch[0]) : o;
  }
};
//static Treap::Node Nil( = {NULL, NULL, -INF, INF};

Treap::Node* root;
int TestNum;
int main(){
  //cout << RAND_MAX << endl;
  //freopen("b.in", "priority", stdin);
  root = Treap::nil;
  int op;
  //int cnt = 0;
  while (scanf("%d", &op) && op){
    //cout << "[" << ++cnt << "]" << endl;
    if (op == 1){
      int K, P; scanf("%d%d", &K, &P);
      Treap::insert(root, P, K);
    }else if (op == 2){
      if (root == Treap::nil) printf("0\n");
      else{
        Treap::Node* no = Treap::findMax(root);
        printf("%d\n", no->value);
        Treap::remove(root, no->key);
      }
    }else{
      if (root == Treap::nil) printf("0\n");
      else{
        Treap::Node* no = Treap::findMin(root);
        printf("%d\n", no->value);
        Treap::remove(root, no->key);
      }
    }
  }
}

