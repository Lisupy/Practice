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
int N, M;
char grid[256][256];
int step[256][256];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, 1, 0,  0}; 
bool isValid(int x, int y){
  return 0 <= x && x < N && 0 <= y && y < M;
}
void reset(){


}
struct Pos{
  int x, y;
};
Pos findCh(char ch){
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      if (grid[i][j] == ch){
        return {i, j};
      }
    }
  }
  assert(0);
  return {0, 0};
}
int solve1(){
  memset(step, 0x1f, sizeof(step));
  Pos start = findCh('A'); 
  list<Pos> Q;
  Q.push_back(start);
  step[start.x][start.y] = 0;
  while (Q.size()){
    Pos p = Q.front(); Q.pop_front();
    for (int i = 0; i < 4; i++){
      int nx = p.x + dx[i], ny = p.y + dy[i];
      if (!isValid(nx, ny)) return step[p.x][p.y];
      if (step[nx][ny] != 0x1f1f1f1f) continue;
      Pos np = {nx, ny};
      step[np.x][np.y] = step[p.x][p.y];
      if (grid[p.x][p.y] == grid[np.x][np.y]){
        Q.push_front(np);
      }else{
        step[np.x][np.y]++;
        Q.push_back(np);
      }
    }
  }
  //assert(0);
  return 1;
}
int solve2(){
  Pos start = findCh('A'); 
  set<char> S;
  for (int i = 0; i < 4; i++){
    int nx = start.x + dx[i], ny = start.y + dy[i];
    if (isValid(nx, ny))S.insert(grid[nx][ny]);
  }
  return S.size();
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (scanf("%d%d", &N, &M) &&N){
    for (int i = 0; i < N; i++) scanf("%s", grid[i]);
    //cout << solve1() << endl;
    printf("%d\n", solve1() + solve2() - 1);
  }
}

