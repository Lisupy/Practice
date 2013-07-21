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
int n, k;
vector<int> cost[16][16];

vector<int> input_vector(){
  vector<int> res;
  int d;
  cin >> d;
  res.resize(d);
  for (size_t i = 0; i < res.size(); i++){
    cin >> res[i];
  }
  return res;
}
int input(){
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      if (i == j) continue;
      cost[i][j] = input_vector();
    }
  }
  return n;
}

const int MAXN = 1024;
const int INF = 0x7f7f7f7f;
int dp[MAXN][16];
int solve(){
  memset(dp, 0x7f, sizeof(dp));
  dp[0][1] = 0;
  for (int d = 0; d <= k; d++){ 
    for (int i = 0; i <= n; i++){
    //  dp[d][i] = min(dp[d][i], dp[d - 1][i]);
    }
    for (int i = 1; i <= n; i++){
      if (dp[d][i] == INF) continue;
      for (int j = 1; j <= n; j++){
        if (i == j) continue;
        int c = cost[i][j][d % cost[i][j].size()];
        if (c == 0) continue;
        dp[d + 1][j] = min(dp[d][i] + c,  dp[d + 1][j]);
      }
    }
  }
  return dp[k][n];
}
int TestNum = 0;
int main(){
  while (input()){
    printf("Scenario #%d\n", ++TestNum);
    int res = solve();
    if (res >= INF){
      printf("No flight possible.\n");
    }else{
      printf("The best flight costs %d.\n", res);
    }
    printf("\n");
  }
}
