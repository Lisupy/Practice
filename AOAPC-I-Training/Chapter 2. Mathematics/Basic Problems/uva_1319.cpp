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


int m, p, a, b;

int TestNum;
int main(){
  while (cin >> m >> p >> a >> b) {
    double total = 0;
    if (b > 0){
      total += b * pow(a, p / 2);
      int n = m - b;
      int k = n / (a + 1);
      total += (a * pow(a, -p / 2) + pow(a, p / 2)) * k;
      int t = n % (a + 1);
      if (t > 1){
        total += ((t - 1) * pow(a, -p / 2) + pow(t - 1, p) * pow(a, -p / 2) );
      }
    }else{
      b = -b;
      total += a * b * pow(a, -p / 2);
      int n = m - a * b;
      int k = n / (a + 1);
      total += (a * pow(a, -p / 2) + pow(a, p / 2)) * k;
      int t = n % (a + 1);
      if (t > 1){
        total += ((t - 1)* pow(a, -p / 2) + pow(t - 1, p) * pow(a, -p / 2) );
      }
    }
    printf("%d\n", int(round(total)));
  }
}

