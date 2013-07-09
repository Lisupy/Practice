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
 * sizeof
 */
int TestNum;

int n;
vector<int> links[22];
bool visited[22];
int pathNum;

void reset(){
  for (int i = 0; i < 22; i++){
    links[i].clear();
  }
  memset(visited, 0, sizeof(visited));
  pathNum = 0;
}

void dfs(int s, vector<int> path){
  visited[s] = true;
  path.push_back(s);
  if (s == n){
    ++pathNum;
    for (size_t i = 0; i < path.size(); i++){
      if (i != 0){
        printf(" ");
      }
      printf("%d", path[i]);
    }
    printf("\n");
  }else{
    for (size_t i = 0; i < links[s].size(); i++){
      size_t t = links[s][i];
      if (!visited[t]){
        visited[t] = true;
        dfs(t, path);
        visited[t] = false;
      }
    }
  }
}
bool reacheable(int s){
  visited[s] = true;
  if (s == n){
    return true;
  }
  for (size_t i = 0; i < links[s].size(); i++){
    size_t t = links[s][i];
    if (!visited[t]){
      visited[t] = true;
      if (reacheable(t)){
        return true;
      }
    }
  }
  return false;
}



int main(){
  while (scanf("%d", &n) != EOF){
    printf("CASE %d:\n", ++TestNum);
    reset();
    int u, v;
    while (scanf("%d %d", &u, &v) && u){
      links[u].push_back(v);
      links[v].push_back(u);
    }
    for (int i = 1; i < 22; i++){
      sort(links[i].begin(), links[i].end());
    }
    if (!reacheable(1)){
      pathNum = 0;
    }else{
      memset(visited, 0, sizeof(visited));
      dfs(1, vector<int>());
    }
  //  printf("There are %d routes from the firestation to streetcorner %d.\n"
    printf("There are %d routes from the firestation to streetcorner %d.\n", pathNum, n);
  }
}
