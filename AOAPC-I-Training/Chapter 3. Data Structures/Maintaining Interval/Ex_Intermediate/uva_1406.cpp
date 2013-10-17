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
const int MAXN = 128*1024;
const int MOD = 1 << 16;
int N;
int a[MAXN];
int C;
int cnt[16][MOD];

int TestNum;
int main(){
  while (scanf("%d", &N) && N != -1 ){
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    memset(cnt, 0, sizeof(cnt));
    for (int bit = 0; bit < 16; bit++){
      for (int i = 0; i < N; i++){
        cnt[bit][a[i] % (1 << (bit + 1))]++;
      }
    }

    C = 0;
    i64 total = 0;
    char cmd[32];
    while (scanf("%s", cmd)){
      if (!strcmp(cmd, "C")){
        int t; scanf("%d", &t);
        C = (C + t) % MOD;
      }else if (!strcmp(cmd, "Q")){
        int bit; scanf("%d", &bit);
        for (int i = 0; i < (1 << (bit + 1)); i++){
          if ((C + i) & (1 << bit)){
            total += cnt[bit][i];
          }
        }
      }else if (!strcmp(cmd, "E")){
        break;
      }else assert(0);
    }
    printf("Case %d: %lld\n", ++TestNum, total);
  }
}

