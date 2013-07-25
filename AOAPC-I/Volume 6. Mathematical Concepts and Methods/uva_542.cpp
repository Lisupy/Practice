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


vector<string> countries(16);
double mat[16][16];

double a[5][16][16];
int main(){
  for (int i = 0; i < 16; i++) cin >> countries[i];
  for (int i = 0; i < 16; i++){
    for (int j = 0; j < 16; j++){
      cin >> mat[i][j];
      mat[i][j] /= 100;
      //cout << mat[i][j] << " ";
    }
    //cout << endl;
  }
  for (int i = 0; i < 16; i++){
    a[0][i][i] = 1.00;
  }
  for (int layer = 1; layer <= 4; layer++){
    //printf("layer: %d\n", layer);
    for (int pos = 0; pos < 8; pos++){
      for (int country = 0; country < 16; country++){
        for (int op = 0; op < 16; op++){
          if (a[layer - 1][2 * pos][country] != 0 || a[layer - 1][2 * pos + 1][op] != 0){
            //printf("%d %d, %d %d \n", 2 * pos, country, 2 * pos + 1, op);
          }
          a[layer][pos][country] += mat[country][op] * a[layer - 1][2 * pos][country] * a[layer - 1][2 * pos + 1][op];
          a[layer][pos][country] += mat[country][op] * a[layer - 1][2 * pos][op] * a[layer - 1][2 * pos + 1][country];
        }
        //printf("%.02lf ", a[layer][pos][country]);
      }
      //printf("\n");
    }
  }
  for (int i = 0; i < 16; i++){
    printf("%-10s p=%.02lf%%\n", countries[i].c_str(), a[4][0][i] * 100);
  }
}


