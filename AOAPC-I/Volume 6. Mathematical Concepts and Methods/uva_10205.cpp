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
 */

vector<vector<int> > arranges;

vector<int> shffle(vector<int> src, vector<int> arrange){
  vector<int> to(src);
  for (int i = 1; i <= 52; i++){
    to[i] = src[arrange[i]];
  }
  return to;
}
const char* value_s[13] = {
  "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"
};
const char* suit_s[4] = {
  "Clubs", "Diamonds", "Hearts", "Spades"
};
int TestNum;
int main(){
  cin >> TestNum;
  while (TestNum--) {
    int n; cin >> n;
    arranges.resize(n + 1, vector<int>(53));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 52; j++) {
        cin >> arranges[i][j];
      }
    }
    vector<int> pos(53);
    for (int i = 1; i <= 52; i++) pos[i] = i;
    for (int i = 0; i < n; i++){
      int k; cin >> k;
      pos = shffle(pos, arranges[k]);
    }
    for (int i = 1; i <= 52; i++){
      int c = pos[i] - 1;
      printf("%s of %s\n", value_s[c%13], suit_s[c/13]);
    }
    if (TestNum) cout << endl;
  }
}



