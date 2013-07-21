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


bool isSmiple(string a){
  return a == "A";
}

bool isFullyGrown(string a){
  return a.size() > 2 && a[a.size() - 1] == 'B' && a[a.size() - 2] == 'A';
}

bool isMutagenic(string a){
  return a.size() > 2 && a[0] == 'B' && a[a.size() - 1] == 'A';
}
bool isValid(string a){
  if (isSmiple(a)) return true;
  if (isFullyGrown(a)) return isValid(a.substr(0, a.size() - 2));
  if (isMutagenic(a)) return isValid(a.substr(1, a.size() - 2));
  return false;
}

int main(){
  int n; cin >> n;
  while (n--){
    string s; cin >> s;
    if (!isValid(s)){
      cout << "MUTANT" << endl;
    }else{
      if (isSmiple(s)) cout << "SIMPLE" << endl;
      if (isFullyGrown(s)) cout << "FULLY-GROWN" << endl;
      if (isMutagenic(s)) cout << "MUTAGENIC" << endl;
    }
  }
}




