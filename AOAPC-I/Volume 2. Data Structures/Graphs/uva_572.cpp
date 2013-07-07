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

int m, n;

int input(){
  grid.clear();
  cin >> m >> n;
  grid.resize(m);
  for (int i = 0; i < m; i++){
    cin >> grid[i];
  }
  return m;
}

bool isValid(int x, int y){
  return 0 <= x && x < m && 0 <= y && y < n;
}

void dfs(int x, int y){
  grid[x][y] = '*';
  for (int dx = -1; dx <= 1; dx++){
    for (int dy = -1; dy <= 1; dy++){
      if (dx == 0 && dy == 0){
        continue;
      }
      int nx = x + dx, ny = y + dy;
      if (isValid(nx, ny) && grid[nx][ny] == '@'){
        dfs(nx, ny);
      }
    }
  }
}
int main(){
  while (input()){
    int total = 0;
    for (int i = 0; i < m; i++){
      for (int j = 0; j < n; j++){
        if (grid[i][j] == '@'){
          dfs(i, j);
          total++;
        }
      }
    }
    cout << total << endl;
  }
}
