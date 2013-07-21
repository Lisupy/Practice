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
const int MAXN = 1024;
int cache[MAXN][MAXN];
int path[MAXN][MAXN];
char buf[MAXN];
int dp(int from, int to){
  if (from >= to) return 0;
  int &res = cache[from][to];
  if (res != -1) return res;
  int &choice = path[from][to];
  int l1 = dp(from, to - 1) + 1;
  int l2 = dp(from + 1, to) + 1;
  if (l1 < l2){
    choice = 1;
    res = l1;
  }else{
    choice = 2;
    res = l2;
  }
  if (buf[from] == buf[to]){
    int l3 = dp(from + 1, to - 1);
    if (l3 < res){
      choice = 3;
      res = l3;
    }
  }
  return res;
}
void pr(int from, int to){
  if (from > to) return;
  if (from == to){printf("%c", buf[from]); return;}
  int p = path[from][to];
  if (p == 1){
    printf("%c", buf[to]);
    pr(from, to - 1);
    printf("%c", buf[to]);
  }else if (p == 2){
    printf("%c", buf[from]);
    pr(from + 1, to);
    printf("%c", buf[from]);
  }else{
    printf("%c", buf[from]);
    pr(from + 1, to - 1);
    printf("%c", buf[to]);
  }
}
int main(){
  while (scanf("%s", buf) != EOF){
    int len = strlen(buf);
    memset(cache, -1, sizeof(cache));
    int cnt = dp(0, len - 1);
    printf("%d ", cnt);
    pr(0, len - 1);
    printf("\n");
  }
}
