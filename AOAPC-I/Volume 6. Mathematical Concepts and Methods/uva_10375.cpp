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
 * sizeof CLOCKS_PER_SEC
 */
const int MAXN = 10 * 1024;
double factor[MAXN];
vector<int> primes;
void primes_init(){
  vector<bool> isPrime(MAXN, true);
  for (int n = 2; n < MAXN; n++){
    if (isPrime[n]) primes.push_back(n);
    for (size_t i = 0; i < primes.size(); i++) {
      int p = primes[i];
      int s = n * p;
      if (s >= MAXN) break;
      isPrime[s] = false;
      if (n % p == 0) break;
    }
  }
}

void factor_init(){
  factor[0] = 1;
  for (int i = 1; i < MAXN; i++) factor[i] = factor[i - 1] * i;
}
double C(int n, int k){
  return factor[n] / factor[k] / factor[n - k];
}
void __incCount(vector<int> &cnt, int n, char op){
  for (size_t i = 0; i < primes.size() && n != 1; i++) {
    int p = primes[i];
    while (n % p == 0){
      n /= p;
      if (op == '+') cnt[i]++;
      else cnt[i]--;
    }
  }
}

void incCount(vector<int> &cnt, int n, char op){
  for (int i = 1; i <= n; i++){
    __incCount(cnt, i, op);
  }
}

double calc(vector<int> &cnt){
  double anss = 1;
  for (size_t i = 0; i < primes.size(); i++) {
    int p = primes[i];
    while (cnt[i] > 0){
      anss *= p;
      cnt[i]--;
    }
    while (cnt[i] < 0){
      anss /= p;
      cnt[i]++;
    }
  }
  return anss;
}
//void p_vector(string info, vector<int> a){
  //cout << info << ": ";
  //for (auto i : a) cout << i << " " ; cout << endl;
//}
int main(){
  primes_init();
  factor_init();
  int p, q, r, s;
  while (cin >> p >> q >> r >> s){
    vector<int> cnt(primes.size());
    incCount(cnt, p, '+');
    //p_vector("p", cnt);
    incCount(cnt, q, '-');
    incCount(cnt, p - q, '-');
    incCount(cnt, r, '-');
    incCount(cnt, r - s, '+');
    incCount(cnt, s, '+');
    double ans = calc(cnt);
    printf("%.05lf\n", ans);
  }
}
