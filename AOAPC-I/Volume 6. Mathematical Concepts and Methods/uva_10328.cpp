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
  reverse(s.begin(), s.end());
  vector<int> a;
  for (size_t i = 0; i < s.size(); i += WIDTH) {
    string t = s.substr(i, WIDTH); reverse(t.begin(), t.end()); 
    a.push_back(atoi(t.c_str()));
  }
  return a;
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
  while (c.size() && c.back() == 0) c.pop_back();
  return c;
}
vector<int> bign0 = bignFromStr("0");
vector<int> bign1 = bignFromStr("1");

vector<int> bign2Pow(int n){
  vector<int> a = bign1;
  for (int i = 0; i < n; i++){
    a = bignAdd(a, a);
  }
  return a;
}
vector<int> f1(int n, int k);
vector<int> f2(int n, int k);
vector<int> f1_cache[128][128];
vector<int> f2_cache[128][128];
bool f1_visited[128][128];
bool f2_visited[128][128];
vector<int> f1(int n, int k){
  if (n < 0) return bign0;
  vector<int> &total = f1_cache[n][k];
  if (f1_visited[n][k]) return total;
  f1_visited[n][k] = true;
  if (n == 0) total = bign1;
  else for (int i = 1; i < k; i++) total = bignAdd(total, f2(n - i, k));
  return total;
}
vector<int> f2(int n, int k){
  if (n < 0) return bign0;
  vector<int> &total = f2_cache[n][k];
  if (f2_visited[n][k]) return total;
  f2_visited[n][k] = true;
  if (n == 0) total = bign1;
  else for (int i = 1; i <= n; i++) total = bignAdd(total, f1(n - i, k));
  return total;
}
vector<int> C(int n, int k){
  //cout << pow(2, n) << endl;
  //cout << f1(n, k) << endl;
  //cout << f2(n, k) << endl;
  return bignSub(bignSub(bign2Pow(n), f1(n, k)) , f2(n, k));
}
int TestNum;
int main(){
  int n, k;
  while (cin >> n >> k) {
    cout << strFromBign( C(n, k) ) << endl;
  }
}

