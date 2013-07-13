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
void pr_bits(int n){
  for (int i = 31; i >= 0; i--){
    if ((1<<i) & n){
      printf("1");
    }else{
      printf("0");
    }
  }
  printf("\n");
}

int main(){
  unsigned N, L, U;
  unsigned mask;

  while (cin >> N >> L >> U){
    mask = 0;
    for (int i = 31; i >= 0; i--){
      //printf("#%d :\n", i);
      //pr_bits(N);
      //pr_bits(L);
      //pr_bits(U);
      //pr_bits(mask);
      //pr_bits((1 << i) & N);
      if (( 1 << i ) & L && ( 1 << i ) & U){
        //printf("step1\n");
        mask |= 1 << i; 
      }else if ( ((1 << i) & U) == 0){
        //printf("step2\n");
        continue;
      }else{
        //printf("step3\n");
        assert((1<<i) & U);
        assert(((1<<i) & L) == 0);
        if (((1 << i) & N ) == 0){
          mask |= 1 << i;
          L = 0;
        }else{
          U = (1 << i) - 1;
        }
      }
    }
    cout << mask << endl;
  }
}
