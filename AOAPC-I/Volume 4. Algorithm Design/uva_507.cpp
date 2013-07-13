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
int a[20*1024];
int n;
int main(){
  int TestNum;
  cin >> TestNum;
  for (int ti = 1; ti <= TestNum; ti++){
    cin >> n;
    n--;
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    int best = -1;
    int bestl, bestr;
    int s = 0;
    int l = 0;
    for (int i = 0; i < n; i++){
      s += a[i];
      if (s == best){
        if (i + 1 - l > bestr - bestl){
          bestl = l;
          bestr = i + 1;
        }
      }
      if (s > best){
        best = s;
        bestl = l;
        bestr = i + 1;
      }
      if (s < 0){
        l = i + 1;
        s = 0;
      }
    }
    if (best <= 0){
      printf("Route %d has no nice parts\n", ti);
    }else{
      printf("The nicest part of route %d is between stops %d and %d\n", ti, bestl + 1, bestr + 1);
    }
  }
}

