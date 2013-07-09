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

bool mat[128][128];
string p;
int input(){
  string line;
  cin >> line;
  if (line == "#"){
    return 0;
  }

  memset(mat, false, sizeof(mat));
  p = "";
  size_t start = 0;
  while (start < line.size()){
    size_t end = line.find(";", start);
    if (end == string::npos){
      end = line.size();
    }
    string s = line.substr(start, end - start);
    for (size_t i = 2; i < s.size(); i++){
      mat[(int)s[0]][(int)s[i]] = true;
      mat[(int)s[i]][(int)s[0]] = true;
    }
    p += s[0] + s.substr(2);
    start = end + 1;
  }
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  return 1;
}

string bestP;
int best = 0xfffffff;
void dfs(string cur, string remain, int band){
  //cout << "[" << cur << "], [" << remain << "] => " << band << endl;
  if (remain.size() == 0){
    if (band < best){
      best = band;
      bestP = cur;
    }
  }else{
    for (size_t i = 0; i < remain.size(); i++){
      int newDist = 0;
      for (size_t j = 0; j < cur.size() && newDist < best; j++){
        if (mat[(int)cur[j]][(int)remain[i]]){
          newDist = max(newDist, int(cur.size() - j));
        }
      }
      if (newDist >= best){
        continue;
      }
      dfs(cur + remain[i], remain.substr(0, i) +  remain.substr(i + 1), max(newDist, band));
    }
  }
}
int main(){
  while (input()){
    best = 0xffffff;
    dfs("", p, 0);
    for (size_t i = 0; i < bestP.size(); i++){
      printf("%c ", bestP[i]);
    }
    printf("-> %d\n", best);
  }
}



