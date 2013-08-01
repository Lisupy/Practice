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
 * sizeof CLOCKS_PER_SEC
 */

unsigned long long factor[13];
void factor_init(){
  factor[0] = 1;
  for (int i = 1; i < 13; i++) {
    factor[i] = factor[i - 1] * i;
  }
}

int a[13];
int main(){
  factor_init();
  int N;
  while (scanf("%d", &N) && N){
    for (int i = 0; i < N; i++) {
      scanf("%d", &a[i]);
    }
    unsigned long long total = factor[N];
    sort(a, a + N);
    for (int i = 0; i < N; i++) {
      if (i == 0 || a[i] != a[i - 1]){
        //cout << total << endl;
        total /= factor[count(a, a + N, a[i])];
        //cout << total << endl;
      }
    }
    //cout << total << endl;
    unsigned long long s = 0;
    for (int i = 0; i < N; i++) {
      s += a[i];
    }
    unsigned long long ans = 0;
    for (int i = 0; i < N; i++) {
      ans = ans * 10 + s * total / N;
    }
    cout << ans << endl;
  }
}
       

