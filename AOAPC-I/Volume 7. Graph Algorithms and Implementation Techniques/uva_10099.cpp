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
const int MAXN = 128;
int N;
double R;
struct Edge{
  int u, v;
  int l;
};
bool operator<(const Edge &a,  const Edge& b){ return a.l < b.l; }


int TestNum;

void addEdge(priority_queue<Edge> &Q, vector<Edge> &edges){
  for (size_t i = 0; i < edges.size(); i++) Q.push(edges[i]);
}
int main(){
  while (cin >> N >> R && N){
    vector<vector<Edge> > links(N + 1);
    while (R--){
      int c1, c2, p; cin >> c1 >> c2 >> p;
      links[c1].push_back({c1, c2, p});
      links[c2].push_back({c2, c1, p});
    }
    int S, D; double T; cin >> S >> D >> T;

    vector<int> visited(N + 1, false);
    vector<int> minEdge(N + 1);
    priority_queue<Edge> edges;
    visited[S] = true;
    minEdge[S] = 0xffff;
    addEdge(edges, links[S]);
    while (!visited[D]){
      Edge e = edges.top();
      edges.pop();
      //cout << e.v << endl;
      if (!visited[e.v]){
        visited[e.v] = true;
        minEdge[e.v] = min(minEdge[e.u], e.l);
        //cout << e.v << ", " << e.l << endl;
        addEdge(edges, links[e.v]);
      }
    }
    //cout << minEdge[D] << endl;
    printf("Scenario #%d\n", ++TestNum);
    printf("Minimum Number of Trips = %d\n", (int)ceil(T / (minEdge[D] - 1)));
    printf("\n");
  }
}


  
