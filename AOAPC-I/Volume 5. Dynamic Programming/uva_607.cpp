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


const int MAXN = 1024;
int n, L, C;
int t[MAXN];
int st[MAXN];
int cost(int from, int to){
  int s = L - (st[to] - st[from - 1]);
  if (s == 0) return 0;
  return s <= 10 ? -C : (s - 10) * (s - 10);
}
int valid(int from, int to){
  //printf("(%d, %d):%d", from, to, st[to] - st[from - 1]);
  return L >= st[to] - st[from - 1];
}
int dp[MAXN][MAXN];

int TestNum;
int main1(){
  while (scanf("%d", &n) && n){
    scanf("%d %d", &L, &C);
    for (int i = 1; i <= n; i++) scanf("%d", t + i);
    partial_sum(t + 1, t + 1 + n, st + 1);
    //for (int i = 1; i <= n; i++) printf("%5d", st[i]); printf("\n");
    memset(dp, 0x1f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
      for (int j = i; j <= n; j++){
        int &target = dp[i][j];
        for (int j1 = j - 1; j1 >= 0; j1--){
          if (!valid(j1 + 1, j)) break;
          if (valid(j1 + 1, j) && dp[i - 1][j1] != 0x1f1f1f1f){
            target = min(target, dp[i - 1][j1] + cost(j1 + 1, j));
          }
        }
        //printf("%10d", target);
      }
      //printf("\n");
      if (dp[i][n] != 0x1f1f1f1f) break;
    }
    int best = 0x1f1f1f1f;
    int pos = -1; 
    for (int i = 1; i <= n; i++){
      if (dp[i][n] < best){
        best = dp[i][n];
        pos = i;
        break;
      }
    }
    if (TestNum) printf("\n");
    printf("Case %d:\n", ++TestNum);
    printf("Minimum number of lectures: %d\n", pos);
    printf("Total dissatisfaction index: %d\n", best);
  }
  return 0;
}    

int costs[MAXN];
int cnts[MAXN];
int main(){
  while (scanf("%d", &n) && n){
    scanf("%d %d", &L, &C);
    for (int i = 1; i <= n; i++) scanf("%d", t + i);
    partial_sum(t + 1, t + 1 + n, st + 1);
    //for (int i = 1; i <= n; i++) printf("%5d", st[i]); printf("\n");
    memset(costs, 0x1f, sizeof(costs));
    memset(cnts, 0, sizeof(cnts));
    costs[0] = 0;
    int s = 0, cnt = 1;
    for (int i = 1; i <= n; i++){
      if (s + t[i] > L){
        s = 0;
        cnt++;
      }
      s += t[i];
      cnts[i] = cnt;
      for (int j = 0; j < i; j++){
        if (valid(j + 1, i) && cnts[j] == cnt - 1){  
          costs[i] = min(costs[i], costs[j] + cost(j + 1, i));
        }
      }
    }

    if (TestNum) printf("\n");
    printf("Case %d:\n", ++TestNum);
    printf("Minimum number of lectures: %d\n", cnt);
    printf("Total dissatisfaction index: %d\n", costs[n]);
  }
}    


