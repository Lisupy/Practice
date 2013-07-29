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

int T;
int A, B, M, L, K;

struct Edge{
  int u, v;
  int w;
};
vector<Edge> edges;

void addEdge(int u, int v, int w){
  edges.push_back({u, v, w});
}


void addEdge1(int u, int lu, int v, int lv, int w){
  edges.push_back({u + lu * (A + B), v + lv * (A + B), w});
}
const int INF = 0x1f1f1f1f;
int d[128][128];

void reset(){
  edges.clear();
  memset(d, 0x1f, sizeof(d));
  for (int i = 0; i < 128; i++) d[i][i] = 0;
}

int main(){
  cin >> T;
  while (T--){
    reset();
    cin >> A >> B >> M >> L >> K;
    int N = A + B;
    for (int i = 0; i < M; i++){
      int X, Y, Li; cin >> X >> Y >> Li;
      d[X][Y] = d[Y][X] = Li;
    }
    for (int i = 1; i <= A; i++){
      for (int s = 1; s <= N; s++){
        for (int t = 1; t <= N; t++){
          d[s][t] = min(d[s][t], d[s][i] + d[i][t]);
        }
      }
    }



    for (int X = 1; X <= N; X++){
      for (int Y = 1; Y <= N; Y++){
        int Li = d[X][Y];        
        if (Li == INF) continue; 
        if (Li <= L){
          for (int j = 1; j <= K; j++){
            addEdge1(X, j, Y, j - 1, 0);
            addEdge1(Y, j, X, j - 1, 0);
          }
        }
        for (int j = 0; j <= K; j++){
          addEdge1(X, j, Y, j, Li);
          addEdge1(Y, j, X, j, Li);
        }
      }
    }
    for (int i = 1; i <= A + B; i++){
      for (int j = 1; j <= K; j++){
        addEdge1(i, j, i, j - 1, 0);
      }
    }
    int to = 1;
    int NN = A + B + K * (A + B); 
    int start = NN;
    //cout << start << endl;
    vector<int> dist(NN + 1, INF);
    dist[start] = 0;
    for (int k = 0; k < NN; k++){
      bool ok = true;
      for (size_t i = 0; i < edges.size(); i++){ 
        Edge &e = edges[i];
        if (dist[e.u] != INF){
          int dv = dist[e.u] + e.w;
          if (dist[e.v] > dv){
            //cout << e.v << ": " << dv << ",,," << e.u << endl;
            dist[e.v] = dv;
            ok = false;
          }
        }
      }
      if (ok) break;
    }
    cout << dist[to] << endl;
  }
}
