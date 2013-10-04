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
  DisjointSet(int n):p(n){
    for (int i = 0; i < n; i++){
      p[i] = i;
    }
  }
  int find(int x){
    if (p[x] == x) return x;
    p[x] = find(p[x]);
    return p[x];
  }
  void join(int x, int y){
    p[find(x)] = p[find(y)];
  }
};
void solve(int n, string str){
  vector<int> links[n + 1];
  DisjointSet ds(n + 1);
  int l = 0;
  for (int i = 0; i <= n; i++){
    for (int j = i + 1; j <= n; j++){
      char ch = str[l++]; 
      if (ch == '0') ds.join(i, j);
    }
  }
  l = 0;
  for (int i = 0; i <= n; i++){
    for (int j = i + 1; j <= n; j++){
      char ch = str[l++]; 
      if (ch == '+') links[ds.find(j)].push_back(ds.find(i));
      if (ch == '-') links[ds.find(i)].push_back(ds.find(j));
    }
  }
  //for (int i = 0; i <= n; i++){
    //if (ds.find(i) == i){
      //printf("%d: ", i);
      //for (size_t j = 0; j < links[i].size(); j++){
        //printf("%2d", links[i][j]);
      //}
      //printf("\n");
    //}
  //}
  vector<int> inDeg(n + 1); 
  for (int i = 0; i <= n; i++){
    if (ds.find(i) == i){
      for (size_t j = 0; j < links[i].size(); j++){
        inDeg[links[i][j]]++;
      }
    }
  }
  queue<int> Q;
  for (int i = 0; i <= n; i++){
    if (ds.find(i) == i){
      if (inDeg[i] == 0) Q.push(i);
    }
  }
  vector<int> order;
  while (!Q.empty()){
    int s = Q.front(); Q.pop();
    //printf("pop: %d\n", s);
    order.push_back(s);
    for (size_t i = 0; i < links[s].size(); i++){
      int t = links[s][i];
      inDeg[t]--;
      if (inDeg[t] == 0) Q.push(t);
    }
  }
  size_t pos = find(order.begin(), order.end(), ds.find(0)) - order.begin();
  vector<int> val(n + 1);
  for (size_t i = 0; i < order.size(); i++){
    val[order[i]] = pos - i;
  }
  for (int i = 0; i <= n; i++){
    val[i] = val[ds.find(i)];
  }
  for (int i = 1; i <= n; i++){
    if (i != 1) printf(" ");
    printf("%d", val[i] - val[i - 1]);
  }
  printf("\n");
}

int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  cin >> TestNum;
  while (TestNum--) {
    int n; string s;
    cin >> n >> s;
    solve(n, s);
  }
}

