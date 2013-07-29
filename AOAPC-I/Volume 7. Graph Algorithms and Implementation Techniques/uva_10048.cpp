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
const int MAXN = 128;
int TestNum;
int C, S, Q;
int d[MAXN][MAXN];

void reset(){
  memset(d, 0x1f, sizeof(d));
  //for (int i = 0; i < MAXN; i++) d[i][i] = 0;
}

int main(){
  while (cin >> C >> S >> Q && C){
    reset();
    for (int i = 0; i < S; i++){
      int u, v, w; cin >> u >> v >> w;
      d[u][v] = d[v][u] = w;
    }
    for (int i = 1; i <= C; i++){
      for (int s = 1; s <= C; s++){
        for (int t = 1; t <= C; t++){
          d[s][t] = min(d[s][t], max(d[s][i], d[i][t]));
        }
      }
    }
    if (TestNum) cout << endl;
    cout << "Case #" << ++TestNum << endl;
    for (int i = 1; i <= Q; i++){
      int u, v; cin >> u >> v;
      if (d[u][v] == 0x1f1f1f1f){
        cout << "no path" << endl;
      }else{
        cout << d[u][v] << endl;
      }
    }
  }
}
