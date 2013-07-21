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

const int MAXN = 1024;

int cache[MAXN][MAXN];
char buf[MAXN];


int dfs(int from, int to){
  if (from >= to) return 0;
  int &res = cache[from][to];
  if (res != -1) return res;
  res = min(dfs(from + 1, to), dfs(from, to - 1)) + 1;
  if (buf[from] == buf[to]){
    res = min(res, dfs(from + 1, to - 1));
  }
  res = min(res, dfs(from + 1, to - 1) + 1);
  return res;
}


int main(){
  int n;
  scanf("%d", &n);
  for (int iCase = 1; iCase <= n; iCase++){
    scanf("%s", buf);
    int len = strlen(buf);
    memset(cache, -1, sizeof(cache));
    int ans = dfs(0, len - 1);
    printf("Case %d: %d\n", iCase, ans);
  }
}
