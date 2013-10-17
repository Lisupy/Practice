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
int C(int n, int k){
  int s = 1;
  for (int i = 1; i <= k; i++){
    s = s * (n - (i - 1) )/ i; 
  }
  //printf("C(%d, %d) : %d\n", n, k, s);
  return s;
}

int allCount(char c, int l){
  int n = 'z' - c + 1;
  return C(n, l);
}
bool isValid(string s){
  string t(s);
  sort(t.begin(), t.end());
  t.erase(unique(t.begin(), t.end()), t.end());
  return t == s;
}
int wordIndex(string s){
  if (!isValid(s)) return 0;
  if (s.size() == 1){
    return s[0] - 'a' + 1;
  }
  int total = 0;
  for (size_t i = 1; i <= s.size() - 1; i++){
    total += allCount('a', i);
  }
  //cout << total << endl;
  for (size_t i = 0; i < s.size() - 1; i++){
    for (char ch = i == 0 ? 'a' : s[i - 1] + 1; ch < s[i]; ch++){
      total += allCount(ch + 1, s.size() - 1 - i);
    }
  }
  total += s[s.size() - 1] - s[s.size() - 2];
  return total;
}


int TestNum;
int main(){
  string s;
  while (cin >> s) {
    cout << wordIndex(s) << endl;
  }

}

