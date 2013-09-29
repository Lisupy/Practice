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
const int sigma_size = 26;
const int maxnode = 4000 * 128;
const int MOD = 20071027;
struct Trie{
  int ch[maxnode][sigma_size];
  int val[maxnode];
  int sz;
  void reset(){
    sz = 1;
    memset(ch, 0, sizeof(ch));
    memset(val, 0, sizeof(val));
  }
  Trie(): sz(1){ reset();}
  int idx(char c) { return c - 'a';}
  int new_node(){ 
    assert(sz < maxnode); 
    return sz++;
  }
  void insert(const char *s, int v = 1, int len = 0){
    int u = 0;
    if (len == 0) len = strlen(s);
    for (int i = 0; i < len; i++){
      int c = idx(s[i]);
      if (!ch[u][c]) ch[u][c] = new_node();
      u = ch[u][c];
    }
    val[u] = v;
  }
};


string S;
int N;
Trie trie;
vector<string> words;
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (cin >> S) {
    trie.reset();
    cin >> N;
    words.resize(N);
    for (int i = 0; i < N; i++) cin >> words[i];
    for (int i = 0; i < N; i++) trie.insert(words[i].c_str());
    int Slen = S.size();
    vector<int> dp(Slen + 1);
    dp[0] = 1;
    for (int i = 0; i < Slen; i++){
      for (int j = 0, u = 0; i + j < Slen ; j++){ 
        int c = trie.idx(S[i + j]);
        u = trie.ch[u][c];
        if (u == 0) break;
        if (trie.val[u]) dp[i + j + 1] = (dp[i + j + 1] + dp[i]) % MOD; 
      }
    }
    cout << "Case " << ++TestNum << ": " << dp[Slen] << endl;
  }
}

