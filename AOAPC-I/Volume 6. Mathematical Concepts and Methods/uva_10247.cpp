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
  string s;
  s += strFromInt(a[0], 0);
  for (size_t i = 1; i < a.size(); i++){
    s += strFromInt(a[i], WIDTH);
  }
  return s;
}
vector<int> bignMul(vector<int> a, int n){
  vector<int> b;
  int carry = 0;
  for (size_t i = 0; i < a.size(); i++){
    int db = a[i] * n + carry;
    b.push_back(db % BASE);
    carry = db / BASE;
  }
  if (carry) b.push_back(carry);
  return b;
}
const int MAXN = 1024 * 8;
vector<bool> isPrime(MAXN, true);
vector<int> primes;
void primes_init(){
  for (int n = 2; n < MAXN; n++){
    if (isPrime[n]) primes.push_back(n);
    for (size_t i = 0; i < primes.size(); i++){
      int p = primes[i];
      int m = p * n;
      if (m >= MAXN) break;
      isPrime[m] = false;
      if (n % p == 0) break;
    }
  }
}

vector<int> factorizate(int n){
  vector<int> a(primes.size());
  for (size_t i = 0; i < primes.size() && n > 1; i++){
    int p = primes[i];
    while (n % p == 0) a[i]++, n /= p;
  }
  assert(n <= 1);
  return a;
}

void factorSub(vector<int> &a, const vector<int> &b){
  for (size_t i = 0; i < primes.size(); i++){
    a[i] -= b[i];
  }
}
void factorAdd(vector<int> &a, const vector<int> &b){
  for (size_t i = 0; i < primes.size(); i++){
    a[i] += b[i];
  }
}
vector<int> factorCombine(vector<int> &a){
  vector<int> b = bignFromStr("1");
  for (size_t i = 0; i < a.size(); i++){
    while (a[i]--) b = bignMul(b, primes[i]);
  }
  return b;
}
int pow_cache[32][32];
int pow(int k, int d){
  int &res = pow_cache[k][d];
  if (res != 0) return res;
  if (d == 0)  res = 1;
  else res = k * pow(k, d - 1);
  return res;
}
int sumPow_cache[32][32];
int sumOfPow(int k, int d){
  int &res = sumPow_cache[k][d];
  if (res != 0) return res;
  if (d == 0) res = 1;
  else res = pow(k, d) + sumOfPow(k, d - 1);
  return res;
}
vector<int> solve(int k, int d){
  vector<int> a = factorizate(0);  
  int n = sumOfPow(k, d);
  for (int i = 1; i <= n; i++){
    factorAdd(a, factorizate(i));
  }
  for (int i = 0; i <= d; i++){
    int m = sumOfPow(k, d - i);
    vector<int> b = factorizate(m);
    for (int j = 0; j < pow(k, i); j++){
      factorSub(a, b);
    }
  }
  return factorCombine(a);
}
int TestNum;
int main(){
  primes_init();
  int k, d;
  while (cin >> k >> d) {
    cout << strFromBign(solve(k, d)) << endl;
  }
}

