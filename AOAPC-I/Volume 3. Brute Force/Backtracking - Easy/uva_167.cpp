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
int a[8][8];
bool isValid(int p[8]){
  vector<bool> c1(16), c2(16);
  for (int i = 0; i < 8; i++){
    if (c1[p[i] + i] == true){
      return false;
    }
    if (c2[p[i] + 8 - i] == true){
      return false;
    }
    c1[p[i] + i] = c2[p[i] + 8 - i] = true;
  }
  return true;
}
int calc(int p[8]){
  int total = 0;
  for (int i = 0; i < 8; i++){
    total += a[i][p[i]];
  }
  return total;
}
int main(){
  int k;
  cin >> k;
  while (k--){
    for (int i = 0; i < 8; i++){
      for (int j = 0; j < 8; j++){
        cin >> a[i][j];
      }
    }
    int p[8];
    for (int i = 0; i < 8; i++){
      p[i] = i;
    }
    int best = 0;
    do {
      if(isValid(p)){
        int score = calc(p);
        best = max(score, best);
      }
    } while (next_permutation(p, p + 8));
    printf("%5d\n", best);
  }
}
