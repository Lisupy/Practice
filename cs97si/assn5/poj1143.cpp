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
const int MAXN = 20;
const int MAXM = 1 << MAXN;
bool cache[MAXM];
bool visited[MAXM];
int n;
int a[MAXN];
bool check(int mask, int k, int t){
  k -= t;
  while (k > 1){
    int pos = find(a, a + n, k) - a;
    if (pos == n || ((1 << pos) & mask) == 0){
      return true;
    }
    k -= t;
  }
  return false;
}
int gaoMask(int mask, int t, int pos){
  //printf("%d %d %d\n", mask, t, pos);
  mask ^= 1 << pos;
  for (int i = 0; i < n; i++){
    if ((1 << i ) & mask){
      if (check(mask, a[i], t)){
        mask ^= 1 << i;
      }
    }
  }
  //printf("%d\n", mask);
  return mask;
}

bool win(int mask){
  if (visited[mask]){
    return cache[mask];
  }
  visited[mask] = true;
  bool &res = cache[mask];
  if (mask == 0){
    return res = false;
  }
  for (int i = 0; i < n; i++){
    if ((1 << i) & mask){
      if (!win(gaoMask(mask, a[i], i))){
        return res = true;
      }
    }
  }
  return res = false;
}


int main(){
  int TestNum = 0;
  while (scanf("%d", &n) && n){
    printf("Test Case #%d\n", ++TestNum);

    for (int i = 0; i < n; i++){
      scanf("%d", &a[i]);
    }
    vector<int> ans;
    memset(cache, 0, sizeof(cache));
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++){
      if (!win(gaoMask((1<<n) - 1, a[i], i))){
        ans.push_back(a[i]);
      }
    }
    if (ans.size() == 0){
      printf("There's no winning move.\n");
    }else{
      printf("The winning moves are:");
      for (size_t i = 0; i < ans.size(); i++){
        printf(" %d", ans[i]);
      }
      printf("\n");
    }
    printf("\n");
  }
}
