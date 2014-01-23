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
const double eps = 1e-8;
int cmp(double x){
  if (fabs(x) < eps) return 0;
  if (x > 0) return 1;
  return -1;
}
const double pi = acos(-1.0);
inline double sqr(double x){
  return x * x;
}
struct point {
  double x, y;
  point(): x(0), y(0){}
  point(double a, double b): x(a), y(b){}
  void input() { 
    cin >> x >> y; 
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
  friend point operator * (const double &a, const point &b){
    return point(a * b.x, a * b.y);
  }
  friend point operator * (const point &a, const double &b){
    return point(a.x * b, a.y * b);
  }
  friend point operator / (const point &a, const double &b){
    return point (a.x / b, a.y / b);
  }
  double norm() {
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
  return point(tx * cos(A) - ty * sin(A), tx * sin(A) + ty * cos(A));
}

struct polygon_convex {
  vector<point> P;
  polygon_convex(int Size = 0):P(Size){}
  double area(){
    int n = P.size();
    double tot = 0;
    for (int i = 0; i < n; i++){
      tot += det(P[i], P[(i + 1)%n]);
    }
    return tot / 2;
  }
  void format(){
    if (area() < 0){
      reverse(P.begin(), P.end());
    }
  }
};
struct halfPlane{
  double a, b, c;
  halfPlane(point p, point q):a(0),b(0),c(0){
    a = p.y - q.y;
    b = q.x - p.x;;
    c = det(p, q);
  }
  halfPlane(double aa, double bb, double cc): a(aa), b(bb), c(cc){}
};
double calc(halfPlane &L, point &a){
  return a.x * L.a + a.y * L.b + L.c;
}
point Intersect(point &a, point &b, halfPlane &L){
  point res;
  double t1 = calc(L, a), t2 = calc(L, b);
  res.x = (t2 * a.x - t1 * b.x) / (t2 - t1);
  res.y = (t2 * a.y - t1 * b.y) / (t2 - t1);
  return res;
}


polygon_convex cut(polygon_convex &a, halfPlane &L){
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
struct line{
  point a, b;
  line():a(), b(){}
  line(point x, point y): a(x), b(y){}
};
line move_d(line a, const double &len){
  point d = a.b - a.a;
  d = d / d.norm();
  d = rotate_point(d, pi / 2);
  return line(a.a + d * len, a.b + d * len);
}
halfPlane getHalfPlane(point a, point b, int h){
  line l(a, b);
  l = move_d(l, h);
  return halfPlane(l.b, l.a);
}
double solve(polygon_convex orig, int n, int k, int h){
  if (k == 0 || n == 0) return 0;
  k = min(k, n);
  double minArea = orig.area();
  for (int mask = 0; mask < (1 << n); mask++) if (__builtin_popcount(mask) == k){
    polygon_convex tmp = orig;
    for (int i = 0; i < n; i++) if (mask & (1 << i)){
      halfPlane L = getHalfPlane(orig.P[i], orig.P[(i + 1)%n], h);
      tmp = cut(tmp, L); 
    }
    minArea = min(minArea, tmp.area());
  }
  return orig.area() - minArea;
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int n, k, h;
  while (cin >> n >> k >> h , n || k || h) {
    polygon_convex orig(n);
    for (int i = 0; i < n; i++) orig.P[i].input();
    orig.format();
    printf("%.02lf\n", solve(orig, n, k, h));
  }
}

