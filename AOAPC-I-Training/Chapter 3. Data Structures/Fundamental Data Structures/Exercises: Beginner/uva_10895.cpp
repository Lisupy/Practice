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
struct Item{
  int r, c, v;
};
bool operator<(const Item &a, const Item &b){
  if (a.r != b.r) return a.r < b.r;
  return a.c < b.c;
}
int n, m;
void output(vector<Item> mat){
  printf("%d %d\n", m, n);
  for (int r = 1, b = 0, e = 0; r <= m; r++, b = e){
    while (e < (int)mat.size() && mat[e].r <= r) e++;
    printf("%d", e - b);
    for (int i = b; i < e; i++) printf(" %d", mat[i].c);
    printf("\n");
    for (int i = b; i < e; i++) printf("%s%d", i == b? "": " ", mat[i].v);
    printf("\n");
  }
}
int TestNum;
int main(){
  while (scanf("%d %d", &n, &m) != EOF){
    vector<Item> mat;
    for (int r = 1; r <= n; r++){
      int k; scanf("%d", &k);
      vector<Item> a(k);
      for (int i = 0; i < k; i++) a[i].c = r;
      for (int i = 0; i < k; i++) scanf("%d", &a[i].r);
      for (int i = 0; i < k; i++) scanf("%d", &a[i].v);
      copy(a.begin(), a.end(), back_inserter(mat));
    }
    sort(mat.begin(), mat.end());
    output(mat);
  }
}

