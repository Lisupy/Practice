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
vector<u64> bs;
void bs_init(){
  bs.resize(128);
  bs[0] = 1;
  for (int i = 1; i < 128; i++) bs[i] = bs[i - 1] * MAGIC;
}
struct StringHash{
  vector<u64> hs;
  StringHash():hs(){}
  void init(string &s){
    hs.resize(s.size() + 1);
    for (size_t i = 1; i <= s.size(); i++)  hs[i] = hs[i - 1] * MAGIC + s[i - 1];
  }
  u64 get(int l, int r){
    return hs[r] - hs[l] * bs[r - l];
  }
};
bool isValid(vector<string> &strs, vector<StringHash>& strHashs, int L, int N){
  //cout << "==[" << L << "]==" << endl;
  vector<pair<u64, int> > a;
  for (int i = 0; i < N; i++){
    for (size_t p = 0; p + L <= strs[i].size(); p++){
      a.push_back(make_pair(strHashs[i].get(p, p + L), i));
      //cout << a.back().first << ", ";
    }
    //cout << endl;
  }
  sort(a.begin(), a.end());
  for (size_t l = 0, r = 0; l < a.size(); l = r){
    while (r < a.size() && a[l].first == a[r].first) r++;
    vector<bool> has(N);
    for (size_t i = l; i < r; i++){
      has[a[i].second] = true;
    }
    if (count(has.begin(), has.end(), true) == N) return true;
  }
  return false;
}
void solve(){
  int N; cin >> N;
  vector<string> strs(N);
  for (int i = 0; i < N; i++) cin >> strs[i];
  vector<StringHash> strHash(N);
  for (int i = 0; i < N; i++){
    string &s = strs[i];
    string t(s.rbegin(), s.rend());
    s += char(-i);
    s += t;
    //cout << s << endl;
    strHash[i].init(s);
  }
  int lo = 0, hi = strs[0].size() / 2 + 1;
  while (hi - lo > 1){
    int mid = (lo + hi) / 2;
    if (isValid(strs, strHash, mid, N)) lo = mid;
    else hi = mid;
  }
  cout << lo << endl;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  bs_init();
  cin >> TestNum;
  while (TestNum--) {
    solve(); 
  }
}

