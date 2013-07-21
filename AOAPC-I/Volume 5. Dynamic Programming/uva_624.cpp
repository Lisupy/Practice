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
int main(){
  int N;
  while (cin >> N){
    int k;
    cin >> k;
    vector<int> tracks(k);
    for (int i = 0; i < k; i++){
      cin >> tracks[i];
    }
    vector<bool> available(N + 1);
    vector<int> path(N + 1, -1);
    available[0] = true;
    for (int i = 0; i < k; i++){
      for (int j = N; j >= 0; j--){
        //printf("%d", (int)available[j]);
        if (!available[j]){
          int last = j - tracks[i];
          if (last >= 0 && available[last]){
            available[j] = true;
            path[j] = last;
          }
        }
      }
      //printf("\n");
    }
    int pos = N;
    while (!available[pos]) pos--;
    int sum = pos;
    vector<int> res;
    while (pos != 0){
      res.push_back(pos - path[pos]);
      pos = path[pos];
    }
    reverse(res.begin(), res.end());
    for (size_t i = 0; i < res.size(); i++){
      printf("%d ", res[i]);
    }
    printf("sum:%d\n", sum);
  }
}



