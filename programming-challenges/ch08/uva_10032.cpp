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
const double PI = acos(-1);
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
const int MAXN = 100;
const int MAXM = 50 * 450 + 1;
bool valid[MAXN][MAXM];
int N;
int weight[MAXN];
int totalWeight;
void reset(){
  memset(valid, 0, sizeof(valid));
  valid[0][0] = true;
}

int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  cin >> TestNum;
  while (TestNum--){
    reset();
    cin >> N;
    for (int i = 0; i < N; i++) cin >> weight[i];
    totalWeight = accumulate(weight, weight + N, 0);

    for (int i = 0; i < N; i++){
      int w = weight[i];
      for (int n = min(i + 1, N / 2 + 1); n >= 1; n--){
        for (int j = totalWeight / 2; j >= 0; j--){
          if (j - w >= 0 && valid[n - 1][j - w]) valid[n][j] = true;
        }
      }
    }
    int lowAns = 0, highAns = totalWeight;
    for (int M = N / 2; M <= (N + 1) / 2; M++){
      for (int i = 0; i <= totalWeight; i++){
        if (valid[M][i]){
          int li = i, hi = totalWeight - i;
          if (li > hi) swap(li, hi);
          if (highAns - lowAns > hi - li){
            lowAns = li, highAns = hi;
          }
        }
      }
    }
    cout << lowAns << " " << highAns << endl;
    if (TestNum) cout << endl;
  }
}

