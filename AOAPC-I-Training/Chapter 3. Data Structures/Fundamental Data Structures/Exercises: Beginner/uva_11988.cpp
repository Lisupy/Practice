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

string solve(string s){
  list<string> res;
  string t;
  string op = "first";
  for (size_t i = 0; i <= s.size(); i++){
    if (i == s.size() || s[i] == '[' || s[i] == ']'){
      if (op == "first"){
        res.push_back(t);
      }else if (op == "head"){
        res.push_front(t);
      }else if (op == "tail"){
        res.push_back(t);
      }
      if (i == s.size()) break;
      t = "";
      if (s[i] == '[') op = "head";
      else op = "tail";
    }else{
      t += s[i];
    }
  }
  string ans;
  for (list<string>::iterator it = res.begin(); it != res.end(); it++){
    ans += *it;
  }
  return ans;
}


int TestNum;
int main(){
  string s;
  while (cin >> s){
    cout << solve(s) << endl;
  }
}

