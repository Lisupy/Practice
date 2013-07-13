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


long long getMax(string s){
  long long a = 0;
  long long b = 1;
  size_t posl = 0;
  s += '*';
  while (posl < s.size()){
    size_t posr = s.find_first_not_of("0123456789", posl);
    if (posr == string::npos) posr = s.size();
    int n = atoi(s.substr(posl, posr - posl).c_str());
    if (s[posr] == '+'){
      a += n;
    }else{
      a += n;
      b *= a;
      a = 0;
    }
    posl = posr + 1;
  }
  return b;
}
long long getMin(string s){
  long long a = 1;
  long long b = 0;
  size_t posl = 0;
  s += '+';
  while (posl < s.size()){
    size_t posr = s.find_first_not_of("0123456789", posl);
    if (posr == string::npos) posr = s.size();
    int n = atoi(s.substr(posl, posr - posl).c_str());
    if (s[posr] == '*'){
      a *= n;
    }else{
      a *= n;
      b += a;
      a = 1;
    }
    posl = posr + 1;
  }
  return b;
}

int main(){
  int N;
  cin >> N;
  while (N--){
    string line;
    cin >> line;
    printf("The maximum and minimum are %lld and %lld.\n", getMax(line), getMin(line));
  }
}



      

