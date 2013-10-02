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
const double PI = acos(-1);
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */

const int MAXN = 32;
map<string, int> ms;
int ID;
int n, m;
int TestNum;
double d[MAXN][MAXN];
void reset(){
  memset(d, 0, sizeof(d));
  ms.clear();
  ID = 1;
  for (int i = 1; i <= n; i++){
    d[i][i] = 1;
  }
}
bool isValid(){
  for (int i = 1; i <= n; i++){
    for (int s = 1; s <= n; s++){
      for (int t = 1; t <= n; t++){
        d[s][t] = max(d[s][t], d[s][i] * d[i][t]);
      }
    }
  }
  for (int i = 1; i <= n; i++){
    if (d[i][i] > 1) return true;
  }
  return false;
}
int main(){
  ios_base::sync_with_stdio(false); 
  while (cin >> n && n) { 
    reset();
    for (int i = 0; i < n; i++){
      string s; cin >> s;
      ms[s] = ID++;
    }
    cin >> m;
    for (int i = 0; i < m; i++){
      string s, t;
      double r;
      cin >> s >> r >> t;
      d[ms[s]][ms[t]] = r;
    }
    cout << "Case " << ++TestNum << ": ";
    if (isValid()) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}

