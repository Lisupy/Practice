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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof
 */
const int MAXN = 128;
int m, n;
int a[MAXN][MAXN];
int path[MAXN][MAXN];
int s[MAXN][MAXN];


void gao(int x, int y){

  int f = -1;
  for (int dx = -1; dx <= 1; dx++){
    int nx = (x + dx - 1 + n) % n + 1;
    if (f == -1 || a[nx][y + 1] < a[f][y + 1] || (a[nx][y + 1] == a[f][y + 1] && nx < f)){
      f = nx;
    }
  }
  a[x][y] += a[f][y + 1];
  path[x][y] = f;
}


int main(){
  while (scanf("%d%d", &n, &m) != EOF){
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= m; j++){
        scanf("%d", &a[i][j]);
      }
    }
    for (int j = m - 1; j >= 1; j--){
      for (int i = 1; i <= n; i++){
        gao(i, j);
      }
    }
    //for (int i = 1; i <= n; i++){
      //for (int j = 1; j <= m; j++){
        //printf("%2d(%2d) ", a[i][j], path[i][j]);
      //}printf("\n");
    //}
    int pos = -1;
    for (int i = 1; i <= n; i++){
      if (pos == -1 || a[i][1] < a[pos][1]){
        pos = i;
      }
    }
    int maxSum = a[pos][1];
    for (int i = 1; i <= m; i++){
      if (i != 1) printf(" ");
      printf("%d", pos);
      pos = path[pos][i];
    }
    printf("\n");
    printf("%d\n", maxSum);
  }
}
