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

const i64 BASE = 1000 * 1000 * 1000;
const int WIDTH = 9;
string strFromI64(i64 n, int w){
  char buf[32];
  sprintf(buf, "%0*lld", w, n);
  return buf;
}
vector<i64> bignFromI64(i64 n){
  return vector<i64>(1, n);
}
string strFromBign(vector<i64> a){
  if (a.size() == 0) return "0";
  reverse(a.begin(), a.end());
  string s;
  s += strFromI64(a[0], 0);
  for (size_t i = 1; i < a.size(); i++) {
    s += strFromI64(a[i], WIDTH);
  }
  return s;
}

vector<i64> bignAdd(vector<i64> a, vector<i64> b){
  vector<i64> c;
  i64 carry = 0;
  for (size_t i = 0; i < max(a.size(), b.size()); i++) {
    i64 da = i < a.size() ? a[i] : 0;
    i64 db = i < b.size() ? b[i] : 0;
    i64 dc = da + db + carry;
    c.push_back(dc % BASE);
    carry = dc / BASE;
  }
  if (carry) c.push_back(carry);
  return c;
}
vector<i64> bignTimes(vector<i64> a, i64 n){
  vector<i64> b;
  i64 carry = 0;
  for (size_t i = 0; i < a.size(); i++) {
    i64 db = a[i] * n + carry;
    b.push_back(db % BASE);
    carry = db / BASE;
  }
  if (carry) b.push_back(carry);
  return b;
}
i64 gcd(i64 A, i64 B){
  if (A % B == 0) return B;
  else return gcd(B, A % B);
}
vector<i64> bignC(i64 n, int k){
  vector<i64> a;
  for (int i = 0; i < k; i++) a.push_back(n - i); 
  for (int i = 1; i <= k; i++){
    i64 t = i;
    for (size_t j = 0; j < a.size() && t != 1; j++){
      i64 g = gcd(a[j], t);
      a[j] /= g;
      t /= g;
    }
    assert(t == 1);
  }
  vector<i64> b = bignFromI64(1);
  for (size_t j = 0; j < a.size(); j++){
    b = bignTimes(b, a[j]);
  }
  return b;
}
vector<i64> F(i64 N){
  vector<i64> C0 = bignC(N, 0);
  vector<i64> C1 = bignC(N, 1);
  vector<i64> C2 = bignC(N, 2);
    //cout << strFromBign(C0) << endl;
    //cout << strFromBign(C1) << endl;
    //cout << strFromBign(C2) << endl;
  return bignAdd(bignAdd(C0, C1), C2);
}
int TestNum;
int main(){
  int N;
  while (cin >> N && N >= 0) {
    cout << strFromBign(F(N)) << endl;
  }

}

