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

const int BASE = 10000;
string strFromInt(int n, int d){
  char buf[32];
  sprintf(buf, "%0*d", d, n);
  return buf;
}
vector<int> bignFromStr(string s){
  reverse(s.begin(), s.end());
  vector<int> a;
  for (size_t i = 0; i < s.size(); i += 4) {
    string t = s.substr(i, 4); reverse(t.begin(), t.end());
    a.push_back(atoi(t.c_str())); 
  }
  return a;
}
string strFromBign(vector<int> a){
  reverse(a.begin(), a.end());
  string s = strFromInt(a[0], 0);
  for (size_t i = 1; i < a.size(); i++) {
    s += strFromInt(a[i], 4); 
  }
  s.erase(0, s.find_first_not_of("0"));
  if (s.size() == 0) return "0";
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
vector<int> bignMinus(vector<int> a, vector<int> b){
  vector<int> c;
  int borrow = 0;
  for (size_t i = 0; i < a.size(); i++) {
    int da = a[i];
    int db = i < b.size() ? b[i] : 0;
    int dc = da - db - borrow;
    if (dc < 0){
      borrow = 1;
      dc += BASE;
    }else{
      borrow = 0;
    }
    c.push_back(dc);
  }
  return c;
}
vector<int> bignTimes(vector<int> a, size_t off, int n){
  vector<int> c(off);
  int carry = 0;
  for (size_t i = 0; i < a.size(); i++) {
    int dc = a[i] * n + carry;
    c.push_back(dc % BASE);
    carry = dc / BASE;
  }
  if (carry) c.push_back(carry);
  return c;
}
vector<int> bignMul(vector<int> a, vector<int> b){
  vector<int> c;
  for (size_t i = 0; i < b.size(); i++) {
    c = bignAdd(c, bignTimes(a, i, b[i]));
  }
  return c;
}

vector<int> cache[512][200];
bool visit[512][200];
vector<int> f(int n, int d){
  if (d < 0) return bignFromStr("0");
  if (n == 0) return bignFromStr("1");
  if (d == 0 && n > 0) return bignFromStr("0");
  vector<int> &total = cache[n][d];
  if (visit[n][d]) return total;
  visit[n][d] = true;
  for (int i = 0; i < n; i++){
    total = bignAdd(total, bignMul(f(i, d - 1), f(n - i - 1, d)));
  }
  return total;
}
int TestNum;
int main(){
  int n, d;
  //cout << strFromBign(bignMul(bignFromStr("3"), bignFromStr("3"))) << endl;
  while (cin >> n >> d) {
    cout << strFromBign(bignMinus(f(n / 2, d), f(n / 2, d - 1))) << endl;
  }
}

