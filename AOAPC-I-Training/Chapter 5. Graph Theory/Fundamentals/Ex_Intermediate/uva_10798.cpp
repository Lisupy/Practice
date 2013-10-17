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
const int MAXN = 32;
int N;
bool isValid(int x, int y){
  return 1 <= x && x <= N && 1 <= y && y <= N;
}
struct Pos{
  int x, y;
  bool isValid(){
    return 1 <= x && x <= N && 1 <= y && y <= N;
  }
  void display(string s=""){
    printf("%s: %d, %d.", s.c_str(), x, y);
  }
};
char grid[MAXN][MAXN];
Pos findCh(char ch){
  for (int i = 1; i <= N; i++){
    for (int j = 1; j <= N; j++){
      if (grid[i][j] == ch) return {i, j};
    }
  }
  assert(0);
  return {0, 0};
}
int step[MAXN][MAXN];
int dx[] = {0, 0, 1, -1};
int dy[] = {1,-1, 0,  0};
int solve(){
  Pos start = findCh('P');
  memset(step, 0x1f, sizeof(step));
  list<Pos> dl;
  dl.push_back(start);
  step[start.x][start.y] = 0;
  while (dl.size()){
    Pos sp = dl.front(); dl.pop_front();
    sp.display("pop");
    for (int i = 0; i < 4; i++){
      Pos tp = {sp.x + dx[i], sp.y + dy[i]};
      if (tp.isValid() && step[tp.x][tp.y] == 0x1f1f1f1f){
        if (grid[tp.x][tp.y] == 'R'){
          dl.push_back(tp);
          step[tp.x][tp.y] = step[sp.x][sp.y] + 1;
        }else{
          step[tp.x][tp.y] = step[sp.x][sp.y];
          dl.push_front(tp);
        }
      }
    }
  }
  int best = 0x1f1f1f1f;
  for (int i = 1; i <= N; i++){
    best = min(best, step[1][i]);
    best = min(best, step[i][1]);
    best = min(best, step[N][i]);
    best = min(best, step[i][N]);
  }
  return best;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (scanf("%d", &N) && N){
    for (int i = 1; i <= N; i++) scanf("%s", grid[i] + 1);
    printf("At most %d rose(s) trampled.\n", solve());
  }
}

