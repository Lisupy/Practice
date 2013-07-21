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
const int INF = 0xfffffff;
const int MAXN = 1 << 12;
int cache[MAXN];
int dfs(int mask){
  int &res = cache[mask];
  if (res != -1) return res;
  res = __builtin_popcount(mask);
  for (int i = 0; i + 3 <= 12; i++){
    if (((mask >> i) & 7) == 6){
      res = min(res, dfs(mask ^ (7 << i)));
    }
    if (((mask >> i) & 7) == 3){
      res = min(res, dfs(mask ^ (7 << i)));
    }
  }
  return res;
}

int maskFromStr(string s){
  int mask = 0;
  for (size_t i = 0; i < s.size(); i++){
    if (s[i] == 'o'){
      mask |= 1 << i;
    }
  }
  return mask;
}


int main(){
  memset(cache, -1, sizeof(cache));
  int n;
  cin >> n;
  while (n--){
    string s;
    cin >> s;
    cout << dfs(maskFromStr(s)) << endl;
  }
}
