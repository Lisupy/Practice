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
int L, R, C;
char grid[32][32][32];
int visitTick[32][32][32];
struct Pos{
  int l, r, c;
  Pos(int _l, int _r, int _c): l(_l), r(_r), c(_c) {}
};
bool isValid(Pos p){
  return 1 <= p.l && p.l <= L && 1 <= p.r && p.r <= R && 1 <= p.c && p.c <= C;
}

Pos findInGrid(char ch){
  for (int l = 1; l <= L; l++){
    for (int r = 1; r <= R; r++){
      for (int c = 1; c <= C; c++){
        if (grid[l][r][c] == ch) return Pos(l, r, c);
      }
    }
  }
  assert(0);
  return Pos(0, 0, 0);
}
Pos dirs[] = {
  Pos(1, 0, 0), Pos(-1, 0, 0),
  Pos(0, -1, 0), Pos(0, 1, 0),
  Pos(0,  0,-1), Pos(0, 0, 1)
};
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (scanf("%d %d %d", &L, &R, &C) && L){
    memset(visitTick, 0x1f, sizeof(visitTick));
    for (int l = 1; l <= L; l++){
      for (int r = 1; r <= R; r++){
        scanf("%s", grid[l][r] + 1);
      }
    }
    Pos start = findInGrid('S');
    Pos end = findInGrid('E');
    queue<Pos> Q;
    Q.push(start);
    visitTick[start.l][start.r][start.c] = 0;
    while (Q.size()){
      Pos s = Q.front(); Q.pop();
      for (int i = 0; i < 6; i++){
        Pos dir = dirs[i];
        Pos t = Pos(s.l + dir.l, s.r + dir.r, s.c + dir.c);
        if (!isValid(t)) continue;
        if (grid[t.l][t.r][t.c] == '#') continue;
        if (visitTick[t.l][t.r][t.c] != 0x1f1f1f1f) continue;
        visitTick[t.l][t.r][t.c] = visitTick[s.l][s.r][s.c] + 1;
        Q.push(t);
      }
    }

    if (visitTick[end.l][end.r][end.c] != 0x1f1f1f1f) {
      printf("Escaped in %d minute(s).\n", visitTick[end.l][end.r][end.c]);
    }else{
      printf("Trapped!\n");
    }

  }
}

