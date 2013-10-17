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

const int sigma_size = 26;
const int maxnode = 128 * 128;
const int MAXN = 1003;
const u64 RMAGIC = 1000 * 1000 * 1000 + 7;
const u64 CMAGIC = 129;
struct Hash{
  u64 hs[MAXN][MAXN]; 
  u64 bs[MAXN][MAXN];
  void init(char a[MAXN][MAXN], int N, int M){
    bs[0][0] = 1;
    for (int i = 1; i <= M; i++) {
      bs[0][i] = bs[0][i - 1] * RMAGIC;
      hs[0][i] = 0;
    }
    for (int i = 1; i <= N; i++){
      bs[i][0] = 1;
      hs[i][0] = 0;
      for (int j = 1; j <= M; j++){
        hs[i][j] = hs[i][j - 1] * RMAGIC + a[i - 1][j - 1];
        //printf("***%d************************\n", a[i - 1][j - 1]);
        bs[i][j] = bs[i][j - 1] * RMAGIC;
      }
      for (int j = 0; j <= M; j++){
        bs[i][j] = bs[i - 1][j] * CMAGIC;
        hs[i][j] += hs[i - 1][j] * CMAGIC;
      }
    }
  }
  Hash(){}
  u64 getHash(int x1, int y1, int x2, int y2){
    return hs[x2][y2] 
         + hs[x1][y1] * bs[x2 - x1][y2 - y1] 
         - hs[x1][y2] * bs[x2 - x1][0]
         - hs[x2][y1] * bs[0][y2 - y1];
  }
};
int N, M, X, Y;
char textMat[MAXN][MAXN];
char patternMat[MAXN][MAXN];
int matchLineCnt[MAXN][MAXN];
Hash hsText;
Hash hsPattern;
int solve(){
  hsText.init(textMat, N, M);
  hsPattern.init(patternMat, X, Y);
  u64 hsTarget = hsPattern.getHash(0, 0, X, Y); 
  int total = 0;
  for (int i = 0; i + X <= N; i++){
    for (int j = 0; j + Y <= M; j++){
      u64 val = hsText.getHash(i, j, i + X, j + Y) ;
      if (val == hsTarget){
        total++;
      }
    }
  }
  return total;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int t; scanf("%d", &t);
  while (t--){
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%s", textMat[i]);
    scanf("%d%d", &X, &Y);
    for (int i = 0; i < X; i++) scanf("%s", patternMat[i]);
    printf("%d\n", solve());
  }
}

