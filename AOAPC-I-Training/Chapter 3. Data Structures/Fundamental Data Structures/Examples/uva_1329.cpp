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

const int MAXN = 20010;
int father[MAXN];
int length[MAXN];
void init(int n){
  for (int i = 0; i <= n; i++) father[i] = i, length[i] = 0;
}

int find(int u){
  int root = u, total = 0;
  while (root != father[root]) {
    total += length[root]; 
    root = father[root];
  }
  while (u != root) {
    int pu = father[u];
    int lu = length[u];
    length[u] = total;
    father[u] = root;
    u = pu;
    total = total - lu;
  }
  return u;
}
void join(int u, int v){
  int pu = find(u);
  int pv = find(v);
  assert(pu != pv);
  father[pu] = v;
  length[pu] = abs(u - v) % 1000;
}

int TestNum;
int main(){
  cin >> TestNum;
  while (TestNum--) {
    int N; cin >> N;
    init(N);
    string s;
    while (cin >> s && s != "O") {
      if (s == "E"){
        int I; cin >> I;
        find(I);
        cout << length[I] << endl;
      }else{
        int I, J; cin >> I >> J;
        join(I, J);
      }
    }
  }
}

