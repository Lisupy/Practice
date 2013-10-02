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
int N;
vector<string> words;
//vector<string> dict[26][26];
vector<string> graph[26];
size_t scaners[26];
int inDeg[26];
int outDeg[26];
void reset(){
  for (int i = 0; i < 26; i++) graph[i].clear();
  memset(scaners, 0, sizeof(scaners));
  memset(inDeg, 0, sizeof(inDeg));
  memset(outDeg, 0, sizeof(outDeg));
}
void dfs(int s, vector<string> &path){
  while (scaners[s] < graph[s].size()){
    string w = graph[s][scaners[s]++];
    int t = w[w.size() - 1] - 'a';
    dfs(t, path);
    path.push_back(w);
  }
}
void solve(){
  int cnt = 0;
  int start = -1;
  for (int i = 0; i < 26; i++){
    if (inDeg[i] != outDeg[i]) cnt++;
    if (outDeg[i] - inDeg[i] > 1) cnt = 3;
    if (inDeg[i] - outDeg[i] > 1) cnt = 3;
    if (inDeg[i] - outDeg[i] < 0) start = i; 
    if (start == -1 && inDeg[i] != 0) start = i;
  }
  if (cnt > 2){
    cout << "***" << endl;
    return;
  }
  vector<string > path;
  dfs(start, path);
  if ((int)path.size() != N){
    cout << "***" << endl;
  }else{
    reverse(path.begin(), path.end());
    string ans;
    for (size_t i = 0; i < path.size(); i++){
      if (i != 0) ans += ".";
      ans += path[i];
    }
    cout << ans << endl;
  }
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  cin >> TestNum;
  while (TestNum--) {
    cin >> N;
    words.resize(N); 
    reset();

    for (int i = 0; i < N; i++){
      string &w = words[i]; cin >> w;
      int u = w[0] - 'a', v = w[w.size() - 1] - 'a';
      graph[u].push_back(w);
      inDeg[v]++;
      outDeg[u]++;
    }
    for (int i = 0; i < 26; i++){
      sort(graph[i].begin(), graph[i].end());
    }
    solve();
  }
}

