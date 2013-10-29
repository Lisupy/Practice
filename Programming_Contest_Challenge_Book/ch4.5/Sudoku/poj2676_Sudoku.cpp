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
const double PI = acos(-1);
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */

string mat[9];
bitset<9> lineused[9];
bitset<9> colused[9];
bitset<9> rectused[9];
void reset(){
  for (int i = 0; i < 9; i++){
    lineused[i].reset();
    colused[i].reset();
    rectused[i].reset();
  }
}
void set1(int x, int y, char ch){
  int v = ch - '1';
  lineused[x].set(v);
  colused[y].set(v);
  rectused[x/3*3+y/3].set(v);
}
void unset(int x, int y, char ch){
  int v = ch - '1';
  lineused[x].reset(v);
  colused[y].reset(v);
  rectused[x/3*3+y/3].reset(v);
}
bool isUsed(int x, int y, char ch){
  int v = ch - '1';
  if (lineused[x].test(v)) return true;
  if (colused[y].test(v)) return true;
  if (rectused[x/3*3+y/3].test(v)) return true;
  return false;
}
bool solve(int x, int y){
  if (y == 9){
    y = 0, x++;
  }
  if (x == 9){
    return true;
  }
  if (mat[x][y] != '0') return solve(x, y + 1);
  for (char ch = '1'; ch <= '9'; ch++){
    if (!isUsed(x, y, ch)){
      mat[x][y] = ch;
      set1(x, y, ch);
      if (solve(x, y + 1)) return true;
      unset(x, y, ch);
    }
  }
  mat[x][y] = '0';
  return false;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  cin >> TestNum;
  while (TestNum--){
    for (int i = 0; i < 9; i++) cin >> mat[i];
    reset();
    for (int i = 0; i < 9; i++){
      for (int j = 0; j < 9; j++){
        if (mat[i][j] != '0') set1(i, j, mat[i][j]);
      }
    }
    solve(0, 0);
    for (int i = 0; i < 9; i++) cout << mat[i] << endl;
  }
}

