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

const int MAXN = 128 * 128;
int N;
struct Pos{
  int x, y;
  int idx;
};
Pos ps[MAXN];
int S;
int avenue[128];
int cntY[128][128];
int A;
int dp[128][128];
int path[128][128];
int costs[128][128];
int cost(int from, int to){
  int total = 0;
  for (int i = 0; i < S; i++){
    if (cntY[i][to] - cntY[i][from - 1] > 0){
      total++;
    }
  }
  return total;
}
int main(){
  while (cin >> N && N >= 0){
    for (int i = 0; i < N; i++){
      cin >> ps[i].x >> ps[i].y;
      //swap(ps[i].y, ps[i].x);
    }
    cin >> S;
    for (int i = 0; i < S; i++){
      cin >> avenue[i];
    }
    cin >> A;
    memset(cntY, 0, sizeof(cntY));
    for (int i = 0; i < N; i++){
      ps[i].idx = upper_bound(avenue, avenue + S, ps[i].x) - avenue;
      cntY[ps[i].idx][ps[i].y]++;
    }
    for (int i = 0; i < S; i++) partial_sum(cntY[i], cntY[i] + 128, cntY[i]);
    for (int i = 0; i <= 100; i++){
      for (int j = 0; j <= 100; j++){
        costs[i][j] = cost(i, j);
      }
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 100; i++){
      dp[0][i] = costs[1][i];
    }
    for (int a = 1; a <= A - 2; a++){
      for (int i = 1; i <= 101; i++){
        int &target = dp[a][i];
        target = -1;
        for (int j = i - 1; j >= 0; j--){
          int s = dp[a - 1][j] + costs[j + 1][i];
          if (s > target){
            target = s;
            path[a][i] = j;
          }
        }
      }
    }
    vector<int> ans;
    int pos = 99;
    ans.push_back(100);
    for (int a = A - 2; a >= 1; a--){
      ans.push_back(path[a][pos] + 1);
      pos = path[a][pos];
    }
    ans.push_back(1);
    sort(ans.begin(), ans.end());
    cout << ans.size();
    for (size_t i = 0; i < ans.size(); i++){
      cout << " " << ans[i];
    }printf("\n");
  }
}


