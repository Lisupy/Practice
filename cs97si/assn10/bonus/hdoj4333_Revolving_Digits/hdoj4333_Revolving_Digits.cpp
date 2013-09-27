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
struct ExtendKMP{
  string &s;
  int n;
  vector<int> nxt;
  ExtendKMP(string _s): s(_s), n(s.size()), nxt(n){
    nxt[0] = n;
    //int &t = nxt[1];
    //while (t + 1 < n && s[t] == s[t + 1]) t++;
    int p = 0, k = 0;
    for (int i = 1; i < n; i++){
      int &h = nxt[i];
      h = min(nxt[i - k], p - i);
      h = max(h, 0);
      while (i + h < n && s[h] == s[i + h]) h++;
      if (p < i + h) p = i + h, k = i;
    }
  }
};

int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int T; cin >> T;
  while (T--) {
    string s; cin >> s;
    int len = s.size();
    string s2 = s + s;
    ExtendKMP exkmp(s2);
    int L = 0, E = 1, G = 0;
    for (int i = 1; i < len; i++){
      if (exkmp.nxt[i] >= len) break; 
      else if (s2[i + exkmp.nxt[i]] > s2[exkmp.nxt[i]]) G++; 
      else if (s2[i + exkmp.nxt[i]] < s2[exkmp.nxt[i]]) L++;
    }
    printf("Case %d: %d %d %d\n", ++TestNum, L, E, G);
  }
}

