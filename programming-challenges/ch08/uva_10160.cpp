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
const double PI = acos(-1);
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
const int MAXN = 36;

vector<int> links[MAXN];
vector<bool> marked;
vector<bool> sel;
int best;
int N, M;
void reset(){
  for (int i = 0; i < MAXN; i++) links[i].clear(), links[i].push_back(i);
  marked.clear();
  marked.resize(N + 1);
  sel.clear();
  sel.resize(N + 1);
  best = MAXN;
}

int get_notMark(){
  for (int i = 1; i <= N; i++){
    if (!marked[i]) return i;
  }
  return -1;
}
void doMark(int s){
  vector<int> &l = links[s];
  for (size_t i = 0; i < l.size(); i++){
    int t = l[i];
    marked[t] = true;
  }
}

void dfs(int cnt){
  if (cnt == best) return;
  vector<bool> bak_mark(marked);
  vector<bool> bak_sel(sel);
  int s = get_notMark();
  if (s == -1) {
    best = min(best, cnt);
    return;
  }
  vector<int> &l = links[s];
  for (size_t i = 0; i < l.size(); i++){
    int t = l[i];
    if (sel[t]) continue;
    sel[t] = true;
    doMark(t);
    dfs(cnt + 1);
    marked = bak_mark;
  }
  sel = bak_sel;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (cin >> N >> M && N){
    reset();
    while (M--){
      int u, v; cin >> u >> v;
      links[u].push_back(v);
      links[v].push_back(u);
    }
    best = MAXN;
    dfs(0); 
    cout << best << endl;
  }
}

