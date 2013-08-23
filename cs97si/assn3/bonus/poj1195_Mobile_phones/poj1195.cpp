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
const int MAX_S = 1024;
int S;

static inline
int lowbit(int x){
  //printf("%d %d\n", x, 1 << __builtin_ctz(x));
  return 1 << __builtin_ctz(x);
  //return x&-x;
}

int cnt[MAX_S][MAX_S];
void add1(int c[], int pos, int A){
  while (pos <= S){
    c[pos] += A;
    pos += lowbit(pos);
  }
}
void add2(int posX, int posY, int A){
  while (posX <= S){
    add1(cnt[posX], posY, A);
    posX += lowbit(posX);
  }
}
int sum1(int c[], int pos){
  int total = 0;
  while (pos){
    total += c[pos];
    pos -= lowbit(pos);
  }
  return total;
}
int sum2(int posX, int posY){
  int total = 0;
  while (posX){
    total += sum1(cnt[posX], posY);
    posX -= lowbit(posX);
  }
  return total;
}
int TestNum;
int main(){
  int op;
  while (scanf("%d", &op)){
    if (op == 0){
      scanf("%d", &S); S++;
    }else if (op == 1){
      int X, Y, A; scanf("%d %d %d", &X, &Y, &A); X++, Y++;
      add2(X, Y, A);
    }else if (op == 2){
      int L, B, R, T; scanf("%d %d %d %d", &L, &B, &R, &T); L++, B++, R++, T++;
      printf("%d\n", sum2(R, T) - sum2(L - 1, T) - sum2(R, B - 1) + sum2(L - 1, B - 1));
    }else{
      break;
    }
  }
}


