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
const long long MAXN = 50000;

bool isValid(long long n, long long p, long long q){
  long long s = n * (n - 1) * p;
  if (s % q != 0) return false;
  s = s / q;
  long long t = sqrt(s);
  if (t * (t + 1) == s){
    cout << t + 1 << " " << n - t - 1 << endl;
    return true;
  }else{
    return false;
  }
}
void solve(long long p, long long q){

  if (p == 0){ cout << "0 2" << endl; return;}
  for (int n = 2; n <= MAXN; n++){
    if (isValid(n, p, q)){
      return ;
    }
  }
  cout << "impossible" << endl;
}

int main(){
  long long p, q;
  while (cin >> p >> q){
    if (p == 0 && q == 0) break;
    solve(p, q);
  }
}
