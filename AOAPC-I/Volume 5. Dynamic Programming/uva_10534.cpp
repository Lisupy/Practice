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
int N;
void Lis(int a[], int n, int lis[]){
  int tmp[n];
  int len = 0;
  for (int i = 0; i < n; i++){
    int pos = lower_bound(tmp, tmp + len, a[i]) - tmp;
    if (len == pos){
      len++;
    }
    tmp[pos] = a[i];
    lis[i] = pos + 1;
  }
}
int nums[MAXN];
int lisi[MAXN];
int lisd[MAXN];
int leng[MAXN];
int main(){
  while (scanf("%d", &N) != EOF){
    for (int i = 0; i < N; i++) scanf("%d", &nums[i]);
    Lis(nums, N, lisi);
    reverse(nums, nums + N);
    Lis(nums, N, lisd);
    reverse(lisd, lisd + N);
    for (int i = 0; i < N; i++) leng[i] = min(lisi[i], lisd[i]) * 2 - 1;
    printf("%d\n", *max_element(leng, leng + N));
  }
}
