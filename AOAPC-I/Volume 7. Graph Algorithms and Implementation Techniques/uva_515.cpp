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

int main(){
  int n, m;
  while (cin >> n && n){
    cin >> m;
    n++;
    vector<int> us(m + n + 1);
    vector<int> vs(m + n + 1);
    vector<int> WS(m + n + 1);
    for (int i = 0; i < m; i++){
      int si, ni, ki; 
      string oi;
      cin >> si >> ni >> oi >> ki;
      int v = si + ni + 1, u = si, w = ki;
      if (oi == "gt") swap(u, v), w = -w;
      us[i] = u; vs[i] = v; WS[i] = w - 1; 
      //us[i] = v; vs[i] = u; WS[i] = -w - 1e10; 
    }
    for (int i = 0; i <= n; i++){
      us[i + m] = n + 1, vs[i + m] = i, WS[i + m] = 0;
    }
    vector<int> d(n + 2, 0x1f1f1f1f);
    d[n + 1] = 0;
    int last_iter = 0;
    for (int k = 1; k <= n + 2; k++){
      bool ok = true;
      last_iter = k;
      for (size_t i = 0; i < us.size(); i++){
        int u = us[i], v = vs[i], w = WS[i];
        if (d[u] != 0x1f1f1f1f){
          if (d[v] > d[u] + w){
            //printf("%d: %d %d %d, %d %d\n", k, u, v, w, d[u], d[v]);
            d[v] = d[u] + w;
            ok = false;
          }
        }
      }
      if (ok) break;
    }
    if (last_iter == n + 2){
      cout << "successful conspiracy" << endl;
    }else{
      cout << "lamentable kingdom" << endl;
    }
  }
}

