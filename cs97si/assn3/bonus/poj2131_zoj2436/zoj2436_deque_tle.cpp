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
const int MAXN = 135 * 1000;
int N, M;
int TestNum;
int main(){
  //while (true);
  //assert(0);
  //printf("%d\n", 1/0);
  scanf("%d", &TestNum);
  while (TestNum--){
    scanf("%d%d", &N, &M);
    vector<int> L(N + 1);
    for (int i = 1; i <= N; i++) scanf("%d", &L[i]);

    deque<int> A(MAXN * 2);
    for (int i = 1; i <= N; i++){
      if (A[L[i]] == 0){
        A[L[i]] = i;
      }else{
        A.insert(A.begin() + L[i], i);
      }
    }
    while (A.back() == 0) A.pop_back();
    printf("%lu\n", A.size() - 1);
    for (size_t i = 1; i < A.size(); i++){
      if (i != 1) printf(" ");
      printf("%d", A[i]);
    }printf("\n");
    if (TestNum){
      printf("\n");
    }
  }
}

