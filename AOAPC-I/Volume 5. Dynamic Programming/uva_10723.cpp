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


const int MAXN = 32;
int T;

int lcs(string a, string b){
  vector<vector<int> > dp(a.size() + 1, vector<int>(b.size() + 1));
  for (size_t i = 1; i < dp.size(); i++){
    for (size_t j = 1; j < dp[i].size(); j++){
      if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp.back().back();
}
long long ways[MAXN][MAXN][MAXN * 2];
int gao(string a, string b, int len){
  memset(ways, 0, sizeof(ways));
  ways[0][0][0] = 1; 
  for (int i = 0; i <= (int)a.size(); i++){
    for (int j = 0; j <= (int)b.size(); j++){
      for (int k = 1; k <= len; k++){
        if (a[i - 1] == b[j - 1]){
          ways[i][j][k] += i - 1 >= 0 && j - 1 >= 0 ? ways[i - 1][j - 1][k - 1] : 0;
        }else{
          ways[i][j][k] += i - 1 >= 0 ? ways[i - 1][j][k - 1] : 0;
          ways[i][j][k] += j - 1 >= 0 ? ways[i][j - 1][k - 1] : 0;
        }
      }
    }
  }
  return ways[a.size()][b.size()][len];
}
int main(){
  cin >> T;
  cin.ignore();
  for (int ti = 1; ti <= T; ti++){
    string a, b; //cin >> a >> b;
    getline(cin, a);
    getline(cin, b);
    int l = lcs(a, b);
    int len = a.size() + b.size() - l;
    int ans = gao(a, b, len);
    printf("Case #%d: %d %d\n", ti, len, ans);
  }
}

