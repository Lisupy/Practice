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
 * decltype // deprecated
 */
string key(128, ' ' );
string rkey(128, ' ' );
struct ExtendKMP{
  string &s;
  int N;
  vector<int> nxt;
  ExtendKMP(string &_s): s(_s), N(s.size()), nxt(N + 1){
    int j = 0;
    while (j + 1 < N && key[s[j + 1]] == s[j]) j++;
    nxt[1] = j;
    int k = 1;
    int p = j + 1;
    for (int i = 2; i < N; i++){
      int &t = nxt[i];
      t = nxt[i - k];
      t = min(t, p - i);
      t = max(0, t);
      while (i + t < N && key[s[i + t]] == s[t]) t++;
      nxt[i] = t;
      if (i + t > p){
        p = i + t;
        k = i;
      }
    }
  }
  void dbg(){
    //cout << s << endl;
    //for (auto e: nxt) cout << e ; cout << endl;
  }
};
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  cin >> TestNum;
  while (TestNum--) {
    string t; cin >> t;
    for (size_t i = 0; i < t.size(); i++){
      key[i + 'a'] = t[i]; 
      rkey[t[i]] = i + 'a';
    }
    string T; cin >> T;
    ExtendKMP exKmp(T);
    string ans = T;
    for (int i = (T.size() + 1) / 2; i < (int)T.size(); i++){
      if (exKmp.nxt[i] + i == (int)T.size()){
        ans = T.substr(0, i);
        break;
      }
    }
    int k = ans.size();
    for (int j = 0; j < k; j++){
      ans += rkey[ans[j]];
    }
    cout << ans << endl;
  }
}

