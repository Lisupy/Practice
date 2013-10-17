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
const int MAXN = 100000 * 2 + 100;
int cnt[MAXN];
int located[MAXN];
int mostLeft;
int n, m;
int N;
int lowbit(int x){ return x&-x;}
int sum(int pos){
  int total = 0;
  while (pos){
    total += cnt[pos];
    pos -= lowbit(pos);
  }
  return total;
}
void add(int pos, int x){
  while (pos <= N){
    cnt[pos] += x;
    pos += lowbit(pos);
  }
}
void reset(){
  memset(cnt, 0, sizeof(cnt));
}
int TestNum;
int main(){
  scanf("%d", &TestNum);
  while (TestNum--) {
    reset();
    scanf("%d%d", &n, &m); N = n + m;
    for (int i = 1; i <= n; i++){
      located[i] = m + i;
      add(m + i, 1);
    }
    mostLeft = m;
    for (int i = 0; i < m; i++) {
      if (i != 0) printf(" ");
      int a; scanf("%d", &a);
      printf("%d", sum(located[a] - 1));
      add(located[a], -1);
      located[a] = mostLeft--;
      add(located[a], 1);
    }printf("\n");
  }
}


