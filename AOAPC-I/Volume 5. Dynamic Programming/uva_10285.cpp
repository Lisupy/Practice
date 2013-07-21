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
const int MAXN = 128;
int R, C;
int longest[MAXN][MAXN];
int height[MAXN][MAXN];

int dr[] = {1, -1,  0, 0};
int dc[] = {0,  0, -1, 1};
bool valid(int r, int c){
  return 0 <= r && r < R && 0 <= c && c < C;
}
int dp(int r, int c){
  if (longest[r][c] != -1){
    return longest[r][c];
  }
  longest[r][c] = 1;
  for (int i = 0; i < 4; i++){
    int nr = r + dr[i], nc = c + dc[i];
    if (valid(nr, nc) && height[nr][nc] < height[r][c]){
      longest[r][c] = max(longest[r][c], dp(nr, nc) + 1);
    }
  }
  return longest[r][c];
}
int main(){
  int TestNum;
  cin >> TestNum;
  while (TestNum--){
    string tmp;
    cin >> tmp;
    cout << tmp << ": ";
    cin >> R >> C;
    for (int i = 0; i < R; i++){
      for (int j = 0; j < C; j++){
        cin >> height[i][j];
        longest[i][j] = -1;
      }
    }
    int ans = 1;
    for (int i = 0; i < R; i++){
      for (int j = 0; j < C; j++){
        ans = max(ans, dp(i, j));
      }
    }
    cout << ans << endl;
  }
}

