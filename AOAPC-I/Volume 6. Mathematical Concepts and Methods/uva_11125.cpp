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
 * (1 << (31 - __builtin_clz(100) ) == 64;
 */

i64 cache[4][4][8][8][8][8][4][4];
bool visited[4][4][8][8][8][8][4][4];
i64 F(int idx, int s, int a[4], int color, int sz){
  int &i0 = a[0], &i1 = a[1], &i2 = a[2], &i3 = a[3]; 
  //cout << i0 << ", " << i1 << ", " << i2 << ", " << i3 << endl;
  assert(i0 + i1 + i2 + i3 != 0);
  i64 &res = cache[idx][s][i0][i1][i2][i3][color][sz];
  if (visited[idx][s][i0][i1][i2][i3][color][sz]) return res; 
  visited[idx][s][i0][i1][i2][i3][color][sz] = true;
  for (int i = 1; i <= 3; i++) if (i != s && a[idx] >= i){
    a[idx] -= i;
    if (i0 + i1 + i2 + i3 == 0){
      if (i == sz || color == idx);
      else res += 1;
    }else{
      for (int j = 0; j < 4; j++) if (j != idx){
        res += F(j, i, a, color, sz);
      }
    }
    a[idx] += i;
  }
  return res;
}

int TestNum;
int main(){
  int t; cin >> t;
  while (t--) {
    int n; scanf("%d", &n);
    int a[4] = {0};
    for (int i = 0; i < n; i++) cin >> a[i];
    i64 total = 0; 
    int &i0 = a[0], &i1 = a[1], &i2 = a[2], &i3 = a[3]; 
    if (i0 + i1 + i2 + i3 == 0){ cout << 1 << endl; continue; }
    for (int i = 0; i < 4; i++) {
      for (int j = 1; j <= 3; j++) if (a[i] >= j){
        a[i] -= j;
        if (i0 + i1 + i2 + i3 != 0){
          for (int k = 0; k < 4; k++) if (k != i){
            total += F(k, j, a, i, j);
          }
        }
        a[i] += j;
      }
    }
    cout << total << endl;
  }
}
