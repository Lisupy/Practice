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
 * sizeof CLOCKS_PER_SEC
 */
const double pi = acos(-1);
typedef long long i64;
struct Pos{
  double x, y;
  double angle;
};

bool operator<(const Pos &a, const Pos &b){
  return a.angle < b.angle;
}

i64 C(i64 n, i64 k){
  if (n < k) return 0;
  i64 total = 1;
  for (i64 i = 1; i <= k; i++) {
    total *= n - i + 1;
    total /= i;
  }
  return total;
}

i64 calc(vector<Pos> ps){
  sort(ps.begin(), ps.end());
  //for (size_t i = 0; i < ps.size(); i++) {
    //cout << ps[i].x << ", " << ps[i].y << ": " << ps[i].angle << endl;
  //}
  i64 total = 0;
  for (size_t i = 0; i < ps.size(); i++) {
    //cout << i << ": " ;
    Pos &p = ps[i];
    Pos t = p;
    if (p.angle <= 0){
      t.angle += pi;
      size_t pos = lower_bound(ps.begin(), ps.end(), t) - ps.begin();
      //cout <<"-" <<  pos ;
      total += C(pos - i - 1, 2);
    }else{
      t.angle -= pi;
      size_t pos = lower_bound(ps.begin(), ps.end(), t) - ps.begin();
      //cout <<"+" <<  pos ;
      if (pos == i) total += C(ps.size() - 1, 2); 
      else total += C(ps.size() - i + pos - 1, 2);
    }
    //cout << total << endl;
  }
  //cout << C(ps.size(), 3)  << ", " << total << endl;
  return C(ps.size(), 3) - total;
}
int TestNum;
int main(){
  //cout << atan2(0, -1) << endl;
  //cout << pi << endl;
  i64 N;
  while (cin >> N && N) {
    vector<Pos> ps(N);
    for (i64 i = 0; i < N; i++) {
      cin >> ps[i].x >> ps[i].y;
    }
    i64 total = 0;
    for (i64 i = 0; i < N; i++) {
      vector<Pos> tmp(ps);
      tmp.erase(tmp.begin() + i);
      for (size_t j = 0; j < tmp.size(); j++) {
        tmp[j].angle = atan2(tmp[j].y - ps[i].y, tmp[j].x - ps[i].x);
      }
      total += calc(tmp);
    }
    //cout << total << endl;
    //cout << C(N, 3) << endl;
    printf("City %d: %.02lf\n", ++TestNum, total * 1.0 / C(N, 3));
  }

}

