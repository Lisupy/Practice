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

//LCS(i, j) = max{ LCS(i - 1, j) , LCS(i, j - 1) }   case a[i] != b[j] 
//LCS(i, j) = LCS(i - 1, j - 1) + 1                  case a[i] == b[j] 
//LCS(i, 0) = 0
//LCS(0, j) = 0

const int MAXN = 32;
int n;
int c[MAXN];
int rc[MAXN];
int r[MAXN];
int rr[MAXN];
int lcs[MAXN][MAXN];
int method_1(){
  int total = 0;
  for (int i = 1; i <= n; i++){
    if (rr[i] == i){
      total++;
    }
  }
  return total;
}
int method_2(){
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      if (rr[i] == rc[j]){
        lcs[i][j] = lcs[i - 1][j - 1] + 1;
      }else{
        lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
      }
    }
  }
  return lcs[n][n];
}

void init_rc(){
  for (int i = 1; i <= n; i++){
    rc[c[i]] = i;
  }
}
int input_r(){
  if (scanf("%d", &r[1]) != EOF){
    for (int i = 2; i <= n; i++){
      scanf("%d", &r[i]);
    }
    return n;
  }
  return 0;
}

void init_rr(){
  for (int i = 1; i <= n; i++){
    rr[r[i]] = i;
  }
  //for (int i = 1; i <= n; i++){
    //printf("%d ", rr[i]);
  //}
  //printf("\n");
}

int main(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++){
    scanf("%d", &c[i]);
  }
  init_rc();
  while (input_r()){
    init_rr();
    int total = method_2();
    printf("%d\n", total);
  }
}
