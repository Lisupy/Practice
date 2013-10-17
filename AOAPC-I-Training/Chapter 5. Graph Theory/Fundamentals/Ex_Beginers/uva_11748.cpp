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
const int MAXN = 128;
int n, m, c;
int win[MAXN][MAXN];
bool visited[MAXN];
void dfs(int s){
  if (visited[s]) return;
  visited[s] = true;
  for (int i = 1; i <= n; i++){
    if (win[s][i]) dfs(i);
  }
}
void reset(){
  memset(win, 0, sizeof(win));
  memset(visited, 0, sizeof(visited));
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (cin >> n >> m >> c && n) {
    reset(); 
    for (int i = 0; i < m ; i++){
      int votes[MAXN];
      for (int j = 0; j < n; j++) cin >> votes[j]; 
      for (int k1 = 0; k1 < n; k1++){
        for (int k2 = k1 + 1; k2 < n; k2++){
          win[votes[k1]][votes[k2]]++;
        }
      }
    }
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        win[i][j] = win[i][j] * 2 > m ? 1 : 0;
      }
    }
    dfs(c);
    if (count(visited + 1, visited + n + 1, true) == n) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}

