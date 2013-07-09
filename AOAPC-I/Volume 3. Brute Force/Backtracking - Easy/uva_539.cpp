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

int u[32];
int v[32];
bool used[32];
int n, m;
int longest;

void dfs(int s, int len){
  longest = max(longest, len);
  for(int i = 0; i < m; i++){
    if (!used[i] && u[i] == s){
      used[i] = true;
      dfs(v[i], len + 1);
      used[i] = false;
    }
    if (!used[i] && v[i] == s){
      used[i] = true;
      dfs(u[i], len + 1);
      used[i] = false;
    }
  }
}


int main(){
  while( scanf("%d %d", &n, &m) && n){
    for (int i = 0; i < m; i++){
      scanf("%d %d", &u[i], &v[i]);
    }
    longest = 0;
    for (int i = 0; i < n; i++){
      memset(used, 0, sizeof(used));
      dfs(i, 0);
    }
    printf("%d\n", longest);
  }
}
