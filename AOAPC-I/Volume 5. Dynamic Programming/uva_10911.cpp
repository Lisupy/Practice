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

const int MAXN = 16;
const int MAXM = 1 << MAXN;

const double INF = 1e20;
double cache[MAXM];
int N;
double x[MAXN];
double y[MAXN];
double cost(int i, int j){
  double s = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);
  return sqrt(s);
}
double dfs(int mask){
  if (mask == 0) return 0;
  double res = cache[mask];
  if (res != INF) return res;
  int tr = __builtin_ctz(mask);
  mask ^= 1 << tr;
  int tmask = mask;
  while (tmask){
    int tl = __builtin_ctz(tmask);
    tmask ^= 1 << tl;
    res = min(res, dfs(mask ^ (1 << tl)) + cost(tl, tr));
  }
  return res;
}

int TestNum;
int main(){
  while (cin >> N && N){
    N *= 2;
    string s;
    for (int i = 0; i < N; i++) cin >> s >> x[i] >> y[i];
    fill(cache, cache + MAXM, INF);
    printf("Case %d: %.02lf\n", ++TestNum, dfs((1 << N) - 1));
  }
}
