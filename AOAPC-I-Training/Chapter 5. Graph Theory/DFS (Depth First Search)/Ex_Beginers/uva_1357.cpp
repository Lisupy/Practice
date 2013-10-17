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
//const int MAXN = 20 * 1024 *1024;
const int MAXN = 1024;
int N;
int childID;
vector<int> edges[MAXN];
int dfs_clock;
int prv[MAXN];
int post[MAXN];
void dfs(int u){
  prv[u] = ++dfs_clock;
  for (size_t i = 0; i < edges[u].size(); i++){
    int v = edges[u][i];
    dfs(v);
  }
  post[u] = ++dfs_clock;
}
int TestNum;

int main(){
  ios_base::sync_with_stdio(false); 
  return 0;
  int T; scanf("%d", &T);
  while (T--){
    if (TestNum) printf("\n");
    printf("Case %d:\n", ++TestNum); 
    scanf("%d", &N);
    childID = 0;
    for (int i = 0; i < N; i++){
      edges[i].clear();
      int C; scanf("%d", &C);
      while (C--) edges[i].push_back(++childID);
    }
    dfs_clock = 0;
    dfs(0);
    int M; scanf("%d", &M);
    while (M--){
      int a, b; scanf("%d%d", &a, &b);
      if (prv[a] < prv[b] && post[a] > post[b]) printf("Yes\n");
      else printf("No\n");
    }
  }
}

