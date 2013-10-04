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

const int INF = 0x1f1f1f1f;
const int MAXN = 32;
int M, N;
/*  
 *  +--> y
 *  |
 *  x
 */
int dx[] = {-1, 0, 1, 0};
int dy[] = { 0, 1, 0,-1};
struct Pos{
  int x, y;
  int color;
  int dir;
  bool isValid(){
    return 1 <= x && x <= M && 1 <= y && y <= N;
  }
  Pos moveOn(){
    return {x + dx[dir], y + dy[dir], (color + 1)%5, dir}; 
  }
  Pos turnLeft(){
    return {x, y, color, (dir + 3) % 4};
  }
  Pos turnRight(){
    return {x, y, color, (dir + 1) % 4};
  }
  Pos action(int i){
    if (i == 0) return moveOn();
    if (i == 1) return turnLeft();
    if (i == 2) return turnRight();
    assert(0);
    return *this;
  }
  void display(string s = ""){
    printf("%s: (%d, %d), %d, %d\n", s.c_str(), x, y, color, dir);
  }
};
char grid[MAXN][MAXN];
int tick[MAXN][MAXN][5][4];
Pos findCh(char ch){
  for (int x = 1; x <= M; x++){
    for (int y = 1; y <= N; y++){
      if (grid[x][y] == ch) return {x, y, 0, 0};
    }
  }
  assert(0);
  return {0, 0, 0, 0};
}
int solve(){
  memset(tick, 0x1f, sizeof(tick));  
  Pos start = findCh('S');
  Pos target = findCh('T');
  //start.display("S");
  //start.display("T");
  queue<Pos> Q;
  Q.push(start);
  tick[start.x][start.y][start.color][start.dir] = 0;
  while (Q.size()){
    Pos s = Q.front(); Q.pop();
    //s.display("Pop");
    for (int i = 0; i < 3; i++){
      Pos t = s.action(i);
      if (!t.isValid()) continue;
      if (tick[t.x][t.y][t.color][t.dir] != INF) continue;
      if (grid[t.x][t.y] == '#') continue;
      tick[t.x][t.y][t.color][t.dir] = tick[s.x][s.y][s.color][s.dir] + 1;
      Q.push(t);
      //s.display("   Push");
    }
  }
  int best = INF;
  for (int i = 0; i < 4; i++){
    target.dir = i;
    best = min(best, tick[target.x][target.y][target.color][target.dir]);
  }
  return best;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (scanf("%d%d", &M, &N) && M){
    for (int i = 1; i <= M; i++) scanf("%s", grid[i] + 1);
    if (TestNum) printf("\n");
    printf("Case #%d\n", ++TestNum);
    int ans = solve();
    if (ans == INF) printf("destination not reachable\n");
    else printf("minimum time = %d sec\n", ans);
  }
}

