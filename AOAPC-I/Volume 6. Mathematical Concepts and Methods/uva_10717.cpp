//Clibrary:
#include<cassert>
#include<cctype>
#include<cerrno>
//#include<cfenv>
#include<cfloat>
//#include<clong longtypes>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
//#include<cstdbool>
#include<cstddef>
//#include<cstdlong long>
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


long long gcd(long long a, long long b){
  return b == 0? a : gcd(b, a % b);
}
long long lcm(long long a, long long b){
  return a / gcd(a, b) * b;
}
int main(){
  long long n, t;
  while (cin >> n >> t && n){
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    vector<int> lcms;
    for (int i = 0; i < n; i++){
      for (int j = i + 1; j < n; j++){
        for (int k = j + 1; k < n; k++){
          for (int l = k + 1; l < n; l++){
            lcms.push_back(lcm(lcm(coins[i], coins[j]), lcm(coins[k], coins[l])));
          }
        }
      }
    }
    sort(lcms.begin(), lcms.end());
    lcms.erase(unique(lcms.begin(), lcms.end()), lcms.end());
    for (long long i = 1; i <= t; i++){
      double bound; cin >> bound;
      int best_low = 0, best_high = 0xfffffff; 
      for (size_t j = 0; j < lcms.size(); j++){
        int lc = lcms[j];
        best_low = max(best_low, (int)floor(bound / lc) * lc);
        best_high = min(best_high, (int)ceil(bound / lc) * lc);
      }
      cout << best_low << " " << best_high << endl;
    }
  }
}
