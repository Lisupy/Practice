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
  vector<int> a;
  reverse(s.begin(), s.end());
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
bool bignLess(vector<int> a, vector<int> b){
  if (a.size() != b.size()) return a.size() < b.size();
  for (int i = a.size() - 1; i >= 0; i--) {
    if (a[i] != b[i]) return a[i] < b[i]; 
  }
  return false;
}
vector<int> bign0 = bignFromStr("0");
vector<int> bign1 = bignFromStr("1");
const int MAXN = 512;
vector<int> fibs[MAXN];
void fibs_init(){
  fibs[0] = fibs[1] = bign1;
  for (int i = 2; i < MAXN; i++) fibs[i] = bignAdd(fibs[i - 1], fibs[i - 2]); 
  //for (int i = 0; i < MAXN; i++){
    //cout << strFromBign(fibs[i]).size() << ": ";
    //cout << strFromBign(fibs[i]) << endl;
  //}
}
int countFibsLessThanX(vector<int> X){
  return lower_bound(fibs + 1, fibs + MAXN, X, bignLess) - fibs - 1;  
}
int solve(vector<int> A, vector<int> B){
  return countFibsLessThanX(bignAdd(B, bign1)) - countFibsLessThanX(A);
}
int TestNum;
int main(){
  fibs_init();
  string sA, sB;
  while (cin >> sA >> sB && sB != "0") {
    cout << solve(bignFromStr(sA), bignFromStr(sB)) << endl; 
  }
}

