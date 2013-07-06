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

int T;
const int MAXN = 128;

char  graph[MAXN][MAXN];
int R, C;

void input(){
  memset(graph, ' ', sizeof(graph));
  C = 0;
  R = 0;
  while (fgets(graph[R], MAXN, stdin) && strcmp(graph[R], "#\n") != 0){
    size_t len = strlen(graph[R]);
 //   graph[R][len] = ' ';
    graph[R][len - 1] = ' ';
    C = max(C, (int)len);
    R++;
  }
  //printf("Input Done!");
  //for (int i = 0; i < R; i++){
    //printf("[%s]\n", graph[i]);
  //}
}
bool valid(int x, int y){
  return 0 <= x && x < R && 0 <= y && y < C;
}
void dfs(int x, int y){
  printf("%c", graph[x][y]);
  int nx = x + 1, ny = y;
  printf("(");
  if (valid(nx, ny)  && graph[nx][ny] == '|'){
    nx = x + 2;
    while (valid(nx, ny - 1) && graph[nx][ny - 1] == '-'){
      ny--;
    }
    while(valid(nx, ny) && graph[nx][ny] == '-'){
      //printf("%d %d\n", nx, ny);
      if (graph[nx + 1][ny] != ' ' && graph[nx + 1][ny] != '\n' && graph[nx + 1][ny] != '\0'){
        dfs(nx + 1, ny);
      }
      ny++;
    }
  }
  printf(")");
}
  


int main(){
  scanf("%d", &T);
  while (T--){
    input();
    printf("(");
    for (int i = 0; i < R; i++){
      for (int j = 0; graph[i][j]; j++){
        if (graph[i][j] != ' ' && graph[i][j] != '\n'){
          dfs(i, j);
          goto out;
        }
      }
    }
out:
    printf(")");
    printf("\n");
  }
}
