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
const i64 MOD = 1000000007;
const int MAXN = 1024;
i64 factorial[MAXN];
i64 cache[MAXN][MAXN];
bool visited[MAXN][MAXN];
i64 F(int N, int M, int K){
  if (N < M || K > M) return 0;
  if (K < 0) return 0;
  if (M < 0) return 0;
  if (M == K) return factorial[N - M]; 
  i64 &res = cache[M][K];
  if (visited[M][K]) return res;
  visited[M][K] = true;
  res = (F(N - 1, M - 1, K - 1) + F(N - 1, M - 1, K) * (N - 1 - K) + F(N - 1, M - 1, K + 1) * (K + 1))%MOD;
  //printf("%d %d %d: %lld\n", N, M, K, res);
  return res;
}

i64 c_cache[MAXN][MAXN];
i64 C(int n, int k){
  if (n < k) return 0;
  if (k == 0) return 1;
  i64 &total = c_cache[n][k];
  if (total != 0) return total;
  total = (C(n - 1, k) + C(n - 1, k - 1)) % MOD;
  //printf("C(%d, %d) = %lld\n", n, k, total);
  return total;
}

i64 F1(int N, int M, int K){
  i64 total = 0;
  for (int j = 0; j <= M - K; j++){
    i64 s = (C(M - K, j) * factorial[N - K - j]) % MOD;
    if (j % 2 == 0) total = (total + s) % MOD;
    else total = (total - s + MOD) % MOD;
    //cout << total << endl;
  }
  total = (total * C(M, K)) % MOD;
  return total;
}
int TestNum;
int main(){
  factorial[0] = 1;
  for (i64 i = 1; i < MAXN; i++) {
    factorial[i] = (factorial[i - 1] * i) % MOD; 
    //cout << factorial[i] << endl;
  }
  int T; cin >> T;
  while (T--) {
    //memset(visited, 0, sizeof(visited));
    int N, M, K; cin >> N >> M >> K;
    cout << "Case " << ++TestNum << ": ";
    //cout << F(N, M, K) << endl;
    cout << F1(N, M, K) << endl;
  }
}

