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

typedef long long i64;
typedef unsigned long long u64;
const double PI = acos(-1);
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */

struct Point{
  double x, y;
};
struct Line{
  double a, b, c;
};
Line points_to_line(Point p1, Point p2){
  if (p1.x == p2.x) return Line({1, 0, -p1.x});
  double b = 1;
  double a = -(p1.y-p2.y)/(p1.x-p2.x);
  double c = -(a * p1.x) - (b - p1.y);
  return Line({a, b, c});
}
double area(Point p1, Point p2, Point p3){
  double tot = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
  return fabs(tot) / 2;
}
double dist(Point p1, Point p2){
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
Point pA, pB, pO;
double R;
double solve(){
  //if (pA.x == pB.x && pA.y == pB.y) return 0;
  //cout << dist(pA, pB) << endl;
  double oh = area(pA, pB, pO) / dist(pA, pB);
  //cout << oh << endl;
  if (oh >= R) return dist(pA, pB);
  double LA = sqrt(pow(dist(pA, pO), 2) - pow(R, 2)); 
  double LB = sqrt(pow(dist(pB, pO), 2) - pow(R, 2)); 
  double a = dist(pB, pO), b = dist(pA, pO), o = dist(pA, pB);
  double angleAOB = acos((a*a + b*b - o*o)/(2*b*a));
  //cout << angleAOB << endl;
  //cout << PI << endl;
  double angleAO_ = acos(R/dist(pA, pO));
  double angleBO_ = acos(R/dist(pB, pO));
  double angleRemain = angleAOB - angleAO_ - angleBO_;
  if (angleRemain <= 0) return dist(pA, pB);
  //cout << LA << endl;
  //cout << LB << endl;
  return LA + LB + angleRemain * R;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  cin >> TestNum;
  while(TestNum--){
    cin >> pA.x >> pA.y >> pB.x >> pB.y >> R;
    printf("%.03lf\n", solve());
  }
}

