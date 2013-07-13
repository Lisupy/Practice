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


vector<string> frags;


bool isValid(string s){
  vector<bool> used(frags.size());
  for (size_t i = 0; i < frags.size(); i++){
    if (used[i])continue;
    for (size_t j = i + 1; j < frags.size(); j++){
      if (frags[i] + frags[j] == s || frags[j] + frags[i] == s){
        used[i] = used[j] = true;
        break;
      }
    }
    if (!used[i])return false;
  }
  return true;
}

string solve(){
  string a = frags[0];
  for (size_t i = 1; i < frags.size(); i++){
    string s = a + frags[i];
    if (isValid(s)){
      return s;
    }
    s = frags[i] + a;
    if (isValid(s)){
      return s;
    }
  }
  assert(0);
}

void input(){
  frags.clear();
  string line;
  while (getline(cin, line) && line.size()){
    frags.push_back(line);
  }
}

int main(){
  int TestNum;
  cin >> TestNum;
  cin.ignore();
  cin.ignore();
  while (TestNum--){
    input();
    cout << solve() << endl;
    if (TestNum) cout << endl;
  }
}
