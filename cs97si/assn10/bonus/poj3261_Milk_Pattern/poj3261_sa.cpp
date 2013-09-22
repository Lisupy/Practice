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
 * decltype // deprecated
 */
const int MAXN = 20 * 1024;
int N, K;
int a[MAXN];
int rnk[MAXN];
int tmp[MAXN];
int sa[MAXN];
int lcp[MAXN];
int k;
bool compare_sa(int i, int j){
  if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
  else{
    int ri = i + k <= N? rnk[i + k] : -1;
    int rj = j + k <= N? rnk[j + k] : -1;
    return ri < rj;
  }
}
void construct_sa(){
  for (int i = 0; i <= N; i++){
    sa[i] = i;
    rnk[i] = i < N ? a[i] : -1;
  }
  for (k = 1; k <= N; k *= 2){
    sort(sa, sa + N + 1, compare_sa);
    //for (int i = 0; i <= N; i++){
      //printf("%d, ", sa[i]);
    //}printf("\n");
    tmp[sa[0]] = 0;
    for (int i = 1; i <= N; i++){
      tmp[sa[i]] = tmp[sa[i - 1]] + compare_sa(sa[i - 1], sa[i]) ;
    } 
    for (int i = 0; i <= N; i++){
      rnk[i] = tmp[i];
    }
  }
  //for (int i = 0; i <= N; i++){
    //printf("%d, ", sa[i]);
  //}printf("\n");
}
void construct_lcp(){
  for (int i = 0; i <= N; i++) rnk[sa[i]] = i;
  int h = 0;
  lcp[0] = 0;
  for (int i = 0; i < N; i++) {
    int j = sa[rnk[i] - 1];
    if (h > 0) h--;
    for (; j + h < N && i + h < N; h++){
      if (a[j + h] != a[i + h]) break;
    }
    lcp[rnk[i] - 1] = h;
  }
  //for ( int i = 0; i <= N; i++){
    //cout << lcp[i] << ", ";
  //}cout << endl;
}

bool isValid(int L){
  for (int l = 0, r = 0; l <= N; l = ++r){
    while (r < N && lcp[r] >= L){
      r++;
    }
    if (r - l + 1 >= K) return true;
  }
  return false;
}

int solve(){
  int lo = 0, hi = N;
  while (lo < hi){
    int mid = (lo + hi + 1) / 2;
    //printf("bserach(%d, %d), %d\n", lo, hi, mid);
    if (isValid(mid)) lo = mid;
    else hi = mid - 1; 
  }
  return lo;
}
int TestNum;
int main(){
  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; i++) scanf("%d", &a[i]);
  //a[N] = -0x1f1f1f1f;
  construct_sa();
  construct_lcp();
  cout << solve() << endl;
}

