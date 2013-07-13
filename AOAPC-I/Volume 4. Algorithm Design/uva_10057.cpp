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
int n;
int a[MAXN];


int main(){
  while (scanf("%d", &n) != EOF){
    for (int i = 0; i < n; i++){
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int ans1, ans2, ans3;
    ans1 = a[(n - 1) / 2];
    if (n % 2 == 1){
      ans2 = upper_bound(a, a + n, ans1) - lower_bound(a, a + n, ans1);
      ans3 = 1;
    }else{
      ans2 = upper_bound(a, a + n, a[n / 2]) - lower_bound(a, a + n, a[(n - 1) / 2]);
      ans3 = a[n / 2] - a[(n - 1) / 2] + 1;
    }
    printf("%d %d %d\n", ans1, ans2, ans3);
  }
}
