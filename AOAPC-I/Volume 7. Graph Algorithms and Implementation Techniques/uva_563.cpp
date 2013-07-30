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

const int MAXN = 5120;
const int INF = 0x1f1f1f1f;
int s, a, b;

int flow[MAXN][MAXN];
int cap[MAXN][MAXN];
int source, dest;

int maxFlow(){
  int totalFlow = 0;
  while (true){
    //cout << "----" << endl;
    vector<int> f(dest + 1); f[source] = INF;
    queue<int> q; q.push(source);
    vector<int> p(dest + 1);
    while (!q.empty() && f[dest] == 0){
      int u = q.front(); q.pop();
      //cout << u << endl;
      for (int v = 0; v <= dest; v++){
        int resdiual = cap[u][v] - flow[u][v];
        if (resdiual > 0 && f[v] == 0){
          //cout << v << ", " << resdiual << endl;
          p[v] = u;
          f[v] = min(f[u], resdiual);
          q.push(v);
        }
      }
    }
    //cout << f[dest] << endl;
    if (f[dest] == 0) break;
    for (int u = dest; u != source; u = p[u]) flow[p[u]][u] += f[dest], flow[u][p[u]] -= f[dest];
    totalFlow += f[dest];
  }
  return totalFlow;
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
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
    cin >> s >> a >> b;
    source = 0, dest = 2 * a * s + 1;
    for (int x1 = 1; x1 <= s; x1++){
      for (int y1 = 1; y1 <= a; y1++){
        cap[inID(x1, y1)][outID(x1, y1)] = 1;
        //cout << inID(x1, y1) << ", " << outID(x1, y1) << endl;
        for (int i = 0; i < 4; i++){
          int x2 = x1 + dx[i], y2 = y1 + dy[i];
          if (isValid(x2, y2)){
            cap[outID(x1, y1)][inID(x2, y2)] = 1;
          }else{
            cap[outID(x1, y1)][dest] = 1;
            //cout << x1 << ", " << y1 << endl;
          }
        }
      }
    }
    for (int i = 0; i < b; i++){
      int x, y; cin >> x >> y;
      cap[source][inID(x, y)]++;
      //cout << inID(x, y) << endl;
    }
    int maxflow = maxFlow();
    //cout << maxflow << endl;
    if (maxflow == b){
      cout << "possible" << endl;
    }else{
      cout << "not possible" << endl;
    }
  }
}
