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
const int MAXN = 100000;
int n, q;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int len;
int rmq[18][MAXN];

void init(){
  memset(rmq, 0, sizeof(rmq));
  for (int i = 0; i < len; i++) rmq[0][i] = c[i];
  for (int layer = 1; layer < 18; layer++){
    for (int i = 0; i < len; i++){
      int pos = i + (1 << (layer - 1));
      rmq[layer][i] = rmq[layer - 1][i];
      if (pos < n) rmq[layer][i] = max(rmq[layer - 1][i], rmq[layer - 1][pos]);
    }
  }
}
int query(int from, int to){
  if (from >= to) return 0;
  int Len = to - from;
  int layer = 0;
  while ((1 << (layer + 1)) <= Len) layer++;
  //printf("%d, %d: %d %d\n", from, to, Len, layer);
  //printf("%d %d\n", rmq[layer][from], rmq[layer][to - (1 << layer)]);
  return max(rmq[layer][from], rmq[layer][to - (1 << layer)]);
}

int TestNum;
int main(){
  while (cin >> n && n){
    cin >> q;
    map<int, int> M;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) M[a[i]]++;
    len = 0;
    for (map<int, int>::iterator it = M.begin(); it != M.end(); it++){
      b[len] = it->first;
      c[len] = it->second;
      len++;
    }
    init();
    while (q--){
      int i, j; cin >> i >> j; i--, j--;
      if (a[i] == a[j]) {
        printf("%d\n", j - i + 1);
        continue;
      }
      int from = upper_bound(b, b + len, a[i]) - b;
      int to   = lower_bound(b, b + len, a[j]) - b;
      int from2 = lower_bound(a, a + n, b[from]) - a;
      int to2 =   lower_bound(a, a + n, a[j]) - a;
      int theMax = query(from, to);
      //printf("%d\n", theMax);
      theMax = max(theMax, from2 - i);
      //printf("%d\n", theMax);
      theMax = max(theMax, j - to2 + 1);
      printf("%d\n", theMax);
    }
  }
}

