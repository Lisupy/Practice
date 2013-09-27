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
const int MOD = 10007;
struct ExtendKMP{
  string s;
  int n;
  vector<int> nxt;
  ExtendKMP(string &_s): s(_s), n(s.size()), nxt(n + 1){
    nxt[0] = n;
    int p = 0;
    while (p + 1 < n && s[p + 1] == s[p]) p++;
    nxt[1] = p;
    int k = 1;
    for (int i = 2; i < n; i++){
      int &matchLen = nxt[i];
      matchLen = min(nxt[i - k], p - i);
      matchLen = max(0, matchLen);
      while (i + matchLen < n && s[matchLen] == s[i + matchLen]) matchLen++;
      if (p < i + matchLen){
        p = i + matchLen;
        k = i;
      }
    }
  }
  void dbg(){
    //for (auto e : nxt) cout << e << " "; cout << endl;
  }
};
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  cin >> TestNum;
  while (TestNum--) {
    int n; cin >> n;
    string s; cin >> s;
    ExtendKMP exkmp(s);
    exkmp.dbg();
    //int ans = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) ans = (ans + exkmp.nxt[i]) % MOD;
    cout << ans << endl;
  }
}

