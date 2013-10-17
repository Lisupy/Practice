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
const int MAXN = 64;
i64 F_cache[MAXN][MAXN];
i64 x[MAXN];
i64 y[MAXN];
int n;
bool up_valid(int from, int to){
  for (int i = from + 1; i < to; i++){
    if ((y[to] - y[from]) * (x[i] - x[from]) <= (x[to] - x[from]) * (y[i] - y[from])){
      return false;
    }
  }
  return true;
}
bool down_valid(int from, int to){
  for (int i = from + 1; i < to; i++){
    if ((y[to] - y[from]) * (x[i] - x[from]) >= (x[to] - x[from]) * (y[i] - y[from])){
      return false;
    }
  }
  return true;
}
int F(int up, int down){
  //if (up == 0 && down == 0) return 1;
  if (up == 0 || down == 0) return 1;
  if (up == down) return 0;
  i64 &total = F_cache[up][down];
  if (total != -1) return total;
  total = 0;
  if (up > down){
    if (up == down + 1){
      for (int j = down - 1; j >= 0; j--){
        if (up_valid(j, up)){
          total += F(j, down);
        }
      }
    }else{
      total += F(up - 1, down);
    }
  }else{
    if (down == up + 1){
      for (int j = up - 1; j >= 0; j--){
        if (down_valid(j, down)){
          total += F(up, j);
        }
      }
    }else{
      total += F(up, down - 1);
    }
  }
  //printf("%d %d: %d\n", up, down, total);
  return total;
}

i64 solve1(){
  i64 total = 0;
  for (int i = 0; i <= n - 3; i++) {
    if (up_valid(i, n - 1)){
      total += F(i, n - 2);
      //printf("#%d %d: %d\n", i, n - 1, total);
    }
    if (down_valid(i, n - 1)){
      total += F(n - 2, i);
      //printf("###%d %d: %d\n", i, n - 1, total);
    }
  }
  return total;

}
int TestNum;
int main(){
  int T; cin >> T;
  while (T--) {
    memset(F_cache, -1, sizeof(F_cache));
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    vector<pair<int, int> > tmp(n);
    for (int i = 0; i < n; i++) tmp[i] = make_pair(x[i], y[i]);
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; i++) x[i] = tmp[i].first, y[i] = tmp[i].second;
    //for (auto i : tmp) cout << i.first << ", " << i.second << endl;
    cout << solve1() << endl;
  }

}

