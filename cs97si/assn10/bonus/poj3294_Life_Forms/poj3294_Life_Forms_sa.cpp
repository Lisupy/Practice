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
  const vector<int> &a;
  string &s;
  int n;
  vector<int> sa;
  vector<int> rnk;
  vector<int> lcp;
  //void debug(){
    //cout << s << endl;
    //for (auto e: sa) cout << s.substr(e) << endl;
    //for (auto e: rnk) cout << e << ", "; cout << endl;
    //for (auto e: lcp) cout << e << ", "; cout << endl;
  //}
  SA(const vector<int> &_a, string &_s): a(_a), s(_s), n(a.size()), sa(n + 1), rnk(n + 1), lcp(n + 1){
    //construct_sa();
    construct_sa_radix_sort();
    construct_rnk();
    construct_lcp();
  }
  struct Less{
    vector<int> &rnk;
    int n;
    int off;
    Less(vector<int> &_r, int _n, int _off):rnk(_r), n(_n), off(_off){}
    bool operator()(int i, int j){
      if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
      int ri = i + off <= n ? rnk[i + off] : -1;
      int rj = j + off <= n ? rnk[j + off] : -1;
      return ri < rj;
    }
  };
  bool sa_less(int off, int i, int j){
    if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
    int ri = i + off <= n ? rnk[i + off] : -1;
    int rj = j + off <= n ? rnk[j + off] : -1;
    return ri < rj;
  }
  void construct_sa_radix_sort(){
    vector<int> c(max(n + 1, 256));
    rnk.resize(max(n + 1, 256));
    for (int i = 0; i < n; i++) c[rnk[i] = a[i]]++;
    c[rnk[n] = 0]++;
    partial_sum(c.begin(), c.end(), c.begin());
    for (int i = n; i >= 0; i--) sa[--c[rnk[i]]] = i;
    //for (int i = 0; i <= n; i++) rnk[sa[i]] = i;
    for (int off = 1; off <= n; off *= 2){
      //debug();
      int p = 0;
      vector<int> sa2(max(n + 1, 256));
      for (int i = n + 1 - off; i <= n; i++) sa2[p++] = i;
      for (int i = 0; i <= n; i++) if (sa[i] >= off) sa2[p++] = sa[i] - off;

      fill(c.begin(), c.end(), 0);
      for (int i = 0; i <= n; i++) c[rnk[sa2[i]]]++;
      partial_sum(c.begin(), c.end(), c.begin());
      for (int i = n; i >= 0; i--) sa[--c[rnk[sa2[i]]]] = sa2[i];

      swap(sa2, rnk);
      vector<int> &rnk2 = sa2;
      p = 0, rnk[sa[0]] = 0;
      for (int i = 1; i <= n; i++){
        rnk[sa[i]] = rnk2[sa[i - 1]] == rnk2[sa[i]] && rnk2[sa[i - 1] + off] == rnk2[sa[i] + off] ? p: ++p; 
      }
      //cout << "SA" << endl;
      //for (auto e : sa) cout << e << ", "; cout << endl;
      //cout << "RNK2" << endl;
      //for (auto e : rnk2) cout << e << ", " ; cout << endl; 
      //cout << "RNK" << endl;
      //for (auto e : rnk) cout << e << ", " ; cout << endl; 
      //if (p >= n) break;
    }
  }
  void construct_sa(){
    for (int i = 0; i <= n; i++){
      rnk[i] = a[i];
      sa[i] = i;
    }
    for (int off = 1; off <= n; off *= 2){
      Less _less(rnk, n, off);
      //sort(sa.begin(), sa.end(), this->::*sa_less);
      //auto _less = bind(&SA::sa_less, this, _2, _3);
      sort(sa.begin(), sa.end(), _less);
      vector<int> tmp(n + 1);
      for (int i = 1; i < n; i++) tmp[sa[i]] = tmp[sa[i - 1]] + _less(sa[i - 1], sa[i]);
      swap(tmp, rnk);
    }
  }
  void construct_rnk(){
    rnk.resize(n + 1);
    for (int i = 0; i <= n; i++) rnk[sa[i]] = i;
  }
  void construct_lcp(){
    int h = 0;
    for (int i = 0; i < n; i++){
      if (h > 0) h--;
      int j = sa[rnk[i] - 1];
      while (i + h < n && j + h < n && a[i + h] == a[j + h]) h++;
      lcp[rnk[i] - 1] = h;
    }
  }
};
bool isValid(int n, string &s, vector<int> &which, SA& sa, int L, bool getAns, vector<string> &ans){
  ans.clear();
  //cout << "===[" << L << "]==" << endl;
  for (size_t l = 0, r = 0; l < sa.lcp.size(); l = ++r){
    while (r < sa.lcp.size() && sa.lcp[r] >= L) {
      r++;
    }
    if ((r - l + 1) * 2 <= (size_t)n) continue;
    vector<bool> visited(n);
    for (size_t i = l; i <= r; i++){
      visited[which[sa.sa[i]]] = true;
    }
    if (count(visited.begin(), visited.end(), true) * 2 > n){
      if (!getAns) return true;
      ans.push_back(s.substr(sa.sa[l], L));
    }
  }
  return false;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int n;
  while (cin >> n && n) {
    if (TestNum++) cout << endl;
    vector<string> ss(n);
    for (int i = 0; i < n; i++) cin >> ss[i];
    vector<int> a;
    vector<int> which;
    string S;
    for (int i = 0; i < n; i++) {
      for (size_t j = 0; j < ss[i].size(); j++){
        a.push_back(ss[i][j]); 
        which.push_back(i);
        S.push_back(ss[i][j]);
      }
      a.push_back(i + 127);
      which.push_back(-1);
      S.push_back('@');
    }
    SA sa(a, S);
    //sa.debug();
    vector<string> ans;
    int lo = 0, hi = ss[0].size() + 1;
    while (hi - lo > 1){
      int mid = (lo + hi) / 2;
      if (isValid(n, S, which, sa, mid, false, ans)) lo = mid;
      else hi = mid;
    }
    if (lo == 0) cout << "?" << endl;
    else{
      isValid(n, S, which, sa, lo, true, ans);
      sort(ans.begin(), ans.end());
      for (size_t i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
      }
    }
  }
}

