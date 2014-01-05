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
const double EPS = 1e-6;
const double R = 2.5;
struct Point{
  double x, y;
};
double dist(Point &a, Point &b){
  return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}
vector<Point> points;
int countInCircle(Point p){
  int cnt = 0;
  for (size_t i = 0; i < points.size(); i++){
    if (dist(points[i], p) <= R + EPS) cnt++;
  }
  return cnt;
}
Point getPO(Point p1, Point p2){
  Point p3({(p1.x + p2.x) / 2, (p1.y + p2.y) / 2}); 
  double l13 = dist(p1, p3);
  double lo3 = sqrt(R * R - l13 * l13);
  Point po;
  po.x = p3.x - (p1.y - p3.y) * lo3 / l13;
  po.y = p3.y + (p1.x - p3.x) * lo3 / l13;
  return po;
}
int TestNum = 1;
int main(){
  ios_base::sync_with_stdio(false); 
  cin >> TestNum;
  cin.ignore();
  string tmp; getline(cin, tmp);
  while (TestNum--){
    points.clear();
    string line;
    while (getline(cin, line) && line.size()){
      istringstream iss(line);
      double x, y; iss >> x >> y;
      points.push_back({x, y});
    }
    int best = points.size()? 1: 0;
    for (size_t i = 0; i < points.size(); i++){
      for (size_t j = 0; j < points.size(); j++){
        if (i == j) continue;
        Point p1 = points[i], p2 = points[j];
        assert(p1.x != p2.x || p1.y != p2.y);
        if (dist(p1, p2) > 2 * R) continue;
        Point po = getPO(p1, p2); 
        best = max(best, countInCircle(po));
      }
    }
    cout << best << endl;
    if (TestNum) cout << endl;
  }
}

