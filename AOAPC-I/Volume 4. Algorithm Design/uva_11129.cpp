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
void output(vector<int> &a){
  printf("%lu:", a.size());
  for (size_t i = 0; i < a.size(); i++){
    printf(" %d", a[i]);
  }
  printf("\n");
}

void solve(vector<int> &a){
  if (a.size() <= 2){
    return;
  }
  vector<int> b;
  vector<int> c;
  for (size_t i = 0; i < a.size(); i += 2){
    b.push_back(a[i]);
  }
  for (size_t i = 1; i < a.size(); i += 2){
    c.push_back(a[i]);
  }
  //output(a);
  //output(b);
  //output(c);
  solve(b);
  solve(c);
  copy(b.begin(), b.end(), a.begin());
  copy(c.begin(), c.end(), a.begin() + b.size());
}
  

int main(){
  int n;
  while (cin >> n && n){
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i;
    solve(a);
    output(a);
  }
}
