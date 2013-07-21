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
vector<int> c;
vector<int> a;
const int MAXN = 64;
int cache[MAXN][MAXN];
int solve(int l, int r){
  if (l == r) return 0;
  int &res = cache[l][r] ;
  if (res != 0) return res;
  res = numeric_limits<int>::max();
  for (int i = l; i < r; i++){
    res = min(res, solve(l, i) + solve(i + 1, r));
  }
  res += accumulate(a.begin() + l, a.begin() + r + 1, 0);
  return res;
}
int main(){
  int l;
  while (cin >> l && l){
    int n; cin >> n;
    c.resize(n + 1);
    for (int i = 0; i < n; i++) cin >> c[i]; c[n] = l;
    a.clear();
    adjacent_difference(c.begin(), c.end(), back_inserter(a));
    memset(cache, 0, sizeof(cache));
    int ans = solve(0, a.size() - 1);
    printf("The minimum cutting is %d.\n", ans);
  }
}
