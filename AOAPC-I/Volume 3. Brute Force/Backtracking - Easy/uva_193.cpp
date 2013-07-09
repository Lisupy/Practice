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
int n;
vector<vector<int> > links;
vector<int> color;
vector<int> bestA;
int m, k;
void input(){
  cin >> m >> k;
  links.clear();
  links.resize(m + 1);
  color.clear();
  color.resize(m + 1);
  while (k--){
    int u, v;
    cin >> u >> v;
    links[u].push_back(v);
    links[v].push_back(u);
  }
}

bool canBlack(int s){
  for (size_t i = 0; i < links[s].size(); i++){
    int t = links[s][i];
    if (color[t] == 2){
      return false;
    }
  }
  return true;
}

int best = 0;
void dfs(int s, int cnt){
  if (s > m){
    return;
  }
  if (canBlack(s)){
    color[s] = 2;
    if (cnt + 1 > best){
      best = cnt + 1;
      bestA = color;
    }
    dfs(s + 1, cnt + 1);
  }
  color[s] = 1;
  dfs(s + 1, cnt);
}

int main(){
  cin >> n;
  while (n--){
    input();
    best = 0;
    dfs(1, 0);
    printf("%d\n", best);
    vector<int> a;
    for (int i = 0; i <= m; i++){
      if (bestA[i] == 2){
        a.push_back(i);
      }
    }

    for (size_t i = 0; i < a.size(); i++){
      if (i != 0){
        printf(" ");
      }printf("%d", a[i]);
    }
    printf("\n");
  }
}

