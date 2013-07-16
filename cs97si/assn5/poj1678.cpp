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
const int MAXN = 10 * 1024;
int t;
int n, a, b;
int nums[MAXN];
bool max_visited[MAXN];
bool min_visited[MAXN];
int maxs[MAXN];
int mins[MAXN];

int getMax(int m){
  if (max_visited[m] == true){
    return maxs[m];
  }
  max_visited[m] = true;
  maxs[m] = nums[m];
  int next_Max = 0;
  bool found = false;
  for (int i = m + 1; i <= n && nums[i] <= nums[m] + b; i++){
    if (nums[i] < nums[m] + a){
      continue;
    }
    int tmp = getMax(i);
    if (!found || tmp > next_Max){
      next_Max = tmp;
      found = true;
    }
  }
  if (found){
    maxs[m] -= next_Max;
  }
  return maxs[m];
}



int main(){
  scanf("%d", &t);
  while (t--){
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++){
      scanf("%d", &nums[i]);
    }
    sort(nums + 1, nums + n + 1);
    memset(max_visited, 0, sizeof(max_visited));
    memset(min_visited, 0, sizeof(min_visited));
    int ans = -getMax(0);
    cout << ans << endl;
  }
}
