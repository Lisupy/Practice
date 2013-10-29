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
 * (1 << (41 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
//inline
//int __builtin_popcount(int x){
  //int s = 0;
  //while (x){
    //s++;
    //x &= x - 1;
  //}
  //return s;
//}
//inline
//int __builtin_ctz(int x){
  //int s = 0;
  //while (((1 << s) & x) == 0){
    //s++;
  //}
  //return s;
//}
struct Sudoku{
  char mat[16][16];
  int lineused[16];
  int colused[16];
  int rectused[16];
  int all[16][16];
  int ux[256];
  int uy[256];
  int usz;
  bool isValid(){
    for (int i = 0; i < 16; i++){
      for (int j = 0; j < 16; j++){
        all[i][j] = ~(lineused[i] | colused[j] | rectused[i/4*4+4]);
      }
    }
    for (int i = 0; i < 16; i++){
      int mask = 0;
      for (int j = 0; j < 16; j++){
        mask |= all[i][j];
      }
      if (((~lineused[i]) & mask) != (~lineused[i])) return false; 
    }
    for (int i = 0; i < 16; i++){
      int mask = 0;
      for (int j = 0; j < 16; j++){
        mask |= all[j][i];
      }
      if (((~colused[i]) & mask) != (~colused[i])) return false; 
    }
    return true;
  }
  void display(){
    for (int i = 0; i < 16; i++){
      for (int j = 0; j < 16; j++){
        cout << (char)(mat[i][j] + 'A' - 1);
      }
      cout << endl;
    }
    cout << endl;
  }
  void reset(){
    memset(lineused, 0, sizeof(lineused));
    memset(colused , 0, sizeof(colused ));
    memset(rectused, 0, sizeof(rectused));
  }
  void set(int x, int y, int v){
    int mask = 1 << v;
    lineused[x] |= mask;
    colused[y] |= mask;
    rectused[x/4*4+y/4] |= mask;
  }
  void unset(int x, int y, int v){
    int mask = 1 << v;
    lineused[x] &= ~mask;
    colused[y] &= ~mask;
    rectused[x/4*4+y/4] &= ~mask;
  }
  int usedMask(int x, int y){
    return lineused[x] | colused[y] | rectused[x/4*4+y/4];
  }
  bool isUsed(int x, int y, int v){
    return usedMask(x, y) & (1 << v);
  }
  void init(){
    usz = 0;
    for (int i = 0; i < 16; i++){
      string s; cin >> s;
      for (int j = 0; j < 16; j++){
        char ch = s[j];
        if (ch == '-'){
          mat[i][j] = 0;
          ux[usz] = i;
          uy[usz] = j;
          usz++;
        }
        else mat[i][j] = ch - 'A' + 1;
      }
    }
    reset();
    for (int i = 0; i < 16; i++){
      for (int j = 0; j < 16; j++){
        if (mat[i][j] != 0) set(i, j, mat[i][j]);
      }
    }
  }
};
bool solve(Sudoku &sudoku, int p){
  if (p == 40){
    sudoku.display();
    return true;
  }
  int cnt = 0;
  int x, y;
  int mask = 0;
  int sel = 0;
  for (int k = 0; k < sudoku.usz; k++){
    int i = sudoku.ux[k], j = sudoku.uy[k];
    int t = __builtin_popcount(sudoku.usedMask(i, j));
    if (t == 16) return false;
    if (t >= cnt){
      cnt = t;
      x = i, y = j;
      sel = k;
      mask = sudoku.usedMask(i, j);
    }
  }
  if (cnt >= 2 && sudoku.isValid()){
    return false;
  }
  sudoku.usz--;
  swap(sudoku.ux[sel], sudoku.ux[sudoku.usz]);
  swap(sudoku.uy[sel], sudoku.uy[sudoku.usz]);
  for (int ch = 1; ch <= 16; ch++){
    if (mask & (1<< ch)) continue;
    sudoku.mat[x][y] = ch;
    sudoku.set(x, y, ch);
    if (solve(sudoku, p - 1)) return true;
    sudoku.unset(x, y, ch);
  }
  sudoku.mat[x][y] = 0;
  swap(sudoku.ux[sel], sudoku.ux[sudoku.usz]);
  swap(sudoku.uy[sel], sudoku.uy[sudoku.usz]);
  sudoku.usz++;
  return false;
}
int TestNum;
int kase;
int main(){
  ios_base::sync_with_stdio(false); 
  Sudoku sudoku;
  sudoku.init();
  solve(sudoku, sudoku.usz);
}

