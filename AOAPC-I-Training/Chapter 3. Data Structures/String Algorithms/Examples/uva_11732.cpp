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
const int maxnode = 1024 * 1024;
const int sigma_size = 26 + 26 + 10 + 1;
struct Trie{
  int ch[maxnode][sigma_size]; 
  i64 isWord[maxnode];
  i64 prefixCnt[maxnode];
  int sz;
  void reset(){
    sz = 1;
    memset(ch, 0, sizeof(ch));
    memset(isWord, 0, sizeof(isWord));
    memset(prefixCnt, 0, sizeof(prefixCnt));
  }
  Trie (): sz(1){ reset();}
  int idx(char c) { 
    if (c == 0)     return 0;
    if (isdigit(c)) return c - '0' + 1;
    if (islower(c)) return c - 'a' + 1 + 10;
    if (isupper(c)) return c - 'A' + 1 + 10 + 26;
    assert(0);
    return 0;
  }
  int newNode() { assert(sz < maxnode); return sz++;}
  void insert(const char* s, int v = 1, int len = 0){
    if (len == 0) len = strlen(s);
    assert(s[len] == 0);
    int u = 0;
    for (int i = 0; i <= len; i++){
      int c = idx(s[i]);
      prefixCnt[u]++;
      if (ch[u][c] == 0) ch[u][c] = newNode();
      u = ch[u][c];
    }
    prefixCnt[u]++;
    isWord[u] = v;
  }
  i64 getAns(int u = 0){
    i64 total = 0;
    //cout << u << ": " << prefixCnt[u] << endl;
    if (u){
      total += prefixCnt[u] * (prefixCnt[u] - 1);
    }else{
      total += prefixCnt[u] * (prefixCnt[u] - 1) / 2;
    }

    for (int i = 0; i < sigma_size; i++){
      if (i == 0){
        if (ch[u][i])total += getAns(ch[u][i]) / 2;
      }else{
        if (ch[u][i])total += getAns(ch[u][i]);
      }
    }
    return total;
  }
};
Trie trie;
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int N; 
  while (cin >> N && N) {
    trie.reset();
    for (int i = 0; i < N; i++){
      string s; cin >> s;
      trie.insert(s.c_str());
    }
    cout << "Case " << ++TestNum << ": " << trie.getAns() << endl;
  }
}

