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
const long long INF = 0x3f3f3f3f3f3f3f3fll;
int TestNum;

struct City{
  int dist;
  long long price;
  City(int d, long long p): dist(d), price(p){};
};
vector<City> citys;
long long dp[256];
int L;

long long solve(){
  memset(dp, 0x3f, sizeof(dp));
  dp[100] = 0;
  for (size_t i = 1; i < citys.size(); i++){
    int d = citys[i].dist - citys[i - 1].dist; 
    long long p = citys[i].price;
    //printf("%lu: %d %lld\n", i, d, p);
    for (int j = 0; j <= 200; j++){
      if (j == 0){
        dp[j] = j + d <= 200 ? dp[j + d] : INF;
      }else{
        dp[j] = min(j + d <= 200 ? dp[j + d] : INF,  dp[j - 1] + p);
      }
      dp[j] = min(dp[j], INF);
      //printf("%d %lld\n", j, dp[j]);
    }
    //printf("\n");
  }
  return dp[100];
}

int main(){
  cin >> TestNum;
  while (TestNum--){

    cin >> L;
    cin.ignore();
    citys.clear();
    citys.push_back(City(0, INF));
    string line;
    while (getline(cin, line) && line.size()){
      istringstream iss(line);
      int d, p;
      iss >> d >> p;
      citys.push_back(City(d, p));
    }
    citys.push_back(City(L, INF));
    long long ans = solve();
    if (ans >= INF){
      printf("Impossible\n");
    }else{
      printf("%lld\n", ans);
    }
    if (TestNum) printf("\n");
  }
}
