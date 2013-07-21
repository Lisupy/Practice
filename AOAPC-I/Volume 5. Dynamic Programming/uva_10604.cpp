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
int TestNum;
const int INF = 0x1f1f1f1f;
int cache[11][11][11][11][11][11];
bool visited[11][11][11][11][11][11];
int rtTable[7][7];
int heatTable[7][7];
int m;
int k;
int holds[7];
int& cacheGet(int s[7]){
  return cache[s[1]][s[2]][s[3]][s[4]][s[5]][s[6]];
}
bool& visitedGet(int s[7]){
  return visited[s[1]][s[2]][s[3]][s[4]][s[5]][s[6]];
}
int dfs(int status[7], int total){
  if (total <= 1) return 0;
  int &res = cacheGet(status); 
  if (visitedGet(status)) return res;
  visitedGet(status) = true;
  res = INF;
  for (int i = 1; i <= m; i++){
    for (int j = 1; j <= m; j++){
      if (i == j && status[i] < 2) continue;
      if (status[i] && status[j]){
        int rt = rtTable[i][j];
        int heat = heatTable[i][j];
        status[i]--, status[j]--, status[rt]++;
        res = min(res, dfs(status, total - 1) + heat);
        status[i]++, status[j]++, status[rt]--;
      }
    }
  }
  return res;
}

int main(){
  cin >> TestNum;
  while (TestNum--){
    cin >> m;
    for (int i = 1; i <= m; i++){
      for (int j = 1; j <= m; j++){
        cin >> rtTable[i][j] >> heatTable[i][j];
      }
    }
    cin >> k;
    memset(holds, 0, sizeof(holds));
    for (int i = 1; i <= k; i++){
      int tmp; 
      cin >> tmp;
      holds[tmp]++;
    }
    memset(visited, 0, sizeof(visited));
    int ans = dfs(holds, k);
    cout << ans << endl;
    string s;
    cin >> s;
  }
}
