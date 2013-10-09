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
const int maxn=1024;
struct TwoSAT{
  int n;
  vector<int> G[maxn*2];
  bool mark[maxn*2];
  int S[maxn*2], c;
  TwoSAT():n(0), c(0){}
  bool dfs(int x){
    if (mark[x^1]) return false;
    if (mark[x]) return true;
    mark[x] = true;
    S[c++] = x;
    for (size_t i = 0; i < G[x].size(); i++){
      if (!dfs(G[x][i])) return false;
    }
    return true;
  }
  void init(int _n){
    n = _n;
    for (int i = 0; i < n * 2; i++) G[i].clear();
    memset(mark, 0, sizeof(mark));
  }
  void add_clause(int x, int sval, int y, int aval){
    x = x * 2 + sval;
    y = y * 2 + aval;
    G[x^1].push_back(y);
    G[y^1].push_back(x);
  }
  bool solve(){
    for (int i = 0; i < n * 2; i += 2){
      if (!mark[i] && !mark[i + 1]){
        c = 0;
        if (!dfs(i)){
          while (c > 0) mark[S[--c]] = false;
          if (!dfs(i + 1)) return false;
        }
      }
    }
    return true;
  }
};
TwoSAT solver;
int S, A, t;
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  scanf("%d", &TestNum);
  while (TestNum--){
    scanf("%d%d%d", &S, &A, &t);
    solver.init(S + A + 1);
    while (t--){
      int s1, a1, s2, a2; scanf("%d%d%d%d", &s1, &a1, &s2, &a2);
      int sval = a2 > a1;
      int aval = s2 > s1;
      a1 += S;
      a2 += S;
      if (s1 == s2 && a1 == a2) continue;
      if (s2 != s1 && a2 != a1){
        solver.add_clause(s1, sval, s2, sval);
        solver.add_clause(s1, sval, a2, aval);
        solver.add_clause(s2, sval, a1, aval);
        solver.add_clause(a2, aval, a1, aval);
      }else{
        if (s1 == s2){
          solver.add_clause(s1, sval, s1, sval);
        }else{
          solver.add_clause(a1, aval, a1, aval);
        }
      }
    }
    if (solver.solve()) printf("Yes\n");
    else printf("No\n");
  }
}

