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
struct Turtle{
  int W, S;
};
const int MAXN = 1024 * 6;
Turtle turtles[MAXN];
bool operator<(const Turtle &a, const Turtle &b){
  if (a.S != b.S) return a.S < b.S;
  return a.W < b.W;
}
int dp[MAXN];
int len = 0;
int main(){
  int W, S;
  while (scanf("%d %d", &W, &S) != EOF){
    turtles[len].W = W;
    turtles[len].S = S;
    len++;
  }
  sort(turtles, turtles + len);
  memset(dp, 0x7f, sizeof(dp));
  dp[0] = 0;
  for (int i = 0; i < len; i++){ 
    W = turtles[i].W, S = turtles[i].S;
    for (int j = MAXN; j > 0; j--){
      if (dp[j - 1] <= S - W){
        dp[j] = min(dp[j], dp[j - 1] + W);
      }
    }
  }
  int pos = len - 1;
  while (dp[pos] == 0x7f7f7f7f){
    pos--;
  }
  printf("%d\n", pos);
}
