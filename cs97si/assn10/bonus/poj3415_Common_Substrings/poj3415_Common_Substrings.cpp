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
    //for (auto e: sa)  cout << s.substr(e) << endl;
    //for (auto e: rnk) cout << e << ", " ; cout << endl;
    //for (auto e: lcp) cout << e << ", " ; cout << endl;
  //}
  SA(const string& _s): s(_s), n(int(s.size())), sa(n + 1), rnk(n + 1), lcp(n + 1){
    //construct_sa();
    construct_sa_radix_sort();
    construct_rnk();
    construct_lcp();
    //debug();
  }
  struct Less{
    vector<int> &rnk;
    int n;
    int off;
    Less(vector<int> &_r, int _n, int _off): rnk(_r), n(_n), off(_off){}
    bool operator()(int i, int j){
      if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
      int ri = i + off <= n? rnk[i + off] : -1;
      int rj = j + off <= n? rnk[j + off] : -1;
      return ri < rj;
    }
  };
  void construct_sa(){
    for (int i = 0; i <= n; i++) {
      sa[i] = i;
      rnk[i] = i < n ? s[i] : -1;
    }
    for (int off = 1; off <= n; off *= 2){
      Less _less(rnk, n, off);
      sort(sa.begin(), sa.end(), _less);
      vector<int> tmp(n + 1);
      tmp[sa[0]] = 0;
      for (int i = 1; i <= n; i++) {
        tmp[sa[i]] = tmp[sa[i - 1]] + _less(sa[i - 1], sa[i]); 
      }
      swap(tmp, rnk);
    }
  }
  void construct_sa_radix_sort(){
    vector<int> x(n + 1), y(n + 1);
    vector<int> c(max(n + 1, 128));
    for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
    c[x[n] = 0]++;
    partial_sum(c.begin(), c.end(), c.begin());
    for (int i = n; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int off = 1; off <= n; off *= 2){
      int p = 0;
      for (int i = n - off + 1; i <= n; i++) y[p++] = i;
      for (int i = 0; i <= n; i++) if (sa[i] >= off) y[p++] = sa[i] - off;
      fill(c.begin(), c.end(), 0);
      for (int i = 0; i <= n; i++) c[x[y[i]]]++;
      partial_sum(c.begin(), c.end(), c.begin());
      for (int i = n; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
      swap(x, y);
      p = 1; x[sa[0]] = 0;
      for (int i = 1; i <= n; i++){
        x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + off] == y[sa[i] + off] ? p - 1 : p++;
      }
      if (p >= n + 1) break;
    }
  }
  void construct_rnk(){
    for (int i = 0; i <= n; i++) rnk[sa[i]] = i;
  }
  void construct_lcp(){
    int h = 0;
    for (int i = 0; i < n; i++){
      int j = sa[rnk[i] - 1];
      if (h > 0) h--;
      while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
      lcp[rnk[i] - 1] = h;
    }
  }
};
int K;
struct MonoStack{
  stack<pair<i64, i64> > S; 
  i64 total;
  MonoStack(): S(), total(0){}
  void push(i64 n, i64 cnt){
    //cout << "push :" << n << ", " << cnt << endl;
    pair<i64, i64> p1 = make_pair(n, cnt);
    while (S.size()){
      if (S.top().first > n){
        pair<i64, i64> p2 = S.top(); S.pop();
        p1.second += p2.second;
        total -= p2.first * p2.second;
      }else{
        break;
      }
    }
    total += p1.first * p1.second;
    //cout << total << endl;
    S.push(p1);
  }
  i64 query(){
    return total;
  }
};

i64 __solve(SA& sa, int lenA, int /*lenB*/, int lenC, char which){
  i64 total = 0;
  MonoStack S;
  for (int i = 0; i <= lenC; i++){
    //cout << endl;
    if ((which == 'A') == (sa.sa[i] < lenA)){
      //cout << i << "A: " << endl;
      S.push(max(sa.lcp[i] - K + 1, 0), 1);
    }else{
      //cout << i << "B: " << endl;
      //cout << S.query() << endl;
      if (sa.sa[i] != lenA) total += S.query();
       //total += S.query();
      //cout << i << ": " << total << endl;
      S.push(max(sa.lcp[i] - K + 1, 0), 0); 
    }
  }
  //cout << endl;
  return total;
}
i64 solve(string A, string B){
  string C = A + "@" + B;
  int lenA = A.size(), lenB = B.size(), lenC = C.size();
  SA sa(C);
  //sa.debug();
  i64 total = 0; 
  total += __solve(sa, lenA, lenB, lenC, 'A');
  total += __solve(sa, lenA, lenB, lenC, 'B');
  return total; 
}

int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (cin >> K && K) {
    string A, B; cin >> A >> B;
    cout << solve(A, B) << endl;
  }
}

