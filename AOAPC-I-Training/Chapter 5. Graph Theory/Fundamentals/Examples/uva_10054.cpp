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
const int MAXN = 64;
int N;
int mat[MAXN][MAXN];
int deg[MAXN];
void dfs(vector<pair<int, int> > &path, int s){
  for (int i = 0; i <= MAXN; i++){
    while (mat[s][i] != 0){
      mat[s][i]--;
      mat[i][s]--;
      dfs(path, i);
      path.push_back(make_pair(i, s));
    }
  }
}
bool existEulerCycle(vector<pair<int, int> > &path){
  memset(deg, 0, sizeof(deg));
  for (int i = 0; i < MAXN; i++){
    for (int j = 0; j < MAXN; j++){
      deg[i] += mat[i][j];
    }
  }
  for (int i = 0; i < MAXN; i++){
    if (deg[i] % 2 != 0) return false;
  }
  int s = 0;
  for (int i = 0; i < MAXN; i++){
    if (deg[i] != 0) s = i;
  }
  dfs(path, s);
  //if (path.size() != N) return false;
  //return true;
  return (int)path.size() == N;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int T; scanf("%d", &T);
  while (T--){
    memset(mat, 0, sizeof(mat));
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
      int u, v; scanf("%d%d", &u, &v);
      mat[u][v]++, mat[v][u]++;
    }
    if (TestNum) printf("\n");
    printf("Case #%d\n", ++TestNum);
    vector<pair<int, int> > path;
    if (existEulerCycle(path)){
      for (size_t i = 0; i < path.size(); i++){
        printf("%d %d\n", path[i].first, path[i].second);
      }
    }else{
      printf("some beads may be lost\n");
    }
  }
}

