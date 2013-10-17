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
const int MAXN = 128 * 1024 * 2;
int n, m;
int id; 
int ids[MAXN];
int father[MAXN];
int cnt[MAXN];
int sum[MAXN];
void init(){
  id = 0;
  for (int i = 0; i < MAXN; i++) father[i] = i, cnt[i] = 1, sum[i] = 0;
  for (int i = 1; i <= n; i++) ids[i] = id++, sum[ids[i]] = i;
}

int find(int x){
  int root = x; while (root != father[root]) root = father[root];
  while (x != root) { int px = father[x]; father[x] = root; x = px;}
  return x;
}
void join(int x, int y){
  int px = find(x);
  int py = find(y);
  if (px != py) father[px] = py, cnt[py] += cnt[px], sum[py] += sum[px];
}
int TestNum;
int main(){
  while (scanf("%d %d", &n, &m) != EOF){
    init();
    while (m--){
      int op; scanf("%d", &op);
      //printf("\n");
      //printf("index :   "); for (int i = 0; i < 10; i++) printf("%3d", i); printf("\n");
      //printf("father:   "); for (int i = 0; i < 10; i++) printf("%3d", father[i]); printf("\n");
      //printf("sum:      "); for (int i = 0; i < 10; i++) printf("%3d", sum[i]); printf("\n");
      //printf("ids:      "); for (int i = 0; i < 10; i++) printf("%3d", ids[i]); printf("\n");
      if (op == 1){
        int p, q; scanf("%d %d", &p, &q);
        join(ids[p], ids[q]);
      }
      if (op == 2){
        int p, q; scanf("%d %d", &p, &q);
        if (find(ids[p]) != find(ids[q])){
          cnt[find(ids[p])]--;
          sum[find(ids[p])] -= p;
          ids[p] = id++;
          cnt[ids[p]] = 1;
          sum[ids[p]] = p;
          join(ids[p], ids[q]);
        }
      }
      if (op == 3){
        int p; scanf("%d", &p);
        printf("%d %d\n", cnt[find(ids[p])], sum[find(ids[p])]);
      }
    }
  }
}

