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
const int MAXN = 512;
const int INF = 0x1f1f1f1f;
int receptacleNum;
string receptacles[128];
int deviceNum;
string devices[128];
int adapterNum;
string adapters[128][2];
int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int source, dest;

int receptacleID(int i){
  return i;
}
int deviceID(int i){
  return i + receptacleNum;
}
int adapterID1(int i){
  return i + receptacleNum + deviceNum;
}
int adapterID2(int i){
  return i + receptacleNum + deviceNum + adapterNum;
}
int maxFlow(){
  int totalFlow = 0;
  while (true){
    //cout << "=========" << endl;
    queue<int> q;
    vector<int> f(dest + 1);
    vector<int> p(dest + 1);
    q.push(source); f[source] = INF;
    while (!q.empty() && f[dest] == 0){
      int u = q.front(); q.pop();
      for (int v = 0; v <= dest; v++){
        int resdiual = cap[u][v] - flow[u][v];
        if (resdiual > 0 && f[v] == 0){
          //cout << u << ", " << v << ": " << resdiual << endl;
          f[v] = min(resdiual, f[u]);
          p[v] = u;
          q.push(v);
        }
      }
    }
    if (f[dest] == 0) break;
    //cout << f[dest] << endl;
    for (int u = dest; u != source; u = p[u]) flow[p[u]][u] += f[dest], flow[u][p[u]] -= f[dest];
    totalFlow += f[dest];
    //cout << endl;
  }
  return totalFlow;
}


    
int main(){
  int TestNum; cin >> TestNum;
  while (TestNum--){
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
    cin >> receptacleNum; for (int i = 1; i <= receptacleNum; i++) cin >> receptacles[i];
    string tmp;
    cin >> deviceNum; for (int i = 1; i <= deviceNum; i++) cin >> tmp >> devices[i];
    cin >> adapterNum; for (int i = 1; i <= adapterNum; i++) cin >> adapters[i][0] >> adapters[i][1];
    source = 0, dest = receptacleNum + deviceNum + 2 * adapterNum + 1;
    for (int i = 1; i <= deviceNum; i++){
      cap[source][deviceID(i)]++;
    }
    for (int i = 1; i <= deviceNum; i++){
      for (int j = 1; j <= receptacleNum; j++){
        if (devices[i] == receptacles[j]){
          cap[deviceID(i)][receptacleID(j)] = INF;
        }
      }
    }
    for (int i = 1; i <= deviceNum; i++){
      for (int j = 1; j <= adapterNum; j++){
        if (devices[i] == adapters[j][0]){
          cap[deviceID(i)][adapterID1(j)] = INF;
        }
      }
    }
    for (int i = 1; i <= adapterNum; i++){
      cap[adapterID1(i)][adapterID2(i)] = INF;
    }
    for (int i = 1; i <= adapterNum; i++){
      for (int j = 1; j <= adapterNum; j++){
        if (adapters[i][0] == adapters[j][1]){
          cap[adapterID2(j)][adapterID1(i)] = INF;
        }
      }
    }
    for (int i = 1; i <= adapterNum; i++){
      for (int j = 1; j <= receptacleNum; j++){
        if (adapters[i][1] == receptacles[j]){
          cap[adapterID2(i)][receptacleID(j)] = INF;
        }
      }
    }
    for (int i = 1; i <= receptacleNum; i++) cap[receptacleID(i)][dest]++;
    int maxflow = maxFlow();
    //cout << maxflow << endl;
    cout << deviceNum - maxflow << endl;
    if (TestNum) cout << endl;
  }
}
