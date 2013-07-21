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


int gcd(int a, int b){
  if (a < b) swap(a, b);
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

int lcm(int a, int b){
  return a * b / gcd(a, b);
}

int main(){
  int m, n, t;
  while (cin >> m >> n >> t){
    if (m > n){
      swap(m, n);
    }
    int waste_time = 0xffffff;
    int total = 0;
    for (int i = 0; t - n * i >= 0; i++){
      int wt = (t - n * i) % m;
      if (wt < waste_time){
        total = i + (t - n * i) / m;
        waste_time = wt;
      }
      if (wt == waste_time){
        int tt = i + (t - n * i) / m;
        total = max(total, tt);
      }
    }
    cout << total;
    if (waste_time != 0){
      cout << " " << waste_time;
    }cout << endl;
  }
}
