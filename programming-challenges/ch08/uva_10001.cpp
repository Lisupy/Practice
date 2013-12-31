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
int code;
int N;
int tran[2][2][2];
int target[64];
int source[64];
int TestNum;

bool dfs(int pos){
  if (pos == N){
    return tran[source[N - 2]][source[N - 1]][source[N]] == target[N - 1] &&
          tran[source[N - 1]][source[N]][source[N + 1]] == target[N];
  }
  for (source[pos] = 0; source[pos] <= 1; source[pos]++){
    if (tran[source[pos - 2]][source[pos - 1]][source[pos]] == target[pos - 1]){
      if (dfs(pos + 1)){
        return true;
      }
    }
  }
  return false;
}
bool isReacheable(){
  for (source[0] = 0; source[0] <= 1; source[0]++){
    for ( source[1] = 0; source[1] <= 1; source[1]++){
      source[N] = source[0];
      source[N + 1] = source[1];
      if (dfs(2)) return true;
    }
  }
  return false;
}
int main(){
  ios_base::sync_with_stdio(false); 
  string s;
  while (cin >> code >> N >> s){
    for (int i = 1; i <= N; i++) target[i] = s[i - 1] - '0';
    for (int i = 0; i < 8; i++){
      tran[(i>>2)&1][(i>>1)&1][i&1] = (code >> i) & 1;
    }
    if (isReacheable()){
      cout << "REACHABLE" << endl;
    }else{
      cout << "GARDEN OF EDEN" << endl;
    }
  }
}

