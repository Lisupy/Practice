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

const int MAXN = 1024;
const int MAXD = 128 * 3;
long long ways[MAXD][MAXN];


void ways_init(){
  ways[0][0] = 1;
  for (int i = 1; i < MAXN; i++){
    for (int j = 1; j < MAXD; j++){
      for (int k = 1; k < MAXN; k++){
        if (j - i >= 0 && k - 1 >= 0){
          ways[j][k] += ways[j - i][k - 1];
        }
      }
    }
  }
  //for (int i = 0; i < MAXD; i++){
    //partial_sum(ways[i], ways[i] + MAXN, ways[i]);
  //}
}

void ways_init_Ferrers(){
  ways[0][0] = 1;
  for (int j = 0; j < MAXD; j++){
    for (int i = 1; i < MAXD; i++){
      if (j >= i) ways[j][i] = ways[j - i][i];
      ways[j][i] += ways[j][i - 1];
    }
  }
}

int main(){
//  ways_init();
  ways_init_Ferrers();
  string line;
  while (getline(cin, line) && line.size()){
    int N, L1 = -1, L2 = -1;
    istringstream iss(line);
    iss >> N >> L1 >> L2;
    if (L1 == -1){
      L1 = MAXD - 1;
    }
    if (L2 == -1){
      L2 = L1;
      L1 = 0;
    }
    L1 = min(L1, 300);
    L2 = min(L2, 300);
    if (L1 > L2){
      cout << 0 << endl;
    }else{
      //cout << accumulate(ways[N] + L1, ways[N] + L2 + 1, 0ll) << endl;
      if (L1 >= 1){
        cout << ways[N][L2] - ways[N][L1 - 1] << endl;
      }else{
        cout << ways[N][L2] << endl;
      }
    }
  }
}
