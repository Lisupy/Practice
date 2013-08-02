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

const int MAXN = 1024;
const int BASE = 10000;
string strFromInt(int n, int d){
  char buf[32];
  sprintf(buf, "%0*d", d, n);
  return buf;
}
vector<int> bignFromStr(string s){
  vector<int> a;
  reverse(s.begin(), s.end());
  for (size_t i = 0; i < s.size(); i+=4) {
    string t = s.substr(i, 4); reverse(t.begin(), t.end());
    a.push_back(atoi(t.c_str()));
  }
  return a;
}
string strFromBign(vector<int> a){
  string s;
  if (a.size() == 0) return "0";
  reverse(a.begin(), a.end());
  s += strFromInt(a[0], 0);
  for (size_t i = 1; i < a.size(); i++) {
    s += strFromInt(a[i], 4);
  }
  return s;
}
vector<int> bignAdd(vector<int> a, vector<int> b){
  vector<int> c;
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
vector<int> bignTimes(vector<int> a, int n){
  vector<int> b;
  int carry = 0;
  for (size_t i = 0; i < a.size() || carry; i++) {
    int da = i < a.size() ? a[i] : 0;
    int db = da * n + carry;
    b.push_back(db % BASE);
    carry = db / BASE;
  }
  return b;
}
vector<int> D[MAXN];

void D_init(){
  D[0] = bignFromStr("0");
  D[1] = bignFromStr("0");
  D[2] = bignFromStr("1");

  for (int i = 3; i < MAXN; i++){
    D[i] = bignTimes(bignAdd(D[i - 1], D[i - 2]), i - 1);
  }
}


int TestNum;
int main(){
  D_init();
  int n;
  while (cin >> n && n != -1) {
    cout << strFromBign(D[n]) << endl; 
  }

}

