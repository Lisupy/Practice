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
struct KMP{
  string &s;
  int n;
  vector<int> nxt;
  KMP(string &_s): s(_s), n(s.size()), nxt(n + 1){
    nxt[0] = -1;
    for (int i = 0; i < n; i++){
      int j = nxt[i];
      while (j >= 0 && s[i] != s[j]) j = nxt[j];
      nxt[i + 1] = j + 1;
    }
  }
  vector<pair<int, int> > getPeriods(){
    vector<pair<int, int> > periods;
    vector<int> tmp(n + 1);
    tmp[0] = 0;
    for (int i = 1; i <= n; i++){
      if (i - nxt[i] == tmp[nxt[i]]) tmp[i] = i - nxt[i];
      else tmp[i] = i; 
    }
    for (int i = 2; i <= n; i++){
      if (tmp[i] != i) periods.push_back(make_pair(i, i / tmp[i]));
    }
    return periods;
  }
};
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int N; 
  while (cin >> N && N) {
    cout << "Test case #" << ++TestNum << endl;
    string s; cin >> s;
    //cout << s << endl;
    KMP kmp(s);
    vector<pair<int, int> > periods = kmp.getPeriods();
    for (size_t i = 0; i < periods.size(); i++){
      cout << periods[i].first << " " << periods[i].second << endl;
    }
    cout << endl;
  }
}


