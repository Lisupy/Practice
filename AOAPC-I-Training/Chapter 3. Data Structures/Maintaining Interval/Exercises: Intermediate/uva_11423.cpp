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
const int MAX_R = 10 * 1024 * 1024; 
struct FenwickTree{
  int cnt[MAX_R];
  int lowbit(int x){ return x & -x;}
  void reset(){
    memset(cnt, 0, sizeof(cnt));
  }
  int sum(int pos){
    int total = 0;
    while (pos){
      total += cnt[pos];
      pos -= lowbit(pos);
    }
    return total;
  }
  void add(int pos, int x){ 
    while (pos <= MAX_R){
      cnt[pos] += x; 
      pos += lowbit(pos);
    }
  }
  int queryRange(int from, int to){
    return sum(to) - sum(from - 1);
  }
};
FenwickTree tree;
const int MAX_N = 1 << 24;
int lastVisit[MAX_N];
int lastTick;
int N;
int cacheSz[30];
int missCnt[30];
void reset(){
  tree.reset();
  memset(missCnt, 0, sizeof(missCnt));
  memset(lastVisit, -1, sizeof(lastVisit));
  lastTick = 0;
}
void visit(int x){
  //printf("visit: %d\n", x);
  if (lastVisit[x] == -1){
    for (int i = 0; i < N; i++) missCnt[i]++;
  }else{
    int minNotMissSize = tree.queryRange(lastVisit[x], lastTick);
    //printf("minCacheSize: %d, lastVisit: %d\n", minNotMissSize, lastVisit[x]);
    for (int i = 0; i < N; i++) if (cacheSz[i] < minNotMissSize) missCnt[i]++;
    tree.add(lastVisit[x], -1);
  }
  lastVisit[x] = ++lastTick;
  tree.add(lastVisit[x], 1);
}
int TestNum;
int main(){
  while (scanf("%d", &N) != EOF){
    reset();
    for (int i = 0; i < N; i++) scanf("%d", &cacheSz[i]);
    char cmd[32];
    while (scanf("%s", cmd) && strcmp(cmd, "END")){
      if (!strcmp(cmd, "RANGE")){
        int b, y, n; scanf("%d %d %d", &b, &y, &n);
        for (int i = 0; i < n; i++, b += y) visit(b);
      }else if (!strcmp(cmd, "ADDR")){
        int x;scanf("%d", &x);
        visit(x);
      }else {
        assert(!strcmp(cmd, "STAT"));
        for (int i = 0; i < N; i++){
          if (i != 0) printf(" ");
          printf("%d", missCnt[i]);
        }printf("\n");
        memset(missCnt, 0, sizeof(missCnt));
      }
    }
  }
}


