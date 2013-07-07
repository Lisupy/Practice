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

vector<int> path;
int m, n;
vector<vector<int> > links;
vector<int> in_degree;
vector<bool> visited;
void dfs(int s){
  path.push_back(s);
  visited[s] = true;
  for (size_t i = 0; i < links[s].size(); i++){
    int t = links[s][i];
    in_degree[t]--;
    if (in_degree[t] == 0 && !visited[t]){
      dfs(t);
    }
  }
}
int main(){
  while (cin >> n >> m && n){
    in_degree.clear();
    links.clear();
    visited.clear();
    links.resize(n + 1);
    in_degree.resize(n + 1);
    for (int i = 0; i < m; i++){
      int s, t;
      cin >> s >> t;
      links[s].push_back(t);
      in_degree[t]++;
    }
    visited.resize(n + 1, false);
    path.clear();
    for (int i = 1; i <= n; i++){
      if (in_degree[i] == 0 && !visited[i]){
        dfs(i);
      }
    }
    for (size_t i = 0; i < path.size(); i++){
      if (i != 0) printf(" ");
      printf("%d", path[i]);
    }
    printf("\n");
  }
}
