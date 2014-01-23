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
const bool dbg = false;
//const bool dbg = true;
const double eps = 1e-6;
int cmp(double x){
  if (fabs(x) < eps) return 0;
  if (x > 0) return 1;
  return -1;
}

const double pi = acos(-1.0);
inline double sqr(double x){
  return x * x;
}
struct point{
  double x, y;
  point(): x(0), y(0) {}
  point(double a, double b): x(a), y(b) {}
  void input(){
    scanf("%lf%lf", &x, &y);
  }
  friend point operator + (const point &a, const point &b){
    return point(a.x + b.x, a.y + b.y);
  }
  friend point operator - (const point &a, const point &b){
    return point(a.x - b.x, a.y - b.y);
  }
  friend bool operator ==(const point &a, const point &b){
    return cmp(a.x - b.x) == 0 && cmp(a.y - b.y) == 0;
  }
  friend point operator * (const point &a, const double &b){
    return point(a.x * b, a.y * b);
  }
  friend point operator * (const double &a, const point &b){
    return point(a * b.x, a * b.y);
  }
  friend point operator / (const point &a, const double &b){
    return point(a.x / b, a.y / b);
  }
  double norm(){
    return sqrt(sqr(x) + sqr(y));
  }
};
double det(const point &a, const point &b){
  return a.x * b.y - a.y * b.x;
}
double dot(const point &a, const point &b){
  return a.x * b.x + a.y * b.y;
}
double dist(const point &a, const point &b){
  return (a - b).norm();
}
point rotate_point(const point &p, double A){
  double tx = p.x, ty = p.y;
  return point (tx * cos(A) - ty * sin(A), tx * sin(A) + ty * cos(A));
}
struct polygon_convex {
  vector<point> P;
  void display(){
    if (!dbg) return;
    printf("polygon_convex(%lu)(%lf): ", P.size(), area());
    for (size_t i = 0; i < P.size(); i++){
      printf("(%lf, %lf), ", P[i].x, P[i].y);
    }
    printf("\n");
  }
  polygon_convex():P(0) {}
  double area(){
    double sum = 0;
    int n = P.size();
    for (int i = 0; i < n; i++){
      sum += det(P[i], P[(i + 1) % n]);
    }
    return sum / 2;
  }
};
struct halfPlane{
  //ax + by + c <= 0
  double a, b, c;
  void display(){
    if (!dbg) return;
    printf("halfPlane(%lf, %lf %lf)\n", a, b, c);
  }
  //
  halfPlane(point p, point q):a(0), b(0), c(0){
    a = p.y - q.y;
    b = q.x - p.x;
    c = det(p, q);
  }
  halfPlane(double aa, double bb, double cc): a(aa), b(bb), c(cc) {};
};
halfPlane getHalfPlane(point a, point b){
  point c = (a + b) / 2;
  point ca = a - c;
  point cd = rotate_point(ca, -PI / 2);
  point d = c + cd;
  return halfPlane(d, c);
}
double calc(halfPlane &L, point &a){
  return a.x * L.a + a.y * L.b + L.c;
}

point Intersect(point &a, point &b, halfPlane &L){
  point res;
  double t1 = calc(L,a), t2 = calc(L, b);
  res.x = (t2 * a.x - t1 * b.x) / (t2 - t1);
  res.y = (t2 * a.y - t1 * b.y) / (t2 - t1);
  return res;
}

polygon_convex cut(polygon_convex a, halfPlane L){
  int n = a.P.size();
  polygon_convex res;
  for (int i = 0; i < n; i++){
    if (calc(L, a.P[i]) < -eps) res.P.push_back(a.P[i]);
    else{
      int j = (i - 1 + n) % n;
      if (calc(L, a.P[j]) < -eps) res.P.push_back(Intersect(a.P[j], a.P[i], L));
      j = (i + 1) % n;
      if (calc(L, a.P[j]) < -eps) res.P.push_back(Intersect(a.P[i], a.P[j], L));
    }
  }
  return res;
}

int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  polygon_convex polygon;
  polygon.P.push_back(point(0,  0));
  polygon.P.push_back(point(10, 0));
  polygon.P.push_back(point(10, 10));
  polygon.P.push_back(point(0,  10));
  polygon.display();
  cut(polygon, halfPlane(point(0, 0), point(10, 0))).display();

  point last = point(0, 0);
  double x, y;
  string s;
  while (cin >> x >> y >> s) {
    point cur = point(x, y);
    //getHalfPlane(last, cur).display(); 
    //getHalfPlane(cur, last).display(); 
    if (s == "Same"){
      polygon.P.resize(0);
    }
    halfPlane hl = (s == "Colder")? getHalfPlane(last, cur): getHalfPlane(cur, last);
    hl.display();
    polygon = cut(polygon, hl);
    polygon.display();
    printf("%.02lf\n", polygon.area());
    last = cur;
  }
}

