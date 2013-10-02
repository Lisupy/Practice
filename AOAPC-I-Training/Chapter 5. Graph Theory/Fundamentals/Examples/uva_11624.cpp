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
const int MAXN = 1024;
char maze[MAXN][MAXN];
int R, C;
int isValid(int r, int c){
  return 1 <= r && r <= R && 1 <= c && c <= C;
}
int isOK(int r, int c){
  return r == 0 || r == R + 1 || c == 0 || c == C + 1;
}
void input(){
  memset(maze, '.', sizeof(maze));
  scanf("%d%d", &R, &C);
  for (int i = 1; i <= R; i++){
    scanf("%s", &maze[i][1]);
    maze[i][C + 1] = '.';
  }
}
struct Pos{
  int r, c;
  char ch;
  int step;
  Pos(int _r, int _c, char _ch, int _step): r(_r), c(_c), ch(_ch), step(_step){}
};
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int solve(){
  queue<Pos> Q;
  for (int r = 1; r <= R; r++){
    for (int c = 1; c <= C; c++){
      char ch = maze[r][c];
      if (ch == 'J'){
        Q.push(Pos(r, c, ch, 0)); 
      }
    }
  }
  for (int r = 1; r <= R; r++){
    for (int c = 1; c <= C; c++){
      char ch = maze[r][c];
      if (ch == 'F'){
        Q.push(Pos(r, c, ch, 0)); 
      }
    }
  }
  while (Q.size()) {
    Pos p = Q.front(); Q.pop(); 
    for (int i = 0; i < 4; i++){
      int x = p.r + dx[i], y = p.c + dy[i];
      Pos t = Pos(x, y, p.ch, p.step + 1);
      if (p.ch == 'F'){
        if (isValid(x, y) && (maze[x][y] == '.' || maze[x][y] == 'J')){
          maze[x][y] = 'F';
          Q.push(t);
        }
      }
      if (p.ch == 'J' && maze[p.r][p.c] == 'J'){
        if (isOK(x, y)) return p.step + 1;
        if (isValid(x, y) && (maze[x][y] == '.')){
          maze[x][y] = 'J';
          Q.push(t);
        }
      }
    }
  }
  return -1;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  scanf("%d", &TestNum);
  while (TestNum--) {
    input();
    int ans = solve();
    if (ans == -1) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
  }
}

