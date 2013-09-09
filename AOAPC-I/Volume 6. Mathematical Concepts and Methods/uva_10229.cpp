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
 * (1 << (31 - __builtin_clz(100) ) == 64;
 */

struct Mat{
  i64 dat[2][2];
  Mat(){
    memset(dat, 0, sizeof(dat));
  }
  void dbg(){
    for (int i = 0; i < 2; i++){
      for (int j = 0; j < 2; j++) printf("%3lld", dat[i][j]); 
      printf("\n");
    }
  }
};
Mat matMul(Mat a, Mat b, int mod){
  Mat c;
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < 2; k++){
        c.dat[i][j] += (a.dat[i][k] * b.dat[k][j])%mod;
      }
    }
  }
  return c;
}
Mat matPow(Mat a, int n, int mod){
  Mat s ;
  s.dat[0][0] = 1; s.dat[0][1] = 0;
  s.dat[1][0] = 0; s.dat[1][1] = 1;
  while (n) {
    if (n % 2 == 1) s = matMul(a, s, mod);
    a = matMul(a, a, mod);
    n /= 2;
  }
  return s;
}
i64 F(int n, int mod){
  if (n == 0) return 0;
  //c = a^n * b
  Mat a, b;
  a.dat[0][0] = 1; a.dat[0][1] = 1;
  a.dat[1][0] = 1; a.dat[1][1] = 0;
  b.dat[0][0] = 1; b.dat[0][1] = 0;
  b.dat[1][0] = 0; b.dat[1][1] = 0;
  Mat c = matMul(matPow(a, (n - 1), mod), b, mod);
  return c.dat[0][0];
}

int TestNum;
int main(){
  int n, m;
  while (cin >> n >> m) {
    cout << F(n, 1 << m) << endl;
  }
}

