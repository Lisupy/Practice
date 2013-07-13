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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof
 */

const int MAXN = 1024 * 1024;
unsigned a[MAXN];
unsigned b[MAXN];
unsigned c[MAXN];
void init(){
  int s = 1;
  for (int i = 1; i <= 6; i++){
    for (int j = s; j < s * 10; j++){
      a[j] = i;
    }
    s *= 10;
  }
  partial_sum(a, a + MAXN, b); 
  partial_sum(b, b + MAXN, c);
  //for (int i = 0; i < 100; i++){
    //printf("%d: %u %u %u\n", i, a[i], b[i], c[i]);
  //}
}

int solve(unsigned n){
  int i = 0;
  while (c[i + 1] < n){
    i++;
  }
  //printf("%u %d\n", n, i);
  n -= c[i];
  //printf("%u\n", n);
  i = 0;
  while (b[i + 1] < n){
    i++;
  }
  n -= b[i];
  //printf("%u %d\n", n, i);
  char buf[32];
  sprintf(buf, "%d", i + 1);
  return buf[n - 1] - '0';
}

int main(){
  init();
  int t;
  cin >> t;
  while (t--){
    int i;
    cin >> i;
    cout << solve(i) << endl;
  }
}
