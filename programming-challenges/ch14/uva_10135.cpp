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
const double EPS = 1e-10;
double add(double a, double b){
  if (abs(a + b ) < EPS * (abs(a) + abs(b))) return 0;
  return a + b;
}
struct Point{
  double x, y;
  Point():x(0), y(0){}
  Point(double _x, double _y): x(_x), y(_y){}
  double angle() const { return atan2(y, x); }
};
double dist(Point &a, Point &b){
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
bool cmpByXY(const Point &a, const Point &b){
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}
bool cmpByRadius(const Point &a, const Point &b){
  return a.angle() < b.angle();
}
double area(Point &a, Point &b, Point &c){
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
bool cw(Point &a, Point &b, Point &c){
  return area(a, b, c) < -EPS;
}
bool ccw(Point &a, Point &b, Point &c){
  return area(a, b, c) > EPS;
}
double total_length(vector<Point> points){
  double tot = 0;
  for (size_t i = 0; i < points.size(); i++){
    tot += dist(points[i], points[(i + 1)%points.size()]);
  }
  return tot;
}
double try_solve(vector<Point> points){
  bool allSameAngle = true;
  Point p0(0, 0);
  for (size_t i = 0; i < points.size(); i++){
    if (fabs(area(points[0], points[i], p0)) > EPS) allSameAngle = false;
  }
  if (allSameAngle){
    points.push_back(Point(0, 0));
    sort(points.begin(), points.end(), cmpByXY);
    return dist(points.front(), points.back()) * 2;
  }
  points.push_back(Point(0, 0));
  sort(points.begin(), points.end(), cmpByXY);
  vector<Point> res(points.size()*2);
  int sz = 0; 
  for (size_t i = 0; i < points.size(); i++){
    while (sz - 2 >= 0 && !ccw(res[sz - 2], res[sz - 1], points[i])) sz--;
    res[sz++] = points[i];
  }
  for (int i = points.size() - 2, tsz = sz; i >= 0; i--){
    while (sz > tsz && !ccw(res[sz - 2], res[sz - 1], points[i])) sz--;
    res[sz++] = points[i];
  }
  res.resize(sz - 1);
  for (size_t i = 0; i < res.size(); i++){
    if (res[i].x == 0 && res[i].y == 0) {
      return total_length(res);
    }
  }
  return -1;
}
double solve(vector<Point> points){
  if (points.size() == 0) return 0 ;
  double ret = try_solve(points);
  if (ret != -1) return ret;
  double best = 1e10;   

  int N = points.size();
  sort(points.begin(), points.end(), cmpByRadius);
  for (int pivot = 0; pivot < N; pivot++){
    vector<Point> res(points.size());
    int sz = 0;
    for (size_t i = 0; i < points.size(); i++){
      Point p = points[(i + pivot) % N];
      while (sz - 2 >= 0 && !ccw(res[sz - 2], res[sz - 1], p)) sz--;
      res[sz++] = p;
    }
    res.resize(sz);
    res.push_back(Point(0, 0));
    best = min(best, total_length(res));
  }
  return best;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  cin >> TestNum;
  while (TestNum--){
    int N; cin >> N;
    vector<Point> points(N);
    for (int i = 0; i < N; i++){
      cin >> points[i].x >> points[i].y;
    }
    printf("%.02lf\n", solve(points) + 2);
    if (TestNum) printf("\n");
  }
}

