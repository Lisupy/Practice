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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof
 */
const int MAXN = 25000;
string words[MAXN];
int dp[MAXN];
int L;

int main(){
  while (cin >> words[L]){
    dp[L] = 1;
    L++;
  }
  for (int si = 0; si < L; si++){
    string s = words[si];
    //cout << "#######" << s << endl;
    for (size_t i = 0; i <= s.size(); i++){
      string t = s.substr(0, i) + ' ' + s.substr(i);
      for (char ch = s[i]; ch <= 'z'; ch++){
        t[i] = ch;
        if (t <= s) continue;
        size_t pos = lower_bound(words, words + L, t) - words;
        if (words[pos] == t) dp[pos] = max(dp[pos], dp[si] + 1);
        //if (words[pos] == t) cout << t << endl;
      }
    }
    for (size_t i = 0; i < s.size(); i++){
      string t = s.substr(0, i) + s.substr(i + 1); 
      if (t <= s) continue;
      size_t pos = lower_bound(words, words + L, t) - words;
      if (words[pos] == t) dp[pos] = max(dp[pos], dp[si] + 1);
      //if (words[pos] == t) cout << t << endl;
    }
    for (size_t i = 0; i <= s.size(); i++){
      string t = s;
      for (char ch = s[i] + 1; ch <= 'z'; ch++){
        t[i] = ch;
        if (t <= s) continue;
        size_t pos = lower_bound(words, words + L, t) - words;
        if (words[pos] == t) dp[pos] = max(dp[pos], dp[si] + 1);
        //if (words[pos] == t) cout << t << endl;
      }
    }
  }
  cout << *max_element(dp, dp + L) << endl;
}

