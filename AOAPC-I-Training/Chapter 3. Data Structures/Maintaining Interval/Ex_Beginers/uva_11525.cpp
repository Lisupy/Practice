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
const int MAXK = 50010;
int K;


int cnt[MAXK];


int lowbit(int x) { return x & -x; }
void add(int pos, int i){
  while (pos <= K){
    cnt[pos] += i;
    pos += lowbit(pos);
  }
}
int sum(int pos){
  int total = 0;
  while (pos){
    total += cnt[pos];
    pos -= lowbit(pos);
  }
  return total;
}
int sumseek(int s){
  int l = 1, r = K + 1; //[l, r] 
  while (l < r){
    int m = (l + r) / 2;
    int sm = sum(m);
    if (sm >= s) r = m;
    else l = m + 1;
  }
  assert(l == r);
  add(r, -1);
  return r ;
}
void init(){
  for (int i = 1; i <= K; i++){
    add(i, 1);
  }
}
int TestNum;
int main(){
  scanf("%d", &TestNum);
  while (TestNum--) {
    scanf("%d", &K);
    init();
    for (int i = 0; i < K; i++){
      if (i != 0) printf(" ");
      int s; scanf("%d", &s);
      printf("%d", sumseek(s + 1)); 
    }printf("\n");
  }
}

