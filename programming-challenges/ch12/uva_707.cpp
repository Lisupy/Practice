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
const int MAXN = 128;
bool available[MAXN][MAXN][MAXN];
bool available1[MAXN][MAXN][MAXN];
bool available2[MAXN][MAXN][MAXN];
int W, H, T;
void reset(){
  memset(available, 0, sizeof(available));
  for (int t = 1; t <= T; t++){
    for (int x = 1; x <= W; x++){
      for (int y = 1; y <= H; y++){
        available[t][x][y] = true;
      }
    }
  }
}
int dx[] = {0, 0, 1, -1, 0};
int dy[] = {1,-1, 0,  0, 0};
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (cin >> W >> H >> T && W){
    cout << "Robbery #" << ++TestNum << ":" << endl; 
    reset();
    int n; cin >> n;
    while (n--){
      int t, L, T1, R, B; cin >> t >> L >> T1 >> R >> B;
      for (int i = L; i <= R; i++){
        for (int j = T1; j <= B; j++){
          available[t][i][j] = false;
        }
      }
    }
    memcpy(available1, available, sizeof(available));
    for (int t = 2; t <= T; t++){
      for (int x = 1; x <= W; x++){
        for (int y = 1; y <= H; y++){
          if (available1[t][x][y]){
            available1[t][x][y] = false;
            for (int i = 0; i < 5; i++){
              int nx = x + dx[i], ny = y + dy[i];
              if (available1[t - 1][nx][ny]) available1[t][x][y] = true;
            }
          }
        }
      }
    }
    memcpy(available2, available1, sizeof(available));
    for (int t = T - 1; t >= 1; t--){
      for (int x = 1; x <= W; x++){
        for (int y = 1; y <= H; y++){
          if (available2[t][x][y]){
            available2[t][x][y] = false;
            for (int i = 0; i < 5; i++){
              int nx = x + dx[i], ny = y + dy[i];
              if (available2[t + 1][nx][ny]) available2[t][x][y] = true;
            }
          }
        }
      }
    }
    bool NothingKnown = true;
    for (int t = 1; t <= T; t++){
      vector<int> xs, ys;
      for (int x = 1; x <= W; x++){
        for (int y = 1; y <= H; y++){
          if (available2[t][x][y]) xs.push_back(x), ys.push_back(y);
        }
      }
      if (xs.size() == 0){
        NothingKnown = false;
        cout << "The robber has escaped." << endl;
        break;
      }

      if (xs.size() == 1){
        NothingKnown = false;
        for (size_t i = 0; i < xs.size(); i++){
          cout << "Time step " << t << ": The robber has been at " << xs[i] << "," << ys[i] << "." << endl;
        }
      }
    }
    if (NothingKnown) cout << "Nothing known." << endl;
    if (TestNum) cout << endl;
  }
}

