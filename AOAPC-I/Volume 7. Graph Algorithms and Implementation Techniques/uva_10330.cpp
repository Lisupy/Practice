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

const int MAXN = 256;
const int INF = 0x1f1f1f1f;
int N;


int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int source, dest;

void reset(){
  memset(cap, 0, sizeof(cap));
  memset(flow, 0, sizeof(flow));
}

void addEdge(int u, int v, int c){
  cap[u][v] += c;
}
void input(){
  source = 0, dest = 2 * N + 1;
  for (int i = 1; i <= N; i++){
    int c; cin >> c;
    addEdge(i, i + N, c);
  }
  int M; cin >> M;
  while (M--){
    int i, j, c; cin >> i >> j >> c;
    addEdge(i + N, j, c);
    //addEdge(j + N, i, c);
  }
  int B, D; cin >> B >> D;
  while (B--){
    int t; cin >> t;
    addEdge(source, t, INF);
  }
  while (D--){
    int t; cin >> t;
    addEdge(t + N, dest, INF);
  }
}

int maxFlow(){
  int f = 0;
  while (true){
    vector<int> r(dest + 1);
    vector<int> p(dest + 1);
    r[source] = INF;
    queue<int> q;
    q.push(source);
    while (!q.empty()){
      int u = q.front(); q.pop();
      for (int v = 1; v <= dest; v++){
        if (r[v] == 0 && cap[u][v] > flow[u][v]){
          p[v] = u; q.push(v);
          r[v] = min(r[u], cap[u][v] - flow[u][v]);
        }
      }
    }
    if (r[dest] == 0) break;
    for (int u = dest; u != source; u = p[u]){
      flow[p[u]][u] += r[dest];
      flow[u][p[u]] -= r[dest];
    }
    f += r[dest];
  }
  return f;
}
int main(){
  while (cin >> N){
    reset();
    input();
    cout << maxFlow() << endl;
  }
}
