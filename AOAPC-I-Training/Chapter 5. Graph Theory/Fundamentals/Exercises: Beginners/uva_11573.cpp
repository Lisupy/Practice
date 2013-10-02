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
struct Pos{
  int r, c;
  int type;
  int cost;
  Pos(int _r, int _c, int _type = 0):r(_r), c(_c), type(_type), cost(0){} 
};
Pos dirs[] = {
  Pos(-1, -1, 7), Pos(-1, 0, 0), Pos(-1, 1, 1), 
  Pos( 0, -1, 6),                Pos( 0, 1, 2),
  Pos( 1, -1, 5), Pos( 1, 0, 4), Pos( 1, 1, 3)};

int R, C;
bool isValid(int r, int c){
  return 1 <= r && r <= R && 1 <= c && c <= C;
}
const int MAXN = 1024;
int grid[MAXN][MAXN];
int step[MAXN][MAXN];
struct posGreater{
  bool operator()(const Pos &a, const Pos &b){
    return a.cost > b.cost;
  }
};
void solve(int rs, int cs, int rd, int cd){
  priority_queue<Pos, vector<Pos>, posGreater> Q;
  //list<Pos> Q;
  memset(step, 0x1f, sizeof(step));

  step[rs][cs] = 0;
  //Q.push_back(Pos(rs, cs));
  Q.push(Pos(rs, cs));
  while (Q.size()){
    //Pos p = Q.front(); Q.pop_front(); 
    Pos p = Q.top(); Q.pop(); 
    //cout << p.r << ", " << p.c << ": " << step[p.r][p.c] << endl;
    for (int i = 0; i < 8; i++){
      Pos dir = dirs[i];
      Pos pt = Pos(p.r + dir.r, p.c + dir.c);
      if (!isValid(pt.r, pt.c)) continue;
      int newStep = step[p.r][p.c] + (dir.type == grid[p.r][p.c] ? 0 : 1);
      if (step[pt.r][pt.c] <= newStep) continue;
      pt.cost = newStep;
      step[pt.r][pt.c] = newStep;
      //if (grid[p.r][p.c] == dir.type) Q.push_front(pt);
      //else Q.push_back(pt);
      Q.push(pt);
    }
  }
  printf("%d\n", step[rd][cd]);
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (scanf("%d%d", &R, &C) != EOF){
    for (int i = 1; i <= R; i++){
      for (int j = 1; j <= C; j++){
        scanf("%1d", &grid[i][j]);
      }
    }
    int T; scanf("%d", &T);
    while (T--){
      int rs, cs, rd, cd;
      scanf("%d%d%d%d", &rs, &cs, &rd, &cd); 
      solve(rs, cs, rd, cd);
    }
  }
}

