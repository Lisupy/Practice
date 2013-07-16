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
const int MAXN = 1024 * 10;
int T;
int N;
int P[MAXN];

int a[MAXN];

bool staircaseNim(){
  int s = 0;
  for (int i = 1; i <= N; i += 2){
    s ^= a[i];
  }
  return s != 0;
}


int main(){
  cin >> T;
  while (T--){
    cin >> N;
    for (int i = 1; i <= N; i++) {
      cin >> P[i];
    }
    sort(P + 1, P + N + 1);
    P[0] = 0;
    for (int i = 1; i <= N; i++){
      a[i] = P[i] - P[i - 1] - 1;
    }
    reverse(a + 1, a + N + 1);
    if (staircaseNim()){
      printf("Georgia will win\n");
    }else{
      printf("Bob will win\n");
    }
  }
}

