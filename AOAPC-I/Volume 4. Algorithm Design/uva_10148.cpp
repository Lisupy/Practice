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
const int MAXM = 20*1024;
int K, N;
struct Joger{
  int A, B;
};
bool operator<(const Joger &a, const Joger &b){
  return a.B < b.B;
}
vector<Joger> jogs;
vector<bool> isAds;
void doFill(int to, int from, int cnt){
  while (to >= from && cnt){
    if (!isAds[to]){
      isAds[to] = true;
      cnt--;
    }
    to--;
  }
}
void input(){
  cin >> K >> N;
  jogs.resize(N);
  isAds.clear();
  isAds.resize(MAXM);
  for (int i = 0; i < N; i++){
    cin >> jogs[i].A >> jogs[i].B;
    jogs[i].A += 10000;
    jogs[i].B += 10000;
    if (jogs[i].A > jogs[i].B){
      swap(jogs[i].A, jogs[i].B);
    }
    if (jogs[i].B - jogs[i].A + 1 <= K){
      doFill(jogs[i].B, jogs[i].A, K);
    }
  }
}
void solve(){
  sort(jogs.begin(), jogs.end());
  for (size_t i = 0; i < jogs.size(); i++){
    Joger &j = jogs[i];
    int cnt = accumulate(isAds.begin() + j.A, isAds.begin() + j.B + 1, 0);
    if (cnt < K){
      doFill(j.B, j.A, K - cnt);
    }
  }
  cout << accumulate(isAds.begin(), isAds.end(), 0) << endl;
  for (size_t i = 0; i < isAds.size(); i++){
    if (isAds[i]){
      cout << (int)i - 10000 << endl;
    }
  }
}
int main(){
  int TestNum;
  cin >> TestNum;
  while (TestNum--){
    input();
    solve();
    if (TestNum){
      cout << endl;
    }
  }
}
