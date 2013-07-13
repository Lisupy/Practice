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


vector<string> words;

int get_diff(string s, string t){
  size_t si = 0;
  size_t ti = 0;
  while (si < s.size() && ti < t.size()){
    if (s[si] == t[ti]){
      si++, ti++;
    }else{
      break;
    }
  }
  return t.size() - ti;
}

int main(){
  int TestNum;
  cin >> TestNum;
  while (TestNum--){
    int n;
    cin >> n;
    words.resize(n + 1);
    for (int i = 1; i <= n; i++){
      cin >> words[i];
    }
    sort(words.begin(), words.end());
    int total = 0;
    for (int i = 1; i <= n; i++){
      total += get_diff(words[i - 1], words[i]);
    }
    cout << total << endl;
    for (int i = 1; i <= n; i++){
      cout << words[i] << endl;
    }
  }
}

