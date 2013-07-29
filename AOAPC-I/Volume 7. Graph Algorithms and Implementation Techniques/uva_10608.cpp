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
 * sizeof CLOCKS_PER_SEC
 */

const int MAXN = 30010;

int p[MAXN];
int c[MAXN];
int N, M;
void reset(){
  for (int i = 1; i <= N; i++){
    p[i] = i;
    c[i] = 1;
  }
}

int find(int u){
  int root = u;
  while (p[root] != root) root = p[root];
  while (u != root) {
    int t = p[u];
    p[u] = root;
    u = t;
  }
  return root;
}

void join(int u, int v){
  int pu = find(u), pv = find(v);
  if (pu != pv){
    p[pu] = pv;
    c[pv] += c[pu];
  }
}

int TestNum;
int main(){
  scanf("%d", &TestNum);
  while (TestNum--){
    scanf("%d", &N);
    reset();
    scanf("%d", &M);
    while (M--){
      int A, B; scanf("%d %d", &A, &B);
      join(A, B);
    }
    cout << *max_element(c + 1, c + N + 1) << endl;
  }
}


