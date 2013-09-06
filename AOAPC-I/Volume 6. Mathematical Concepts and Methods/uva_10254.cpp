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
const int MAXN = 10 * 1024;
const int BASE = 10 * 1000;
const int WIDTH = 4;
string strFromInt(int n, int w = 0){
  char buf[32];
  sprintf(buf, "%0*d", w, n);
  return buf;
}
string strFromBign(vector<int> a){
  if (a.size() == 0) return "0";
  reverse(a.begin(), a.end());
  string s;
  s += strFromInt(a[0]);
  for (size_t i = 1; i < a.size(); i++) {
    s += strFromInt(a[i], WIDTH); 
  }
  return s;
}
vector<int> bignFromStr(string s){
  vector<int> a;
  reverse(s.begin(), s.end());
  for (size_t i = 0; i < s.size(); i += WIDTH) {
    string t = s.substr(i, WIDTH); reverse(t.begin(), t.end());
    a.push_back(atoi(t.c_str()));
  }
  return a;
}
vector<int> bignAdd(vector<int> a, vector<int> b){
  vector<int> c(max(a.size(), b.size()));
  int carry = 0;
  for (size_t i = 0; i < max(a.size(), b.size()); i++) {
    int da = i < a.size() ? a[i] : 0;
    int db = i < b.size() ? b[i] : 0;
    int dc = da + db + carry;
    c[i] = dc % BASE;
    carry = dc / BASE;
  }
  if (carry) c.push_back(carry);
  return c;
}
vector<int> bignSub(vector<int> a, vector<int> b){
  vector<int> c(max(a.size(), b.size()));
  int borrow = 0;
  for (size_t i = 0; i < max(a.size(), b.size()); i++) {
    int da = i < a.size() ? a[i] : 0;
    int db = i < b.size() ? b[i] : 0;
    int dc = da - db - borrow;
    if (dc < 0) c[i] = dc + BASE, borrow = 1;
    else c[i] = dc, borrow = 0;
  }
  assert(borrow == 0);
  while (c.size() && c.back() == 0) c.pop_back();
  return c;
}
bool bignLess(vector<int> a, vector<int> b){
  if (a.size() != b.size()) return a.size() < b.size();
  for (int i = a.size() - 1; i >= 0; i--) {
    if (a[i] != b[i]) return a[i] < b[i]; 
  }
  return false;
}
bool bignCheckMin(vector<int> &a, vector<int> b){
  if (bignLess(b, a)) return a = b, true;
  return false;
}
vector<int> bign0 = bignFromStr("0");
vector<int> bign1 = bignFromStr("1");

vector<int> bign2Pow_cache[MAXN];
bool bign2Pow_visited[MAXN];
vector<int> bign2Pow(int n){
  vector<int> &res = bign2Pow_cache[n];
  if (bign2Pow_visited[n]) return res;
  bign2Pow_visited[n] = true;
  if (n == 0) res = bign1;
  else {
    vector<int> b = bign2Pow(n - 1); 
    res = bignAdd(b, b);
  }
  return res;
}

vector<int> f3_cache[MAXN];
bool f3_visited[MAXN];
vector<int> f3(int n){
  vector<int> &res = f3_cache[n];
  if (f3_visited[n]) return res;
  f3_visited[n] = true;
  return res = bignSub(bign2Pow(n), bign1) ;
}
vector<int> f4_cache[MAXN]; 
bool f4_visited[MAXN];
int f4_best[MAXN];
vector<int> f4(int n){
  vector<int> &res = f4_cache[n];
  if (f4_visited[n]) return res;
  f4_visited[n] = true;
  res = f3(n);
  if (n == 0) res = bign0;
  else if (n == 1) res = bign1;
  else {
    f4(n - 1); 
    for (int i = max(1, f4_best[n - 1]); i < n; i++) {
      if (!bignCheckMin(res, bignAdd(bignAdd(f4(i), f4(i)) , f3(n - i)))) {
        f4_best[n] = i - 1;
        break;
      }
    }
  }
  return res;
}

int TestNum;
int main(){
  int n;
  while (cin >> n) {
    //time_t start = time(NULL);
    cout << strFromBign( f4(n)  ) << endl;
    //cout << f4_best[n] << endl;
    //time_t end = time(NULL);
    //cout << end - start << "s" << endl;
  }
}

