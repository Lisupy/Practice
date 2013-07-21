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
int TestNum;

const int MAXN = 128;
bool unsafe[MAXN][MAXN];
int ways[MAXN][MAXN];
int W, N;
int main(){
  cin >> TestNum;
  while (TestNum--){
    cin >> W >> N;
    memset(unsafe, 0, sizeof(unsafe));
    cin.ignore();
    for (int i = 1; i <= W; i++){
      string line;
      getline(cin, line);
      istringstream iss(line);
      int t;
      iss >> t;
      while (iss >> t){
        unsafe[i][t] = true;
      }
    }
    for (int i = 1; i <= W; i++){
      for (int j = 1; j <= N; j++){
        if (i == 1 && j == 1){
          ways[i][j] = unsafe[i][j] ? 0 : 1;
        }else{
          ways[i][j] = unsafe[i][j] ? 0 : ways[i - 1][j] + ways[i][j - 1];
        }
        //cout << ways[i][j] << ", ";
      }
      //cout << endl;
    }
    cout << ways[W][N] << endl;
    if (TestNum) cout  << endl;
  }
}

