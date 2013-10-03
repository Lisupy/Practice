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
//extern struct Pos dirs[];
struct Pos{
  int x, y;
  char face;
  // for Dir
  Pos():x(0), y(0), face(0){}
  Pos(int _x, int _y, int _d):x(_x), y(_y), face(_d){}
  int getFaceI(){
    if (face == 'E') return 0;
    if (face == 'S') return 1;
    if (face == 'W') return 2;
    if (face == 'N') return 3;
    assert(0);
    return -1;
  }
};
extern struct Dir dirs[];
struct Dir{
  int dx, dy;
  char face;
  Dir(int _x, int _y):dx(_x), dy(_y), face(0){
    face = getDir();
  }
  char getDir(){
    if (dx == 0 && dy > 0) return 'E';
    if (dx >  0 && dy ==0) return 'S';
    if (dx == 0 && dy < 0) return 'W';
    if (dx <  0 && dy ==0) return 'N';
    assert(0);
    return 0;
  }
  int getDirI(){
    for (int i = 0; i < 4; i++){
      if (dirs[i].dx == dx && dirs[i].dy == dy){
        return i;
      }
    }
    assert(0);
    return -1;
  }
  Dir turnLeft(){
    return Dir(-dy, dx);
  }
  // For Dir
  Dir turnRight(){
    return Dir(dy, -dx);
  }
  Dir turn(char ch){
    if (ch == 'F') return *this;
    if (ch == 'L') return turnLeft();
    if (ch == 'R') return turnRight();
    assert(0);
    return *this;
  }
  void display(){
    printf("%c: %d, %d\n", face, dx, dy);
  }
};
Dir dirs[] = {
  Dir(0, 1), Dir(1, 0), Dir(0, -1), Dir(-1, 0), 
};
vector<string> maze[32][32]; 
int step[32][32][4];
Pos prv[32][32][4];
void reset(){
  memset(step, 0x1f, sizeof(step));
  for (int i = 0; i < 32; i++){
    for (int j = 0; j < 32; j++){
      maze[i][j].clear();
    }
  }
}
int sc, sr, dc, dr;
char sdir;
void input(){
  cin >> sr >> sc >> sdir >> dr >> dc;
  int r, c;
  while (cin >> r && r){
    cin >> c;
    string s;
    while (cin >> s && s != "*"){
      maze[r][c].push_back(s);
    }
  }
}
Dir getDir(char ch){
  for (int i = 0; i < 4; i++){
    if (dirs[i].face == ch) return dirs[i];
  }
  assert(0);
  return dirs[0];
}
char getDirCH(int i){
  return "ESWN"[i];
}
void solve(){
  //cout << sr << dr << sc << dc << endl;
  //if (sr == dr && sc == dc){
    //printf("  (%d,%d)\n", sr, sc);
    //return ;
  //}
  Dir start_dir = getDir(sdir);
  Pos start = Pos(sr + start_dir.dx, sc + start_dir.dy, start_dir.face); 
  //for (int i = 0; i < 4; i++){
    //dirs[i].display();
  //}
  //printf("===\n");
  //start_dir.display();
  //start.display();
  queue<Pos> Q;
  Q.push(start);
  step[start.x][start.y][start.getFaceI()] = 0;
  prv[start.x][start.y][start.getFaceI()] = Pos(sr, sc, start_dir.face);
  while (Q.size()){
    Pos p = Q.front(); Q.pop();
    //printf("pop: "); p.display();
    char ch = p.face;
    vector<string> &vs = maze[p.x][p.y];
    for (size_t i = 0; i < vs.size(); i++){
      string &s = vs[i];
      if (s[0] == ch){
        for (size_t j = 1; j < s.size(); j++){
          Dir pdir = getDir(ch);
          Dir tdir = pdir.turn(s[j]);
          Pos np = Pos(p.x + tdir.dx, p.y + tdir.dy, tdir.getDir());
          if (step[np.x][np.y][np.getFaceI()] == 0x1f1f1f1f){
            step[np.x][np.y][np.getFaceI()] = step[p.x][p.y][p.getFaceI()] + 1;
            prv[np.x][np.y][np.getFaceI()] = p; 
            Q.push(np);
            //printf("      "); pdir.display();
            //printf("     %c", s[j]); tdir.display();
            //printf("   push: "); np.display(); 
          }
        }
      }
    }
  }
  int end_dir = -1;
  for (int i = 0; i < 4; i++){
    if (end_dir == -1 || step[dr][dc][i] < step[dr][dc][end_dir]){
      end_dir = i;
    }
  }
  if (step[dr][dc][end_dir] == 0x1f1f1f1f){
    printf("  No Solution Possible\n");
    return ;
  }
  Pos cur = Pos(dr, dc, getDirCH(end_dir));
  vector<Pos> path;
  while (cur.x != sr || cur.y != sc){
    //cur.display();
    path.push_back(cur);
    cur = prv[cur.x][cur.y][cur.getFaceI()];
  }
  path.push_back(Pos(sr, sc, getDirCH(sdir)));
  reverse(path.begin(), path.end());
  for (size_t i = 0; i < path.size(); i++){
    if (i % 10 == 0){
      if (i != 0) printf("\n");
      printf(" ");
    }
    printf(" (%d,%d)", path[i].x, path[i].y);
  }
  printf("\n");
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  string s;
  while (cin >> s && s != "END") {
    reset();
    printf("%s\n", s.c_str());
    input();
    solve(); 
  }
}

