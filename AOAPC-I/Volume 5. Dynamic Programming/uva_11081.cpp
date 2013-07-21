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

int ways[64][64][64];

int main(){
  int T; cin >> T;
  while (T--){
    string a, b, c; cin >> a >> b >> c;
    memset(ways, 0, sizeof(ways));
    ways[0][0][0] = 1;
    for (int k = 1; k <= (int)c.size(); k++){
      //printf("%d:\n", k);
      for (int i = 0; i <= (int)a.size(); i++){
        for (int j = 0; j <= (int)b.size(); j++){
            if (i - 1 >= 0 && k - 1 >= 0 && a[i - 1] == c[k - 1]){
              for (int i1 = 0; i1 < i; i1++){
                ways[i][j][k] += ways[i1][j][k - 1];
                ways[i][j][k] %= 10007;
              }
            }
            if (j - 1 >= 0 && k - 1 >= 0 && b[j - 1] == c[k - 1]){
              for (int j1 = 0; j1 < j; j1++){
                ways[i][j][k] += ways[i][j1][k - 1];
                ways[i][j][k] %= 10007;
              }
            }
            //printf("%3d", ways[i][j][k]);
        }
        //printf("\n");
      }
    }
    int total = 0;
    for (int i = 0; i <= (int)a.size(); i++){
      for (int j = 0; j <= (int)b.size(); j++){
        total += ways[i][j][c.size()];
        total %= 10007;
      }
    }
    cout << total << endl;
  }
}
