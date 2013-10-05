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
struct AC{
  //vector<int> val[maxnode]; 
  int val[maxnode][128];
  int valsz[maxnode];
  int ch[maxnode][sigma_size];
  int f[maxnode];
  int sz;
  void reset(){
    //for (int i = 0; i< maxnode; i++) val[i].clear();
    memset(valsz, 0, sizeof(valsz));
    memset(ch, 0, sizeof(ch));
    memset(f,  0, sizeof(f));
    sz = 1;
  }
  AC(): sz(0){
    reset();
  }
  int idx(char c){
    //if (islower(c)) return c - 'a';
    //else return c - 'A' + 26;
    assert(islower(c));
    return c - 'a';
  }
  int newNode(){ assert(sz < maxnode); return sz++;}
  void insert(const char *s, int v = 1, int len = 0){
    if (len == 0) len = strlen(s); 
    int u = 0;
    for (int i = 0; i < len; i++){
      int c = idx(s[i]);
      if (ch[u][c] == 0) ch[u][c] = newNode();
      u = ch[u][c];
    }
    //val[u].push_back(v);
    val[u][valsz[u]++] = v;
    //assert(val[u].size() <= 1);
  }
  void getFail(){
    queue<int> Q;
    for (int i = 0; i < sigma_size; i++){
      int v = ch[0][i];
      if (v != 0) Q.push(v);
    }
    while (!Q.empty()){
      int r = Q.front(); Q.pop();
      for (int c = 0; c < sigma_size; c++){
        int u = ch[r][c];
        if (!u){
          ch[r][c] = ch[f[r]][c];
          continue;
        }
        Q.push(u);
        int v = f[r]; 
        while (v && !ch[v][c]) v = f[v];
        f[u] = ch[v][c];
      }
    }
  }
};
AC ac;
int N, M, X, Y;
char textMat[1024][1024];
char patternMat[1024][1024];
int matchLineCnt[1024][1024];

int solve(){
  memset(matchLineCnt, 0, sizeof(matchLineCnt));
  ac.reset();
  for (int i = 0; i < X; i++) ac.insert(patternMat[i], i, Y);
  //ac.getFail();
  for (int i = 0; i < N; i++){
    int u = 0;
    for (int j = 0; j < M; j++){
      int c = ac.idx(textMat[i][j]);
      u = ac.ch[u][c];
      for (int k = 0; k < ac.valsz[u]; k++){
        int ln = ac.val[u][k];
        if (i - ln >= 0 && j + 1 - Y >= 0){
          matchLineCnt[i - ln][j + 1 - Y]++;
        }
      }
    }
  }
  int total = 0;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      if (matchLineCnt[i][j] == X) total++;
      //printf("%2d", matchLineCnt[i][j]);
    }
    //printf("\n");
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

