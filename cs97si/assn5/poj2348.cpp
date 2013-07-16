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
//MLE
map<pair<long long, long long>, bool> cache;
bool f(long long A, long long B){
  if (A < B){
    swap(A, B);
  }
  if (B == 0){
    return true;
  }
  if (A == B){
    return true;
  }

  if (cache.count(make_pair(A, B))){
    return cache[make_pair(A, B)];
  }

  bool &res = cache[make_pair(A, B)];  
  A -= B;
  while (A > 0){
    if (!f(A, B)){
      return res = true;
    }
    A -= B;
  }
  return res = false;
}

bool f2(long long A, long long B){
  if (A < B) swap(A, B);
  if (B == 0) return true;
  if (A == B) return true;
  if (A >= 2 * B) return true;
  return !f2(B, A - B);
}
int main(){
  long long A, B;
  while (cin >> A >> B){
    if (A == 0 && B == 0){
      break;
    }
    //assert(f(A, B) == f2(A, B));
    if (f2(A, B)){
      cout << "Stan wins" << endl;
    }else{
      cout << "Ollie wins" << endl;
    }
  }
}
