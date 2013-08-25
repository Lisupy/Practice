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

const int MAX_N = 50 * 1024;

int N;
int M;
int a[MAX_N];
int block[MAX_N];
int sqN;
int TestNum;

int BlockId(int idx){
  return idx / sqN * sqN;
}

int count_less_than(int from, int to, int val){
  int begin = from / sqN * sqN + sqN;
  int end = to / sqN * sqN;
  int total = 0;
  for (int i = from; i < begin; i++)
    total += a[i] < val;

  for (int i = begin; i < end; i += sqN)
    total += upper_bound(block + i, block + i + sqN, val - 1) - (block + i);

  for (int i = end; i <= to; i++)
    total += a[i] < val;
  return total;
}

int query(int from, int to, int kth){
  int l = 0, r = 1000*1000*1000; //[l, r)
  while (r - l > 1){
    int mid = (l + r) / 2;
    int total = count_less_than(from, to, mid);
    if (total <= kth) l = mid;
    else r = mid;
  }
  return l;
}

void update(int idx, int val){
  a[idx] = val;
  int begin = idx / sqN * sqN;
  int end = min(N, idx / sqN * sqN + sqN);
  copy(a + begin, a + end, block + begin);
  sort(block + begin, block + end);
}

void solve(){
  scanf("%d %d", &N, &M);
  sqN = sqrt(N);
  for (int i = 0; i < N; i++) scanf("%d", &a[i]);
  copy(a, a + N, block);
  for (int i = 0; i < N; i += sqN) sort(block + i, block + min(i + sqN, N));
  //for (int i = 0; i < N; i++) printf("%2d", block[i]); printf("\n");
    
  while (M--){
    char cmd[32];
    scanf("%s", cmd);
    if (cmd[0] == 'Q'){
      int from, to, kth; scanf("%d %d %d", &from, &to, &kth);
      printf("%d\n", query(from - 1, to - 1, kth - 1));
    }else{
      int idx, val; scanf("%d %d", &idx, &val);
      update(idx - 1, val);
    }
  }
}

int main(){
  scanf("%d", &TestNum);
  while (TestNum--) {
    solve();
  }

}

