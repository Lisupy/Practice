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
struct SA{
  const string &s;
  int n;
  vector<int> sa;
  vector<int> rnk;
  vector<int> lcp;
  //void debug(){
    //cout << s << endl;
    //for (auto e : sa) cout << s.substr(e) << endl;
    //for (auto e : rnk) cout << e << ", " ; cout << endl;
    //for (auto e : lcp) cout << e << ", " ; cout << endl;
  //}
  SA(const string &_s): s(_s), n(int(s.size())), sa(n + 1), rnk(n + 1), lcp(n + 1){
    construct_sa();
    construct_rnk();
    construct_lcp();
  }
  struct Less{
    const vector<int> &rnk;
    int off;
    int n;
    Less(const vector<int> &_r, int _off, int _n): rnk(_r), off(_off), n(_n){}
    bool operator()(int i, int j){
      if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
      int ri = i + off <= n? rnk[i + off] : -1;
      int rj = j + off <= n? rnk[j + off] : -1;
      return ri < rj;
    }
  };
  void construct_sa(){
    for (int i = 0; i <= n; i++){
      rnk[i] = s[i];
      sa[i] = i;
    }
    for (int off = 1; off <= n; off *= 2){
      Less _less(rnk, off, n);
      sort(sa.begin(), sa.end(), _less);
      vector<int> tmp(n + 1);
      tmp[sa[0]] = 0;
      for (int i = 1; i <= n; i++){
        tmp[sa[i]] = tmp[sa[i - 1]] + _less(sa[i - 1], sa[i]);
      }
      swap(tmp, rnk);
    }
  }
  void construct_rnk(){
    for (int i = 0; i <= n; i++) rnk[sa[i]] = i;
  }
  void construct_lcp(){
    int h = 0;
    lcp[0] = 0;
    for (int i = 0; i < n; i++){
      if (h > 0) h--;
      int j = sa[rnk[i] - 1];
      while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
      lcp[rnk[i] - 1] = h;
    }
  }
};
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  string A, B; cin >> A >> B;
  string C = A + '@'+ B;
  int lenA = A.size(), lenC = C.size();
  SA sa(C);
  //sa.debug();
  int best = 0;
  for (int i = 0; i < lenC; i++){
    if ( (sa.sa[i] < lenA) != (sa.sa[i + 1] < lenA) ){
      best = max(best, sa.lcp[i]);
    }
  }
  cout << best << endl;
}

