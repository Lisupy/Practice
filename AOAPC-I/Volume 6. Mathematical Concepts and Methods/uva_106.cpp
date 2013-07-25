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
bool isCompoents[MAXN]; 
long long gcd(long long a, long long b){
  return b ? gcd(b, a % b) : a;
}
int main(){
  int N;
  while (cin >> N){
    fill (isCompoents, isCompoents + N + 1, false); 
    int cnt = 0;
    for (long long n = 1; n <= N; n++){
      for (long long m = n + 1; m <= N; m++){
        long long a = m * m - n * n;
        long long b = 2 * m * n;
        long long c = m * m + n * n;
        if (c > N) break;
        if (gcd(a, b) != 1) continue;
        //if (a > b) continue;
        cnt++;
        for (long long k = 1; c * k <= N; k++){
          isCompoents[a * k] = isCompoents[b * k] = isCompoents[c * k] = true;
        }
      }
    }
    printf("%d %d\n", cnt, N - accumulate(isCompoents, isCompoents + N + 1, 0));
  }
}


