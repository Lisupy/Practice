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
const int INF = 0xffffffff;
const int MAXN = 32;
int N, M;
vector<string> grid;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1,  0,-1};
size_t dist[MAXN][MAXN][5][4];
struct Pos{
  int x, y, c;
  int d;
};
int isValid(Pos p){
  return 0 <= p.x && p.x < M && 0 <= p.y && p.y < N;
}

Pos turn_left(Pos p){
  return {p.x, p.y, p.c, (p.d + 1) % 4};
}
Pos turn_right(Pos p){
  return {p.x, p.y, p.c, (p.d + 3) % 4};
}
Pos forward(Pos p){
  return {p.x + dx[p.d], p.y + dy[p.d], (p.c + 1) % 5, p.d};
}
int bfs(Pos from, Pos to){
  queue<Pos> Q;
  Q.push(from);
  memset(dist, -1, sizeof(dist));
  dist[from.x][from.y][from.c][from.d] = 0;
  while (!Q.empty()){
    Pos s = Q.front();
    Q.pop();
    Pos ts[] = {forward(s), turn_left(s), turn_right(s)};
    for (int i = 0; i < 3; i++){
      Pos t = ts[i];
      if (isValid(t) && grid[t.x][t.y] != '#' && dist[t.x][t.y][t.c][t.d] > dist[s.x][s.y][s.c][s.d] + 1){
        dist[t.x][t.y][t.c][t.d] = dist[s.x][s.y][s.c][s.d] + 1;
        Q.push(t);
      }
    }
  }
  return *min_element(dist[to.x][to.y][to.c], dist[to.x][to.y][to.c] + 4);
}

Pos posFind(char ch){
  for (int i = 0; i < M; i++){
    for (int j = 0; j < N; j++){
      if (grid[i][j] == ch){
        return {i, j, 0, 2};
      }
    }
  }
  assert(0);
}

int TestNum;
int main(){
  while (cin >> M >> N && M){
    if (TestNum){
      printf("\n");
    }
    printf("Case #%d\n", ++TestNum);
    grid.resize(M);
    for (int i = 0; i < M; i++){
      cin >> grid[i];
    }
    Pos from = posFind('S');
    Pos to = posFind('T');
    int ans = bfs(from, to);
    if (ans != INF){
      printf("minimum time = %d sec\n", ans);
    }else{
      printf("destination not reachable\n");
    }
  }
}
