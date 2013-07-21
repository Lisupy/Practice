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
 * sizeof
 */
const int BASE = 10000;
string strFromInt(int n, int w){
  char buf[32];
  sprintf(buf, "%0*d", w, n);
  return buf;
}
string strFromBign(vector<int> a){
  if (a.size() == 0) return "0";
  reverse(a.begin(), a.end());
  string s;
  for (size_t i = 0; i < a.size(); i++){
    s += strFromInt(a[i], i ? 4 : 0);
  }
  return s;
}
vector<int> bignFromStr(string s){
  vector<int> a;
  reverse(s.begin(), s.end());
  for (size_t i = 0; i < s.size(); i += 4){ 
    string t = s.substr(i, 4);
    reverse(t.begin(), t.end());
    a.push_back(atoi(t.c_str()));
  }
  return a;
}

vector<int> bignAdd(vector<int> a, vector<int> b){
  vector<int> c;
  for (size_t i = 0, carry = 0; i < max(a.size(), b.size()) || carry != 0; i++){
    int da = i < a.size() ? a[i] : 0; 
    int db = i < b.size() ? b[i] : 0;
    int dc = da + db + carry;
    c.push_back(dc % BASE);
    carry = dc / BASE;
  }
  return c;
}
vector<int> distinct_subsequence(string X, string Z){
  vector<vector<int> >dp(Z.size() + 1);
  dp[0] = bignFromStr("1");
  for (size_t i = 0; i < X.size(); i++){
    for (int j = Z.size(); j > 0; j--){
      if (X[i] == Z[j - 1]){
        dp[j] = bignAdd(dp[j], dp[j - 1]);
      }
    }
  }
  return dp[Z.size()];
}


int main(){
  int N;
  cin >> N;
  while (N--){
    string X, Z;
    cin >> X >> Z;
    cout << strFromBign(distinct_subsequence(X, Z)) << endl;
  }
}
