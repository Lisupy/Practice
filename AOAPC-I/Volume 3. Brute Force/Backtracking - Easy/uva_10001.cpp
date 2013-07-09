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
int N;
int trans[2][2][2];
string target;
bool dfs(int cur, string s){
  if (cur == N){
    return(target[0] - '0' == trans[s[N - 1] - '0'][s[0] - '0'][s[1] - '0'])
      && (target[cur-1] - '0' == trans[s[N - 2] - '0'][s[N - 1] - '0'][s[0] - '0']);
  }else{
    for (s[cur] = '0'; s[cur] <= '1'; s[cur]++){
      if (trans[s[cur - 2] - '0'][s[cur - 1] - '0'][s[cur] - '0'] == target[cur - 1] - '0' && 
        dfs(cur + 1, s)){
        return true;
      }
    }
  }
  return false;
}
int main(){
  unsigned key;
  while (cin >> key >> N >> target){
    for (int i = 0; i < 8; i++){
      trans[i>>2][(i>>1)&1][i & 1] = (key >> i) & 1;
    }
    string source(N, '1');
    bool valid = false;
    for (source[0] = '0'; source[0] <= '1' && !valid; source[0]++){
      for (source[1] = '0'; source[1] <= '1' && !valid; source[1]++){
        if (dfs(2, source)){
          valid = true;
        }
      }
    }
    if (valid){
      cout << "REACHABLE" << endl;
    }else{
      cout << "GARDEN OF EDEN" << endl;
    }
  }
}



