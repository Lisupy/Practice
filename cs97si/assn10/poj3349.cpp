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

const int MAXN = 100024;
struct Snow{
  int a[6];
};
bool operator<(const Snow& a, const Snow &b){
  for (int i = 0; i < 6; i++){
    if (a.a[i] != b.a[i]) return a.a[i] < b.a[i];
  }
  return false;
}
bool operator==(const Snow&a, const Snow &b){
  return !memcmp(&a, &b, sizeof(a));
}

Snow snows[MAXN];

void format(Snow &s, Snow& o){
  int b[12];
  for (int i = 0; i < 6; i++) b[i] = b[i + 6] = s.a[i];
  int i = 0, j = 1;
  while (j < 6){
    int k = 0;
    while (k < 6 && b[i + k] == b[j + k]) k++;
    if (b[i + k] > b[j + k]){
      int tmp = i + k + 1;
      i = j;
      j = max(tmp, j + 1);
    }else{
      j = j + k + 1;
    }
  }
  for (int k = 0; k < 6; k++) o.a[k] = b[i + k];
}
int TestNum;
int main(){
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    Snow s, a, b;
    for (int j = 0; j < 6; j++) scanf("%d", &s.a[j]);
    format(s, b);
    reverse(s.a, s.a + 6);
    format(s, a);
    snows[i] = min(a, b);
  }
  sort(snows, snows + n);
  if (adjacent_find(snows, snows + n) == snows + n){
    cout << "No two snowflakes are alike." << endl;
  }else{
    cout << "Twin snowflakes found." << endl;
  }
}


