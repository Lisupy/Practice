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
  vector<int> &pattern;
  int M;
  vector<int> nxt;
  //void dbg(){
    //for (auto e : nxt) cout << e << " "; cout << endl;
  //}
  KMP(vector<int> &_p): pattern(_p), M(pattern.size()), nxt(M + 1){
    int j = -1;
    nxt[0] = -1;
    //for (auto e : pattern) cout << e << " "; cout << endl;
    for (int i = 0; i < M; i++){
      while (j >= 0 && pattern[i] != pattern[j]) j = nxt[j];
      nxt[i + 1] = ++j;
    }
  }
  int execute(vector<int> &text){
    for (int i = 0, j = 0; i < (int)text.size(); i++){
      while (j >= 0 && text[i] != pattern[j]) j = nxt[j];
      if (++j == M ) return i + 1 - M;
    }
    return -1;
  }
};
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  cin >> TestNum;
  while (TestNum--) {
    int N, M; cin >> N >> M;
    vector<int> text(N);
    for (int i = 0; i < N; i++) cin >> text[i];
    vector<int> pattern(M);
    for (int i = 0; i < M; i++) cin >> pattern[i];
    //cout << N << ", " << M << endl;
    KMP kmp(pattern);
    int ans = kmp.execute(text);
    if (ans != -1) ans++;
    cout << ans << endl;
  }
}

