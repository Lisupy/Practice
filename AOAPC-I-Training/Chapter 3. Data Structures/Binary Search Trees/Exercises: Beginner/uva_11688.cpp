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
 */
const int MAXN = 128 * 1024;
int N;
int l[MAXN];
int r[MAXN];
int height[MAXN];
int depth[MAXN];
int inDegree[MAXN];
int ans[MAXN];

int calcHeight(int s){
  if (s == 0) return 0;
  else return height[s] = max(calcHeight(l[s]), calcHeight(r[s])) + 1;
}

void calcDepth(int s, int d){
  if (s == 0) return;
  depth[s] = d;
  calcDepth(l[s], d + 1);
  calcDepth(r[s], d + 1);
}

void calcAns(int i, int lh = 0, int rh = 0, int lth = 0, int rth = 0){
  if (i == 0) return;
  ans[i] = 0;
  ans[i] = max(ans[i], lh + 1);
  ans[i] = max(ans[i], rh + 1);
  ans[i] = max(ans[i], lth + height[l[i]] + 1);
  ans[i] = max(ans[i], rth + height[r[i]] + 1);
  calcAns(l[i], lh, max(rh, 1 + rth + height[r[i]]), lth, 1 + rth);
  calcAns(r[i], max(lh, 1 + lth + height[l[i]]), rh, lth + 1, rth);
}
int TestNum;
int main(){
  while (scanf("%d", &N) && N) {
    for (int i = 1; i <= N; i++) scanf("%d %d", &l[i], &r[i]);
    memset(height, 0, sizeof(height));
    memset(depth, 0, sizeof(depth));
    memset(inDegree, 0, sizeof(inDegree));
    for (int i = 1; i <= N; i++) inDegree[l[i]]++, inDegree[r[i]]++;
    int root = find(inDegree + 1, inDegree + N + 1, 0) - inDegree;
    calcHeight(root);
    calcDepth(root, 1);
    calcAns(root);
    for (int i = 1; i <= N; i++) printf("%d\n", ans[i]);
  }
}

