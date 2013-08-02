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
 * sizeof CLOCKS_PER_SEC
 */

typedef long long i64;
i64 d[64];
i64 sd[64];
void d_init(){
  d[0] = 0, d[1] = 2, d[2] = 1, d[3] = 2;
  for (int i = 4; i < 64; i++) {
    d[i] = d[i - 1] + d[i - 2]; 
    //cout << d[i] << " ";
  }
  //cout << endl;
  partial_sum(d, d + 64, sd);
  //for (int i = 0; i < 64; i++) cout  << sd[i] << " ";
}
i64 solve(int n){
  i64 total = 0;
  while (n > 2){
    size_t pos = upper_bound(sd, sd + 64, n) - sd - 1;
    //cout << pos << endl;
    total += 1ll << pos;
    n -= sd[pos];
  }
  total += n;
  //cout << total << endl;
  return total;
}



string strFromI64(i64 n){
  string s;
  for (int i = 0; i < 64 && n; i++){
    if (n & (1ll << i)){
      s += "1";
      n ^= 1ll << i;
    }else{
      s += "0";
    }
  }
  reverse(s.begin(), s.end());
  if (s == "") s = "0";
  return s;
}
int TestNum;
int main(){
  d_init();
  int T; cin >> T;
  while (T--) {
    int K; cin >> K;
    cout << strFromI64(solve(K)) << endl;
  }
}

