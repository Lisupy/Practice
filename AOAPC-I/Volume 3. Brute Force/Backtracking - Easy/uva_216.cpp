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
string breakLine = "**********************************************************";
struct Pos{
  double x, y;
};
double dist(Pos &a, Pos &b){
  double s = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  return sqrt(s) + 16;
}
vector<Pos> ps;

double calc(vector<int> a){
  double total = 0;
  for (size_t i = 1; i < a.size(); i++){
    total += dist(ps[a[i]], ps[a[i - 1]]);
  }
  return total;
}
vector<int> bestPermuattion(){
  vector<int> a(ps.size());
  double best = 1e20;
  vector<int> bestP;
  for (size_t i = 0; i < a.size(); i++){
    a[i] = i;
  }
  do {
    double len = calc(a);
    if (len < best){
      best = len;
      bestP = a;
    }
  } while (next_permutation(a.begin(), a.end()));
  return bestP;
}

void output(vector<int> a){
  for (size_t i = 1; i < a.size(); i++) {
    printf("Cable requirement to connect (%.lf,%.lf) to (%.lf,%.lf) is %.02lf feet.\n", 
      ps[a[i - 1]].x, ps[a[i - 1]].y, ps[a[i]].x, ps[a[i]].y, dist(ps[a[i - 1]], ps[a[i]]));  
  }
  printf("Number of feet of cable required is %.02lf.\n", calc(a));
}

int main(){
  int n;
  while (cin >> n && n){
    ps.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> ps[i].x >> ps[i].y;
    }
    vector<int> a = bestPermuattion();
    cout << breakLine << endl;
    printf("Network #%d\n", ++TestNum);
    output(a);
  }
}
