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
const double EPS = 1e-2;
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */

double radiusFromAngle(double a){
  return a / 180 * PI;
}
double angleFromRadius(double r){
  return r / PI * 180;
}
double getByConsines(double d1, double d2, double a){
  double tot = d1 * d1 + d2 * d2 - 2 * d1 * d2 * cos(radiusFromAngle(a));
  return sqrt(tot);
}
double getAngleByConsines(double d1, double d2, double d3){
  double tot = d1 * d1 + d2 * d2 - d3 * d3;
  tot /= 2 * d1 * d2;
  return angleFromRadius(acos(tot));
}
double angleAdjust(double a){
  while (a >= 360) a -= 360;
  while (a < 0) a += 360;
  return a;
}
double a1, d1, a2, d2;
double a3, d3;
double a21;
void gao1(){
  d3 = d2 * 2 - d1;
  if (d3 >= 0){
    printf("%.02lf %.02lf\n", a1, d3);
  }else{
    printf("%.02lf %.02lf\n", 360 - a1, -d3);
  }
}

void gao2(){
  d3 = (d2 + d1) * 2 + d2;
  printf("%.02lf %.02lf\n", a2, d3);
}

void gao3(){
  double d21 = getByConsines(d1, d2, 360 - a21);
  double lo = d21 / a21 * (180 + 360 - a21), hi = d21 / a21 * 360; 
  d3 = -1;
  while (fabs(lo - hi) > 1e-10) {
    double mid = (lo + hi) / 2;
    double d32 = mid;
    double a32 = angleAdjust(d32 / d21 * a21);
    double a021 = getAngleByConsines(d21, d2, d1);
    double a032 = a021 - (360 - a32); 
    if (a032 < 0){
      //assert(0);
      lo = mid;
      continue;
    }
    double d32_ = d2 / sin(radiusFromAngle(a032)) * sin(radiusFromAngle(360 - a32)); 

    //printf("%lf\n", a021);
    //printf("%lf %lf\n", a032, a32);
    //printf("%lf %lf\n", d32_, d32);
    if (d32_ > d32) lo = mid;
    else hi = mid;
    if (fabs(d32_ - d32) < EPS) {
      d3 = d2 / sin(radiusFromAngle(a032)) * sin(radiusFromAngle(180 - a021)); 
      a3 = angleAdjust(a32 + a2); 
    }
    d3 = d2 / sin(radiusFromAngle(a032)) * sin(radiusFromAngle(180 - a021)); 
    a3 = angleAdjust(a32 + a2); 
    //printf("bin: %lf %lf, %lf\n", lo, hi, mid);
    //printf("bin: %lf %lf, %lf\n", lo, hi, mid);
  }
  //printf("%.02lf %.02lf\n", lo, hi); 
  printf("%.02lf %.02lf\n", a3, d3); 
}
bool Pcmp(pair<double, double> a, pair<double, double> b){
  if (a.first != b.first) return a.first < b.first;
  return a.second > b.second;
}
bool Pequ(pair<double, double> a, pair<double, double> b){
  return fabs(a.first - b.first) < EPS && fabs(a.second - b.second) < EPS;
}
void gao4(){
  vector<pair<double, double> > ans;
  for (double a21d = 0; a21d <= 360; a21d += 360){
    for (double tt = 0; tt <= 360; tt += 360){
      double d21 = getByConsines(d1, d2, a21);
      double lo = d21 / (a21d + a21) * (tt + 0), hi = d21 / (a21d + a21) * (tt + 180 - a21); 
      d3 = -1;
      while (fabs(lo - hi) > 1e-10) {
        double mid = (lo + hi) / 2;
      //for (double mid = lo; mid < hi; mid += 1e-6) {
        //cout << mid << endl;
        double d32 = mid;
        double a32 = angleAdjust(d32 / d21 * (a21 + a21d));
        double a021 = getAngleByConsines(d21, d2, d1);
        double a032 = a021 - a32; 

        double dd3 = d32 / sin(radiusFromAngle(a32)) * sin(radiusFromAngle(180 - a021));
        double dd3_ = d2 / sin(radiusFromAngle(a032)) * sin(radiusFromAngle(180 - a021)); 

        //if (a032 < 0){
          //printf("%lf\n", a032);
          //lo = mid;
          //continue;
        //}
        //double d32_ = d2 / sin(radiusFromAngle(a032)) * sin(radiusFromAngle(a32)); 

        //printf("bin: %lf %lf, %lf\n", lo, hi, mid);
        //printf("%lf\n", a021);
        //printf("%lf %lf\n", a032, a32);
        //printf("%lf %lf\n", d32_, d32);
        //if (d32_ > d32) lo = mid;
        //else hi = mid;
        if (dd3 > dd3_) lo = mid;
        else hi = mid;
        if (fabs(dd3 - dd3_) < 1e-2){
          //d3 = d2 / sin(radiusFromAngle(a032)) * sin(radiusFromAngle(180 - a021)); 
          a3 = angleAdjust(a32 + a2); 
          d3 = dd3 ;
          ans.push_back(make_pair(a3, d3));
          break;
        }
      }
    }
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end(), Pequ), ans.end());
  for (size_t i = 0; i < ans.size(); i++){
    if (i != 0) printf(" ");
    printf("%.02lf %.02lf", ans[i].first, ans[i].second);
  }
  printf("\n");
  //printf(" gao4\n");
  //printf("gao4\n");
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (cin >> a1 >> d1 >> a2 >> d2) {
    assert(a1 != 360 && a2 != 360);
    if (a1 == a2){
      gao1();  
    }else if (fabs(a2 - a1) == 180){
      gao2();
    }else{
      a21 = a2 - a1;
      a21 = angleAdjust(a21);
      if (a21 > 180) gao3();
      else gao4();
    }
  }
}

