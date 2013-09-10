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
 * (1 << (31 - __builtin_clz(100) ) == 64;
 */

int n;
int giftNum[5];
double a[16][5];
void input(){
  cin >> n;
  for (int i = 0; i < 5; i++) cin >> giftNum[i];
  for (int i = 0; i < n; i++) {
    double total = 0;
    for (int j = 0; j < 5; j++){
      cin >> a[i][j];
      if (giftNum[j] == 0) a[i][j] = 0;
      total += a[i][j];
    }
    for (int j = 0; j < 5; j++){
      a[i][j] /= total;
      cout << a[i][j] << ", ";
    }
    cout << endl;
  }
}
int lowbit(int x) { return x & -x; }
double p[5];
double p1[5];
double p2[5];
double p3[5];
void solve(){
  for (int i = 0; i < 5; i++){
    p1[i] = 0;
    p2[i] = 0;
    for (int comb = 0; comb < (1 << n); comb++) if (__builtin_popcount(comb) == giftNum[i]){
      double t = 1;
      for (int j = 0; j < n; j++){
        if ((1 << j) & comb) t *= a[j][i];
        else t *= (1 - a[j][i]);
      }
      if (comb & 1) p1[i] += t;
      else p2[i] += t;
    }
  }
  double total1 = 0;
  for (int i = 0; i < 5; i++){
    p3[i] = p1[i] + p2[i];
    total1 += p1[i];
    p[i] = p1[i] / (p3[i]) / giftNum[i];
  }
  cout << total1 << endl;
  double total = 0;
  for (int i = 0; i < 5; i++){
    p[i] = p[i] * p1[i] / total1;
    total += p[i];
  }
  cout << total << endl;
  for (int i = 0; i < 5; i++){
    cout << i << ": " << p1[i] << ", " << p2[i] << ", " << p[i] << endl;
  }
  int best_i = -1;
  for (int i = 0; i < 5; i++){
    if (giftNum[i] && (best_i == -1 || p[i] > p[best_i])) {
      best_i = i;
    }
  }
  printf("%d %.03lf\n", best_i + 1, p[best_i]);
}

int TestNum;
int main(){
  cin >> TestNum;
  while (TestNum--) {
    input();
    solve();
  }

}

