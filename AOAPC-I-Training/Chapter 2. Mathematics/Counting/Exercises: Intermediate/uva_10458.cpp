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

const int MAXK = 7;

i64 C(int n, int k){
  if (n < k) return 0;
  i64 total = 1;
  for (int i = 0; i < k; i++) {
    total *= n - i;
    total /= i + 1;
  }
  return total;
}  
int K, N;
i64 upper[MAXK], lower[MAXK];


i64 solve(){
  i64 total = 0;
  for (int i = 0; i < (1 << K); i++) {
    i64 s = 0;
    i64 M = N;
    for (int j = 0; j < K; j++){
      if ((i & (1 << j)) == 0){
        M -= lower[j];
      }else{
        M -= upper[j] + 1;
      }
    }
    s = C(M + K - 1, K - 1);
    if (__builtin_parity(i)){
      total -= s;
    }else{
      total += s;
    }
  }
  return total;
}
int TestNum;
int main(){
  while (cin >> K >> N) {
    //assert(N < 10000);
    for (int i = 0; i < K; i++) {
      cin >> lower[i] >> upper[i];
      assert(lower[i] <= upper[i]);
    }
    cout << solve() << endl;
  } 
}

