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
const int BASE = 100;
const int WIDTH = 2;
//const int BASE = 1000 * 1000 * 100;
//const int WIDTH = 8;
//const int BASE = 1000 * 10;
//const int WIDTH = 4;
string strFromInt(int n, int w){
  char buf[32];
  sprintf(buf, "%0*d", w, n);
  return buf;
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
vector<int> bignFromStr(string s){
  reverse(s.begin(), s.end());
  vector<int> a;
  a.reserve(128);
  for (size_t i = 0; i < s.size(); i += WIDTH) {
    string t = s.substr(i, WIDTH); reverse(t.begin(), t.end()); 
    a.push_back(atoi(t.c_str()));
  }
  while(a.size() && a.back() == 0) a.pop_back();
  return a;
}
vector<int> bignFromInt(int n){
  assert(n < BASE);
  return vector<int>(1, n);
}
vector<int> bignAdd(const vector<int> &a, const vector<int> &b){
  vector<int> c;
  c.reserve(128);
  int carry = 0;
  for (size_t i = 0; i < max(a.size(), b.size()); i++) {
    int da = i < a.size() ? a[i] : 0;
    int db = i < b.size() ? b[i] : 0;
    int dc = da + db + carry;
    c.push_back(dc % BASE);
    carry = dc / BASE;
    //if (dc >= BASE) c.push_back(dc - BASE), carry = 1;
    //else c.push_back(dc), carry = 0;
  }
  if (carry) c.push_back(carry);
  return c;
}
vector<int> bignSub(const vector<int> &a, const vector<int> &b){
  vector<int> c;
  c.reserve(128);
  int borrow = 0;
  for (size_t i = 0; i < max(a.size(), b.size()); i++) {
    int da = i < a.size() ? a[i] : 0;
    int db = i < b.size() ? b[i] : 0;
    int dc = da - db - borrow;
    if (dc < 0) c.push_back(dc + BASE), borrow = 1;
    else c.push_back(dc), borrow = 0;
  }
  while (c.size() && c.back() == 0) c.pop_back();
  //if (carry) c.push_back(carry);
  return c;
}
vector<int> bignTimes(const vector<int> &a, i64 n, size_t off = 0){
  vector<int> b(off);
  b.reserve(100);
  int carry = 0;
  for (size_t i = 0; i < a.size(); i++) {
    i64 db = a[i] * n + carry;
    b.push_back(db % BASE);
    carry = db / BASE;
  }
  if (carry) b.push_back(carry);
  return b;
}
vector<int> bignMul(const vector<int> &a, const vector<int> &b){
  vector<int> c;
  c.reserve(100);
  for (size_t i = 0; i < a.size(); i++) {
    c = bignAdd(c, bignTimes(b, a[i], 0));
  }
  return c;
}
vector<int> bignHalf(vector<int> a){
  int r = 0;
  for (int i = a.size() - 1; i >= 0; i--) {
    a[i] += r * BASE;
    r = a[i] % 2;
    a[i] /= 2;
    assert(a[i] < BASE);
  }
  while(a.size() && a.back() == 0) a.pop_back();
  return a;
}
bool bignLess(const vector<int> &a, const vector<int> &b){
  if (a.size() != b.size()) return a.size() < b.size();
  for (int i = a.size() - 1; i >= 0; i--) {
    if (a[i] != b[i]) return a[i] < b[i]; 
  }
  return false;
}
double doubleFromStr(string s){
  double d;
  sscanf(s.c_str(), "%lf", &d);
  return d;
}
vector<int> bign0 = bignFromStr("0");
vector<int> bign1 = bignFromStr("1");
vector<int> bign20 = bignFromStr("20");
vector<int> f(vector<int> x, vector<int> y){
  return bignSub(bignMul(x, x), y);
}
int get(vector<int> a, const vector<int> &b, int off){
  a.erase(a.begin(), a.begin() + off);
  vector<int> c(1);
  int lo = 0, hi = BASE;
  while (lo <= hi){
    int mid = (lo + hi) / 2;
    c.back() = mid; 
    vector<int> tmp = bignMul(c, b);
    if (!bignLess(tmp, a)) hi = mid - 1 ;
    else lo = mid + 1;
  }
  return max(hi, 0);
}
vector<int> bignDiv(vector<int> a, const vector<int> &b){
  //cout << strFromBign(a) << "/" << strFromBign(b) << endl;
  vector<int> c(a.size());
  for (int i = c.size() - 1; i >= 0; i--){
    c[i] = get(a, b, i);
    vector<int> t(i + 1, 0);
    t.back() = c[i];
    a = bignSub(a, bignMul(b, t));
  }
  while (c.size() && c.back() == 0) c.pop_back();
  //cout << strFromBign(c) << endl;
  return c;
}

vector<int> ChineseSquareRoot(vector<int> Y){
  vector<int> X; 
  vector<int> remain;
  for (int i = Y.size() - 1; i >= 0; i--){
    //printf("====%d :%d\n", i, Y[i]);
    remain = bignAdd(bignTimes(remain, 100), bignFromInt(Y[i]));
    //cout << "Remain: " << strFromBign(remain) << endl;
    vector<int> last;
    for (int j = 1; j <= 10; j++){
      vector<int> tmp = bignTimes(bignAdd(bignTimes(X, 20), bignFromInt(j)), j);
      if (bignLess(remain, tmp)){
        //cout << j << endl;
        X = bignAdd(bignTimes(X, 10), bignFromInt(j - 1)); 
        remain = bignSub(remain, last);
        break;
      }
      last = tmp;
    }
    //cout << "X : " << strFromBign(X) << endl;
  }
  return X;
}

//vector<int> NewTonSquareRoot(vector<int> Y){
  //string ys = strFromBign(Y);
  //string xs = ys.substr(0, ys.size() / 2);
  //vector<int> x = bignFromStr(xs); 
  //int cnt = 0;
  //while (true){
    //cnt++;
    //if (bignMul(x, x) == Y) return x;
    //x = bignHalf(bignAdd(x, bignDiv(Y, x)));
    //if (cnt == 20) return x;
  //}
  //return {};
//}
//vector<int> bignSquareRoot(vector<int> Y){
  //string s = strFromBign(Y);
  //double ds = doubleFromStr(s);
  ////cout << strFromBign(bignFromStr("")) << endl;;
  //vector<int> lo =  bignFromStr(s.substr(0, s.size() / 2)); 
  ////vector<int> lo = bign0;
  //vector<int> hi =  bignFromStr(s.substr(0, (s.size() + 1) / 2 + 1)); 
  ////vector<int> hi = Y;
  //while (!bignLess(hi, lo)){
    //vector<int> mid = bignHalf(bignAdd(lo, hi)); 
    //double m = doubleFromStr(strFromBign(mid));
    //if (m * m < ds) {
      //lo = bignAdd(mid, bign1);  
      //continue;
    //}
    //if (m * m > ds) {
      //hi = bignSub(mid, bign1);
      //continue;
    //}
    //vector<int> m2 = bignMul(mid, mid);
    //if (m2 == Y) return mid;
    //if (bignLess(m2, Y)) lo = bignAdd(mid, bign1);
    //else  hi = bignSub(mid, bign1);
  //}
  ////assert(
  ////assert(0);
  //return hi;
//}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false);   
  cin >> TestNum;
  while (TestNum--) {
    string s; cin >> s;
    cout << strFromBign(ChineseSquareRoot(bignFromStr(s) ) ) << endl; 
    if (TestNum) cout << endl;
  }
}

