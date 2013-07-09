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

struct Order{
  int start, dest, num;
  int earning;
};

Order orders[32];
int cnt[32];
int n, numCity, numOrders;

static inline
bool isValid(int mask){
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < numOrders; i++){
    if ((1 << i) & mask){
      cnt[orders[i].start] += orders[i].num;
      cnt[orders[i].dest] -= orders[i].num;
    }
  }
  int s = 0;
  for (int i = 0; i <= numCity; i++){
    s += cnt[i];
    if (s > n){
      return false;
    }
  }
  return true;
}


int best;

bool tryAndSet(int idx){
  Order &o = orders[idx];
  for (int i = o.start; i < o.dest; i++){
    if (cnt[i] + o.num > n){
      return false;
    }
  }
  for (int i = o.start; i < o.dest; i++){
    cnt[i] += o.num;
  }
  return true;
}

void unset(int idx){
  Order &o = orders[idx];
  for (int i = o.start; i < o.dest; i++){
    cnt[i] -= o.num; 
  }
}
void dfs(int cur, int earning){
  if (cur == numOrders){
    best = max(best, earning);
  }else{
    dfs(cur + 1, earning);
    if (tryAndSet(cur)){
      dfs(cur + 1, earning + orders[cur].earning);
      unset(cur);
    }
  }
}

int main(){
  while (scanf("%d %d %d", &n, &numCity, &numOrders) && n){
    for (int i = 0; i < numOrders; i++){
      scanf("%d %d %d", &orders[i].start, &orders[i].dest, &orders[i].num);
      orders[i].earning = (orders[i].dest - orders[i].start ) * orders[i].num;
    }
    best = 0;
    dfs(0, 0);
    printf("%d\n", best);
  }
}
