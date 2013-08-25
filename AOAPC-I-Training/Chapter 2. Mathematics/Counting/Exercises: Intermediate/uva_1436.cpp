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
 */
const i64 MAXN = 512 * 1024;
//vector<bool> isPrime(MAXN, true);
//vector<int> primesID(MAXN);
//vector<int> primes;
bool isPrime[MAXN];
int primesID[MAXN];
int primes[MAXN];
size_t primesNum;
void primes_init(){
  isPrime[1] = false;
  for (int i = 2; i < MAXN; i++) isPrime[i] = true;
  for (int i = 2; i < MAXN; i++){
    if (isPrime[i]) primesID[i] = primesNum, primes[primesNum++] = i;
    for (size_t j = 0; j < primesNum; j++) {
      i64 p = primes[j];
      i64 s = i * p;
      if (s >= MAXN) break;
      isPrime[s] = false;
      if (i % p == 0) break; 
    }
  }
  //for (auto i : primes) cout << i << ", " ; cout << endl;
  //cout << primesNum << endl;
}
i64 powMod(i64 x, i64 p, i64 m){
  i64 total = 1;
  while (p){
    if (p % 2) total = (total * x) % m;
    x = (x * x) % m;
    p /= 2;
  }
  return total;
}
int p[MAXN];
int childCnt[MAXN];
int inDegree[MAXN];
int factor[MAXN];
void reset(){
  memset(p, 0, sizeof(p));
  memset(childCnt, 0, sizeof(childCnt));
  memset(inDegree, 0, sizeof(inDegree));
  memset(factor, 0, sizeof(factor));
}

template<class T> inline void readint(T& x) 
{ 
  char c; 
  int mul = 1; 
  while((c = getchar()) != EOF) 
  { 
    if(c == '-')mul = -1; 
    if(c >= '0' && c <= '9') 
    { 
      x = c-'0'; 
      break; 
    } 
  } 
  if(c == EOF){x = EOF;return;} 
  while(c = getchar()) 
  { 
    if(c >= '0' && c <= '9') 
    { 
      x = (x<<1)+(x<<3)+(c-'0'); 
    } 
    else break; 
  } 
  x *= mul; 
} 

int n, m;
int TestNum;
//HDU 2974 AC
int main(){
  return 0;
  primes_init();
  int t; 
  //cin >> t;
  scanf("%d", &t);
  while (t--) {
    //reset();
    //cin >> n >> m;
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; i++) {
      scanf("%d", &p[i]);
      inDegree[p[i]]++;
    }
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
      childCnt[i] = 1;
      if (inDegree[i] == 0){
        Q.push(i);
      }
    }
    while (!Q.empty()) {
      int s = Q.front(); Q.pop();
      childCnt[p[s]] += childCnt[s];
      inDegree[p[s]]--;
      if (inDegree[p[s]] == 0){
        Q.push(p[s]);
      }
    }
    for (int i = 2; i <= n; i++){
      int k = i;
      for (size_t j = 0; j < primesNum && k != 1; j++){
        int pr = primes[j];
        while(k % pr == 0){
          k /= pr;
          factor[j]++;
        }
        if (isPrime[k]){
          factor[primesID[k]]++;
          break;
        }
      }
    }
    for (int i = 1; i <= n; i++){
      int k = childCnt[i];
      for (size_t j = 0; j < primesNum && k != 1; j++){
        int pr = primes[j];
        while(k % pr == 0){
          k /= pr;
          factor[j]--;
        }
        if (isPrime[k]){
          factor[primesID[k]]--;
          break;
        }
      }
    }
    i64 total = 1;
    for (size_t i = 0; i < primesNum; i++) {
      int pr = primes[i];
      //printf("%d: %d\n", pr, factor[i]);
      total = (total * powMod(pr, factor[i], m)) % m;
      factor[i] = 0;
    }
    printf("%lld\n", total); 
    //cout << total << endl;
    //printf("%d %d: %lld\n", n, m, total);
  }
}


