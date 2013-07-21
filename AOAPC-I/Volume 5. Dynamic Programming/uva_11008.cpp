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
const int MAXM = 1 << 16;
const int INF = 32;
int TestNum;
int n;
int m;
int x[MAXN];
int y[MAXN];
int cache[MAXM];
int area2(int x1, int y1, int x2, int y2, int x3, int y3){
  int s1 = x1 * y2 + x2 * y3 + x3 * y1;
  int s2 = y1 * x2 + y2 * x3 + y3 * x1;
  return s1 - s2;
}
bool isSameLines[MAXN][MAXN][MAXN];
bool isSameLine(int i, int j, int k){
  return isSameLines[i][j][k];
//  return area2(x[i], y[i], x[j], y[j], x[k], y[k]) == 0;
}

int dfs(int mask){
  if (__builtin_popcount(mask) <= n - m) return 0;
  int &res = cache[mask];
  if (res != -1) return res;
  res = INF;
  for (int i = 0; i < n; i++){
    if ((mask & (1 << i)) == 0) continue;
    res = min(res, dfs(mask ^ (1 << i)) + 1);
    for (int j = i + 1; j < n; j++){
      if ((mask & (1 << j)) == 0) continue;
      int tmask = mask ^ (1 << i) ^ (1 << j);
      for (int k = j + 1; k < n; k++){
        if ((mask & (1 << k)) == 0) continue;
        if (isSameLine(i, j, k)){
          tmask ^= 1 << k;
        }
      }
      res = min(res, dfs(tmask)  + 1);
    }
  }
  //printf("%d %d\n", mask, res);
  return res;
}


int main(){
  scanf("%d", &TestNum);
  for (int ti = 1; ti <= TestNum; ti++){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d %d", x + i, y + i);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) 
      isSameLines[i][j][k] = area2(x[i], y[i], x[j], y[j], x[k], y[k]) == 0;
    memset(cache, -1, sizeof(cache));
    int ans = dfs((1 << n) - 1);
    printf("Case #%d:\n", ti);
    printf("%d\n", ans);
    if (ti != TestNum) printf("\n");
  }
}
