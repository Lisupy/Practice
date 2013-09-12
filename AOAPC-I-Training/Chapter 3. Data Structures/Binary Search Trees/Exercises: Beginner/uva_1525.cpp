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
 * (1 << (31 - __builtin_clz(100) ) == 64;
 */
vector<string> layers;
vector<int> pos;
string ans;
void dfs(int d, char maxs){
  if (d == (int)layers.size()) return;
  string &la = layers[d];
  if (pos[d] < (int)la.size()){
    char ch = la[pos[d]];
    if (ch < maxs){
      ans += ch;
      pos[d]++;
      dfs(d + 1, ch);
      dfs(d + 1, maxs);
    }else{
      dfs(d + 1, maxs);
    }
  }else{
    dfs(d + 1, maxs);
  }
}
void solve(){
  reverse(layers.begin(), layers.end());
  pos.clear(); pos.resize(layers.size());
  ans = "";
  dfs(0, 127);
  cout << ans << endl;
}

int TestNum;
int main(){
  string s;
  while (cin >> s) {
    if (s == "*" || s == "$") solve(), layers.clear();
    else layers.push_back(s);
    if (s == "$") break;
  }
}

