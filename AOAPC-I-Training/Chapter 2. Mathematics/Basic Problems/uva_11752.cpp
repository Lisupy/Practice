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

const int MAXN = (1 << 16) + 10;
vector<int> primes;
vector<bool> isPrime(MAXN, true);
void primes_init(){
  for (int n = 2; n < MAXN; n++) {
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

int next_not_prime(int n){
  n++;
  while (isPrime[n] && n <= MAXN){
    n++;
  }
  return n;
}
unsigned long long power(unsigned long long x, unsigned long long p){
  unsigned long long s = 1;
  while (p){
    if (p % 2) s *= x;
    x *= x;
    p /= 2;
  }
  return s;
}
struct Record{
  int  m_x, m_p;
  unsigned long long m_n;
  double m_s;
  Record(int x, int p): m_x(x), m_p(p), m_n(power(x, p)), m_s(pow(x, p)){};
  bool operator<(const Record &b) const{
    return m_s > b.m_s;
  }
};

const double LIMIT = pow(2, 64) - 1;
void gen(){
  priority_queue<Record> Q;
  set<unsigned long long> S;
  Q.push({1, 4});
  while(true){
    Record a = Q.top(); Q.pop();
    if (a.m_s > LIMIT) break;
    if (a.m_n == 0) break;
    if (S.count(a.m_n) == 0){
      cout << a.m_n << endl;
      S.insert(a.m_n);
    }
    Q.push({a.m_x + 1, a.m_p});
    if (a.m_x == 2){
      Q.push({2, next_not_prime(a.m_p)});
    }
  }
}

int main(){
  primes_init();
  gen();
}
