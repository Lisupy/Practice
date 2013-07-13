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

int n;
int a[1024];
int findCloset(int target){
  int l = 0, r = n - 1;
  int closest = a[l] + a[r];
  while (l < r){
    int s = a[l] + a[r];
    if (abs(target - closest) > abs(s - target)){
      closest = s;
    }
    if (s == target) return s;
    if (s > target) r--;
    if (s < target) l++;
  }
  return closest;
}
int TestNum;
int main(){
  while (cin >> n && n){
    printf("Case %d:\n", ++TestNum);
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    sort(a, a + n);
    int m;
    cin >> m;
    while (m--){
      int q;
      cin >> q;
      printf("Closest sum to %d is %d.\n", q, findCloset(q));
    }
  }
}
