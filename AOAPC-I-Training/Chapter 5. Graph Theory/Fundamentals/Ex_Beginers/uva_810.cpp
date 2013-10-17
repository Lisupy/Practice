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

struct Dice{
  int a[6];
  Dice(){
    a[0] = 1;
    a[1] = 2;
    a[2] = 6;
    a[3] = 5;
    a[4] = 4;
    a[5] = 3;
  }
  Dice rotateLeft(){
    Dice b;
    b.a[0] = a[5];
    b.a[1] = a[1];
    b.a[2] = a[4];
    b.a[3] = a[3];
    b.a[4] = a[0];
    b.a[5] = a[2];
    return b;
  }
  Dice rotateRight(){
    Dice b;
    b.a[0] = a[4];
    b.a[1] = a[1];
    b.a[2] = a[5];
    b.a[3] = a[3];
    b.a[4] = a[2];
    b.a[5] = a[0];
    return b;
  }
  Dice rotateUp(){
    Dice b;
    b.a[0] = a[1];
    b.a[1] = a[2];
    b.a[2] = a[3];
    b.a[3] = a[0];
    b.a[4] = a[4];
    b.a[5] = a[5];
    return b;
  }
  Dice rotateDown(){
    Dice b;
    b.a[0] = a[3];
    b.a[1] = a[0];
    b.a[2] = a[1];
    b.a[3] = a[2];
    b.a[4] = a[4];
    b.a[5] = a[5];
    return b;
  }
  Dice rotate(int dir){
    if (dir == 0) return rotateDown();
    if (dir == 1) return rotateUp();
    if (dir == 2) return rotateLeft();
    if (dir == 3) return rotateRight();
    assert(0);
    return *this;
  }
  void display(){
    for (int i = 0; i < 6; i++) printf("%d ", a[i]);
    printf("\n");
  }
};

int R, C, sr, sc, stop, sface;
int maze[16][16];
bool visited[16][16][6][6];
int cnt = 0;
struct Pos{
  int r, c;
};
int dx[] = {1, -1, 0, 0};
int dy[] = {0,  0,-1, 1};
bool dfs(int r, int c, Dice d, vector<Pos> &path, string s = ""){
  if (r == sr && c == sc){
    cnt++;
    if (cnt == 2){
      path.push_back({r, c});
      return true;
    }
  }
  //printf("%s %d, %d: ", s.c_str(), r, c); d.display(); 
  if (visited[r][c][d.a[0]][d.a[1]]) return false;
  visited[r][c][d.a[0]][d.a[1]] = true;
  for (int i = 0; i < 4; i++){
    int nr = r + dx[i], nc = c + dy[i];
    if (1 <= nr && nr <= R && 1 <= nc && nc <= C){
      if (maze[nr][nc] == -1 || maze[nr][nc] == d.a[0]){ 
        if (dfs(nr, nc, d.rotate(i), path, s + "  ")){
          path.push_back({r, c});
          return true;
        }
      }
    }
  }
  //cout << endl;
  return false;
}
Dice getStartDice(int top, int face){
  queue<Dice> Q;
  Dice d;
  set<Dice> M;
  Q.push(d);
  M.insert(d);
  while (!Q.empty()){
    d = Q.front(); Q.pop();
    if (d.a[0] == top && d.a[1] == face) return d;
    for (int i = 0; i < 4; i++){
      Dice t = d.rotate(i);
      if (M.count(t) == 0){
        Q.push(t);
        M.insert(t);
      }
    }
  }
  assert(0);
  return d;
}
bool operator<(const Dice &a, const Dice &b){
  return lexicographical_compare(a.a, a.a+6, b.a, b.a+6);
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  string s;
  while (cin >> s && s != "END") {
    printf("%s\n", s.c_str());
    cin >> R >> C >> sr >> sc >> stop >> sface;
    memset(visited, 0, sizeof(visited));
    cnt = 0;
    for (int i = 1; i <= R; i++){
      for (int j = 1; j <= C; j++){
        cin >> maze[i][j];
      }
    }
    Dice d = getStartDice(stop, sface);
    vector<Pos> path; 
    if (dfs(sr, sc, d, path)){
      reverse(path.begin(), path.end());
      for (size_t i = 0; i < path.size(); i++){
        if (i % 9 == 0){
          if (i != 0) printf("\n");
          printf("  ");
        }
        printf("(%d,%d)", path[i].r, path[i].c);
        if (i + 1 != path.size()) printf(",");
        else printf("\n");
      }
    }else{
      printf("  No Solution Possible\n");
    }
  }
}

