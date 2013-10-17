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

struct Set{
  //set<Set> S;
  vector<int> S;
  int h;
  Set():S(), h(249){};
  Set(int _n): S(), h(_n){};
  Set(const Set& s): S(s.S), h(s.h){};
  //Set& operator=(const Set& s){
    //this->S = s.S;
    //this->h = s.h;
    //return *this;
  //}
  //bool operator<(const Set &s) const{
    //if (S.size() != s.S.size()) return S.size() < s.S.size();
    //return S < s.S;
    //return h < s.h;
  //}
  void display(){
    //printf("{ ");
    //for (auto i : S) {
      //i.display(); 
      //cout << ", ";
    //}
    //printf("} ");
  }
  void rehash(){
    h = 249;
    for (vector<int>::iterator it = S.begin(); it != S.end(); it++){
      h = (h << 7) + h + *it; 
    }
  }
  void Add(const Set& s){
    //S.insert(Set(s.h)); 
    vector<int>::iterator it = lower_bound(S.begin(), S.end(), s.h);
    if (it == S.end() || *it != s.h) S.insert(it, s.h);
    rehash();
  }
  void Union(const Set& s){
    //for (vector<Set>::iterator it = s.S.begin(); it != s.S.end(); it++){
      //S.insert(*it);
    //}
    vector<int> ss(S);
    S.clear();
    set_union(ss.begin(), ss.end(), s.S.begin(), s.S.end(), back_inserter(S));
    rehash();
  }
  void Intersect(const Set &s){
    //vector<Set> ss;
    S.erase(set_intersection(s.S.begin(), s.S.end(), S.begin(), S.end(), S.begin()), S.end()); 
    //S.clear();
    //for (vector<Set>::iterator it = ss.begin(); it != ss.end(); it++){
      //S.insert(*it);
    //}
    rehash();
  }
  
};
void solve(){
  stack<Set> Stack;
  int N; cin >> N;
  while (N--){
    string s; cin >> s;
    if (s == "PUSH"){
      Stack.push(Set());
    }else if (s == "DUP"){
      Stack.push(Stack.top());
    }else if (s == "UNION"){
      Set a = Stack.top(); Stack.pop();
      Stack.top().Union(a);
    }else if (s == "INTERSECT"){
      Set a = Stack.top(); Stack.pop();
      Stack.top().Intersect(a);
    }else if (s == "ADD"){
      Set a = Stack.top(); Stack.pop();
      Stack.top().Add(a);
    }
    cout << Stack.top().S.size() << endl;
    //Stack.top().display();
  }
}

int TestNum;
int main(){
  cin >> TestNum;
  while (TestNum--) {
    solve();
    cout << "***" << endl;
  }
}

