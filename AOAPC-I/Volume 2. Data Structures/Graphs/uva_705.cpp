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


vector<string> grid;
int w, h;
int w3, h3;
int input(){
  cin >> w >> h;
  w3 = w * 3; h3 = h * 3;
  string s;
  grid.resize(h3);
  for (int i = 0; i < h3; i++){
    grid[i].resize(w3);
  }
  for (int i = 0; i < h; i++){
    cin >> s;
    for (int j = 0; j < w; j++){
      if (s[j] == '/'){
        grid[i * 3 + 0][j * 3] = ' '; grid[i * 3 + 0][j * 3 + 1] = ' '; grid[i * 3 + 0][j * 3 + 2] = '#';
        grid[i * 3 + 1][j * 3] = ' '; grid[i * 3 + 1][j * 3 + 1] = '#'; grid[i * 3 + 1][j * 3 + 2] = ' ';
        grid[i * 3 + 2][j * 3] = '#'; grid[i * 3 + 2][j * 3 + 1] = ' '; grid[i * 3 + 2][j * 3 + 2] = ' ';
      }else{
        grid[i * 3 + 0][j * 3] = '#'; grid[i * 3 + 0][j * 3 + 1] = ' '; grid[i * 3 + 0][j * 3 + 2] = ' ';
        grid[i * 3 + 1][j * 3] = ' '; grid[i * 3 + 1][j * 3 + 1] = '#'; grid[i * 3 + 1][j * 3 + 2] = ' ';
        grid[i * 3 + 2][j * 3] = ' '; grid[i * 3 + 2][j * 3 + 1] = ' '; grid[i * 3 + 2][j * 3 + 2] = '#';
      }
    }
  }
  return h;
}

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int isValid(int x, int y){
  return 0 <= x && x < h3 && 0 <= y && y < w3;
}

int dfs(int x, int y){
  grid[x][y] = 'X';
  int total = 1;
  bool out = false;
  for (int i = 0; i < 4; i++){
    int nx = x + dx[i], ny = y + dy[i];
    if (!isValid(nx, ny)){
      out = true;
      continue;
    }

    if (grid[nx][ny] == ' '){
      int ret = dfs(nx, ny);
      if (ret == -1){
        out = true;
      }
      total += ret;
    }
  }
  return out ? -1 : total;
}

int main(){
  int TestNum = 0;
  while (input()){
    printf("Maze #%d:\n", ++TestNum);
    int total = 0;
    int longest = 0;
    //for (int i = 0; i < h3; i++){
      //cout << grid[i] << endl;
    //}

    for (int i = 0; i < h3; i++){
      for (int j = 0; j < w3; j++){
        if (grid[i][j] == ' '){
          int ret = dfs(i, j);
          //printf("%d %d=>%d\n", i, j , ret);
          //for (int k = 0; k < h3; k++){
            //cout << grid[k] << endl;
          //}
          if (ret > 0){
            total++;
            longest = max(longest, ret);
          }
        }
      }
    }
    if (total == 0){
      printf("There are no cycles.\n");
    }else{
      printf("%d Cycles; the longest has length %d.\n", total, longest / 3);
    }
    printf("\n");
  }
}

