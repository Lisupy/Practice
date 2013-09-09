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
  reverse(a.begin(), a.end());
  string s = strFromInt(a[0], 0);
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
vector<int> bignDiv(vector<int> a, int n){
  vector<int> b(a);
  int r = 0;
  for (int i = b.size() - 1; i >= 0; i--) {
    b[i] = b[i] + r * BASE;
    r = b[i] % n;
    b[i] /= n;
  }
  assert(r == 0);
  while (b.size() && b.back() == 0) b.pop_back();
  return b;
}
vector<int> bign1 = bignFromStr("1");
vector<int> bign0 = bignFromStr("0");
vector<int> C_cache[2048][2048];
bool C_visited[2048][2048];
vector<int> C(int n, int k){
  vector<int> &res = C_cache[n][k];
  if (C_visited[n][k]) return res;
  C_visited[n][k] = true;
  if (k > n - k) k = n - k;
  if (k == 0) res = n >= 0? bign1 : bign0;
  else res = bignAdd(C(n - 1, k) , C(n - 1, k - 1));
  return res; 
}
vector<int> Catalan_cache[2048];
bool Catalan_visited[2048];
vector<int> Catalan(int n){
  vector<int> &res = Catalan_cache[n];
  if (Catalan_visited[n]) return res;
  Catalan_visited[n] = true;
  res = bignDiv(C(2 * n, n), n + 1);
  return res;
}
vector<int> Catalan2(int n){
  vector<int> &res = Catalan_cache[n];
  if (Catalan_visited[n]) return res;
  Catalan_visited[n] = true;
  if (n == 0) res = bign1;
  else res = bignDiv(bignMul(Catalan2(n - 1), vector<int>(1, 4*n-2) ), n + 1);
  return res;
}

int TestNum;
int main(){
  int i;
  while (cin >> i) {
    //cout << strFromBign(Catalan(i)) << endl;
    cout << strFromBign(Catalan2(i)) << endl;
  }
}

