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
const int BASE = 10 * 1000;
const int WIDTH = 4;
string strFromInt(int n, int w){
  char buf[32];
  sprintf(buf, "%0*d", w, n);
  return buf;
}
vector<int> bignFromStr(string s){
  reverse(s.begin(), s.end());
  vector<int> a;
  for (size_t i = 0; i < s.size(); i += WIDTH) {
    string t = s.substr(i, WIDTH); reverse(t.begin(), t.end());
    a.push_back(atoi(t.c_str()));
  }
  return a;
}
string strFromBign(vector<int> a){
  if (a.size() == 0) return "0";
  string s;
  reverse(a.begin(), a.end());
  s += strFromInt(a[0], 0);
  for (size_t i = 1; i < a.size(); i++) {
    s += strFromInt(a[i], WIDTH);
  }
  return s;
}
vector<int> bignAdd(vector<int> a, vector<int> b){
  vector<int> c;
  int carry = 0;
  for (size_t i = 0; i < max(a.size(), b.size()); i++) {
    int da = i < a.size() ? a[i] : 0;
    int db = i < b.size() ? b[i] : 0;
    int dc = da + db + carry;
    c.push_back(dc % BASE);
    carry = dc / BASE;
  }
  if (carry) c.push_back(carry);
  return c;
}
vector<int> bignSub(vector<int> a, vector<int> b){
  vector<int> c;
  int borrow = 0;
  for (size_t i = 0; i < max(a.size(), b.size()); i++) {
    int da = i < a.size() ? a[i] : 0;
    int db = i < b.size() ? b[i] : 0;
    int dc = da - db - borrow;
    if (dc < 0) c.push_back(dc + BASE), borrow = 1;
    else c.push_back(dc), borrow = 0;
  }
  assert(borrow == 0);
  while(c.size() && c.back() == 0) c.pop_back();
  return c;
}
vector<int> bignTimes(vector<int> a, size_t off, int n){
  vector<int> b(off);
  int carry = 0;
  for (size_t i = 0; i < a.size(); i++) {
    int db = a[i] * n + carry;
    b.push_back(db % BASE);
    carry = db / BASE;
  }
  if (carry) b.push_back(carry);
  return b;
}
vector<int> bignMul(vector<int> a, vector<int> b){
  vector<int> c;
  for (size_t i = 0; i < a.size(); i++) {
    c = bignAdd(c, bignTimes(b, i, a[i]));
  }
  return c;
}
vector<int> bignHalf(vector<int> a){
  int r = 0;
  reverse(a.begin(), a.end());
  vector<int> b;
  for (size_t i = 0; i < a.size(); i++) {
    int db = (a[i] + r * BASE);
    b.push_back(db / 2);
    r = db % 2;
  }
  reverse(b.begin(), b.end());
  assert(r == 0);
  while(b.size() && b.back() == 0) b.pop_back();
  return b;
}
vector<int> bign0 = bignFromStr("0");
vector<int> bign1 = bignFromStr("1");
vector<int> bign2 = bignFromStr("2");
vector<int> C2(vector<int> n){
  return bignHalf(bignMul(n, bignSub(n, bign1))); 
}
vector<int> F(vector<int> n){
  if (n == bign0) return bign1; 
  return bignAdd(bignAdd(C2(n), C2(n)) , bign2);
}
vector<int> F2(vector<int> n){
  if (n == bign0) return bign1; 
  return bignAdd(bignMul(n, bignSub(n, bign1)) , bign2);
}
int TestNum;
int main(){
  string n;
  while (cin >> n) {
    cout << strFromBign(F2(bignFromStr(n))) << endl;;
  }
}

