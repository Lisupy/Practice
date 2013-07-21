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
const int MAXN = 16;
int r[MAXN];
int c[MAXN];
int best[MAXN][MAXN];
int path[MAXN][MAXN]; 

const int INF = numeric_limits<int>::max();
int dp(int from, int to){
  int &res = best[from][to];
  if (res != -1) return res;
  
  int fewest = INF;
  int choice;
  for (int i = from; i < to; i++){
    int need = dp(from, i) + dp(i + 1, to) + r[from] * c[i] * c[to];
    if (need < fewest){
      fewest= need;
      choice = i;
    }
  }
  res = fewest;
  path[from][to] = choice;
  return res;
}
void print(int from, int to){
  if (from == to){
    printf("A%d", from);
  }else{
    printf("(");
    int choice = path[from][to];
    print(from, choice); 
    printf(" x ");
    print(choice + 1, to);
    printf(")");
  }
}
int n;
int TestNum;
int main(){
  while (scanf("%d", &n) && n){
    for (int i = 1; i <= n; i++){
      scanf("%d %d", &r[i], &c[i]);
    }
    memset(best, -1, sizeof(best));
    dp(1, n);
    printf("Case %d: ", ++TestNum);
    print(1, n);
    printf("\n");
  }
}

