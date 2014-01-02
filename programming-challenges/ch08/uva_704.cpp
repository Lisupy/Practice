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
const double PI = acos(-1);
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
const int MAXSTEP = 8;
struct State{
  char a[21];
  char ops[MAXSTEP];
  int ops_sz;
  void init(vector<int> &_a){
    for (int i = 0; i < 21; i++){
      a[i] = _a[i];
    }
    ops_sz = 0;
  }
  void display(){
    for (int i = 0; i < 21; i++){
      cout << (int)a[i] << ", ";
    }cout << endl;
  }
};
bool operator<(const State& a, const State &b){
  return memcmp(&a.a, &b.a, sizeof(a.a)) < 0;
}
bool operator==(const State& a, const State &b){
  return memcmp(&a.a, &b.a, sizeof(a.a)) == 0;
}
int moves[4][21] = {
// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20
  {10,11,0, 1, 2, 3, 4, 5, 6, 7, 8, 9,12,13,14,15,16,17,18,19,20},
  {0, 1, 2, 3, 4, 5, 6, 7, 8,11,12,13,14,15,16,17,18,19,20, 9,10},
  {2, 3, 4, 5, 6, 7, 8, 9,10,11, 0, 1,12,13,14,15,16,17,18,19,20},
  {0, 1, 2, 3, 4, 5, 6, 7, 8,19,20, 9,10,11,12,13,14,15,16,17,18},
};
State getNewStateSource(State &s, int id){
  State t;
  t.ops_sz = s.ops_sz;
  for (int i = 0; i < t.ops_sz; i++) t.ops[i] = s.ops[i];
  t.ops[t.ops_sz++] = id + '1';
  int *m = moves[id];
  for (int i = 0; i < 21; i++){
    t.a[i] = s.a[m[i]];
  }
  return t;
}
State getNewStateTarget(State &s, int id){
  State t;
  t.ops_sz = s.ops_sz;
  for (int i = 0; i < t.ops_sz; i++) t.ops[i] = s.ops[i];
  t.ops[t.ops_sz++] = id + '1';
  int *m = moves[id];
  for (int i = 0; i < 21; i++){
    t.a[m[i]] = s.a[i];
  }
  //State t1 = getNewStateSource(t, id);
  //assert(t1 == s);
  return t;
}
set<State> fromTarget;
State target;
void gao(State s, set<State> &S, bool isTarget){
  queue<State> Q;
  Q.push(s);
  S.insert(s);
  State (*getNewState)(State &, int)  = isTarget? getNewStateTarget : getNewStateSource;
  while (Q.size()){
    s = Q.front(); Q.pop();
    for (int i = 0; i < 4; i++){
      State t = getNewState(s, i);
      if (S.count(t)) continue;
      S.insert(t);
      if (t.ops_sz == MAXSTEP) continue;
      Q.push(t);
    }
  }
  //cout << S.size() << endl;
  //cout << "Fuck" << endl;
  if (!isTarget) return;
  for (set<State>::iterator it = S.begin(); it != S.end(); it++){
    reverse((char*)it->ops, (char*)it->ops + it->ops_sz);
  }
}
string getCode(const State &s1, const State &s2){
  string a(s1.ops_sz + s2.ops_sz, '0');
  for (int i = 0; i < s1.ops_sz; i++){
    a[i] = s1.ops[i];
  }
  for (int i = 0; i < s2.ops_sz; i++){
    a[i + s1.ops_sz] = s2.ops[i];
  }
  return a;
}
void solve(State source){
  if (source == target){
    cout << "PUZZLE ALREADY SOLVED" << endl;
    return ;
  }
  set<State> fromSource;
  gao(source, fromSource, false);
  string bestCode = "NO SOLUTION WAS FOUND IN 16 STEPS";
  for (set<State>::iterator it = fromSource.begin(); it != fromSource.end(); it++){
    set<State>::iterator it2 = fromTarget.find(*it);
    if (it2 == fromTarget.end()) continue;
    string code = getCode(*it, *it2);
    //cout << code.size() << endl;
    //cout << code << endl;
    if (code.size() < bestCode.size()) bestCode = code;
    else if (code.size() == bestCode.size() && code < bestCode) bestCode = code;
    //if (code < bestCode) bestCode = code;
  }
  //cout << bestCode << endl;
  //target.display();
  //for (auto op: bestCode){
    //int i = op - '1';
    //source = getNewStateSource(source, i);
  //}
  //source.display();
  //target.display();
  //cout << "Done!" << endl;
  cout << bestCode << endl;
}

int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  vector<int> a(24);
  int b[] = {0,3,4,3,0,5,6,5,0,1,2,1,0,7,8,7,0,9,10,9,0,1,2,1};
  for (int i = 0; i < 24; i++) a[i] = b[i];
  target.init(a);
  gao(target, fromTarget, true);
  cin >> TestNum;
  while (TestNum--){
    State source;
    for (int i = 0; i < 24; i++) cin >> a[i];
    source.init(a);
    solve(source);
  }
}

