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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 */
const int MAX_N = 200001;
const int MAX_M = 100001;
const int INF = 0x1f1f1f1f;
int a[MAX_N];
int N;
vector<int> b[MAX_M];


int TestNum;
//139 AC   befor my SE
int main(){
  int T; scanf("%d", &T);
  while (T--){
    scanf("%d", &N);
    for (int i = 0; i < MAX_M; i++) b[i].clear();
    for (int i = 1; i <= N; i++){
      int t; scanf("%d", &t);
      b[t].push_back(i);
    }
    for (int i = 0; i < MAX_M; i++) sort(b[i].begin(), b[i].end());
    int Q; scanf("%d", &Q);
    while (Q--){
      int from, to; scanf("%d %d", &from, &to);
      int best = INF;
      vector<int> c;
      for (int i = 0; i < MAX_M; i++){
        int from_i = lower_bound(b[i].begin(), b[i].end(), from) - b[i].begin();
        int to_i = upper_bound(b[i].begin(), b[i].end(), to) - b[i].begin();
        if (from_i >= (int)b[i].size()) continue; 
        if (to_i - from_i > 1){
          best = 0; 
          break;
        }
        if (b[i][from_i] > to) continue;
        assert(from_i + 1 == to_i);
        assert(b[i][from_i] <= to);
        c.push_back(i);
      }
      if (best != 0){
        for (size_t i = 1; i < c.size(); i++){
          best = min(best, abs(c[i] - c[i - 1]));
        }
      }
      printf("%d\n", best);
    }
  }
}

