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
const int MAXN = 256 * 1024;
const int INF = 0x1f1f1f1f;
int a[MAXN];
int lis[MAXN];
int lds[MAXN];
int tmp[MAXN];
int L;
int n;
void preProcess(){
  memset(tmp, 0x1f, sizeof(tmp));
  for (int i = 0; i < n; i++) {
    if (i == 0) lis[i] = 1;
    else lis[i] = a[i] > a[i - 1] ? lis[i - 1] + 1 : 1;
  }
  memset(tmp, 0, sizeof(tmp));
  for (int i = n - 1; i >= 0; i--){
    if (i == n - 1) lds[i] = 1;
    else lds[i] = a[i] < a[i + 1] ? lds[i + 1] + 1 : 1;
  }
  //for (int i = 0; i < n; i++) printf("%2d", lis[i]); printf("\n");
  //for (int i = 0; i < n; i++) printf("%2d", lds[i]); printf("\n");
}
int solve(){
  int res = 1;
  map<int, int> M;
  for (int i = 0; i < n; i++){
    map<int, int>::iterator it = M.upper_bound(a[i] - 1);
    if (it != M.begin()){ 
      it--;
      res = max(res, lds[i] + it->second);
    }
    it = M.upper_bound(a[i]);
    if (it != M.begin()){
      map<int, int>::iterator it1 = prev(it);
      if (it1->second < lis[i]) M.insert(make_pair(a[i], lis[i]));
    }else M.insert(make_pair(a[i], lis[i]));

    while (it != M.end() && it->second < lis[i]) M.erase(it), it++;
  }
  return res;
}
int TestNum;
int main(){
  scanf("%d", &TestNum);
  while (TestNum--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    preProcess();
    printf("%d\n", solve());
  }
}

