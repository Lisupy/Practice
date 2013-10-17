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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 */

const int MAXN = 1024;



//[from, to)
//void solve(vector<int> bfs, vector<int> bfs_rank){
  
//}

int TestNum;
int main(){
  int n;
  while (cin >> n){
    vector<vector<int> > sons(n + 1);
    vector<vector<int> > layers;
    
    vector<int> bfs(n);
    vector<int> dfs(n);
    vector<int> bfs_rank(n + 1);
    vector<int> dfs_rank(n + 1); 
    for (int i = 0; i < n; i++) cin >> bfs[i];
    for (int i = 0; i < n; i++) cin >> dfs[i];
    for (int i = 0; i < n; i++) bfs_rank[bfs[i]] = i;// = find(bfs.begin(), bfs.end(), i) - bfs.begin();
    for (int i = 0; i < n; i++) dfs_rank[dfs[i]] = i;
    layers.push_back(vector<int>(1, dfs[0]));
    for (int i = 1; i < n; i++){
      size_t l = 1;
      while (l < layers.size()){
        if (bfs_rank[layers[l].back()] + 1 < bfs_rank[dfs[i]])
          l++;
        else
          break;
      }
      if (l == layers.size()) layers.push_back(vector<int>(1, dfs[i]));
      else layers[l].push_back(dfs[i]);
    }
    //cout << endl;
    //for (auto la : layers){
      //for (auto i : la) cout << i << "(" << bfs_rank[i] << ", " << dfs_rank[i] << ") "; cout << endl;
    //}
    for (size_t l = 0; l < layers.size() - 1; l++){
      for (size_t i = 0; i < layers[l].size(); i++){
        int father = layers[l][i];
        int from = dfs_rank[layers[l][i]];
        int to = i + 1 < layers[l].size() ? dfs_rank[layers[l][i + 1]] : 0xffffff;
        //printf("father: %d , (%d, %d):\n", father, from, to);
        for (size_t j = 0; j < layers[l + 1].size(); j++){
          int node = layers[l + 1][j];
          if (from < dfs_rank[node] && dfs_rank[node] < to){
            sons[father].push_back(node);
          }
        }
      }
    }

    //solve(dfs, bfs_rank);

    for (int i = 1; i <= n; i++) sort(sons[i].begin(), sons[i].end());
    for (int i = 1; i <= n; i++){
      printf("%d:", i);
      for (size_t j = 0; j < sons[i].size(); j++){
        printf(" %d", sons[i][j]);
      }printf("\n");
    }
  }
}

