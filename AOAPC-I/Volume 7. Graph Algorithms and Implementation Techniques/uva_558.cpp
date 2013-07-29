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
const int INF = 0x1f1f1f1f;
int main(){
  int TestNum; cin >> TestNum;
  while (TestNum--){
    int n, m;
    cin >> n >> m;
    int x[m];
    int y[m];
    int w[m];
    for (int i = 0; i < m; i++) cin >> x[i] >> y[i] >> w[i];
    vector<int> d(n, INF);
    d[0] = 0;
    int last = 0;
    for (int k = 0; k <= n; k++){
      last = k;
      bool ok = true;
      for (int i = 0; i < m; i++){
        if (d[x[i]] != INF){
          if (d[y[i]] > d[x[i]] + w[i]){
            d[y[i]] = d[x[i]] + w[i];
            ok = false;
          }
        }
        /*
        if (d[y[i]] != INF){
          if (d[x[i]] > d[y[i]] + w[i]){
            d[x[i]] = d[y[i]] + w[i];
            ok = false;
          }
        }
        */
      }
      if (ok) break;
    }
    if (last == n) cout << "possible" << endl;
    else cout << "not possible" << endl;
  }
}
