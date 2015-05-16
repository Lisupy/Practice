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
bool visited[26][26];
int p, q;
vector<pair<int, int> > path;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1,  1, -2,  2, -2,2,-1, 1};
bool dfs(int x, int y) {
  path.push_back(make_pair(x, y));
  if (int(path.size()) == p * q) return true;
  visited[x][y] = true;
  for (int i = 0; i < 8; i++) {
    int tx = x + dx[i];
    int ty = y + dy[i];
    if (0 <= tx && tx < q && 0 <= ty && ty < p && !visited[tx][ty]){
      if (dfs(tx, ty)) return true;
    }
  }
  visited[x][y] = false;
  path.pop_back();
  return false;
}
string solve() {
  memset(visited, 0, sizeof(visited));
  path.clear();
  if (dfs(0, 0)) {
    string s;
    for (size_t i = 0; i < path.size(); i++) {
      s += path[i].first + 'A';
      s += path[i].second + '1';
    }
    return s;
  }
  return "impossible";
}

int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int T; cin >> T;
  while (T--) {
    cin >> p >> q;
    cout << "Scenario #" << ++TestNum << ":" << endl;
    cout << solve() << endl;
    if (T) cout << endl;
  }
}

