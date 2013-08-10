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

i64 catlan[32];
void catlan_init(){
  catlan[0] = 1;
  catlan[1] = 1;
  for (int n = 2; n < 32; n++){
    for (int i = 0; i < n; i++){
      catlan[n] += catlan[i] * catlan[n - i - 1];
    }
    //cout << catlan[n] << endl;
  }
}

void mth_seq(i64 N, i64 M){
  for (int i = N; i > 0; i--){
    i64 s = catlan[i - 1] * catlan[N - i];
    if (M >= s){
      M -= s;
    }else{
      cout << "E";
      mth_seq(i - 1, M / catlan[N - i]);
      cout << "S";
      mth_seq(N - i, M % catlan[N - i]);
      return;
    }
  }
}

int TestNum;
int main(){
  catlan_init();
  i64 N, M;
  while (cin >> N >> M && N) {
    if (M > catlan[N - 1]){
      cout << "ERROR" << endl;
    }else{
      mth_seq(N - 1, M - 1);
      cout << endl;
    }
  }
}

