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
const int MAXN = 1024 * 1024 * 1024;
long long S(long long n){
  return n * (n + 1) / 2;
}

long long T(long long n){
  return n + S(n - 1) * 2;
}
int find_k(int n){
  int l = 1, r = n;
  long long sn = S(n);
  while (l <= r){
    int mid = (l + r) / 2;
    long long tk = T(mid);
    if (tk == sn) return mid;
    else if (tk < sn) l = mid + 1;
    else r = mid - 1;
  }
  return -1;
}

void gao(){
  for (int n = 2, cnt = 0; n < MAXN && cnt < 10; n++){
    int k = find_k(n);
    if (k != -1){
      printf("%10d%10d\n", k, n);
      //printf("  %10d%10d\n", T(k), S(n));
      cnt++;
    }
  }
}

int main(){
  printf("         6         8\n");
  printf("        35        49\n");
  printf("       204       288\n");
  printf("      1189      1681\n");
  printf("      6930      9800\n");
  printf("     40391     57121\n");
  printf("    235416    332928\n");
  printf("   1372105   1940449\n");
  printf("   7997214  11309768\n");
  printf("  46611179  65918161\n");
}
