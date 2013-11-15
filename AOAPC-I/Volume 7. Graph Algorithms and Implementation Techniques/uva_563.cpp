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

const int MAX_V = 5100;
const int INF = 0x1f1f1f1f;
int s, a, b;

int source, dest;


struct edge{
  int to, cap, rev;
};

vector<edge> G[MAX_V];
bool used[MAX_V];
void add_edge(int from, int to, int cap){
  G[from].push_back({to, cap, (int)G[to].size()});
  G[to].push_back({from, 0, (int)G[from].size() - 1});
}

int dfs(int v, int t, int f){
  if (v == t) return f;
  used[v] = true;
  for (size_t i = 0; i < G[v].size(); i++){
    edge &e = G[v][i];
    if (!used[e.to] && e.cap > 0){
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0){
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int so, int t){
  int flow = 0;
  while (true){
    memset(used, 0, sizeof(used));
    int f = dfs(so, t, INF);
    if (f == 0) return flow;
    flow += f;
  }
  return flow;
}

void reset(){
  for (int i = 0; i < MAX_V; i++){
    G[i].clear();
  }
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1,-1, 0, 0};
bool isValid(int x, int y){
  return 1 <= x && x <= s && 1 <= y && y <= a;
}
int inID(int x, int y){
  return (x - 1) * a + (y - 1) + 1;
}
int outID(int x, int y){
  return inID(x, y) + s * a;
}
int main(){
  int TestNum; cin >> TestNum;
  while (TestNum--){
    reset();
    cin >> s >> a >> b;
    source = 0, dest = 2 * a * s + 1;
    for (int x1 = 1; x1 <= s; x1++){
      for (int y1 = 1; y1 <= a; y1++){
        add_edge(inID(x1, y1), outID(x1, y1), 1);
        for (int i = 0; i < 4; i++){
          int x2 = x1 + dx[i], y2 = y1 + dy[i];
          if (isValid(x2, y2)){
            add_edge(outID(x1, y1), inID(x2, y2), 1);
          }else{
            add_edge(outID(x1, y1), dest, 1);
          }
        }
      }
    }
    for (int i = 0; i < b; i++){
      int x, y; cin >> x >> y;
      add_edge(source, inID(x, y), 1);
    }
    int maxflow = max_flow(source, dest);
    //cout << maxflow << endl;
    if (maxflow == b){
      cout << "possible" << endl;
    }else{
      cout << "not possible" << endl;
    }
  }
}
