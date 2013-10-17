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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 */
const int MAXN = 512;
char grid[MAXN][MAXN];
int L[MAXN][MAXN];
int R[MAXN][MAXN];
int M[MAXN][MAXN];
int D[MAXN][MAXN];
int U[MAXN][MAXN];
int F[MAXN][MAXN];
int T[MAXN][MAXN];
void reset(){
  memset(L, 0, sizeof(L));
  memset(R, 0, sizeof(L));
  memset(U, 0, sizeof(L));
  memset(D, 0, sizeof(L));
  memset(T, 0, sizeof(L));
  memset(F, 0, sizeof(L));
  memset(M, 0, sizeof(M));
}

int n;
void p_grid(const char *buf, int c[MAXN][MAXN]){
  printf("%s \n", buf);
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      printf("%3d", c[i][j]);
    }
    printf("\n");
  }
}

int TestNum;
int main(){
  while (scanf("%d", &n) != EOF){
    reset();
    for (int i = 1; i <= n; i++) {
      scanf("%s", grid[i] + 1);
    }
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        if (grid[i][j] == 'x'){
          L[i][j] = L[i][j - 1] + 1;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = n; j >= 1; j--) {
        if (grid[i][j] == 'x'){
          R[i][j] = R[i][j + 1] + 1;
        }
      }
    }
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        M[i][j] = min(L[i][j], R[i][j]);
      }
    }
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        if (grid[i][j] == 'x'){
          U[i][j] = U[i - 1][j] + 1;
        }
      }
    }
    for (int i = n; i >= 1; i--){
      for (int j = 1; j <= n; j++){
        if (grid[i][j] == 'x'){
          D[i][j] = D[i + 1][j] + 1;
        }
      }
    }
    i64 total = 0;
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        F[i][j] = min(F[i - 1][j - 1] + 1, min(U[i][j], L[i][j]));
        if (F[i][j] > 0) total += (F[i][j] - 1);
      }
    }
    //cout << total << endl;
    //p_grid("F", F);
    memset(U, 0, sizeof(U));
    memset(D, 0, sizeof(D));
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        U[i][j] = min(M[i][j], U[i - 1][j] + 1);
        if (U[i][j] < 0) U[i][j] = 0;
      }
    }
    for (int i = n; i >= 1; i--){
      for (int j = 1; j <= n; j++){
        D[i][j] = min(M[i][j], D[i + 1][j] + 1);
        if (D[i][j] < 0) D[i][j] = 0;
      }
    }
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        if (grid[i][j] == 'x'){
          T[i][j] = min(U[i][j], D[i][j]);   
          total += T[i][j] - 1;
        }
      }
    }
    //p_grid("T", T);
    //p_grid("L", L);
    //p_grid("R", R);
    //p_grid("M", M);
    //p_grid("D", D);
    //p_grid("U", T);
    printf("%lld\n", total);
  }
}

