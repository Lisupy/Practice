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

int a[5];
int n;

int best;
int cnt = 0;
void dfs(int cur){
  if (cur > best){
    return;
  }
  bool sorted = true;
  for (int i = 1; i < n; i++){
    if (a[i - 1] > a[i]){
      sorted = false;
      swap(a[i - 1], a[i]);
      dfs(cur + 1);
      swap(a[i], a[i - 1]);
    }
  }
  if (sorted){
    if (best > cur){
      best = cur;
      cnt = 1;
    }else{
      cnt++;
    }
  }
}

int TestNum;
int main(){
  while (scanf("%d", &n) && n){
    for (int i = 0; i < n; i++){
      scanf("%d", a + i);
    }
    best = 0xfffff;
    cnt = 0;
    dfs(0);
    if (best == 0){
      cnt = 0;
    }
    printf("There are %d swap maps for input data set %d.\n", cnt, ++TestNum);
  }
}
