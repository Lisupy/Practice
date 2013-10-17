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


int TestNum;
const int MAXN = 50010;
long double a[MAXN];
double s[MAXN];
long double c[MAXN];
int main(){
  int N; cin >> N;
  while (N--){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    c[0] = log2(1);
    for (int i = 1; i < n; i++){
      c[i] = c[i - 1] + log2((n - 1) - (i - 1)) - log2(i);
    }
    long double total = 0;
    //long double pn = powl(2, n - 1);
    for (int i = 0; i < n; i++){
      //cout << c[i] << endl;
      //cout << pow(2, c[i]) << endl;
      total += a[i] * powl(2, c[i] - (n - 1));
    }
    //total /= pow(2, n - 1);
    printf("Case #%d: %.3Lf\n", ++TestNum, total);
  }
}


