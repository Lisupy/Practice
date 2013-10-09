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
const int maxn = 1024;
struct TwoSAT{
  int n;
  vector<int> G[maxn * 2];
  bool mark[maxn * 2];
  vector<int> S;
  TwoSAT():n(0), S(){}
  void init(int _n){
    n = _n;
    memset(mark, 0, sizeof(mark));
    for (int i = 0; i < n * 2; i++) G[i].clear();
  }
  bool dfs(int x){
    if (mark[x^1]) return false;
    if (mark[x]) return true;
    mark[x] = true;
    S.push_back(x);
    for (size_t i = 0; i < G[x].size(); i++){
      if (!dfs(G[x][i])) return false;
    }
    return true;
  }
  void add_clause(int x, int xval, int y, int yval){
    x = x * 2 + xval;
    y = y * 2 + yval;
    G[x^1].push_back(y);
    G[y^1].push_back(x);
  }
  bool solve(){
    if (!dfs(0)) return false;
    for (int i = 2; i < 2 * n; i += 2){
      if (!mark[i] && !mark[i + 1]){
        S.clear();
        if (!dfs(i)){
          while (S.size()) mark[S.back()] = false, S.pop_back();
          if (!dfs(i + 1)) return false;
        }
      }
    }
    return true;
  }
};
TwoSAT solver;
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int n, m;
  while (cin >> n >> m && n){
    solver.init(n);
    while (m--){
      string s1, s2; cin >> s1 >> s2;
      int x = atoi(s1.c_str()), y = atoi(s2.c_str());
      int xval = s1[s1.size()-1] == 'w';
      int yval = s2[s2.size()-1] == 'w'; // w ==> 1
      //cout << x << ", " << y << endl;
      //solver.add_clause(x, xval, y, yval);
      solver.add_clause(x, xval^1, y, yval^1);
      ///~xval  V ~yval
    }
    if (solver.solve()){
      for (int i = 1; i < n; i++){
        if (i != 1) printf(" ");
        printf("%d%s", i, solver.mark[i*2] == solver.mark[1] ? "h" : "w");
      }
      printf("\n");
    }else{
      printf("bad luck\n");
    }
  }
}

