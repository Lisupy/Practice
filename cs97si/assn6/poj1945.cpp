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

typedef long long               ll;
typedef long double             ld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef pair<int, int>          pii;
typedef vector<pii>             vii; // vector of integer pairs
typedef set<int>                si;
typedef map<string, int>        msi;


/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
int path[64];
int limit;
int P;
//set<int> S;
static inline
bool checkOpt(int n, int depth, int theMax) {
  if (n == 0) return false;
  if (n == P) return true;
  if ((max(theMax, n) << (limit - depth - 1)) < P) return false;
  if (theMax > P && n > P) return false;
  //if (S.count(n)) return false;
  for (int i = 0; i <= depth; i++) if (path[i] == n) return false;
  return true;
}
bool dfs(int n, int depth, int theMax) {
  if (n == P) return true;
  if (depth + 1 >= limit) return false;
  //S.insert(n);
  path[depth] = n;
  for (int i = 0; i <= depth; i++) { int m = path[i];
    if (m + n == P || abs(m - n) == P) return true;
  }
  for (int i = depth; i >= 0; i--) { int m = path[i];
    if (checkOpt(m + n, depth, theMax) && dfs(m + n, depth + 1, max(theMax, m + n))) return true;
    //if (n > m && checkOpt(n - m, depth, theMax) && dfs(n - m, depth + 1, theMax)) return true;
  }
  //S.erase(n);
  return false;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  cin >> P;
  for (int i = 1; i <= 64; i++) {
    limit = i;
    //S.clear();
    if (dfs(1, 0, 1)) {
      cout << i - 1<< endl;
      break;
    }
  }
}

