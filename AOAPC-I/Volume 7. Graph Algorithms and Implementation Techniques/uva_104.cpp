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
double d[32][32];
double f[32][32][128];
int path[32][32][128];
int n;
void dfs(int from, int to, int k){
  if (k == 1){
    cout << to << " " << from << " ";
    return;
  }
  dfs(path[to][from][k], to, k - 1);
  cout << from << " ";
}
void solve(){
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      f[i][j][1] = d[i][j];
      path[i][j][1] = i;
    }
  }
  for (int k = 2; k <= n; k++){
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        f[i][j][k] = f[i][j][k - 1];
        path[i][j][k] = j;
      }
    }
    for (int i = 1; i <= n; i++){
      for (int s = 1; s <= n; s++){
        for (int t = 1; t <= n; t++){
          if (f[s][i][k - 1] * d[i][t] > f[s][t][k]){
            f[s][t][k] = f[s][i][k - 1] * d[i][t];
            path[s][t][k] = i;
          }
        }
      }
    }
    for (int i = 1; i <= n; i++){
      if (f[i][i][k] > 1.01){
        //cout << f[i][i][k] << endl;
        dfs(path[i][i][k], i, k - 1);
        cout << i << endl;
        return;
      }
    }
  }
  cout << "no arbitrage sequence exists" << endl;
}
int main(){
  while ( cin >> n){
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        if (i == j) d[i][j] = 1;
        else cin >> d[i][j];
      }
    }
    solve();
  }
}
