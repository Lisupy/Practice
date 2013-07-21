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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof
 */

int t;
int n, p, q;
vector<int> ps;
vector<int> qs;
vector<int> ranks;
int lcs(vector<int> a, vector<int> b){
  vector<vector<int> > dp(a.size() + 1);
  for (size_t i = 0; i < dp.size(); i++){
    dp[i].resize(b.size() + 1);
  }
  for (size_t i = 1; i < dp.size(); i++){
    for (size_t j = 1; j < dp[i].size(); j++){
      if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp.back().back();
}

bool less_by_rank(const int a, const int b){
  return ranks[a] < ranks[b];
}

int lis(vector<int> a){
  vector<int> tmp;
  for (size_t i = 0; i < a.size(); i++) {
    vector<int>::iterator it = lower_bound(tmp.begin(), tmp.end(), a[i]);
    if (it == tmp.end()){
      tmp.push_back(a[i]);
    }else{
      *it = a[i];
    }
  }
  return tmp.size();
}
int main(){
  cin >> t;
  for (int ti = 1; ti <= t; ti++){
    cin >> n >> p >> q;
    ps.resize(p + 1);
    qs.resize(q + 1);
    ranks.clear();
    ranks.resize(n * n + 1, n * n);
    for (int i = 0; i <= p; i++) cin >> ps[i];
    for (int i = 0; i <= q; i++) cin >> qs[i];
    for (int i = 0; i <= q; i++) ranks[qs[i]] = i;
    vector<int> cs;
    for (int i = 0; i <= p; i++) if (ranks[ps[i]] != n * n) cs.push_back(ranks[ps[i]]);
    int ans = lis(cs);
    printf("Case %d: %d\n", ti, ans);
  }
}
