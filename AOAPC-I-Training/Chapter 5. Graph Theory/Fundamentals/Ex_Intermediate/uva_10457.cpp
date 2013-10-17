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
struct DisjointSet{
  vector<int> p;
  DisjointSet(int n): p(n){
    for (int i = 0; i < n; i++) p[i] = i;
  }
  int find(int x){
    if (p[x] == x) return x;
    p[x] = find(p[x]);
    return p[x];
  }
  void join(int x, int y){
    p[find(x)] = p[find(y)];
  }
  bool isSame(int x, int y){
    return find(x) == find(y);
  }
};
int N, M;
struct Edge{
  int u, v, speed;
};
bool speedLess(const Edge &a, const Edge &b){
  return a.speed < b.speed;
}
vector<Edge> edges;
int solve(int start, int end){
  int best = 0x1f1f1f1f;
  for (size_t i = 0; i < edges.size(); i++){
    int hiSpeed = edges[i].speed; 
    DisjointSet ds(N + 1);
    size_t j = i;
    int loSpeed = hiSpeed;
    while (j < edges.size() && !ds.isSame(start, end)){  
      ds.join(edges[j].u, edges[j].v);
      loSpeed = edges[j].speed; 
      j++;
    }
    if (ds.isSame(start, end)){
      best = min(best, hiSpeed - loSpeed);
    }
  }
  return best;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while(cin >> N >> M){
    edges.resize(M);
    for (int i = 0; i < M; i++){
      cin >> edges[i].u >> edges[i].v >> edges[i].speed;
    }
    sort(edges.begin(), edges.end(), speedLess);
    reverse(edges.begin(), edges.end());
    int startCost, stopCost; cin >> startCost >> stopCost;
    int K; cin >> K;
    while (K--) {
      int start, end; cin >> start >> end; 
      cout << solve(start, end)  + startCost + stopCost << endl;
    }
  }
}

