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
const int MAXN = 20;
long long a[MAXN];
long long s[MAXN];
void init(){
  a[0] = 0;
  a[1] = 9;
  for (int i = 2; i < MAXN; i++){
    if (i % 2 == 0) a[i] = a[i - 1];
    else a[i] = a[i - 1] * 10;
    //cout << a[i] << endl;
  }
  partial_sum(a, a + MAXN, s);
}

string strFromInt(int n){
  char buf[32];
  sprintf(buf, "%d", n);
  return buf;
}

void solve(int n){
  int pos = lower_bound(s, s + MAXN, n) - s - 1;
  //int pos = upper_bound(s, s + MAXN, n) - s - 1;
  //cout << pos << endl;
  n -= s[pos];
  int len = pos + 1;
  int half_len = (len  + 1) / 2;
  n = pow(10,  half_len - 1) - 1 + n;
  //cout << n << endl;
  string s1 = strFromInt(n);
  string t(s1.rbegin(), s1.rend());
  if (len % 2 == 0){
    cout << s1 << t << endl;
  }else{
    cout << s1 << t.substr(1) << endl;
  }
}

int main(){
  init();
  int i;
  while (cin >> i && i){
    solve(i);
  }
}
