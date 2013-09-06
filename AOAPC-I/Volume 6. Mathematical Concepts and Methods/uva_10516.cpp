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
const int BASE = 10000;
const int WIDTH = 4;
string strFromInt(int n, int w){
  char buf[32];
  sprintf(buf, "%0*d", w, n);
  return buf;
}
vector<int> bignFromStr(string s){
  vector<int> a;
  reverse(s.begin(), s.end());
  for (size_t i = 0; i < s.size(); i += WIDTH){
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
  for (size_t i = 1; i < a.size(); i++){
    s += strFromInt(a[i], WIDTH);
  }
  return s;
}
vector<int> bignAdd(vector<int> a, vector<int> b){
  vector<int> c(max(a.size(), b.size()));
  int carry = 0;
  for (size_t i = 0; i < max(a.size(), b.size()); i++) {
    int da = i < a.size()? a[i] : 0;
    int db = i < b.size()? b[i] : 0;
    int dc = da + db + carry;
    c[i] = dc % BASE;
    carry = dc / BASE;
  }
  if (carry) c.push_back(carry);
  return c;
}
vector<int> bignSub(vector<int> a, vector<int> b){
  vector<int> c(a);
  int borrow = 0;
  for (size_t i = 0; i < c.size(); i++) {
    int db = i < b.size() ? b[i] : 0;
    c[i] -= db + borrow;
    if (c[i] < 0) c[i] += BASE, borrow = 1;
    else borrow = 0;
  }
  while (c.size() && c.back() == 0) c.pop_back();
  assert(borrow == 0);
  return c;
}

vector<int> bignTimes(vector<int> a, size_t off, int n){
  vector<int> b(off);
  int carry = 0;
  for (size_t i = 0; i < a.size(); i++){
    int d = a[i] * n + carry;
    b.push_back(d % BASE);
    carry = d / BASE;
  }
  if (carry) b.push_back(carry);
  return b;
}
vector<int> bignMul(vector<int> a, vector<int> b){
  vector<int> c;
  for (size_t i = 0; i < a.size(); i++){
    c = bignAdd(c, bignTimes(b, i, a[i]));
  }
  return c;
}
vector<int> bigPow(vector<int> a, int p){
  vector<int> res = bignFromStr("1");
  while (p){
    if (p % 2) res = bignMul(res, a);
    a = bignMul(a, a);
    p /= 2;
  }
  return res;
}
vector<int> cache[33][17];
bool visited[33][17];

vector<int> f(int n, int d){
  vector<int> &res = cache[n][d];
  if (visited[n][d]) return res;
  visited[n][d] = true;
  if (d == 0) res = bignFromStr("1");
  else res = bignAdd(bigPow(f(n, d - 1), n), bignFromStr("1"));
  return res;
}

vector<int> c(int n, int d){
  if (d == 0) return bignFromStr("1");
  return bignSub(f(n, d), f(n, d - 1));
}

int TestNum;
int main(){
  int n, d;
  while (cin >> n >> d && n) {
    cout << n << " " << d << " " <<  strFromBign(c(n, d)) << endl; 
  }
}

