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
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popsolve_count  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
const int MAXN = 50;
const int MAXM = 50*50;
vector<bool> isPrime(MAXN + 1, true);
vector<int> primes;
void primes_init(){
  for (int n = 2; n <= MAXN; n++){
    if (isPrime[n]) primes.push_back(n);
    for (size_t i = 0; i < primes.size(); i++){
      int p = primes[i];
      int s = n * p;
      if (s > MAXN) break;
      isPrime[s] = false;
      if (n % p == 0) break;
    }
  }
}

int minMumCombs[MAXN + 1][MAXM + 1];
void minMumCombs_init(){
  for (int L = 0; L < MAXN; L++){
    for (int i = 0; i <= MAXM; i++){
      minMumCombs[L][i] = i;
    }
    for (int i = 0; i <= MAXM; i++){
      for (int j = 0; j <= L; j++){
        int t = i - j * j;
        if (t >= 0){
          minMumCombs[L][i] = min(minMumCombs[L][i], minMumCombs[L][t] + 1);
        }
      }
    }
  }
}
char grid[MAXN][MAXN];
struct Item{
  int x, y, L;
};
vector<Item> sols[MAXN + 1];
int best = 0;
void display(int L){
  for (int x = 0; x < L; x++){
    for (int y = 0; y < L; y++){
      printf("%3d", grid[x][y]);
    }
    printf("\n");
  }
}
void solve(vector<Item> &ans, vector<Item> &sol, int L, int remain, int xFrom){
  int depth = sol.size();
  if (depth > 1 && sol.back().x == sol.back().y && remain) return;
  int x = -1, y;
  for (x = xFrom; x < L; x++){
    for (y = 0; y < L; y++){
      if (grid[x][y] == 0) goto findOK;
    }
  }
  if ((int)sol.size() < best){
    //display(L);
    best = sol.size();
    ans = sol;
    //cout << sol.size() << endl;
  }
  return;
findOK:
  //display(L);
  if (depth != 0){
    if (minMumCombs[sol[0].L][remain] + depth > best) return ;
    //if (minMumCombs[L - sol[0].L][remain] + depth > best) return ;
  }

  int l = min(L - 1, min(L - x, L - y));
  if (depth != 0) l = min(l, sol[0].L);
  //if (L > 20 && x != y) l = min(l, abs(x - y));
  if (depth == 0) l = (L + 1) / 2;
  for (int i = 0; i <= l; i++){
    if (grid[x][y + i] || grid[x + i][y]){ 
      l = i;
      break;
    }
  }
  for (int i = 0; i < l; i++){
    for (int j = 0; j < l; j++){
      grid[x + i][y + j] = depth + 1;
    }
  }

  sol.push_back({x, y, l});
  bool canSym = true;
  if (x == y) canSym = false;
  //if (x + l == L || y + l == L) canSym = true;
  if (L < 20) canSym = false;
  if (canSym){
    swap(x, y);
    for (int i = 0; i < l; i++){
      for (int j = 0; j < l; j++){
        if (grid[x + i][y + j]) canSym = false;
      }
    }
    swap(x, y);
  }
  if (canSym){
    swap(x, y);
    for (int i = 0; i < l; i++){
      for (int j = 0; j < l; j++){
        assert(grid[x + i][y + j] == 0);
        grid[x + i][y + j] = depth + 1;
      }
    }
    sol.push_back({x, y, l});
    swap(x, y);
  }

  while (l >= 1){
    solve(ans, sol, L, remain - l * l * (canSym?2:1), x);
    if (depth == 0 && l * 2 < L)  break; 
    //=================
    //if (x == y || (y + l == L && x == 0) || (x + l == L && y == 0)) {
    if (x == y || ((y + l == L || x + l == L) && canSym) ) {
      for (int i = 0; i < l; i++){
        for (int j = 0; j < l; j++){
          grid[x + i][y + j] = 0;
        }
      }
      if (canSym){
        swap(x, y);
        for (int i = 0; i < l; i++){
          for (int j = 0; j < l; j++){
            grid[x + i][y + j] = 0;
          }
        }
        swap(x, y);
      }
      break;
    }
    //===============
    for (int i = 0; i < l; i++){
      grid[x + i][y + l - 1] = 0;
      grid[x + l - 1][y + i] = 0;
    }
    grid[x + l - 1][y + l - 1] = 0;
    if (canSym){
      swap(x, y);
      for (int i = 0; i < l; i++){
        grid[x + i][y + l - 1] = 0;
        grid[x + l - 1][y + i] = 0;
      }
      grid[x + l - 1][y + l - 1] = 0;
      swap(x, y);
    }
    l--;
    sol.back().L = l;
    if (canSym){
      sol[sol.size() - 2].L = l;
    }
  }

  sol.pop_back();
  if (canSym){
    sol.pop_back();
  }
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  primes_init();
  minMumCombs_init();
  //for (size_t i = 0; i < primes.size(); i++){
    //int p = primes[i]; 
    ////if (p > 13) break;
    //best = p * p + 1;
    //vector<Item> tmp;
    //memset(grid, 0, sizeof(grid));
    //solve(sols[p], tmp, p, p * p);
    //cout << p << ": " << sols[p].size() << endl;
  //}
  cin >> TestNum;
  while (TestNum--){
    int N; cin >> N;
    for (size_t i = 0; i < primes.size(); i++){
      int p = primes[i];
      if (N % p == 0){
        if (sols[p].size() == 0){
          best = p * p + 1;
          vector<Item> tmp;
          memset(grid, 0, sizeof(grid));
          solve(sols[p], tmp, p, p * p, 0);
          //cout << p << ": " << sols[p].size() << endl;
        }
        int m = N / p;
        cout << sols[p].size() << endl;
        for (size_t j = 0; j < sols[p].size(); j++){
          Item it = sols[p][j];
          cout << it.x * m + 1<< " " << it.y * m + 1<< " " << it.L * m << endl;
        }
        break;
      }
    }
  }
}


