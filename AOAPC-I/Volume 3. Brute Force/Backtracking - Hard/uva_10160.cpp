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

int N, M;
unsigned long long links[36];
int max_u[36];
unsigned long long upper_mask[36];
int best;


bool isValid(unsigned long long color){
  //cout << color << endl;
  return color == (1llu << N) - 1;
}

bool dfs(int cur, int cnt, int upper, unsigned long long color){
  if (cnt == upper){
    return isValid(color);
  }else{
    bool must = ((color ^ upper_mask[cur]) & upper_mask[cur] ) != 0;
    if (!must){
      if (N - cur >= upper - cnt && dfs (cur + 1, cnt, upper, color)){
        return true;
      }
    }
    if (cnt < upper && cur < N && dfs (cur + 1, cnt + 1, upper, color | links[cur])){
      return true;
    }
    
    return false;
  }
}
int solve(){
#if 0
  for (int i = 1; i <= N; i++){
    if (dfs(0, 0, i, 0)){
      return i;
    }
  }
  assert(0);
  return -1;
#endif
  int l = 1, r = N;
  int ans = N;
  while (l <= r){
    int mid = (l + r) / 2;
    if (dfs(0, 0, mid, 0)){
      ans = mid;
      r = mid - 1;
    }else{
      l = mid + 1;
    }
  }
  return ans;
}
int main(){
  while (cin >> N >> M && N){
    memset(links, 0, sizeof(links));
    memset(max_u, 0, sizeof(max_u));
    memset(upper_mask, 0, sizeof(upper_mask));
    while (M--){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      links[u] |= 1llu << v;
      links[v] |= 1llu << u;
      max_u[u] = max(max_u[u], v);
      max_u[v] = max(max_u[v], u);
    }
    for (int i = 0; i < N; i++){
      links[i] |= 1llu << i;
      max_u[i] = max(max_u[i], i);
      upper_mask[max_u[i]] |= 1llu << i;
    }

    int ans = solve();
    cout << ans << endl;
  }
}
