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
struct Pos{
  int hight;
  int h, w, n;
  void display(){
    printf("height: %d, (%d, %d), %d\n", hight, h, w, n);
  }
};
bool operator<(const Pos &a, const Pos &b){
  return a.hight < b.hight;
}
int grid[512][512];
int h, w, d;
int total = 0;
int father[512 * 512];
int used[512 * 512];
int Max[512 * 512];
int MaxCnt[512 * 512];
Pos ps[512 * 512];
int ps_len;
void init(){
  for (int i = 0; i < ps_len; i++) father[i] = i; 
  for (int i = 0; i < ps_len; i++) used[i] = false;
  for (int i = 0; i < ps_len; i++){
    Max[i] = ps[i].hight;
    MaxCnt[i] = 1;
  }
}
int find(int x){
  return father[x] == x? x: father[x] = find(father[x]);
}

void input(){
  scanf("%d%d%d", &h, &w, &d);
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      scanf("%d", &grid[i][j]);
}
bool valid(int x, int y){
  return 0 <= x && x < h && 0 <= y && y < w;
}
void join(int x, int y, int v){
  int px = find(x);
  int py = find(y);
  if (px != py){
    father[px] = py;
    if (Max[px] == Max[py]){
      MaxCnt[py] += MaxCnt[px];
    }else if (Max[px] > Max[py]){
      if (Max[py] - d < v){
        total -= MaxCnt[py];
      }
      Max[py] = Max[px];
      MaxCnt[py] = MaxCnt[px];
    }else{
      if (Max[px] - d < v){
        total -= MaxCnt[px];
      }
    }
  }
}
int dxs[] = {-1, 1, 0, 0};
int dys[] = { 0, 0, 1, -1};
void solve(){
  total = 0;
  ps_len = 0;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      ps[ps_len++] = {grid[i][j], i, j, i * w + j};
    }
  }
  init();
  sort(ps, ps + ps_len);
  reverse(ps, ps + ps_len);
  for (int i = 0; i < ps_len; i++){
    Pos &p = ps[i];
    //if (p.hight > 0) total++;
    total++;
    used[p.n] = true;
    for (int j = 0; j < 4; j++){
      int dx = dxs[j];
      int dy = dys[j];
      int tx = dx + p.h;
      int ty = dy + p.w;
      int tn = tx * w + ty;
      if (!valid(tx, ty)) continue;
      if (!used[tn]) continue;
      join(tn, p.n, p.hight); 
    }
  }
  cout << total << endl;
}


int TestNum;
int main(){
  scanf("%d", &TestNum);
  while (TestNum--) {
    input();
    solve();
  }
}

