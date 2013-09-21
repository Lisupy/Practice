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

vector<int> getNext(string s){
  vector<int> nxt(s.size() + 1, 0);
  nxt[0] = -1;
  int j = -1;
  for (size_t i = 0; i < s.size(); i++){
    while (j >= 0 && s[i] != s[j]){
      j = nxt[j];
    }
    nxt[i + 1] = ++j;
  }
  return nxt;
}
int TestNum;
int main(){
  string s;
  while (cin >> s){
    vector<int> nxt = getNext(s);
    //cout << s.size() << endl;
    vector<int> ans;
    int pos = s.size();
    while (pos > 0){
      ans.push_back(pos);
      pos = nxt[pos];
    }
    reverse(ans.begin(), ans.end());
    for (size_t i = 0; i < ans.size(); i++){
      if (i != 0) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }
}

