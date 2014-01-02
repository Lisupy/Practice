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
int costTable[4][4][16];

static inline int __calcCost(int v, int x, int y){
  int _x = v / 4;
  int _y = v % 4;
  return abs(_x - x) + abs(_y - y);
}
void costTableInit(){
  for (int v = 0; v < 16; v++){
    for (int x = 0; x < 4; x++){
      for (int y = 0; y < 4; y++){
        costTable[x][y][v] = __calcCost(v, x, y);
      }
    }
  }
}
struct State{
  int data[4][4];
  int dist;
  int score;
  char steps[51];
  int stepsSz;
  u64 h;
  void display(){
    cout << "dist: " << dist << ", " << steps << ", score: " << score << endl;
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        cout << data[i][j] << " ";
      }
      cout << endl;
    }
    cout <<endl;
  }
  void init(){
    dist = 0;
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        if(data[i][j] != 15){
          dist += costTable[i][j][data[i][j]];
        }
      }
    }
    score = dist + stepsSz;
    h = 0;
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        h = h * 16 + data[i][j];
      }
    }
  }
  bool reacherAble(){
    vector<int> a;
    int spaceMove = 0;
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        a.push_back(data[i][j]);
        if (data[i][j] == 15){
          spaceMove = abs(3 - i) + abs(3 - j);
        }
      }
    }
    for (int i = 0; i < 16; i++){
      for (int j = i + 1; j < 16; j++){
        if (a[i] > a[j]) spaceMove--;
      }
    }
    return spaceMove % 2 == 0;
  }

};
State gao(State &s, int x, int y, int nx, int ny, char ch){
  State t = s;
  t.steps[t.stepsSz++] = ch;
  swap(t.data[x][y], t.data[nx][ny]);
  t.init();
  return t;
}
bool operator<(const State &a, const State &b){
  //if (a.ok / 4 != b.ok / 4) return a.ok < b.ok;
  //if (a.distv != b.distv) return a.distv > b.distv;
  //if (a.empty != b.empty) return a.empty > b.empty;
  return a.score > b.score;
}
const char* move_name = "LRUD";
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
void solve(State from){
  priority_queue<State> open;
  map<u64, int> closed;
  from.init();
  open.push(from);
  if (from.dist == 0) {
    cout << endl;
    return;
  } 
  while (open.size()){
    State s = open.top(); open.pop();
    closed[s.h] = s.score;
    //if (s.dist < 5){
      //s.display();
    //}

    int x = 0, y = 0;
    for (x = 0; x < 4; x++){
      for (y = 0; y < 4; y++){
        if (s.data[x][y] == 15){
          goto findOK;
        }
      }
    }
    assert(0);
findOK:

    for (int i = 0; i < 4; i++){
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx == 4 || ny == 4) continue;
      State t = gao(s, x, y, nx, ny, move_name[i]);
      if (t.dist == 0){
        //t.display();
        cout << t.steps << endl;
        return;
      }
      if (t.stepsSz + t.dist > 50) continue;
      map<u64, int>::iterator it = closed.find(t.h);
      if (it != closed.end()){
        if (t.score >= it->second) continue;
        closed.erase(it);
      }
      open.push(t);
    }
  }
}

int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  costTableInit();
  scanf("%d", &TestNum);
  while (TestNum--){
    State s;
    memset(&s, 0, sizeof(s));
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        int v; scanf("%d", &v);
        v = v == 0? 15: v - 1;
        s.data[i][j] = v;
      }
    }
    if (s.reacherAble()){
      solve(s);
    }else{
      cout << "This puzzle is not solvable." << endl;
    }
  }
}


