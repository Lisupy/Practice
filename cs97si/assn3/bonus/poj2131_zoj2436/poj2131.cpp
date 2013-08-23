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
const int MAXN = 131073 * 4;

int N, M;
int L[MAXN];
int A[MAXN];
int B[MAXN];
int p[MAXN];
int theMax[MAXN];
int theMin[MAXN];
int lChildCnt[MAXN];

void p_init(){
  for (int i = 0; i < MAXN; i++) p[i] = theMin[i] = theMax[i] = i;
}

int find(int u){
  int root = u, Max = theMax[u], Min = theMin[u];
  while (root != p[root]) root = p[root], Max = max(theMax[root], Max), Min = min(theMin[root], Min);
  theMax[root] = Max; theMin[root] = Min;
  while (u != root) {int v = p[u]; p[u] = root; u = v;}
  return root;
}
int findMax(int u){
  int pu = find(u);
  return theMax[pu];
}
int findMin(int u){
  int pu = find(u);
  return theMin[pu];
}
void join(int u, int v){
  int pu = find(u);
  int pv = find(v);
  int Max = max(findMax(u), findMax(v));
  int Min = min(findMin(u), findMin(v));
  if (pu != pv) p[pu] = pv, theMax[pv] = Max, theMin[pv] = Min;
}

int z = 1;
void tree_init(){
  while (z < M) z *= 2; z *= 2;
  for (int i = z / 2; i < z; i++) lChildCnt[i] = 1;
  for (int i = z / 2 - 1; i > 0; i--){
    lChildCnt[i] += lChildCnt[i * 2];
    lChildCnt[i] += lChildCnt[i * 2 + 1];
  }
  //for(z=1;z<n;z=z<<1);z<<=1;
  //for(int i=z>>1;i<z;++i)a[i]=1;
  //for(int i=(z>>1)-1;i;--i)a[i]=a[i+i]+a[i+i+1];
}
int Remove(int n){
  int r = 1;
  //printf("Remove(%d)\n", n);
  while (r < z){
    //printf("lChildCnt[%d] = %d, %d\n", r, lChildCnt[r], n);
    if (lChildCnt[r] >= n){
      lChildCnt[r]--;
      r = r * 2;
    }else{
      n -= lChildCnt[r];
      r = r * 2 + 1;
    }
  }
  //printf("%d\n", r);
  return r - (z - 1);
}
int TestNum;
int main(){
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; i++) scanf("%d", &L[i]);
  //Step1
  p_init();
  for (int i = 1; i <= N; i++){
    int pos = L[i];
    if (B[pos] != 0) pos = findMax(pos) + 1;
    B[pos] = i;
    if (B[pos - 1] != 0) join(pos, pos - 1);
    if (B[pos + 1] != 0) join(pos, pos + 1);
  }
  //Stpe2
  M = N + M;
  //for (int i = 1; i <= M; i++){
    //printf("%d ", B[i]);
  //}printf("\n");
  tree_init();
  while (B[M] == 0 && M) M--;
  for (int i = 1; i <= M; i++) printf("%2d",    i);printf("\n");
  for (int i = 1; i <= M; i++) printf("%2d", p[i]);printf("\n");
  for (int i = 1; i <= M; i++) printf("%2d", B[i]);printf("\n");
  for (int i = M; i >= 1; i--){
    if (i == M || (B[i] != 0 && B[i + 1] == 0)){
      int j = i; while (B[j] != 0) j--;
      j++; sort(B + j, B + i + 1);
      printf("%d - %d:\n", j, i);
      for (int k = i; k >= j; k--){
        int pos = Remove(L[B[k]]);
        printf("%d , %d\n", k, pos); 
        A[pos] = B[k];
      }
    }
  }
  //Output
  printf("%d\n", M);
  for (int i = 1; i <= M; i++){
    if (i != 1) printf(" ");
    printf("%d", A[i]);
  }printf("\n");
}

