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

struct Seg{
  double from, to;
};
vector<Seg> segs;


bool operator<(const Seg &a, const Seg &b){
  return a.from < b.from;
}

Seg segFromPos(double pos, double r, double w){
  double s = r * r - (w / 2.0) * (w / 2.0);
  if (s < 0) s = 0;
  double d = sqrt(s);
  return {pos - d, pos + d};
}
int solve(double L){
  int total = 0;
  double R = 0.0;
  //for (size_t i = 0; i < segs.size(); i++) {
    //printf("%lf %lf\n", segs[i].from, segs[i].to); 
  //}
  sort(segs.begin(), segs.end());
  for (size_t l = 0, r = 0; l < segs.size() && R < L; l = r){
    double newR = R;
    while (r < segs.size() && segs[r].from <= R){
      newR = max(newR, segs[r].to);
      r++;
    }
    if (newR == R){
      break;
    }
    R = newR;
    total++;
  }
  return R < L ? -1 : total;
}
int main(){
  int n;
  double l, w;
  while (scanf("%d%lf%lf", &n, &l, &w) != EOF){
    segs.resize(n);
    for (int i = 0; i < n; i++){
      double pos, r;
      scanf("%lf%lf", &pos, &r);
      segs[i] = segFromPos(pos, r, w);
    }
    int ans = solve(l);
    cout << ans << endl;
  }
}
    
