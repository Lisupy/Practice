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
const int MAXN = 256;
char maze[MAXN][MAXN];
char omaze[MAXN][MAXN]; 
bool visited[MAXN][MAXN];
char tr1[3][4] = {
  "  #",
  " # ",
  "#  ", 
};
char tr2[3][4] = {
  "#  ",
  " # ",
  "  #", 
};
int w, h;
bool isValid(int x, int y){
  return 0 <= x && x < 3 * h && 0 <= y && y < 3 * w;
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(int x, int y, int &st, bool &valid){
  if (maze[x][y] == '#'){
    valid = false;
    return;
  }
  //cout << "(" << x << ", " << y << ") :" <<  maze[x][y] << endl;
  visited[x][y] = true;
  st++;
  for (int i = 0; i < 4; i++){
    int tx = x + dx[i], ty = y + dy[i];
    //printf("  %d %d: %c %d\n", tx, ty, maze[tx][ty], visited[tx][ty]); 
    if (!isValid(tx, ty)){
      valid = false;
      continue;
    }
    //printf("  %d %d: %c %d\n", tx, ty, maze[tx][ty], visited[tx][ty]); 
    if (maze[tx][ty] == '#') continue;
    if (visited[tx][ty]) continue;
    dfs(tx, ty, st, valid);
  }
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (scanf("%d%d", &w, &h) && w){
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < h; i++){
      scanf("%s", omaze[i]);
    }
    for (int i = 0; i < h; i++){
      for (int j = 0; j < w; j++){
        char (*tr)[3][4] = omaze[i][j] == '/' ? &tr1 : &tr2;
        for (int x = 3 * i; x < 3 * i + 3; x++){
          for (int y = 3 * j; y < 3 * j + 3; y++){
            maze[x][y] = (*tr)[x%3][y%3];
          }
        }
      }
    }
    //for (int i = 0; i < 3 * h; i++){
      //for (int j = 0; j < 3 * w; j++){
        //printf("%c", maze[i][j]);
      //}
      //printf("\n");
    //}
    int longest = -1;
    int cnt = 0;
    for (int i = 0; i < 3 * h; i++){
      for (int j = 0; j < 3 * w; j++){
        if (visited[i][j]) continue;
        bool valid = true;
        //printf("%d %d:\n", i, j);
        int len = 0;
        dfs(i, j, len, valid);
        if (valid){ 
          //printf("valid %d %d: %d\n", i, j, len);
          cnt++;
          longest = max(longest, len);
        }
      }
    }
    printf("Maze #%d:\n", ++TestNum);
    if (cnt != 0) printf("%d Cycles; the longest has length %d.\n", cnt, (longest + 1)/ 3);
    else printf("There are no cycles.\n");
    printf("\n");
  }
}

