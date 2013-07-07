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

const int MAXN = 256;
vector<vector<int> > links;
vector<int> color;

int input(){
  int n, l;
  cin >> n;
  if (n == 0){
    return 0;
  } 
  links.clear();
  links.resize(n);
  color.clear();
  color.resize(n);
  cin >> l;
  while (l--){
    int s, t;
    cin >> s >> t;
    links[s].push_back(t);
    links[t].push_back(s);
  }
  return n;
}
int dfs(int s, int d){
  color[s] = d;
  for (size_t i = 0; i < links[s].size(); i++){
    int t = links[s][i];
    if (color[t] == 0){
      if (!dfs(t, d + 1)){
        return false;
      }
    }else{
      if ((color[t] + d) % 2 == 0){
        return false;
      }
    }
  }
  return true;
}

int main(){
  while (input()){
    bool valid = dfs(0, 0);
    if (valid){
      cout << "BICOLORABLE." << endl;
    }else{
      cout << "NOT BICOLORABLE." << endl;
    }
  }
}
