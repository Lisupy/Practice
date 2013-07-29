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

int N;
vector<int> us;
vector<int> vs;
vector<int> Ws;
int n, m, S, T;

const long long INF = 0x1f1f1f1f1f1fll;
int main(){
  int TestNum; cin >> TestNum;
  for (int ti = 1; ti <= TestNum; ti++){
    scanf("%d %d %d %d", &n, &m, &S, &T);
    us.resize(m); vs.resize(m); Ws.resize(m);
    for (int i = 0; i < m; i++){ 
      cin >> us[i] >> vs[i] >> Ws[i];
    }
    vector<long long> dist(n, INF);
    dist[S] = 0;
    for (int k = 0; k < n - 1; k++){
      bool ok = true;
      for (int i = 0; i < m; i++){
        int x = us[i], y = vs[i], w = Ws[i];
        if (dist[x] != INF){
          if (dist[y] > dist[x] + w)dist[y] = dist[x] + w, ok = false;
        }
        if (dist[y] != INF){
          if (dist[x] > dist[y] + w)dist[x] = dist[y] + w, ok = false;
        }
      }
      if (ok) break;
    }
    if (dist[T] != INF){
      printf("Case #%d: %lld\n", ti, dist[T]);
    }else{
      printf("Case #%d: unreachable\n", ti);
    }
  }
}

