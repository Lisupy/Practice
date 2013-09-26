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
  vector<int> &a;
  string &s;
  int n;
  vector<int> sa;
  vector<int> rnk;
  vector<int> lcp;
  //void display(){
    //cout << s << endl;
    //for (auto e : sa) cout << s.substr(e) << endl;
    //for (auto e : rnk) cout << e << ", " ; cout << endl;
    //for (auto e : lcp) cout << e << ", " ; cout << endl;
  //}
  SA(vector<int> &_a, string &_s):a(_a), s(_s), n(a.size()), sa(n + 1), rnk(n + 1), lcp(n + 1){
    construct_sa();
    construct_rnk();
    construct_lcp();
    // display();
  }
  struct Less{
    vector<int> &rnk;
    int n;
    int off;
    Less(vector<int>& _r, int _n, int _off):rnk(_r), n(_n), off(_off){}
    bool operator()(int i, int j){
      if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
      int ri = i + off <= n? rnk[i + off] : -1;
      int rj = j + off <= n? rnk[j + off] : -1;
      return ri < rj;
    }
  };
  void construct_sa(){
    for (int i = 0; i <= n; i++){
      rnk[i] = i < n? a[i] : -1;
      sa[i] = i;
    }
    for (int off = 1; off <= n; off *= 2){
      Less _less(rnk, n, off);
      sort(sa.begin(), sa.end(), _less);
      vector<int> trnk(n + 1);
      for (int i = 1; i <= n; i++) trnk[sa[i]] = trnk[sa[i - 1]] + _less(sa[i -1], sa[i]);
      swap(trnk, rnk);
    }
  }
  void construct_rnk(){
    for (int i = 0; i<= n; i++) rnk[sa[i]] = i;
  }
  void construct_lcp(){
    for (int i = 0, h = 0; i < n; i++){
      if (h > 0) h--;
      int j = sa[rnk[i] - 1];
      while (i + h < n && j + h < n && a[i + h] == a[j + h]) h++;
      lcp[rnk[i] - 1] = h;
    }
  }
};


bool isValid(int N, SA &sa, vector<int> &ps,  int L){
  //cout << "==[" << L << "]==" << endl;
  for (int l = 1, r = 1; l < (int)sa.lcp.size(); l = ++r){
    while (r < (int)sa.lcp.size() && sa.lcp[r] >= L) r++; 
    
    vector<bool> has(N);
    //cout << "# " << l << " , " << r << endl;
    for (int i = l; i <= r; i++){
      if (sa.sa[i] >= (int)ps.size()) continue;
      int p = ps[sa.sa[i]];
      //cout << i << ": " << p << endl;
      //cout << sa.s.substr(sa.sa[i]) << endl;
      if (p != -1) has[p] = true;
    }
    if (count(has.begin(), has.end(), true) == N) return true;
  }
  return false;
}
void solve(){
  int N; cin >> N;
  vector<string> strs(N);
  for (int i = 0; i < N; i++) cin >> strs[i];
  string S;
  vector<int> a;
  vector<int> ps;
  for (int i = 0; i < N; i++){
    string s = strs[i];

    for (size_t j = 0; j < s.size(); j++){
      a.push_back(s[j]);
      S += s[j];
      ps.push_back(i);
    }

    a.push_back(i + 127);
    S += "@";
    ps.push_back(-1);

    reverse(s.begin(), s.end());
    for (size_t j = 0; j < s.size(); j++){
      a.push_back(s[j]);
      S += s[j];
      ps.push_back(i);
    }

    a.push_back(i + 258);
    S += "#";
    ps.push_back(-1);
  }

  SA sa(a, S);
  int lo = 0, hi = strs[0].size() + 1;
  while (hi - lo > 1) {
    int mid = (lo + hi) / 2; 
    if (isValid(N, sa, ps, mid)) lo = mid;
    else hi = mid;
  }
  cout << lo << endl; 
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  cin >> TestNum;
  while (TestNum--) {
    solve(); 
  }
}

