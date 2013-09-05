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
const int MAXN = 512;
int tmp[MAXN];

int reverse_num(int a[], int n){
  int total = 0;
  //for (int i = 1; i <= n; i++) printf("%3d", a[i]);
  for (int i = 1; i <= n; i++){
    if (a[i] != i){
      int cnt = 0;
      int t = a[i];
      while (a[t] != t){
        int tt = t;
        t = a[t];
        a[tt] = tt;
        cnt++;
      }
      total += cnt - 1;
    }
  }
  //printf(": %d\n", total);
  return total;
}
int TestNum;
int main(){
  int N; 
  while (scanf("%d", &N) && N){
    int a[MAXN];
    for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
    int best = MAXN * MAXN;
    for (int i = 1; i <= N; i++){
      rotate(a + 1, a + 2, a + N + 1);
      int b[MAXN]; copy(a + 1, a + N + 1, b + 1);
      best = min(best, reverse_num(b, N));
      copy(a + 1, a + N + 1, b + 1); reverse(b + 1, b + N + 1);
      best = min(best, reverse_num(b, N));
    }
    printf("%d\n", best);
  }
}


