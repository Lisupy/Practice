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
const u64 MAGIC = 1000 * 1000 * 1000 + 7;
struct StringHash{
  const string &s;
  vector<u64> hs;
  vector<u64> bs;
  StringHash(const string &_s): s(_s), hs(int(s.size() + 1)), bs(int(s.size() + 1)){
    bs[0] = 1;
    for (size_t i = 1; i <= s.size(); i++){
      hs[i] = hs[i - 1] * MAGIC + s[i - 1];
      bs[i] = bs[i - 1] * MAGIC;
    }
  }
  u64 get(int l, int r){
    return hs[r] - hs[l] * bs[r - l];
  }
};
int solve(string s){
  StringHash strHash(s);
  int len = s.size();
  for (int i = 1; i < len; i++){
    if (len % i == 0){
      if (strHash.get(i, len) == strHash.get(0, len - i)) return len / i;
    }
  }
  return 1;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  string s;
  while (cin >> s && s != ".") {
    cout << solve(s) << endl; 
  }
}

