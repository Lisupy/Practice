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
const int INF = 0x1f1f1f1f;
const int MAXN = 20000;
const int MAXM = 100001;
int N;
int a[MAXN];

void input(){
  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];
}

int cnt[MAXM];



int sorted_a[MAXN];
int sorted_a_len;

int getAndSet1(int val){
  int total = 0;
  int l = 0, r = sorted_a_len; // [l, r]
  while (l < r){
    int mid = (l + r) / 2;
    if (sorted_a[mid] <= val) total += cnt[mid];
    if (sorted_a[mid] >= val) cnt[mid]++;
    if (sorted_a[mid] == val) return total;
    if (sorted_a[mid] < val) l = mid;
    else if (sorted_a[mid] > val) r = mid;
  }
  assert(0);
  return 0;
}

int getAndSet2(int val){
  int total = 0;
  int bak = val;
  while (val){
    total += cnt[val];
    val -= 1 << __builtin_ctz(val);
  }
  val = bak;
  while (val < MAXM){
    cnt[val]++;
    val += 1 << __builtin_ctz(val);
  }
  return total;
}

i64 solve1(){
  copy(a, a + N, sorted_a);
  sort(sorted_a, sorted_a + N);
  sorted_a_len = unique(sorted_a, sorted_a + N) - sorted_a;
  assert(sorted_a_len == N);
  int c[MAXN];
  int d[MAXN];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < N; i++) c[i] = getAndSet2(a[i]); 
  memset(cnt, 0, sizeof(cnt));
  for (int i = N - 1; i >= 0; i--) d[i] = getAndSet2(a[i]); 
  i64 total = 0;
  for (int i = 1; i < N - 1; i++){
    total += (i64)c[i] * (N - i - 1 - d[i]) + (i64)(i - c[i]) * d[i];
  }
  return total;
}

int TestNum;
int main(){
  int T; cin >> T;
  while (T--) {
    input();
    cout << solve1() << endl;
  }
}

