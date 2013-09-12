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
const int MAXN = 2000010;
//const int MAXN = 256;
int lowbit(int x) { return x & -x; }
int a[MAXN];
bool kicked[MAXN];
int sum(int pos){
  int total = 0;
  while (pos) {
    total += a[pos];
    pos -= lowbit(pos); 
  }
  return total;
}
void add(int pos, int x){
  while (pos < MAXN) {
    a[pos] += x;
    pos += lowbit(pos);
  }
}
int sumseek (int k)
{
  int ans = 0, sum = 0;
  for (int i = 21; i >= 0; i--){
    ans += (1 << i);
    if (ans >= MAXN || sum + a[ans] >= k) ans -= (1 << i);
    else sum += a[ans];
  }
  return ans + 1;
}
int findIdx(int Idx){
  int lo = 1, ro = MAXN;
  while (lo < ro) {
    int m = (lo + ro) / 2;
    int cnt = sum(m);
    if (cnt < Idx) lo = m + 1;
    else ro = m;
  }
  return lo;
}
int S[MAXN];
int s_len;
void gen(){
  for (int i = 1; i < MAXN; i++) add(i, 1);
  int sz = MAXN - 1;
  for (int i = 1; i < MAXN; i++){
    int len = i == 1? 2: sumseek(i);
    //cout << "===" << i << ": " << len << endl;
    if (len > sz) break;
    for (int j = len; j <= sz; j += len - 1){
      int pos = sumseek(j);
      assert(kicked[pos] == false);
      add(pos, -1); 
      kicked[pos] = true;
      //cout << "kick" << pos << endl;
      sz--;
    }
  }
  for (int i = 1; i < MAXN; i++) if (!kicked[i]){
    //cout << i << ", ";
    S[s_len++] = i;
  }
}
void solve(int n){
  bool valid = false;
  int L1, L2;
  if (n % 2 == 0){
    for (int i = lower_bound(S, S + s_len, n / 2) - S; i >=0; i--){
      if (n - S[i] >= S[i] && !kicked[n - S[i]]){
        L1 = S[i], L2 = n - S[i], valid = true;
        break;
      }
    }
  }
  if (valid) printf("%d is the sum of %d and %d.\n", n, L1, L2);
  else printf("%d is not the sum of two luckies!\n", n);
}
int TestNum;
int main(){
  gen();
  int n;
  while (scanf("%d", &n) != EOF){
    solve(n);
  }
}

