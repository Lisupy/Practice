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
int TestNum;
int C, n1, n5, n10;
const int INF = 0x1f1f1f1f;
const int MAXV = 500 + 100 * 5 + 10 * 500;
int dp[151][300 + 1][150 + 1];
int dfs(int c, int i1, int i5, int i10){
  if (i1 < 0 || i5 < 0 || i10 < 0) return INF;
  if (c == 0) return 0;
  int &res = dp[c][i5][i10];
  if (res != -1) return res;
  res = INF;
  res = min(res, dfs(c - 1, i1 + 2, i5,     i10 - 1 ) + 1);
  res = min(res, dfs(c - 1, i1 + 2, i5 - 2, i10     ) + 2);
  res = min(res, dfs(c - 1, i1 - 3, i5 - 1, i10     ) + 4);
  res = min(res, dfs(c - 1, i1 - 8, i5    , i10     ) + 8);
  res = min(res, dfs(c - 1, i1 - 3, i5 + 1, i10 - 1 ) + 4);
  return res;
}
int main(){
  cin >> TestNum;
  while (TestNum--){
    cin >> C >> n1 >> n5 >> n10;
    memset(dp, -1, sizeof(dp));
    cout << dfs(C, n1, n5, n10) << endl;
    //int total = 0;
    //while (C && n10 > 0) C--, total += 1, n1 += 2, n5 += 0, n10 -= 1; 
    //while (C && n5 >= 2) C--, total += 2, n1 += 2, n5 -= 2, n10 -= 0; 
    //while (C && n5 >= 1 &&) C--, total += 4, n1 -= 3, n5 -= 1, n10 -= 0; 
    //while (C && n1 >= 8) C--, total += 8, n1 += 8, n5 -= 0, n10 -= 0; 
    //cout << C << endl;
    //cout << total << endl;
  }
}

    
