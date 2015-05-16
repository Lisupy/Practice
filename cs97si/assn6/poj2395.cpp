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

typedef long long               ll;
typedef long double             ld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef pair<int, int>          pii;
typedef vector<pii>             vii; // vector of integer pairs
typedef set<int>                si;
typedef map<string, int>        msi;

const double PI = acos(-1);

/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
const int MAXN = 2003;

int father[MAXN];
int find(int i) {
  return father[i] == i? i : (father[i] = find(father[i]));
}
void init() {
  for (int i = 0; i < MAXN; i++) father[i] = i;
}
struct Edge{
  int A, B, L;
};
bool operator<(const Edge &lhs, const Edge &rhs) {
  return lhs.L < rhs.L;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  init();
  int N, M; cin >> N >> M;
  vector<Edge> edges(M);
  for (int i = 0; i < M; i++) cin >> edges[i].A >> edges[i].B >> edges[i].L;
  sort(edges.begin(), edges.end());
  int tot = 0;
  for (size_t i = 0; i < edges.size(); i++) {
    int u = edges[i].A, v = edges[i].B, w = edges[i].L;
    if (find(u) != find(v)) father[find(u)] = find(v), tot++;
    if (tot == N - 1) {
      cout << w << endl;
      break;
    }
  }
}


