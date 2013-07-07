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

const int MAXN = 32;
char grid[MAXN][MAXN][MAXN];
int step[MAXN][MAXN][MAXN];
struct Pos{
  int x, y, z;
};

int dx[] = {-1, 1,  0, 0,  0, 0};
int dy[] = {0,  0, -1, 1,  0, 0};
int dz[] = {0,  0,  0, 0, -1, 1};
int L, R, C;
bool isValid(Pos p){
  return 0 <= p.x && p.x < L && 0 <= p.y && p.y < R && 0 <= p.z && p.z < C;
}

int bfs(Pos from, Pos to){
  memset(step, -1, sizeof(step));
  queue<Pos> Q;
  step[from.x][from.y][from.z] = 0;
  Q.push(from);
  while (!Q.empty()){
    Pos s = Q.front();
    Q.pop();
    for (int i = 0; i < 6; i++){
      Pos t = {s.x + dx[i], s.y + dy[i], s.z + dz[i]};
      if (isValid(t) && grid[t.x][t.y][t.z] != '#' && step[t.x][t.y][t.z] == -1){
        step[t.x][t.y][t.z] = step[s.x][s.y][s.z] + 1;
        Q.push(t);
      }
    }
  }
  return step[to.x][to.y][to.z];
}

Pos posFind(char ch){
  for (int i = 0; i < L; i++){
    for (int j = 0;j < R; j++){
      for (int k = 0; k < C; k++){
        if (grid[i][j][k] == ch){
          return {i, j, k};
        }
      }
    }
  }
  assert(0);
}

int main(){
  while (scanf("%d %d %d", &L, &R, &C) && L){
    scanf("\n");
    for( int i = 0; i < L; i++){
      for (int j = 0; j < R; j++){
        fgets(grid[i][j], MAXN, stdin);
        //puts(grid[i][j]);
      }
      scanf("\n");
    }
    Pos from = posFind('S');
    Pos to   = posFind('E');
    int ans = bfs(from, to);
    if (ans == -1){
      printf("Trapped!\n");
    }else{
      printf("Escaped in %d minute(s).\n", ans);
    }
  }
}

