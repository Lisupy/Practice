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

vector<string> dict;
map<string, vector<string> > anagramMap;
string wordFormat(string s){
  sort(s.begin(), s.end());
  return s;
}
bool myLess(const vector<string> &a, const vector<string> &b){
  if (a.size() != b.size()) return a.size() > b.size();
  return a[0] < b[0];
}
int TestNum;
int main(){
  string s;
  while (cin >> s) dict.push_back(s);
  for (size_t i = 0; i < dict.size(); i++){
    anagramMap[wordFormat(dict[i])].push_back(dict[i]);
  }
  vector<vector<string> > res;
  for (map<string, vector<string> >::iterator it = anagramMap.begin(); it != anagramMap.end(); it++){
    res.push_back(it->second);
  }
  for (size_t i = 0; i < res.size(); i++){
    sort(res[i].begin(), res[i].end());
  }
  sort(res.begin(), res.end(), myLess);
  for (size_t i = 0; i < res.size() && i < 5; i++){
    cout << "Group of size " << res[i].size() << ": ";
    res[i].erase(unique(res[i].begin(), res[i].end()), res[i].end());
    for (size_t j = 0; j < res[i].size(); j++){
      cout << res[i][j] << " ";
    }
    cout << "." << endl;
  }
}

