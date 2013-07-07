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

const int MAXN = 128;
bool connect[MAXN][MAXN];
int dist[MAXN];
int v[MAXN];
vector<vector<int> > links;
int d[MAXN];
int cnt[MAXN];
int n;
int main(){
  while (scanf("%d", &n) && n != -1){
    links.clear();
    links.resize(n + 1);
    memset(connect, false, sizeof(connect));
    for (int i = 0; i <= n; i++){
      dist[i] = -0xffffff;
      for (int j = 0; j <= n; j++){
        if (i == j){
          connect[i][j] = true;
        }
      }
    }

    for (int i = 1; i <= n; i++){
      scanf("%d", &v[i]);
      int m;
      scanf("%d", &m);
      links[i].resize(m);
      for (int j = 0; j < m; j++){
        scanf("%d", &links[i][j]);
      }
    }
    for (int i = 1; i <= n; i++){
      vector<int> &link = links[i];
      for (size_t j = 0; j < link.size(); j++){
        int t = link[j];
        connect[i][t] = true;
      }
    }

    for (int i = 1; i <= n; i++){
      for (int s = 1; s <= n; s++){
        for (int t = 1; t <= n; t++){
          if (connect[s][i] && connect[i][t]){
            connect[s][t] = true;
          }
        }
      }
    }

    queue<int> Q;
    Q.push(1);
    dist[1] = 100;
    memset(cnt, 0, sizeof(cnt));
    cnt[1] = 1;
    bool pathFound = false;
    if (n == 1){
      pathFound = true;
    }
    while (!Q.empty() && !pathFound){
      int s = Q.front();
      Q.pop();
      vector<int> &link = links[s];
      for (size_t i = 0; i < link.size(); i++){
        int t = link[i];
        if (t == n){
          pathFound = true;
          break;
        }
        if (!connect[t][n]){
          continue;
        }
        if (dist[s] + v[t] > 0 && dist[s] + v[t] > dist[t]){
          dist[t] = dist[s] + v[t];
          Q.push(t);
          cnt[t]++;
          if (cnt[t] > n){
            pathFound = true;
            break;
          }
        }
      }
    }
    if (pathFound){
      printf("winnable\n");
    }else{
      printf("hopeless\n");
    }
  }
}
