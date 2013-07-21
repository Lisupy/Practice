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

const int MAXN = 256;
int n;
int f[MAXN];
int sf[MAXN];
int cache[MAXN][MAXN];

int dfs(int from, int to){
  if (from >= to) return 0;
  int &res = cache[from][to];
  if (res != -1) return res;
  res = 0xffffff;
  for (int i = from; i <= to; i++){
    int cost = dfs(from, i - 1) + dfs(i + 1, to) + sf[to] - sf[from - 1] - f[i];
    res = min(res, cost);
  }
  return res;
}


int main(){
  while (scanf("%d", &n) != EOF){
    for (int i = 1; i <= n; i++) scanf("%d", &f[i]);
    partial_sum(f + 1, f + n + 1, sf + 1);
    //for (int i = 1; i <= n; i++) printf("%d ", sf[i]);printf("\n");
    memset(cache, -1, sizeof(cache));
    int ans = dfs(1, n);
    printf("%d\n", ans);
  }
}

