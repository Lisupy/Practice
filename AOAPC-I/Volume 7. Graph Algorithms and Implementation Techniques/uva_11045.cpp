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

const int MAXN = 64;
bool mat[64][64];
int f[MAXN];
bool visited[MAXN];
void reset(){
  memset(mat, 0, sizeof(mat));
  memset(f, -1, sizeof(f));
}

string volunters[MAXN][2];
string shirts[MAXN];
int N, M;

string shirts_type[] = {"XXL", "XL", "L", "M" , "S", "XS"};
void input(){
  cin >> N >> M;
  for (int i = 0; i < N; i++){
    shirts[i] = shirts_type[i % 6];
  }
  for (int i = 0; i < M; i++){
    cin >> volunters[i][0] >> volunters[i][1];
  }
  for (int i = 0; i < M; i++){
    for (int j = 0; j < N; j++){ 
      mat[i][j] = (volunters[i][0] == shirts[j]) || (volunters[i][1] == shirts[j]);
      //cout << mat[i][j] << " ";
    }
    //cout << endl;
  }
}

int dfs(int u){
  if (visited[u]) return 0;
  visited[u] = true;
  for (int v = 0; v < N; v++){
    if (mat[u][v]){
      if (f[v] == -1 || dfs(f[v])){
        f[v] = u;
        return 1;
      }
    }
  }
  return 0;
}

void solve(){
  int ans = 0;
  for (int i = 0; i < M; i++){
    memset(visited, 0, sizeof(visited));
    ans += dfs(i);
  }
  //cout << ans << endl;
  if (ans == M){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
int main(){
  int TestNum; cin >> TestNum;
  while (TestNum--){
    reset();
    input();
    solve();
  }
}
