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
 * decltype // deprecated
 */
struct KMP{
  string &P;
  int N;
  vector<int> nxt;
  void dbg(){
    //for (auto e: nxt) cout << e << " "; cout << endl;
  }
  KMP(string &_p): P(_p), N(P.size()), nxt(N + 1){
    nxt[0] = -1;
    for (int i = 0, j = -1; i < N; i++){
      while (j >= 0 && P[j] != P[i]) j = nxt[j];
      nxt[i + 1] = ++j;
    }
    //dbg();
  }
  vector<int> executeAll(string &T){
    vector<int> ans;
    for (int i = 0, j = 0; i < (int)T.size(); i++){
      while (j >= 0 && (j == N || P[j] != T[i])) j = nxt[j];
      if (++j == N) ans.push_back(i + 1 - N);
      //cout << j << endl;
    }
    return ans;
  }
};


int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  cin >> TestNum;
  while (TestNum--) {
    string W, T; cin >> W >> T; 
    KMP kmp(W);
    vector<int> res = kmp.executeAll(T);
    cout << res.size() << endl;
  }
}

