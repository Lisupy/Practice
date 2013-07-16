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
const int MAXN = 10 * 1024;
int T;
int N;
int A[MAXN];
//
//SG(0) = 1
//SG(1) = 0
//SG(2) = 2
//SG(3) = 3
//...
bool solve(){
  int s = 0;
  int maxSG = 0;
  for (int i = 0; i < N; i++){
    int SG = A[i];
    s ^= SG;
    maxSG = max(maxSG, SG);
  }
  //cout << s << endl;
  if (s == 0){
    return !(maxSG > 1);
  }else{
    return maxSG > 1;
  }
}
int main(){
  scanf("%d", &T);
  while (T--){
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
      scanf("%d", A + i);
    }
    if (solve()){
      cout << "John" << endl;
    }else{
      cout << "Brother" << endl;
    }
  }
}
