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

i64 calc(i64 m, i64 n, i64 p){
  i64 total = 2;
  total += m * (m - 1) * 2;
  total += n * (n - 1);
  total += p * (p - 1) * 3;
  total += n * m * 4;
  total += n * p * 6;
  total += m * p * 6;
  return total;
}
i64 test(i64 m, i64 p, i64 ways){
  i64 l = 0, r = 20000 - 1;
  while (l <= r){
    i64 mid = (l + r) / 2;
    i64 guess = calc(m, mid, p);
    if (guess == ways) return mid;
    if (guess < ways) l = mid + 1;
    if (guess > ways) r = mid - 1;
  }
  return -1;
}
int solve(i64 ways){
  if (ways == 1){
    cout << "0 0 0" << endl;
    return 1;
  }
  int cnt = 0;
  for (int m = 0; m < 100; m++){
    for (int p = 100 - 1; p >= 0; p--) {
      i64 n = test(m, p, ways);
      if (n != -1){
        cout << m << " " << n << " " << p << endl;
        cnt++;
      }
    }
  }
  return cnt;
}
int TestNum;
int main(){
  i64 N;
  while (cin >> N && N != -1) {
    cout << "Case " << ++TestNum << ":" << endl;
    if (!solve(N)){
      cout << "Impossible." << endl;
    }
  }
}

