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
 * decltype // deprecated
 */
const int MAXN = 20 * 1024;
const u64 MAGIC = 1000 * 1000 * 1000 + 7;
int N, K;
int A[MAXN];
u64 H[MAXN];
u64 B[MAXN];
void init_hash(){
  H[0] = 0;
  for (int i = 0; i <= N; i++) H[i] = H[i - 1] * MAGIC + A[i - 1];
  B[0] = 1;
  for (int i = 1; i <= N; i++) B[i] = B[i - 1] * MAGIC;
}
inline u64 string_hash(int l, int r){
  return H[r] - H[l] * B[r - l];
}
u64 tmp[MAXN];
inline bool isValid(int L){

  //cout << "==[" << L << "]==" << endl;
  for (int i = 0; i + L <= N; i++){
    u64 hs = string_hash(i, i + L);
    tmp[i] = hs;
    //cout << i << ": " << hs << endl;
  }
  sort(tmp, tmp + N - L + 1);
  //for (int i = 0; i + L <= N; i++){
    //cout << tmp[i] << ", ";
  //}cout << endl;
  for (int l = 0, r = 0; l + L <= N; l = r){
    while (r + L <= N && tmp[l] == tmp[r]){
      r++;
    }
    if (r - l >= K) return true;
  }
  return false;
}
int solve(){
  int lo = 0, hi = N + 1;
  while (hi - lo > 1){
    int mid = (lo + hi) / 2;
    if (isValid(mid)) lo = mid;
    else hi = mid;
  }
  return lo;
}
int TestNum;
int main(){
  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; i++) scanf("%d", &A[i]);
  init_hash();
  printf("%d\n", solve());
}

