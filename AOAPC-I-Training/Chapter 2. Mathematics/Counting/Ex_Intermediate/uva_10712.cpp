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
int N;

int f1[10][100];
int f2[10];
void f1_init(){
  memset(f1, 0, sizeof(f1));
  for (int i = 0; i <= 9; i++) f1[1][i] = i != N;
  for (int d = 2; d <= 9; d++){
    for (int i = 0; i <= 99; i++){
      for (int j = 0; j <= 9; j++){
        int n;
        if (d == 2){
          if (i >= 10) continue;
          n = i + j * 10;
          if (n != N && n / 10 != N && n % 100 != N){
            f1[d][n] += f1[d - 1][i];
          }
        } else {
          n = i + j * 100;
          if (n / 100 != N && n != N && n / 10 != N && n % 100 != N){
            f1[d][n / 10] += f1[d - 1][i];
          }
        }
        if (n == 117){
          printf("%d: %d %d %d, %d\n", d, n, i, j, f1[d - 1][i]);
        }
      }
    }
  }
  for (int d = 1; d <= 9; d++){
    for (int i = 0; i <= 99; i++){ 
      f2[d] += f1[d][i];
    }
  }
}
int getSum1(int d){
  int total = 0;
  if (d == 1){
    for (int i = 0; i <= 9; i++){
      total += f1[d][i];
    }
  }else{
    for (int i = 10; i <= 99; i++){
      total += f1[d][i];
    }
  }
  return total;
}
int getSum2(int d){
  int total = 0;
  for (int i = 0; i <= d; i++){
    total += getSum1(i);
  }
  return total;
}
int getSum3(int B){
  int total = 0;
  int s = k * 10 + last_d;
  if (k != N && s != N && s % 100 != N && s % 10 != N){
    total += getSum3(B % ss);
  }
  return total;
}
int TestNum;
int main(){
  int A, B;
  while (cin >> A >> B >> N && A != -1){
    f1_init();
    for (int i = 0; i <= 9; i++) {
      printf("%2d: %d, %d %d\n", i, f2[i], getSum1(i), getSum2(i));
    }
    cout << getSum3(B) - getSum3(A - 1) << endl;
  }

}

