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
const double PI = acos(-1);
const double EPS = 1e-6;
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
double a1, d1, a2, d2;
double a21;
void gao1(){
  double d3 = d2 * 2 - d1;
  if (d3 >= 0){
    printf("%.02lf %.02lf\n", a1, d3);
  }else{
    printf("%.02lf %.02lf\n", 360 - a1, -d3);
  }
}
void gao2(){
  double d3 = (d2 + d1) * 2 + d2;
  printf("%.02lf %.02lf\n", a2, d3);
}
void gao3(){
  a1 = a1 / 360 * PI * 2;
  a2 = a2 / 360 * PI * 2; 

}
void gao4(){

}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (cin >> a1 >> d1 >> a2 >> d2) {
    assert(a1 != 360 && a2 != 360);
    if (a1 == a2){
      gao1();  
    }else if (fabs(a2 - a1) == 180){
      gao2();
    }else{
      a21 = a2 - a1;
      if (a21 < 0) a21 += 2 * PI;
      if (a21 > PI){
        gao3();
      }else{
        gao4();
      }
    }
  }
}

