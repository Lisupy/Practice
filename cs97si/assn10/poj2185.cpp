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
int Rcnt[11000];
int Ccnt[11000];
void get_rep(string s, int cnt[]){
  int len = s.size();
  vector<int> nxt(len + 1);
  nxt[0] = -1;
  for(int i = 0; i < len; i++){
    int j = nxt[i];
    while (j >= 0 && s[i] != s[j]){
      j = nxt[j];
    }
    nxt[i + 1] = ++j;
  }
  vector<int> rep(len + 1);
  rep[0] = 1;
  for (int i = 1; i <= len; i++){
    rep[i] = i;
    if (i - nxt[i] == rep[nxt[i]]){
      rep[i] = i - nxt[i];
    }
  }
  int j = len;
  int best = len;
  vector<bool> isValid(len + 1);
  while (j >= 0){
    if (j <= len - j){
      //int t = rep[len - j];
      isValid[len - j] = true;
      best = min(rep[len - j], best);
    }
    j = nxt[j];
  }
  for (int i = 1; i <= len; i++){
    if (isValid[i] || i % best == 0){
      cnt[i]++;
    }
  }
}
int TestNum;
int main(){
  std::ios::sync_with_stdio(false);
  int R, C; cin >> R >> C;
  vector<string> mat(R);
  vector<string> rmat(C, string(R, ' '));
  for (int i = 0; i < R; i++) cin >> mat[i];
  for (int i = 0; i < R; i++){
    for (int j = 0; j < C; j++){
      rmat[j][i] = mat[i][j];
    }
  }
  for (int i = 0; i < R; i++){
    get_rep(mat[i], Rcnt);
  }
  for (int i = 0; i < C; i++){
    get_rep(rmat[i], Ccnt);
  }
  int max_hori = find(Rcnt, Rcnt + C, R) - Rcnt;
  int max_vert = find(Ccnt, Ccnt + R, C) - Ccnt;
  //cout << max_hori << ", " << max_vert << endl;
  cout << max_hori * max_vert << endl;
}

