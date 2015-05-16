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
int n, m;
vector<int> G[2560];
struct V{
  int x, y;
  V():x(0), y(0) {}
  V(int _x, int _y): x(_x), y(_y) {}
  V(int k): x(k / m), y(k % m) {}
  int toN() { return x * m + y; }
  bool isValid() { return 0 <= x && x < n && 0 <= y && y < m; }
  string to_s() {
    stringstream ss;
    ss << toN() << ": " << x << ", " << y << endl;
    return ss.str();
  }
};
int dx[] =   {0,-1,0, 1};
int dy[] =   {-1,0,1, 0};
int mask[] = {1, 2, 4, 8};
bool visited[2560];
int dfs(int s) {
  int tot = 1;
  visited[s] = true;
  for (size_t i = 0; i < G[s].size(); i++) {
    int t = G[s][i];
    if (visited[t]) continue;
    tot += dfs(t);
  }
  return tot;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int ma; cin >> ma;
      V s(i, j);
      for (int k = 0; k < 4; k++) {
        V t(s.x + dx[k], s.y + dy[k]);
        if (!t.isValid()) continue;
        if (ma & mask[k]) continue;
        G[s.toN()].push_back(t.toN());
      }
    }
  }
  int numberOfRooms = 0;
  int largestRoom = 0;
  for (int i = 0; i < n * m; i++) if (!visited[i]) {
    largestRoom = max(largestRoom, dfs(i));
    numberOfRooms++;
  }
  cout << numberOfRooms << endl;
  cout << largestRoom << endl;
}

