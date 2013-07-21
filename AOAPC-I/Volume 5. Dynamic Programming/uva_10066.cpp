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

int N1, N2;
int t1[128], t2[128];

int lcs[128][128];
int TestNum;
int main(){
  while (scanf("%d %d", &N1, &N2) && N1){
    for (int i = 1; i <= N1; i++) cin >> t1[i];
    for (int i = 1; i <= N2; i++) cin >> t2[i];
    for (int i1 = 1; i1 <= N1; i1++){
      for (int i2 = 1; i2 <= N2; i2++){
        if (t1[i1] == t2[i2]){
          lcs[i1][i2] = lcs[i1 - 1][i2 - 1] + 1;
        }else{
          lcs[i1][i2] = max(lcs[i1 - 1][i2], lcs[i1][i2 - 1]);
        }
      }
    }

    printf("Twin Towers #%d\n", ++TestNum);
    printf("Number of Tiles : %d\n", lcs[N1][N2]);
    printf("\n");
  }
}
