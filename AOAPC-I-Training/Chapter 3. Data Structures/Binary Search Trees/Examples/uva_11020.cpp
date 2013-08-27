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
 */


void solve(){
  int n; cin >> n;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  //sort(a.begin(), a.end());
  multimap<int, int> M;
  M.insert(make_pair(-1, 1024 * 1024 * 1024));
  M.insert(make_pair(1024*1024*1024, -1));
  for (int i = 0; i < n; i++){
    multimap<int, int>::iterator it = M.lower_bound(a[i].first);
    multimap<int, int>::iterator et = M.lower_bound(a[i].first);
    if (pair<int, int>(*it) == a[i]){
      //cout << "[" << i << "]" << endl;
      M.insert(a[i]);
    }else{
      if ((--it)->second > a[i].second){
        it++;
        while (it->second >= a[i].second){
          it++;
        }
        M.erase(et, it);
        M.insert(a[i]);
      }
    }
    cout << M.size() - 2 << endl;
  }
}
int TestNum;
int main(){
  int N; cin >> N;
  while (N--){
    if (TestNum) printf("\n");
    printf("Case #%d:\n", ++TestNum);
    solve();
  }
}

