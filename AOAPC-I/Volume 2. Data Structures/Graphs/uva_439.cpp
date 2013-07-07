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

const int MAXN = 8;

struct Pos{
  int x, y;
};

int grid[MAXN][MAXN];


int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2,-2,  2, -2, 1,-1,  1, -1};

bool isValid(Pos a){
  return 0 <= a.x && a.x < MAXN && 0 <= a.y && a.y < MAXN;
}

int bfs(Pos &from, Pos &to){
  memset(grid, 0, sizeof(grid));
  queue<Pos> Q;
  grid[from.x][from.y] = 1;
  Q.push(from);
  while (!Q.empty()){
    Pos s = Q.front();
    Q.pop();
    for (int i = 0; i < 8; i++){
      Pos t = {s.x + dx[i], s.y + dy[i]};
      if (isValid(t) && grid[t.x][t.y] == 0){
        grid[t.x][t.y] = grid[s.x][s.y] + 1;
        Q.push(t);
      }
    }
  }
  return grid[to.x][to.y] - 1;
}



int main(){
  string s1, s2;
  while (cin >> s1 >> s2){
    Pos from = {s1[0] - 'a', s1[1] - '1'};
    Pos to   = {s2[0] - 'a', s2[1] - '1'};
    int moveNum = bfs(from, to);
    printf("To get from %s to %s takes %d knight moves.\n", s1.c_str(), s2.c_str(), moveNum);
  }
}

