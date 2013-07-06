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

int N;

const int MAXN = 32;
int grid[MAXN][MAXN];
void init(){
  memset(grid, 0, sizeof(grid));
}

string s;
int pos = 0;
void dfs(int x1, int y1, int x2, int y2){
  char ch = s[pos++];
  int L = x2 - x1;
  int L2 = L / 2;
  if (ch == 'p'){
    dfs(x1,       y1 + L2,  x1 + L2,  y2);
    dfs(x1,       y1,       x1 + L2,  y1 + L2);
    dfs(x1 + L2,  y1,       x2,       y1 + L2);
    dfs(x1 + L2,  y1 + L2,  x2,       y2);
  }else{
    if (ch == 'f'){
      for (int i = x1; i < x2; i++){
        for (int j = y1; j < y2; j++){
          grid[i][j] = 1;
        }
      }
    }
  }
}

int total(){
  return accumulate(&grid[0][0], &grid[MAXN - 1][MAXN - 1] + 1, 0);
}

int main(){
  cin >> N;
  while (N--){
    init();
    for (int i = 0; i < 2; i++){
      cin >> s;
      pos = 0;
      dfs(0, 0, MAXN, MAXN);
    }
    printf("There are %d black pixels.\n", total());
  }
}
