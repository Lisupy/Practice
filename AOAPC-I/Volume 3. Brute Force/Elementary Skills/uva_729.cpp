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


int N, H;
int TestNum;

int dist(int A, int B){
  return __builtin_popcount((A ^ B) & ((1 << N) - 1));
}

vector<int> gen(){
  vector<int> a;
  for (int i = 0; i < (1 << N); i++){
    if (__builtin_popcount(i) == H) {
      a.push_back(i);
    }
  }
  return a;
}

void output(int n){
  for (int i = N - 1; i >= 0; i--){
    if (n & (1 << i)){
      printf("1");
    }else{
      printf("0");
    }
  }
  printf("\n");
}
int main(){
  cin >> TestNum;
  while (TestNum--) {
    cin >> N >> H;
    vector<int> a = gen();
    for (size_t i = 0; i < a.size(); i++) {
      output(a[i]);
    }
    if (TestNum){
      cout << endl;
    }
  }
}
