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
int R, C;
int input(){
  grid.clear();
  string line;
  while (getline(cin, line) && line[0] != '_'){
    grid.push_back(line);
  }
  R = grid.size();
  if (R != 0){
    C = grid[0].size();
  }
  grid.push_back(line);
  return 0;
}

bool isValid(int r, int c){
  return 0 <= r && r < R && 0 <= c && c < C;
}

void output(){
  for (int i = 0; i <= R; i++){
    cout << grid[i] << endl;
  }
}
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
void dfs(int r, int c){
  grid[r][c] = '#';
  for (int i = 0; i < 4; i++){
    int nr = r + dr[i], nc = c + dc[i];
    if (isValid(nr, nc) && grid[nr][nc] == ' '){
      dfs(nr, nc);
    }
  }
}
int main(){
  int TestNum;
  cin >> TestNum;
  cin.ignore();
  while (TestNum--){
    input();
    for (int i = 0; i < R; i++){
      for (int j = 0; j < C; j++){
        if (grid[i][j] == '*'){
          dfs(i, j);
        }
      }
    }
    output();
  }
}

