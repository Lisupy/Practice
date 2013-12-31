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
const double PI = acos(-1);
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
const int MAXN = 32;
i64 C_cache[MAXN][MAXN];
bool C_visited[MAXN][MAXN];
i64 C(int N, int K){
  if (K > N) return 0;
  if (N < 0 || K < 0) return 0;
  if (K == 0) return 1;
  i64 &res = C_cache[N][K];
  if (C_visited[N][K]) return res;
  C_visited[N][K] = true;
  res = C(N - 1, K - 1) + C(N - 1, K);
  return res;
}
i64 A_cache[MAXN];
i64 A_visited[MAXN];
i64 A(int N){
  if (N == 0) return 1;
  i64 &res = A_cache[N];
  if (A_visited[N]) return res;
  A_visited[N] = true;
  res = N * A(N - 1);
  return res;
}
i64 F_cache[MAXN][MAXN];
bool F_visited[MAXN][MAXN];
i64 F(int N, int K){
  if (N == 0 && K == 0) return 1;
  if (K > N) return 0;
  if (N < 0 || K < 0) return 0;
  i64  &res = F_cache[N][K];
  if (F_visited[N][K]) return res;
  F_visited[N][K] = true;
  for (int i = 1; i <= N; i++){
    res += C(N - 1, i - 1) * F(i - 1, K - 1) * A(N - i);
  }
  return res;
}

int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  cin >> TestNum;
  while (TestNum--){
    int N, P, R; cin >> N >> P >> R;
    i64 total = 0;
    for (int i = 1; i <= N; i++){
      total += C(N - 1, i - 1) * F(i - 1, P - 1) * F(N - i, R - 1);
    }
    cout << total << endl;
  }
}

