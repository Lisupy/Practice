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
const int MAXN = 1024 * 1024;
int t1[MAXN];
int t2[MAXN];
struct SA{
  const string& s;
  int n;
  vector<int> sa;
  vector<int> rnk;
  vector<int> lcp;
  struct Less{
    const vector<int> &rnk;
    int n;
    int off;
    bool operator()(int i, int j){
      if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
      int ri = i + off <= n ? rnk[i + off] : -1;
      int rj = j + off <= n ? rnk[j + off] : -1;
      return ri < rj;
    }
    Less(vector<int> &_r, int _n, int _off):rnk(_r), n(_n), off(_off){};
  };
  void construct_sa(){
    for (int i = 0; i <= n; i++){
      sa[i] = i;
      rnk[i] = i < n? s[i] : 0;
    }
    for (int off = 1; off <= n; off *= 2){
      Less _less(rnk, n, off);
      sort(sa.begin(), sa.end(), _less);
      vector<int> tmp(n + 1);
      tmp[sa[0]] = 0;
      for (int i = 1; i <= n; i++){
        tmp[sa[i]] = tmp[sa[i - 1]] + _less(sa[i - 1], sa[i]);
      }
      swap(rnk, tmp);
    }
  }
  void construct_sa_radix_sort(){
    int *x = t1;
    int *y = t2;
    vector<int> c(max(n + 1, 128));
    int m = 128;
    for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
    c[x[n] = 0]++;
    partial_sum(c.begin(), c.begin() + m, c.begin());
    for (int i = n; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int off = 1; off <= n; off <<= 1){
      int p = 0;
      for (int i = n - off + 1; i <= n; i++) y[p++] = i;
      for (int i = 0; i <= n; i++) if (sa[i] >= off) y[p++] = sa[i] - off;

      for (int i = 0; i < m; i++) c[i] = 0;
      for (int i = 0; i <= n; i++) c[x[y[i]]]++;
      partial_sum(c.begin(), c.end(), c.begin());
      for (int i = n; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];

      swap(x, y);
      p = 1; x[sa[0]] = 0;
      for (int i = 1; i <= n; i++){
        x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + off] == y[sa[i] + off] ? p - 1: p++;
      }
      if (p >= n + 1) break;
      m = p;
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
  SA(const string &_s):s(_s), n((int)s.size()), sa(MAXN), rnk(MAXN), lcp(MAXN){
    construct_sa();
    construct_rnk();
    construct_lcp();
  }
  //void debug(){
    //cout << s << endl;
    //for (auto e : sa) cout << s.substr(e) << endl;
    //for (auto e : rnk) cout << e << ", "; cout  << endl;
    //for (auto e : lcp) cout << e << ", "; cout  << endl;
  //}
};
struct FakeRmq{
  vector<int> a;
  int n;
  FakeRmq(const vector<int> &_a, int _n): a(_a), n(_n){
    for (size_t i = n + 1; i < a.size(); i++){ 
      a[i] = min(a[i - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; i--){
      a[i] = min(a[i + 1], a[i]);
    }
  }
  int query(int from, int to){
    if (from == n) return a[to];
    if (to == n - 1) return a[from];
    assert(0);
    return -1;
  }
  //void debug(){
    //for (auto e: a) cout << e << " "; cout << endl;
  //}
};
int solve(string s){
  int len = s.size();
  SA sa(s);
  //sa.debug();
  FakeRmq rmq(sa.lcp, sa.rnk[0]);
  //rmq.debug();
  for (int i = 1; i <= len; i++){
    if (len % i == 0){
      int from = sa.rnk[0];
      int to = sa.rnk[i];
      if (from > to) swap(from, to);
      int tlen = rmq.query(from, to - 1);
      //printf("%d: %d, %d => %d\n", i, from, to, tlen); 
      if (tlen >= len - i){
        return len / i;
      }
    }
  }
  return 1;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  string s;
  while (cin >> s && s != ".") {
    cout << solve(s) << endl;
  }
}

