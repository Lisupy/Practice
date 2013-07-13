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
const int INF = 0xffffff;
int N;
int a[128][128];
int b[128];
int maxSub(){
  int best = -INF;
  int s = 0;
  for (int i = 1; i <= N; i++){
    s += b[i];
    best = max(best, s);
    if (s < 0){
      s = 0;
    }
  }
  return best;
}
int main(){
  cin >> N;
  for (int i = 1; i <= N; i++){
    for (int j = 1; j <= N; j++){
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= N; i++){ 
    for (int j = 1; j <= N; j++){
      a[i][j] += a[i - 1][j];
    }
  }
  int best = -INF;
  for (int i = 0; i <= N; i++){
    for (int j = i + 1; j <= N; j++){
      for (int k = 1; k <= N; k++){
        b[k] = a[j][k] - a[i][k];
      }
      best = max(best, maxSub());
    }
  }
  printf("%d\n", best);
}
