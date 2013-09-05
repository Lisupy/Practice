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
int n;
struct Cipher{
  vector<int> key;
  vector<vector<int> > pos;
  Cipher():key(), pos(){};
  void process(){
    pos.resize(key.size());
    for (int i = 1; i <= n; i++){
      vector<int> &a = pos[i]; a.clear();
      a.push_back(i);
      int t = key[i];
      while (t != i){
        a.push_back(t);
        t = key[t];
      }
    }
  }
  void debug(){
    //for (int i = 1; i <= n; i++){
      //printf("%2d: ", i);
      //for (auto k : pos[i]) printf("%2d", k);printf("\n");
    //}
  }
  string encode(int k, string s){
    while ((int)s.size() < n) s.push_back(' ');
    string t(s);
    for (size_t i = 1; i <= s.size(); i++){
      char c = s[i - 1];
      int idx = pos[i][k % (int)pos[i].size()];
      t[idx - 1] = c;
    }
    return t;
  }
};
Cipher ci;
int TestNum;
int main(){
  while (cin >> n && n) {
    ci.key.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> ci.key[i];
    ci.process();
    //ci.debug();
    int k; 
    while (cin >> k && k){ 
      cin.ignore();
      string s; getline(cin, s);
      //cout << "[" << s << "]" << endl;
      cout << ci.encode(k, s) << endl; 
    }
    cout << endl;
  }
}

