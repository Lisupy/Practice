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

const int MAXN = 1024 * 20;
int n;
int p[MAXN];
void reset(){
  for (int i = 0; i < MAXN; i++) p[i] = i;
}
int find(int u){
  int v = u;
  while (v != p[v]) v = p[v];
  while (u != v){ int pu = p[u]; p[u] = v; u = pu;};
  return v;
}
void join(int u, int v){
  p[find(u)] = find(v);
}
int main(){
  while (scanf("%d", &n) != EOF){
    reset();
    int c, x, y;
    while (scanf("%d %d %d", &c, &x, &y) && c){
      if (c == 1){
        if (find(x) == find(y + n)){
          cout << -1 << endl;
        }else{
          join(x, y);
          join(x + n, y + n);
        }
      }
      if (c == 2){
        if (find(x) == find(y)){
          cout << -1 << endl;
        }else{
          join(x, y + n);
          join(x + n, y);
        }
      }
      if (c == 3){
        if (find(x) == find(y)){
          cout << 1 << endl;
        }else{
          cout << 0 << endl;
        }
      }
      if (c == 4){
        if (find(x) == find(y + n)){
          cout << 1 << endl;
        }else{
          cout << 0 << endl;
        }
      }
    }
  }
}

