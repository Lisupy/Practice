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
const int INF = 0x1f1f1f1f;
struct SA{
  const string &s;
  int n;
  vector<int> sa;
  vector<int> rnk;
  vector<int> lcp;
  struct Less{
    vector<int>& rnk;
    int off;
    int n;
    bool operator()(int i, int j){
      if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
      int ri = i + off <= n ? rnk[i + off] : -1;
      int rj = j + off <= n ? rnk[j + off] : -1;
      return ri < rj;
    }
    Less(vector<int> &_r, int _off, int _n):rnk(_r), off(_off), n(_n){}
  };
  SA(const string &_s): s(_s), n((int)s.size()), sa(n + 1), rnk(n + 1), lcp(n + 1){
    construct_sa();
    construct_rnk();
    construct_lcp();
  }
  void construct_sa(){
    for (int i = 0; i <= n; i++){
      sa[i] = i;
      rnk[i] = i < n? s[i] : -1;
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
    lcp[0] = 0;
    int h = 0;
    for (int i = 0; i < n; i++){
      int j = sa[rnk[i] - 1];
      if (h > 0) h--;
      while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
      lcp[rnk[i] - 1] = h;
    }
  }
  //void debug(){
    //cout << s << endl;
    //for (auto e : sa) cout << s.substr(e) << endl; ; cout << endl;
    //for (auto e : rnk) cout << e << ", "; cout << endl;
    //for (auto e : lcp) cout << e << ", "; cout << endl;
  //}
};
struct RMQ{
  vector<vector<int> > a;
  int log2(int n){
    return 31 - __builtin_clz(n);
  }
  RMQ(const vector<int> &_a): a(){
    int len = _a.size();
    int h = log2(len);
    a.resize(h + 1);
    a[0] = _a;
    for (int i = 1, off = 1; off * 2 <= len; off *= 2, i++){
      a[i].resize(len);
      for (int j = 0; j < len; j++){
        a[i][j] = min(a[i - 1][j], j + off < len ? a[i - 1][j + off]: INF);
      }
    }
  }
  int query(int from, int to){
    int len = to - from + 1;
    int h = log2(len);
    int off = 1 << h;
    return min(a[h][from], a[h][to + 1 - off]);
  }
};
int commonPrefix(SA &sa, RMQ &rmq, int p1, int p2){
  p1 = sa.rnk[p1];
  p2 = sa.rnk[p2];
  if (p1 > p2) swap(p1, p2);
  return rmq.query(p1, p2 - 1);
} 
string solve(const string &s){
  int len = s.size();
  string rs(s.rbegin(), s.rend());
  SA sa(s);
  RMQ rmq(sa.lcp);
  //sa.debug();
  SA sa2(rs);
  RMQ rmq2(sa2.lcp);
  //sa2.debug();
  RMQ trmq(sa.rnk);
  int bestRepCnt = 1;
  int bestRepLen = 1;
  int bestRepStart = sa.sa[1];
  //cout << rs << endl;
  for (int L = 1; L < len; L++){
    int prv = 0, cur = L;
    //printf("==[%d]==\n", L);
    while (cur < len){
      int l1 = commonPrefix(sa, rmq, cur, prv);
      int cur2 = len - cur - 1, prv2 = len - prv - 1;
      //cout << prv2 << ", " << cur << endl;
      int l2 = commonPrefix(sa2, rmq2, cur2, prv2);
      int repLen = l1 + l2 - 1;
      int repCnt = repLen/L + 1;
      int s1 = prv - l2 + 1;  
      int s2 = s1 + repLen + L;
      repLen = repCnt * L;
      s2 -= repLen;
      int repStart = sa.sa[trmq.query(s1, s2)]; 
      //printf("%d, %d: %d %d, %d %d, %d %d %d\n", prv, cur, prv2, cur2, l1, l2, repStart, repLen, repCnt);
      if (bestRepCnt < repCnt || (bestRepCnt == repCnt && sa.rnk[bestRepStart] > sa.rnk[repStart]) ){
        bestRepStart = repStart, bestRepCnt = repCnt, bestRepLen = repLen;
        //cout << "Update: "  << s.substr(repStart, repLen) << endl;
      }
      prv += L, cur += L; 
    }
  }
  //cout << bestRepStart << endl;
  //cout << bestRepLen << endl;
  //cout << bestRepCnt << endl;

  return s.substr(bestRepStart, bestRepLen);
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  string s;
  while (cin >> s && s != "#") {
    cout << "Case " << ++TestNum << ": " << solve(s) << endl; 
  }
}

