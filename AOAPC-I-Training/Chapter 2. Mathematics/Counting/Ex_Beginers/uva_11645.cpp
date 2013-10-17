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
typedef unsigned long long u64;
typedef vector<int> bign;

string strFromInt(int n, int d){
  char buf[32];
  sprintf(buf, "%0*d", d, n);
  return buf;
}
bign bignFromStr(string s){
  reverse(s.begin(), s.end());
  bign a;
  for (size_t i = 0; i < s.size(); i += 4) {
    string t = s.substr(i, 4); reverse(t.begin(), t.end());
    a.push_back(atoi(t.c_str()));
  }
  return a;
}
bign bignFromU64(u64 u){
  char buf[32];
  sprintf(buf, "%llu", u);
  return bignFromStr(buf);
}
string strFromBign(bign a){
  string s;
  reverse(a.begin(), a.end());
  for (size_t i = 0; i < a.size(); i++) {
    s += strFromInt(a[i], i == 0? 0: 4);  
  }
  if (s == "") s = "0";
  return s;
}
bign bignAdd(bign a, bign b){
  bign c;
  int carry = 0;
  for (size_t i = 0; i < max(a.size(), b.size()) || carry; i++) {
    int da = i < a.size() ? a[i] : 0;
    int db = i < b.size() ? b[i] : 0;
    int dc = da + db + carry;
    c.push_back(dc % BASE);
    carry = dc / BASE;
  }
  return c;
}
bign bignTimes(bign a, size_t off, int n){
  bign c(off);
  int carry = 0;
  for (size_t i = 0; i < a.size(); i++) {
    int d = a[i] * n + carry;
    c.push_back(d % BASE);
    carry = d / BASE;
  }
  if (carry) c.push_back(carry);
  return c;
}
bign bignMul(bign a, bign b){
  bign c;
  for (size_t i = 0; i < b.size(); i++) {
    c = bignAdd(c, bignTimes(a, i, b[i]));
  }
  return c;
}
bign bignPower(bign a, u64 p){
  bign s = bignFromStr("1");
  while (p){
    if (p % 2) s = bignMul(s, a);
    a = bignMul(a, a);
    p /= 2;
  }
  return s;
}
bign bign0 = bignFromStr("0"); 
bign bign1 = bignFromStr("1"); 
bign bign2 = bignFromStr("2"); 
bign getSum1(int n){
  if (n <= 1) return bign0; 
  if (n == 2) return bign1; 
  return bignMul(bignPower(bign2, n - 2) , bignFromU64(n - 1));
}

bign getSum2(u64 n){
  //cout << "getSum2: " << n << endl;
  if (n < 3) return bign0;
  if (n < 4) return bign1;
  u64 tn = 1;
  int d = 1;
  while (tn * 2 <= n) tn *= 2, d++;
  //cout << d << ", " << tn << endl;
  bign total = bign0;
  total = bignAdd(total, getSum1(d - 1));
  //cout << total << endl;
  n -= tn;
  tn /= 2;
  d--;
  int last = 1;
  while (d > 0){
    if (n / tn >= 1){
      //cout << d << ", ";
      total = bignAdd(total, getSum1(d - 1));
      //cout << total << endl;
      if (last == 1){
        //total += (n - tn + 1);
        total = bignAdd(total, bignFromU64(n - tn + 1));
      }
      //cout << total << endl;
      last = 1;
      n -= tn;
    }else{
      last = 0;
    }
    tn /= 2;
    d--;
  }
  return total;
}
  



int TestNum;
int main(){
  long long N;
  //cout << getSum1(0) << endl;
  //cout << getSum1(4) << endl;
  while (cin >> N && N >= 0) {
    printf("Case %d: %s\n", ++TestNum, strFromBign(getSum2(N)).c_str());
  }

}

