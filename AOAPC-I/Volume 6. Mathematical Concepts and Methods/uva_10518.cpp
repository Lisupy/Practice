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
  int dat[3][3];
  Mat(){
    memset(dat, 0, sizeof(dat));
  }
  void dbg(){
    for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++) printf("%4d", dat[i][j]);
      printf("\n");
    }
  }
};
Mat matMul(Mat a, Mat b, int mod){
  Mat c;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++){
      for (int k = 0; k < 3; k++){
        c.dat[i][j] = (c.dat[i][j] + a.dat[i][k] * b.dat[k][j])%mod;
      }
    }
  }
  return c;
}
// anx = x ^ p % mod
Mat matPow(Mat x, i64 p, int mod){
  Mat s;
  s.dat[0][0] = 1; s.dat[0][1] = 0; s.dat[0][2] = 0; 
  s.dat[1][0] = 0; s.dat[1][1] = 1; s.dat[1][2] = 0; 
  s.dat[2][0] = 0; s.dat[2][1] = 0; s.dat[2][2] = 1; 
  while (p) {
    if (p % 2) s = matMul(s, x, mod);
    x = matMul(x, x, mod);
    p /= 2;
  }
  return s;
}

i64 F(i64 n, int mod){
  Mat A, B;
  A.dat[0][0] = 1; A.dat[0][1] = 1; A.dat[0][2] = 1; 
  A.dat[1][0] = 1; A.dat[1][1] = 0; A.dat[1][2] = 0; 
  A.dat[2][0] = 0; A.dat[2][1] = 0; A.dat[2][2] = 1; 
  B.dat[0][0] = 1; B.dat[0][1] = 0; B.dat[0][2] = 0; 
  B.dat[1][0] = 1; B.dat[1][1] = 0; B.dat[1][2] = 0; 
  B.dat[2][0] = 1; B.dat[2][1] = 0; B.dat[2][2] = 0; 
  Mat C = matMul(matPow(A, n - 1, mod), B, mod);
  return C.dat[0][0]; 
}

int TestNum;
int main(){
  i64 n, b;
  while (cin >> n >> b && b) {
    printf("Case %d: %lld %lld %lld\n", ++TestNum, n, b, F(n, b)); 
  }
}

