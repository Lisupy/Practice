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

vector<vector<int> > blocks;

int solve(){
  int M = blocks.size();
  vector<vector<int> > links(M);
  vector<int>  indegree(M);
  queue<int> Q;
  for (size_t i = 0; i < blocks.size(); i++) {
    for (size_t j = 0; j < blocks.size(); j++) {
      if (blocks[i][0] > blocks[j][0] && blocks[i][1] > blocks[j][1]){
        links[i].push_back(j);
        indegree[j]++;
      }
    }
  }
  for (size_t i = 0; i < indegree.size(); i++) {
    if (indegree[i] == 0){
      Q.push(i);
    }
  }
  vector<int> longest(M);
  for (size_t i = 0; i < blocks.size(); i++){
    longest[i] = blocks[i][2];
  }
  while (!Q.empty()){
    int s = Q.front(); Q.pop();
    for (size_t i = 0; i < links[s].size(); i++){
      int t = links[s][i];
      longest[t] = max(longest[t], longest[s] + blocks[t][2]);
      if (--indegree[t] == 0){
        Q.push(t);
      }
    }
  }
  return *max_element(longest.begin(), longest.end());
}
int TestNum;
vector<int> make_vector(int a, int b, int c){
  vector<int> v(3);
  v[0] = a, v[1] = b, v[2] = c;
  return v;
}
int main(){
  while (cin >> n && n){
    blocks.clear();
    for (int i = 0; i < n; i++){
      int x, y, z;
      cin >> x >> y >> z;
      blocks.push_back(make_vector(max(x, y), min(x, y), z));
      blocks.push_back(make_vector(max(z, x), min(z, x), y));
      blocks.push_back(make_vector(max(y, z), min(y, z), x));
    }
    int ans = solve();
    printf("Case %d: maximum height = %d\n", ++TestNum, ans);
  }
}
     

