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
const int MAXN = 256;
const int MAXK = 32;
int n, k;
int d[MAXN];
int sd[MAXN];
int dp[MAXN][MAXK];
int path[MAXN][MAXK];

int sum(int from, int to){
  return sd[to] - sd[from - 1];
}

int cost(int from, int to){
  int mid = (from + to) / 2;
  int s1 = d[mid] * (mid - from + 1) - sum(from, mid);
  int s2 = sum(mid, to) - d[mid] * (to - mid + 1);
  //printf("%d %d: %d %d\n", from, to, s1 , s2);
  return s1 + s2;
}
int TestNum;
int main(){
  while (cin >> n >> k && n){
    for (int i = 1; i <= n; i++) cin >> d[i];
    partial_sum(d + 1, d + 1 + n, sd + 1);
    //for (int i = 1; i <= n; i++) cout <<  sd[i] << " "; cout << endl;
    memset(dp, 0x1f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
      for(int j = 1; j <= k; j++){
        int &s = dp[i][j];
        for (int l = 0; l < i; l++){
          int c = dp[l][j - 1] + cost(l + 1, i);
          if (c < s){
            s = c;
            path[i][j] = l;
          }
        }
      }
    }
    
    vector<int> ans;
    //ans.push_back(n);
    int pos = n;
    ans.push_back(pos);
    for (int i = k; i > 0; i--){
      pos =  path[pos][i];
      ans.push_back(pos);
    }
    reverse(ans.begin(), ans.end());
    printf("Chain %d\n", ++TestNum); 
    int total = 0;
    for (size_t i = 1; i < ans.size(); i++){
      if (ans[i] != ans[i - 1] + 1){
        total += cost(ans[i - 1] + 1, ans[i]);
        printf("Depot %lu at restaurant %d serves restaurants %d to %d\n", 
          i, (ans[i - 1] + 1 + ans[i]) / 2, ans[i - 1] + 1, ans[i]); 
      }else{
        printf("Depot %lu at restaurant %d serves restaurant %d\n", i,  ans[i], ans[i]);
      }
    }
    assert(total == dp[n][k]);
    printf("Total distance sum = %d\n", dp[n][k]);
    printf("\n");
  }
}

