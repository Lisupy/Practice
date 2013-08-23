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
 */
const int MAXN = 15000;
int N;
int a[MAXN];
int tree_cnt[MAXN];

int cnt[MAXN]; 
int len;
int count(int x){
  int l = 0, r = len - 1;
  int total = 0;
  while (l <= r){
    int m = (l + r) / 2;
    if (a[m] <= x) total += tree_cnt[m];
    if (a[m] == x) return total;
    if (a[m] <  x) l = m + 1;
    else if(a[m] > x) r = m - 1;
  }
  assert(0);
}
void add(int x){
  int l = 0, r = len - 1;
  while (l <= r){
    int m = (l + r) / 2;
    if (x    <= a[m]) tree_cnt[m]++;
    if (a[m] == x   ) return;
    if (a[m] <  x   ) l = m + 1;
    else if (a[m] > x) r = m - 1;
  }
  assert(0);
}
int TestNum;
int main(){
  int x[MAXN], y[MAXN];
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d%d", x + i, y + i), a[i] = x[i];
  sort(a, a + N);
  len = unique(a, a + N) - a;
  for (int i = 0; i < N; i++){
    //printf("%d: %d\n", x[i], count(x[i]));
    cnt[count(x[i])]++;
    add(x[i]);
  }
  for (int i = 0; i < N; i++){
    printf("%d\n", cnt[i]);
  }
}

