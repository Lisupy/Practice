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


const int MAXN = 128;
struct Edge{
  int u, v;
  double w;
};
double dist[MAXN][MAXN];
int main(){
  int TestNum; cin >> TestNum;
  for (int kcase = 1; kcase <= TestNum; kcase++){
    int N;
    cin >> N;
    vector<int> x(N);
    vector<int> y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
    vector<Edge> edges;
    for (int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){
        double d = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
        if (d > 10) d = 1e20;
        dist[i][j] = d;
      }
    }
    for (int i = 0; i < N; i++){
      for (int s = 0; s < N; s++){
        for (int t = 0; t < N; t++){
          dist[s][t] = min(dist[s][t], dist[s][i] + dist[i][t]);
        }
      }
    }
    double ans = 0;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        ans = max(ans, dist[i][j]);

    printf("Case #%d:\n", kcase);
    if (ans != 1e20){
      printf("%.4lf\n", ans);
    }else{
      printf("Send Kurdy\n");
    }
    printf("\n");
  }
}
