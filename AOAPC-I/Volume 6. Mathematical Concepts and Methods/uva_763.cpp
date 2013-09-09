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
bool bignLess(vector<int> a, vector<int> b){
  if (a.size() != b.size()) return a.size() < b.size();
  for (int i = a.size() - 1; i >= 0; i--) {
    if (a[i] != b[i]) return a[i] < b[i]; 
  }
  return false;
}
const int MAXN = 128;
vector<int> fibs[MAXN];
void fibs_init(){
  fibs[0].push_back(1);
  fibs[1].push_back(1);
  for (int i = 2; i < MAXN; i++) {
    fibs[i] = bignAdd(fibs[i - 1], fibs[i - 2]); 
  }
}
string fibnFromBign(vector<int> a){
  string s;
  for (int i = MAXN - 1; i >= 1; i--) {
    if (bignLess(a, fibs[i])) s+= '0';
    else s += '1', a = bignSub(a, fibs[i]);
  }
  s = s.substr(min(s.find_first_of("1"), s.size()));
  if (s == "") s = "0";
  return s;
}
vector<int> bignFromFibn(string s){
  reverse(s.begin(), s.end());
  vector<int> a;
  for (size_t i = 0; i < s.size(); i++) if (s[i] == '1') {
    a = bignAdd(a, fibs[i + 1]);
  }
  return a;
}

int TestNum;
int main(){
  fibs_init();
  string A, B;
  while (cin >> A >> B) {
    if (TestNum++) cout<<endl; 
    string C = fibnFromBign(bignAdd(bignFromFibn(A), bignFromFibn(B))); 
    cout << C << endl;

  }

}

