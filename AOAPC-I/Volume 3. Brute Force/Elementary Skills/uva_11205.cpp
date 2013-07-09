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



int TestNum;
int P;
int N;
vector<int> leds;
int readLED(){
  int s = 0;
  for (int i = 0; i < P; i++) {
    int t = 0;
    cin >> t;
    s = s * 2 + t; 
  }
  return s;
}

void input(){
  scanf("%d", &P);
  scanf("%d", &N);
  leds.resize(N);
  for (int i = 0; i < N; i++) {
    leds[i] = readLED(); 
  }
}

bool isValid(int mask){
  vector<int> as(leds);
  for (size_t i = 0; i < as.size(); i++) {
    as[i] = as[i] & mask;
  }
  for (size_t i = 0; i < as.size(); i++){
    for (size_t j = i + 1; j < as.size(); j++){
      if (as[i] == as[j]){
        return false;
      }
    }
  }
  return true;
}

int solve(){
  int minNum = 0xffff;
  for (int i = 0; i < (1 << P); i++){
    if (__builtin_popcount(i) < minNum && isValid(i)){
      minNum = __builtin_popcount(i);
    }
  }
  return minNum;
}

int main(){
  cin >> TestNum;
  while (TestNum--){
    input();
    int ans = solve();
    cout << ans << endl;
  }
}



