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
 * (1 << (31 - __builtin_clz(100) ) == 64;
 */
enum MatchRes{
  WIN = 0,
  LOSS,
};
bool f_visited[2][512][512];
double f_cache[2][512][512];

double f(MatchRes last, int n, int len, double p){
  double &res = f_cache[last][n][len];
  if (f_visited[last][n][len]) return res;
  f_visited[last][n][len] = true;
  if (n <= 0) res = 1;
  else if (n <= len) res = last == WIN? p : 1 - p;
  else{
    if (last == WIN){
      //res = 0;
      //double x = p;
      //for (int i = 1; i <= min(len, n); i++){
        //res += f(LOSS, n - i, len, p) * x;
        //x *= p;
      //}
      if (n == 1) res = len == 0? 0: p;
      else if (n > len){
        res = (f(WIN, n - 1, len, p) - f(LOSS, n - len - 1, len, p) * pow(p, len)) * p + f(LOSS, n - 1, len, p)*p;
      }else{
        res = f(WIN, n - 1, len, p) * p + f(LOSS, n - 1, len, p) * p;
      }
    }else{
      if (n == 1) res = 1 - p;
      else{
        res = f(LOSS, n - 1, len, p) * (1 - p) + f(WIN, n - 1, len, p) * (1 - p);
      }
    }
  }
  return res;
}

double F(int n, int len, double p){
  if (len == 0) return f(WIN, n, len, p) + f(LOSS, n, len, p);
  //printf("%lf, %lf, %lf, %lf\n", f(WIN, n, len, p) , f(LOSS, n, len, p), f(WIN, n, len - 1, p), f(LOSS, n, len - 1, p));
  return f(WIN, n, len, p) + f(LOSS, n, len, p) - f(WIN, n, len - 1, p) - f(LOSS, n, len - 1, p);
}
double solve(int n, double p){
  memset(f_visited, 0, sizeof(f_visited));
  double total = 0;
  for (int i = 0; i <= n; i++) {
    //printf("%d: %lf\n", i, F(n, i, p));
    total += i * F(n, i, p);
  }
  return total;
}

int TestNum;
int main(){
  int n;
  double p;
  while (cin >> n >> p && n) {
    printf("%.06lf\n", solve(n, p)); 
  }
}

