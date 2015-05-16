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

int G[128][128];
int minEdge[128];
bool used[128];
int N;
void update(int s) {
  used[s] = true;
  for (int i = 0; i < N; i++) {
    minEdge[i] = min(minEdge[i], G[s][i]); 
  }
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (cin >> N) {
    memset(minEdge, 0x3f, sizeof(minEdge));
    memset(used, 0, sizeof(used));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> G[i][j];
      }
    }
    update(0);
    int tot = 0;
    for (int i = 1; i < N; i++) {
      int selected = -1;
      for (int j = 0; j < N; j++) if (!used[j]) {
        if (selected == -1 || minEdge[j] < minEdge[selected]) {
          selected = j;
        }
      }
      tot += minEdge[selected];
      update(selected);
    }
    cout << tot << endl;
  }
}

