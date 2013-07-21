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

const int MAXM = 4500 * 4500 / 40;

bool available[MAXM];

int TestNum;
int total;
int bottleNum;
int mins[128];
int maxs[128];
int main(){
  cin >> TestNum;
  while (TestNum--){
    cin >> total >> bottleNum;
    total *= 1000;
    for (int i = 0; i < bottleNum; i++) cin >> mins[i] >> maxs[i];
    int limit = MAXM;
    for (int i = 0; i < bottleNum; i++){
      if (maxs[i] != mins[i]){
        limit = mins[i] * mins[i] / (maxs[i] - mins[i]);
      }
    }
    vector<int> ts;
    for (int i = 0; i < bottleNum; i++){
      for (int j = mins[i]; j <= maxs[i]; j++){
        ts.push_back(j);
      }
    }
    sort(ts.begin(), ts.end());
    ts.erase(unique(ts.begin(), ts.end()), ts.end()); 
    if (total > limit){
      cout << 0 << endl;
    }else{
      memset(available, 0, sizeof(available));
      available[0] = true;
      for (int j = 0; j <= min(MAXM - 1, total); j++){
        if (!available[j]) continue;
        for (size_t i = 0; i < ts.size(); i++){
          int k = ts[i];
          int next = j + k;
          if (next < MAXM){
            available[next] = true;
          }
        }
      }
      for (int i = 0; i <= total; i++){
        if (available[total - i]){
          cout << i << endl;
          break;
        }
      }
    }
    if (TestNum) cout << endl;
  }
}



