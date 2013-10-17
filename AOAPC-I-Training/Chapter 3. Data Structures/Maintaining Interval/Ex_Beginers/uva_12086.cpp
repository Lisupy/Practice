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
const int MAXN = 200010;
int N;

int a[MAXN];
int _sum[MAXN];

int lowbit(int x) { return x & -x; }
int sum(int pos){
  int total = 0;
  while (pos){
    total += _sum[pos];
    pos -= lowbit(pos);
  }
  return total;
}
void add(int pos, int x){
  while (pos <= N){
    _sum[pos] += x;
    pos += lowbit(pos);
  }
}

int TestNum;
int main(){
  while (scanf("%d", &N) && N){
    if (TestNum) printf("\n");
    printf("Case %d:\n", ++TestNum);
    memset(a, 0, sizeof(a));
    memset(_sum, 0, sizeof(_sum));
    for (int i = 1; i <= N; i++) scanf("%d", a + i);
    for (int i = 1; i <= N; i++) add(i, a[i]);
    char buf[32];
    while (scanf("%s", buf) && buf[0] != 'E'){
      int x, y; scanf("%d %d", &x, &y); 
      if (buf[0] == 'S'){
        add(x, y - a[x]);
        a[x] = y;
      }else{
        printf("%d\n", sum(y) - sum(x - 1));
      }
    }
  }
}

