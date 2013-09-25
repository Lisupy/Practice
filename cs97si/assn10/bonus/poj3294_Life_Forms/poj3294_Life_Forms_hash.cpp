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
const u64 MAGIC = 1000 * 1000 * 1000 + 7;

struct StringHash{
  vector<u64> hs;
  vector<u64> bs;
  void init(const string &s){
    hs.resize(s.size() + 1);
    bs.resize(s.size() + 1);
    bs[0] = 1;
    for (size_t i = 1; i <= s.size(); i++) {
      hs[i] = hs[i - 1] * MAGIC + s[i - 1];
      bs[i] = bs[i - 1] * MAGIC; 
    }
  }
  StringHash(): hs(), bs(){}
  StringHash(const string &s): hs(), bs(){
    init(s);
  }
  u64 get(int l, int r){
    return hs[r] - hs[l] * bs[r - l];
  }
  vector<pair<u64, int> > getAll(int L){
    vector<pair<u64, int> > a;
    for (size_t i = 0; i + L < hs.size(); i++){
      a.push_back(make_pair(get(i, i + L), i));
    }
    return a;
  }
};
bool getCommonSubstr(vector<string>& ss , vector<StringHash> &hss, int n, int L, bool allAns, vector<string> &ans){
  //cout << "===[" << L << "]===" << endl;
  vector<vector<pair<u64, int> > > as(n);
  for (int i = 0; i < n; i++) as[i] = hss[i].getAll(L);
  for (int i = 0; i < n; i++) {
    sort(as[i].begin(), as[i].end());
    //as[i].erase(unique(as[i].begin(), as[i].end()), as[i].end());
  } 
  vector<u64> all;
  for (int i = 0; i < n; i++){
    for (size_t j = 0; j < as[i].size(); j++){
      all.push_back(as[i][j].first);
    }
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  vector<int> cnt(all.size());
  for (int i = 0; i < n; i++){
    for (size_t j = 0; j < as[i].size(); j++){
      if (j == 0 || as[i][j].first != as[i][j - 1].first){
        //cout << as[i][j].first << ", ";
        int pos  = lower_bound(all.begin(), all.end(), as[i][j].first) - all.begin();
        if (++cnt[pos] * 2 >  n ){
          if (allAns)ans.push_back(ss[i].substr(as[i][j].second, L));
          else return true;
          cnt[pos] = 0;
        }
      }
    }
    //cout << endl;
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
    vector<StringHash> hss(n);
    for (int i = 0; i < n; i++) hss[i].init(ss[i]);
    int lo = 0, hi = ss[0].size() + 1;
    vector<string> ans;
    while (hi - lo > 1){
      int mid = (lo + hi) / 2;
      if (getCommonSubstr(ss, hss, n, mid, false, ans)) lo = mid;
      else hi = mid;
    }
    if (lo == 0) cout << "?" << endl;
    else{
      getCommonSubstr(ss, hss, n, lo, true, ans);
      sort(ans.begin(), ans.end());
      for (size_t i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
      }
    }
  }
}

