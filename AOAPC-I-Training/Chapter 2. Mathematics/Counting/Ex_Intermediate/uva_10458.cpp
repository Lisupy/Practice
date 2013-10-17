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

const int MAXK = 16;
const int BASE = 10000;
const int OC = 4;
string strFromInt(int n, int d){
  char buf[32];
  sprintf(buf, "%0*d", d, n);
  return buf;
}
struct Bign{
  vector<int> data;
  Bign(string s): data(0){
    reverse(s.begin(), s.end());
    for (size_t i = 0; i < s.size(); i += OC){
      string t = s.substr(i, OC); reverse(t.begin(), t.end());
      data.push_back(atoi(t.c_str()));
    }
  }
  Bign(i64 n): data(0){
    while (n){
      data.push_back(n % BASE);
      n /= BASE;
    }
  }
  Bign(): data(0){};
  string toStr(){
    string s;
    while(data.size() && data.back() == 0) data.pop_back();
    for (size_t i = 0; i < data.size(); i++) {
      s += strFromInt(data[data.size() - i - 1], i ? OC : 0);
    }
    if (s == "") return "0";
    return s;
  }
};

Bign operator+(const Bign &a, const Bign &b){
  Bign c;
  int carry = 0;
  for (size_t i = 0; carry || i < max(a.data.size(), b.data.size()); i++) {
    int da = i < a.data.size() ? a.data[i] : 0; 
    int db = i < b.data.size() ? b.data[i] : 0; 
    int dc = da + db + carry;
    c.data.push_back(dc % BASE);
    carry = dc / BASE;
  }
  return c;
}

Bign operator-(const Bign &a, const Bign &b){
  Bign c;
  int borrow = 0;
  for (size_t i = 0; i < max(a.data.size(), b.data.size()); i++) {
    int da = i < a.data.size() ? a.data[i] : 0; 
    int db = i < b.data.size() ? b.data[i] : 0; 
    int dc = da - db - borrow;
    if (dc < 0){
      c.data.push_back(dc + BASE);
      borrow = 1;
    }else{
      c.data.push_back(dc);
      borrow = 0;
    }
  }
  assert(borrow == 0);
  return c;
}

Bign bignTimes(const Bign &a, size_t off, int n){
  Bign b;
  b.data.resize(off);
  int carry = 0;
  for (size_t i = 0; i < a.data.size(); i++) {
    int db = a.data[i] * n + carry;
    b.data.push_back(db % BASE);
    carry = db / BASE;
  }
  if (carry) b.data.push_back(carry);
  return b;
}
Bign operator*(const Bign &a, const Bign &b){
  Bign c;
  for (size_t i = 0; i < b.data.size(); i++) {
    c = c + bignTimes(a, i, b.data[i]);
  }
  return c;
}
Bign operator*(const Bign &a, i64 n){
  return a * Bign(n);
}
Bign operator/(const Bign &a, i64 n){
  int remain = 0;
  Bign b;
  for (int i = a.data.size() - 1; i >= 0; i--) {
    i64 up = remain * BASE + a.data[i];
    b.data.push_back(up / n);
    remain = up % n;
  }
  reverse(b.data.begin(), b.data.end());
  while(b.data.size() && b.data.back() == 0) b.data.pop_back();
  return b;
}
Bign C(i64 n, i64 k){
  if (n < k) return 0;
  Bign total(1);
  //printf("C(%d, %d) = %s\n", n, k, total.toStr().c_str());
  for (int i = 0; i < k; i++) {
    //printf("C(%d, %d) = %s\n", n, k, total.toStr().c_str());
    total = total * (n - i);
    //printf("C(%d, %d) = %s\n", n, k, total.toStr().c_str());
    total = total / (i + 1);
  }
  //printf("C(%lld, %lld) = %s\n", n, k, total.toStr().c_str());
  return total;
}  
int K, N;
i64 upper[MAXK], lower[MAXK];
i64 a[MAXK];

Bign solve1(){
  Bign total1(0);
  Bign total2(0);
  for (int i = 0; i < (1 << K); i++) {
    i64 M = N;
    int b = 0;
    for (int j = 0; j < K; j++){
      if ((i & (1 << j)) == 0){
        M -= max(lower[j], 0ll);
      }else{
        b++;
        M -= max(upper[j] + 1, 0ll);
      }
    }
    Bign s = C(M + K - 1, K - 1);
    assert(b % 2 == __builtin_parity(i));
    if (__builtin_parity(i)){
      total1 = total1 + s;
    }else{
      total2 = total2 + s;
    }
  }
  //cout << total2.toStr() << endl;
  //cout << total1.toStr() << endl;
  return total2 - total1;
}
int TestNum;
int main(){
  while (cin >> K >> N) {
    //assert(N < 10000);
    for (int i = 0; i < K; i++) {
      cin >> lower[i] >> upper[i];
      assert(lower[i] <= upper[i]);
    }
    cout << solve1().toStr() << endl;
  } 
}

