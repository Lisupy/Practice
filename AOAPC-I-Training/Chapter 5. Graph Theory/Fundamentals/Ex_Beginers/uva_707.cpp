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
bool valid[MAXN][MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN];
struct Fact{
  int step;
  int x, y;
};
vector<Fact> facts;
void reset(){
  memset(valid, 0, sizeof(valid));
  memset(visited, 0, sizeof(visited));
  facts.clear();
}
int dx[] = {0, 0, -1, 1, 0};
int dy[] = {1,-1,  0, 0, 0};
int W, H, tmax;
bool dfs(int t, int x, int y){
  if (t > tmax) return true; 
  bool &ans = valid[t][x][y];
  if (visited[t][x][y]) return ans;
  visited[t][x][y] = true;
  for (int i = 0; i < 5; i++){
    int tx = x + dx[i], ty = y + dy[i];
    if (1 <= tx && tx <= H && 1 <= ty && ty <= W){
      if (dfs(t + 1, tx, ty)) ans = true;
    }
  }
  return ans;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (cin >> W >> H >> tmax && W){
    reset();
    int n; cin >> n;
    for (int i = 0; i < n; i++){
      int ti, L, T, R, B;
      cin >> ti >> L >> T >> R >> B;
      for (int x = T; x <= B; x++){
        for (int y = L; y <= R; y++){
          visited[ti][x][y] = true;
        }
      }
    }
    for (int i = 1; i <= tmax; i++){
      for (int x = 1; x <= H; x++){
        for (int y = 1; y <= W; y++){
          if(i == 1){
            if (dfs(i, x, y)) facts.push_back({i, x, y});
          }else{
            if (valid[i][x][y]) facts.push_back({i, x, y});
          }
        }
      }
    }
    //for (auto f: facts){
      //cout << f.step << ": " << f.x << ", " << f.y << endl;
    //}
    vector<Fact> ans;
    for (size_t l = 0, r = 0; l < facts.size(); l = r){
      while (r < facts.size() && facts[l].step == facts[r].step) r++;
      if (r - l == 1)ans.push_back(facts[l]);
    }
    cout << "Robbery #" << ++TestNum << ":" << endl;
    if (facts.size() == 0) cout << "The robber has escaped." << endl;
    else if (ans.size() == 0) cout << "Nothing known." << endl;
    else{
      for (size_t i = 0; i < ans.size(); i++){
        cout << "Time step " << ans[i].step << ": The robber has been at " ;
        cout << ans[i].y << "," << ans[i].x << "." << endl;
      }
    }
    cout << endl;
  }
}
