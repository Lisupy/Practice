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
 * sizeof CLOCKS_PER_SEC
 */


int d[32][32];

int TestNum;
int main(){
  int N;
  while (true){
    memset(d, 0x1f, sizeof(d));
    for (int i = 0; i < 32; i++) d[i][i] = 0;
    if (!(cin >> N))break;
    for (int i = 0; i < N; i++){
      int A; cin >> A;
      d[A][1] = d[1][A] = 1;
    }
    for (int i = 2; i < 20; i++){
      cin >> N;
      for (int j = 0; j < N; j++){
        int A; cin >> A;
        d[A][i] = d[i][A] = 1;
      }
    }
    for (int i = 1; i <= 20; i++){
      for (int s = 1; s <= 20; s++){
        for (int t = 1; t <= 20; t++){
          d[s][t] = min(d[s][t], d[s][i] + d[i][t]);
        }
      }
    }
    printf("Test Set #%d\n", ++TestNum);
    cin >> N;
    while (N--){
      int A, B; cin >> A >> B;
      printf("%2d to %2d: %d\n", A, B, d[A][B]);
    }
    printf("\n");
  }
}
