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

const int MAXN = 1024;
int T;
int N;
int P[MAXN];
int W[MAXN];
int G;
int MW;

int dp[MAXN * 100];

int total = 0;
void gao(){
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  total = accumulate(P + 1, P + N + 1, 0); 
  for (int i = 1; i <= N; i++){
    for (int j = total; j >= 0; j--){
      int last = j - W[i];
      if (last >= 0 && dp[last] != -1){
        dp[j] = max(dp[j], dp[last] + P[i]); 
      }
    }
  }
  for (int i = 1; i <= total; i++){
    dp[i] = max(dp[i], dp[i - 1]);
  }
}


int main(){
  cin >> T;
  while (T--){
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> P[i] >> W[i];
    gao();
    cin >> G;
    int ans = 0;
    while (G--){
      cin >> MW;
      ans += dp[MW];
    }
    cout << ans << endl;
  }
}
