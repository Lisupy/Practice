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

i64 cache[20][20][11];
int a[20];
int num[256];
int D, M;
i64 C(int n, int k){
  i64 total = 1;
  for (int i = 1; i <= k; i++) total = total * (n - i + 1) / i;
  return total;
}
i64 F(int idx, int remainder, int m){
  if (m == 0) return remainder == 0 ? 1 : 0;
  if (idx == D) return 0;
  i64 &res = cache[idx][remainder][m];
  if (res != -1) return res;
  res = 0;
  for (int i = 0; i <= min(m, a[idx]); i++){
    res += C(a[idx], i) * F(idx + 1, ((remainder - i * idx) % D + D) % D, m - i);
  }
  return res;
}
int N, Q;

int TestNum;
int main(){
  while (scanf("%d %d", &N, &Q) && N){
    printf("SET %d:\n", ++TestNum);
    for (int i = 0; i < N; i++) scanf("%d", &num[i]);
    for (int q = 1; q <= Q; q++){
      scanf("%d%d", &D, &M);

      memset(cache, -1, sizeof(cache));
      memset(a, 0, sizeof(a));
      for (int i = 0; i < N; i++) a[(num[i]%D +D)%D]++;

      printf("QUERY %d: %lld\n", q, F(0, 0, M));
    }
  }
}

