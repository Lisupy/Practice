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

vector<string> grid;
int n;
bool isValid(int x, int y){
  int nx = x;
  while (nx < n){
    if (grid[nx][y] == '@')return false;
    if (grid[nx][y] == 'X')break;
    nx++;
  }
  nx = x;
  while (nx >= 0){
    if (grid[nx][y] == '@')return false;
    if (grid[nx][y] == 'X')break;
    nx--;
  }
  int ny = y;
  while (ny < n){
    if (grid[x][ny] == '@')return false;
    if (grid[x][ny] == 'X')break;
    ny++;
  }
  ny = y;
  while (ny >= 0){
    if (grid[x][ny] == '@')return false;
    if (grid[x][ny] == 'X')break;
    ny--;
  }
  return true;
}
int best;
void dfs(int x, int y, int cnt){
  if (y == n){
    y = 0;
    x++;
  }
  if (x == n){
    best = max(best, cnt);
    return;
  }
  if (grid[x][y] == 'X'){
    dfs(x, y + 1, cnt);
  }else{
    dfs(x, y + 1, cnt);
    if (isValid(x, y)){
      grid[x][y] = '@';
      dfs(x, y + 1, cnt + 1);
      grid[x][y] = '.';
    }
  }
}
int main(){
  while (cin >> n && n){
    grid.resize(n);
    for (int i = 0; i < n; i++){
      cin >> grid[i];
    }
    best = 0;
    dfs(0, 0, 0);
    cout << best << endl;
  }
}
