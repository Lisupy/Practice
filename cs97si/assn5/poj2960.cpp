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
int k;
int s[MAXN];
int sg[MAXN];
bool flag[128];;
void init_sg(){
  sg[0] = 0;
  for (int i = 1; i < MAXN; i++){
    memset(flag, 0, sizeof(flag));
    for (int j = 0; j < k; j++){
      if (i - s[j] >= 0){
        int t = sg[i - s[j]];
        flag[t] = true;
      }
    }
    for (int j = 0; j < 128; j++){
      if (!flag[j]){
        sg[i] = j;
        break;
      }
    }
  }
}



int main(){
  while (scanf("%d", &k) && k){
    for (int i = 0; i < k; i++){
      scanf("%d", &s[i]);
    }
    init_sg();
    int m;
    scanf("%d", &m);
    while (m--){
      int l;
      cin >> l;
      int S = 0;
      while (l--){
        int h;
        scanf("%d", &h);
        S ^= sg[h];
      }
      if (S == 0){
        printf("L");
      }else{
        printf("W");
      }
    }
    printf("\n");
  }
}
