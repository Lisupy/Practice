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

long long getsum1(long long prefix, long long d){ 
  long long n = pow(10, d);
  return prefix * n + n * d / 10;
}
long long getsum2(long long n){
  if (n < 10){
    return 1;
  }
  //printf("getsum2(%lld)\n", n);
  long long d = 1;
  long long tn = 1;
  long long total = 1;
  while (tn * 10 <= n) tn *= 10, d++;
  //cout << d << ", " << tn << endl;
  for (int i = 2; i < d; i++){
    total += getsum1(0, i - 1) * 9;
  }
  total += getsum1(0, d - 1) * (n / tn - 1);
  n %= (long long)pow(10, d -1);
  d--;
  while (d > 1){
    int k = n / pow(10, d - 1);
    if (k == 0){
      total += n % tn + 1;
    }else{
      total += pow(10, d - 1);
      total += k * getsum1(0, d - 1);
    }
    n %= (long long)(pow(10, d - 1)), d--;
  }
  total++;
  return total;
}
int TestNum;
int main(){
  long long m, n;
  while (cin >> m >> n && m != -1){
    long long sm = m == 0 ? 0: getsum2(m - 1);
    long long sn = getsum2(n);
    //cout << sm << endl;
    //cout << sn << endl;
    cout << sn - sm << endl;
  }
}

