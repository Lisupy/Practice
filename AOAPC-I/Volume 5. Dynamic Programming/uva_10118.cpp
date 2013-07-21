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

const int MAXN = 42;
int n;
int cache[MAXN][MAXN][MAXN][MAXN];
int piles[4][MAXN];
int dfs(int is[4], vector<int> basket, int cnt){
  if (cnt == 5) return 0;
  int &res = cache[is[0]][is[1]][is[2]][is[3]];
  if (res != -1) return res;
  res = 0;
  for (int i = 0; i < 4; i++){
    if (is[i] > n) continue;
    int color = piles[i][is[i]];
    if (basket[color] == 1){
      basket[color] = 0;
      is[i]++;
      res = max(res, dfs(is, basket, cnt - 1) + 1); 
      is[i]--;
      basket[color] = 1;
    }else{
      basket[color] = 1;
      is[i]++;
      res = max(res, dfs(is, basket, cnt + 1));
      is[i]--;
      basket[color] = 0;
    }
  }
  return res;
}


int main(){
  while (cin >> n && n){
    for (int i = 1; i <= n; i++){
      for (int j = 0; j < 4; j++){
        cin >> piles[j][i];
      }
    }
    memset(cache, -1, sizeof(cache));
    int is[] = {1, 1, 1, 1};
    vector<int> basket(21, 0);
    cout << dfs(is, basket, 0) << endl;
  }
}

