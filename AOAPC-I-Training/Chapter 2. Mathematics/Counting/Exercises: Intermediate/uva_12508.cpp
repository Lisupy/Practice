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

i64 solve(i64 n, i64 m, i64 A, i64 B){
  i64 total = 0;
  for (i64 x1 = 0; x1 <= n; x1++){
    for (i64 y1 = x1 == 0? 0: -m; y1 <= m; y1++){
      for (i64 x2 = x1; x2 <= n; x2++){
        for (i64 y2 = (x1 == x2 ? y1 : -m); y2 <= m; y2++){
          if (abs(x1 - x2) > n) continue;
          if (abs(y1 - y2) > m) continue;
          i64 area = abs(x1 * y2 - x2 * y1);
          if (area <= 0) continue;
          if (area < 2 * A) continue;
          if (area > 2 * B) break;
          i64 x = max(max(abs(x1), abs(x2)), abs(x1 - x2));
          i64 y = max(max(abs(y1), abs(y2)), abs(y1 - y2));
          total += (n + 1 - x) * (m + 1 - y);
          //printf("%lld %lld, %lld %lld : %lld %lld\n", x1, y1, x2, y2, area, total);
        }
      }
    }
  }
  return total;
}

int TestNum;
int main(){
  int T; cin >> T;
  while (T--) {
    int n, m, A, B;
    cin >> n >> m >> A >> B;
    cout << solve(n, m, A, B) << endl;
  }
}

