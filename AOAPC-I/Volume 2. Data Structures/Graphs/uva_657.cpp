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

int w, h;
const int MAXN = 64;

bool isValid(int r, int c){
  return 0 <= r && r < h && 0 <= c && c < w;
}

vector<string> grid;

int input(){
  cin >> w >> h;
  grid.resize(h);
  for (int i = 0; i < h; i++){
    cin >> grid[i];
  }
  return w;
}
int dr[] = {0, 0, 1, -1};
int dc[] = {1,-1, 0,  0};

int dfs2(int r, int c){
  int total = 0;
  if (grid[r][c] == 'X'){
    total++;
  }
  grid[r][c] = '*';
  for (int i = 0; i < 4; i++){
    int nr = r + dr[i], nc = c + dc[i];
    if (isValid(nr, nc)){
      if (grid[nr][nc] == 'X'){
        total += dfs2(nr, nc);
      }
    }
  }
  return total;
}
int dfs(int r, int c){
  int total = 0;
  if (grid[r][c] == 'X'){
    total++;
  }
  grid[r][c] = '.';
  for (int i = 0; i < 4; i++){
    int nr = r + dr[i], nc = c + dc[i];
    if (isValid(nr, nc)){
      if (grid[nr][nc] != '.'){
        total += dfs(nr, nc);
      }
    }
  }
  return total;
}
void debug(){
  for (int i = 0; i < h; i++){
    cout << grid[i] << endl;
  }
}
int TestNum;
int main(){
  while (input()){
    vector<int> res;
    printf("Throw %d\n", ++TestNum);
    for (int i = 0; i < h; i++){
      for (int j = 0; j < w; j++){
        if (grid[i][j] == 'X'){
          dfs2(i, j);
          grid[i][j] = 'X';
        }
      }
    }
    //debug();    
    for (int i = 0; i < h; i++){
      for (int j = 0; j < w; j++){
        if (grid[i][j] != '.'){
          res.push_back(dfs(i, j));
        }
      }
    }
    sort(res.begin(), res.end());
    for (size_t i = 0; i < res.size(); i++){
      if (i != 0){
        cout << " ";
      }
      cout << res[i];
    }
    cout << endl;
    cout << endl;
  }
}

