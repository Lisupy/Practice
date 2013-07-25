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
 * sizeof CLOCKS_PER_SEC
 */
const int MAXN = 128 * 1024;
double factor[MAXN];
void factor_init(){
  factor[0] = 1;
  for (int i = 1; i < MAXN; i++) factor[i] = factor[i - 1] * i;
  cout << factor[MAXN - 1];

}
double C(int k, int n, int t){
  double s = 1;
  if (n - k < k) k = n - k;
  while (t > 0) s /= 2, t--;
  return s;
}
double a[MAXN];
double solve(int n){
  if (a[n] != 0) return a[n];
  double s = 0;
  double acc = 1;
  int t = n / 2;
  for (int i = n / 2; i <= n - 2; i++){
    s += acc;
    //cout << acc << endl;
    acc = acc * i / (i - (n / 2 - 1)) / 2;
    while (s > 1 && acc > 1 && t > 0) t--, s /= 2, acc /= 2; 
  }
  while (t > 0) t--, s /= 2;
  return a[n] = s * 2 ;
}

int main(){
  //factor_init();
  a[2] = 1;
  for (int i = 4; i < MAXN; i++){
    a[i] = a[i - 2] *  (i - 2) * (i - 3) / ((i - 2) / 2) / ((i - 2) / 2) / 4; 
  }
  int n; cin >> n;
  while (n--){
    int m; cin >> m;
    printf("%.04lf\n", 1 - a[m]);
  }
}
