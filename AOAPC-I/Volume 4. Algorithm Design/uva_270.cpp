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
const double INF = 1e20;
const int MAXN = 1024;
int x[MAXN];
int y[MAXN];
int N;
double getGradient(int x1, int y1, int x2, int y2){
  double x3 = x2 - x1;
  double y3 = y2 - y1;
  if (x3 == 0) return INF;
  return y3 / x3;
}
int getLineCnt(int k){
  map<double, int> M;
  int best = 0;
  for (int i = 0; i < N; i++){
    if (i == k) continue;
    double g = getGradient(x[i], y[i], x[k], y[k]);
    M[g]++;
    best = max(best, M[g]);
  }
  return best + 1;
}

int solve(){
  int best = 0;
  for (int i = 0; i < N; i++){
    int cnt = getLineCnt(i);
    if (cnt > best){
      best = cnt;
    }
  }
  return best;
}

void input(){
  string line;
  N = 0;
  while (getline(cin, line) && line.size()){
    istringstream iss(line);
    iss >> x[N] >> y[N];
    N++;
  }
} 
int main(){
  int TestNum;
  cin >> TestNum;
  cin.ignore();
  cin.ignore();
  while (TestNum--){
    input();
    cout << solve() << endl;
    if (TestNum) cout << endl;
  }
}
