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
 * sizeof
 */
int N, S;
char path[64][64][512];
long long  cnt[64][64][512];
int  a[64][64];
int input(){
  memset(a, 0x1f, sizeof(a));
  cin >> N >> S;
  for (int i = 1; i <= N; i++){
    for (int j = i; j <= N; j++){
      cin >> a[i][j];
    }
  }
  for (int i = N + 1; i <= 2 * N - 1; i++){
    for (int j = N; j <= i; j++){
      cin >> a[i][j];
    }
  }
  return N;
}

void gao(){
  memset(cnt, 0, sizeof(cnt));
  memset(path, 0, sizeof(path));
  for (int i = N; i <= 2 * N - 1; i++){
    cnt[2 * N - 1][i][a[2 * N - 1][i]] = 1;
  }
  for (int i = 2 * N - 2; i >= 1; i--){
    for (int j = 0; j <= 2 * N; j++){
      for (int k = 0; k <= 500; k++){
        int last = k - a[i][j];
        if (last >= 0){
          if (cnt[i + 1][j + 1][last]){
            path[i][j][k] = 'R';
            cnt[i][j][k] += cnt[i + 1][j + 1][last];
          }
          if (cnt[i + 1][j][last]){
            path[i][j][k] = 'L';
            cnt[i][j][k] += cnt[i + 1][j][last];
          }
        }
      }
    }
  }
  long long total = 0;
  for (int i = 0; i <= 2 * N; i++) total += cnt[1][i][S];
  cout << total << endl;
  int pos = -1;
  for (int i = 0; i <= 2 * N && pos == -1; i++) if (cnt[1][i][S]) pos = i;
  if (pos != - 1){
    cout << pos - 1 << " ";
    for (int i = 1; i < 2 * N - 1; i++){
      cout << path[i][pos][S];
      if (path[i][pos][S] == 'R'){ S -= a[i][pos]; pos++;}
      else{S -= a[i][pos];}

    }
  }
  cout << endl;
}

int main(){
  while (input()){
    gao();
  }
}





