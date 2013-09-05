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
using namespace std::rel_ops;

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
struct Bign{
  vector<int> data;
  Bign():data(){};
  void set(string s){
    data.clear();
    reverse(s.begin(), s.end());
    for (size_t i = 0; i < s.size(); i += WIDTH){
      string t = s.substr(i, 4); reverse(t.begin(), t.end());
      data.push_back(atoi(t.c_str()));
    }
  }
  Bign(string s):data(){
    set(s);
  }
  Bign& operator=(const Bign &b){
    data = b.data;
    return *this;
  }
  Bign(const Bign &b): data(b.data){}
  string to_s() const {
    int len = data.size();
    if (len == 0) return "0";
    string s;
    s += strFromInt(data[len - 1], 0);
    for (int i = len - 2; i >= 0; i--){
      s += strFromInt(data[i], WIDTH);
    }
    return s;
  }
};
istream& operator>>(istream &is, Bign &a){
  string s; is >> s;
  a.set(s);
  return is;
}
Bign operator+(const Bign &lhs, const Bign &rhs){
  Bign res;
  const vector<int> &a = lhs.data;
  const vector<int> &b = rhs.data;
  vector<int> &c = res.data; 
  c.resize(max(a.size(), b.size()));
  int carry = 0;
  for (size_t i = 0; i < max(a.size(), b.size()) ; i++){
    int da = i < a.size() ? a[i] : 0;
    int db = i < b.size() ? b[i] : 0;
    int dc = da + db + carry;
    c[i] = dc % BASE;
    carry = dc / BASE;
  }
  if (carry) c.push_back(carry);
  return res;
}
Bign operator-(const Bign &lhs, const Bign &rhs){
  //cout << lhs.to_s() << "- " << rhs.to_s() << endl;
  Bign res;
  const vector<int> &a = lhs.data;
  const vector<int> &b = rhs.data;
  vector<int> &c = res.data; 
  int borrow = 0;
  for (size_t i = 0; i < max(a.size(), b.size()) ; i++){
    int da = i < a.size() ? a[i] : 0;
    int db = i < b.size() ? b[i] : 0;
    int dc = da - db - borrow;
    if (dc < 0) dc += BASE, borrow = 1;
    else borrow = 0;
    c.push_back(dc);
  }
  while (c.size() && c.back() == 0) c.pop_back();
  assert(borrow == 0);
  return res;
}
bool operator<(const Bign &lhs, const Bign &rhs){
  if (lhs.data.size() != rhs.data.size()) return lhs.data.size() < rhs.data.size();
  for (int i = lhs.data.size() - 1; i >= 0; i--) if (lhs.data[i] != rhs.data[i]) return lhs.data[i] < rhs.data[i];
  return false;
}
bool operator==(const Bign &lhs, const Bign &rhs){
  return lhs.data == rhs.data;
}
Bign pow2(int n){
  Bign a("1");
  for (int i = 0; i < n; i++){
    a = a + a;
  }
  return a;
}
void solve(int &a, int &b, int &c, int n, Bign m){
  if (n == 0) return;
  //int k = 1 << (n - 1);
  //printf("%d\n", k);
  Bign k = pow2(n - 1);
  //cout << n << ": " << m.to_s() << ", " << k.to_s() << ",," << (k > m) << endl;
  if (k > m){
    a++;
    solve(a, c, b, n - 1, m);
  }else{
    c++;
    solve(b, a, c, n - 1, m - k);
  }
}


int TestNum;
int main(){
  int n; Bign m;
  while (cin >> n >> m && n){
    //cout << n << ", " << m.to_s() << endl;
    int a = 0, b = 0, c = 0;
    solve(a, b, c, n, m);
    if (n % 2) swap(b, c);
    cout << a << " " << b << " " << c << endl;
  }
}

