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

const int MAXN = 128;
bool visited[MAXN][MAXN];
int cache[MAXN][MAXN];
int nums[MAXN];
int sums[MAXN];
int sum(int from, int to){
  return sums[to] - sums[from - 1];
}
int dp(int from, int to){
  if (from == to) return nums[from];
  if (from > to) return 0;
  int &res = cache[from][to];
  if (visited[from][to]) return res;
  visited[from][to] = true;
  res = sum(from, to);
  for (int i = from; i <= to; i++){
    res = max(res, sum(from, i) - dp(i + 1, to));
  }
  for (int i = from; i <= to; i++){
    res = max(res, sum(i, to) - dp(from, i - 1));
  }
  return res;
}

int main(){
  int n;
  while (scanf("%d", &n) && n){
    for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
    partial_sum(nums + 1, nums + 1 + n, sums + 1);
    memset(visited, 0, sizeof(visited));
    printf("%d\n", dp(1, n));
  }
}
