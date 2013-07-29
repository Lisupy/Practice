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

int getID(int elevator, int _floor){
  return elevator * 100 + _floor;
}

int main(){
  int n, K;
  while (cin >> n >> K){
    vector<vector<pair<int, int> > > links(n * 100);
    vector<vector<int> > stopAt(100);
    vector<int> T(n);
    for (int i = 0; i < n; i++) cin >> T[i];
    cin.ignore();
    for (int i = 0; i < n; i++){
      string line; getline(cin, line);
      //cout << "[" << line << "]" << endl;
      istringstream iss(line);
      vector<int> stops;
      int t;
      while (iss >> t){
        stops.push_back(t);
        stopAt[t].push_back(i);
        //cout << t << "=>" << i << endl;
      }
      for (size_t j = 1; j < stops.size(); j++){
        int u = getID(i, stops[j - 1]);
        int v = getID(i, stops[j]);
        int w = (stops[j] - stops[j - 1]) * T[i];
        links[u].push_back(make_pair(v, w));
        links[v].push_back(make_pair(u, w));
      }
    }
    for (int i = 0; i < 100; i++){
      //cout << i << " +++==>" << stopAt[i].size() << endl;
      for (size_t k = 0; k < stopAt[i].size(); k++){
        for (size_t j = 0; j < stopAt[i].size(); j++){
          int u = getID(stopAt[i][k], i);
          int v = getID(stopAt[i][j], i);
          links[u].push_back(make_pair(v, 60));
          links[v].push_back(make_pair(u, 60));
          //cout << k << ", " << j << endl;
          //cout << i << ", " << u << ", " << v << endl;;
        }
      }
    }
    vector<bool> inQueue(100 * n);
    vector<int> dist(100 * n, 0x1f1f1f1f);
    queue<int> Q;
    for (int i = 0; i < n; i++){
      int s = getID(i, 0);
      Q.push(s);
      inQueue[s] = true;
      dist[s] = 0;
    }
    while (!Q.empty()){
      int s = Q.front(); Q.pop(); inQueue[s] = false;
      //printf("pop: %d %d\n", s, dist[s]);
      for (size_t i = 0; i < links[s].size(); i++){
        int t = links[s][i].first;
        int w = links[s][i].second;
        //printf("%d %d %d\n", t, dist[t], w);
        if (dist[s] + w < dist[t]){
          //printf("push \n");
          dist[t] = dist[s] + w;
          if (!inQueue[t]){
            Q.push(t);
            inQueue[t] = true;
          }
        }
      }
    }
    int minDist = 0x1f1f1f1f;
    for (int i = 0; i < n; i++){
      int s = getID(i, K);
      minDist = min(minDist, dist[s]);
    }
    if (minDist >= 0x1f1f1f1f){
      cout << "IMPOSSIBLE" << endl;
    }else{
      cout << minDist << endl;
    }
  }
}



