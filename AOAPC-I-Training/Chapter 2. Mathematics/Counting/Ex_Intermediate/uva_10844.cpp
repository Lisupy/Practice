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
 */
//AC 2.758s
//const int BASE = 1000 * 1000;
//const int OC = 6;

//AC 2.099s
const int BASE = 1000 * 1000 * 1000;
const int OC = 9;

string strFromInt(int n, int d){
  char buf[32];
  sprintf(buf, "%0*d", d, n);
  return buf;
}
struct Bign{
  vector<int> a;
  Bign(string s):a(0){
    reverse(s.begin(), s.end());
    for (size_t i = 0; i < s.size(); i += OC) {
      string t = s.substr(i, OC); reverse(t.begin(), t.end());
      a.push_back(atoi(t.c_str()));
      //cout << a.back() << endl;
    }
  }
  Bign():a(0){};
  string toStr(){
    string s;
    while (a.size() && a.back() == 0) a.pop_back();
    reverse(a.begin(), a.end());
    for (size_t i = 0; i < a.size(); i++) {
      s += strFromInt(a[i], i == 0 ? 0 : OC);
    }
    if (s == "") return "0";
    return s;
  }
};
Bign operator+(Bign a, Bign b){
  Bign c;
  int carry = 0;
  for (size_t i = 0; i < max(a.a.size(), b.a.size()); i++) {
    i64 da = i < a.a.size() ? a.a[i] : 0;
    i64 db = i < b.a.size() ? b.a[i] : 0;
    i64 dc = da + db + carry;
    c.a.push_back(dc % BASE);
    carry = dc / BASE;
  }
  if (carry) c.a.push_back(carry);
  return c;
}
Bign operator*(Bign a, int n){
  Bign b;
  int carry = 0;
  for (size_t i = 0; i < a.a.size(); i++) {
    i64 db = (i64)a.a[i] * n + carry;
    b.a.push_back(db % BASE);
    carry = db / BASE;
  }
  if (carry) b.a.push_back(carry);
  return b;
}
Bign bignTimes(Bign a, int n, size_t off){
  Bign b;
  b.a.resize(off);
  int carry = 0;
  for (size_t i = 0; i < a.a.size(); i++) {
    int db = a.a[i] * n + carry;
    b.a.push_back(db % BASE);
    carry = db / BASE;
  }
  if (carry) b.a.push_back(carry);
  return b;
}
Bign operator*(Bign a, Bign b){
  Bign c;
  for (size_t i = 0; i < b.a.size(); i++) {
    c = c + bignTimes(a, b.a[i], i);
  }
  return c;
}
const int MAXN = 1024;
Bign f[MAXN][MAXN];
bool visited[MAXN][MAXN];
Bign bign0("0");
Bign bign1("1");
Bign F(int n, int k){
  if (n < k) return bign0;
  if (n == k) return bign1;
  if (k == 1) return bign1;
  if (n == 1){
    if (k == 1) return bign1;
    else return bign0;
  }
  Bign &res = f[n][k];
  if (visited[n][k]) return res;
  visited[n][k] = true;
  res = F(n - 1, k) * k + F(n - 1, k - 1);
  //printf("F(%d, %d) : %s\n", n, k, res.toStr().c_str());
  return res;
}
Bign c[MAXN][MAXN];
bool c_visited[MAXN][MAXN];
Bign C(int n, int k){
  //return bign1;
  if (n < k) return bign0;
  if (k < 0) return bign0;
  if (k == 0) return bign1; 
  if (k > n - k) k = n - k; 
  if (c_visited[n][k]) return c[n][k];
  c_visited[n][k] = true;
  c[n][k] = C(n - 1, k - 1) + C(n - 1, k);
  //printf("C(%d, %d) : %s\n", n, k, c[n][k].toStr().c_str());
  return c[n][k];
}
Bign b[MAXN];
bool b_visited[MAXN];
Bign B(int n){
  if (n == 0) return bign1;
  if (n == 1) return bign1;
  Bign &res = b[n]; 
  if (b_visited[n]) return res;
  b_visited[n] = true;
  for (int i = 0; i <= n - 1; i++){
    res = res + C(n - 1, i)*B(i);
  }
  return res; 
}
int TestNum;
int main(){
  //Bign a("1");
  //cout << a.toStr() << endl;
  int n;
  while (cin >> n && n) {
    Bign total("0");
    for (int i = 1; i <= n; i++) {
      total = total + F(n, i); 
    }
    cout << n << ", " << total.toStr() << endl;
    //cout << n << ", " << B(n).toStr() << endl;
  }
}

