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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 */
const int MAX_M = 50000;
typedef pair<int, int> Interval;
const pair<int, int> invalid = make_pair(1, 0); 
struct Shape{
  int c;
  Shape(int _c): c(_c) {};
  virtual Interval getInterval(int x) = 0;
  //virtual Shape(const Shape &);
  virtual ~Shape(){};
  //virtual void debug();
};
struct Circle : Shape{
  int xc, yc, r;
  Circle(int _xc, int _yc, int _r, int _c): Shape(_c), xc(_xc), yc(_yc), r(_r){ };
  virtual ~Circle(){};
  Interval getInterval(int x){
    int r2 = r * r - (xc - x) * (xc - x);
    if (r2 < 0) return invalid;
    int d = floor(sqrt(r2));
    return make_pair(yc - d, yc + d);
  }
};
struct Diamond : Shape{
  int xc, yc, r;
  Diamond(int _xc, int _yc, int _r, int _c): Shape(_c), xc(_xc), yc(_yc), r(_r){};
  ~Diamond(){};
  Interval getInterval(int x){
    if (xc - r <= x && x <= xc + r){
      int d = r - abs(xc - x);
      return make_pair(yc - d, yc + d);
    }else{
      return invalid;
    }
  }
};
struct Rectangle : Shape{
  int xc, yc, l, w;
  Rectangle(int _xc, int _yc, int _l, int _w, int _c): Shape(_c), xc(_xc), yc(_yc), l(_l), w(_w){};
  ~Rectangle(){};
  Interval getInterval(int x){
    if (xc <= x && x <= xc + l - 1){
      return make_pair(yc, yc + w - 1); 
    }else{
      return invalid;
    }
  }
};
struct Triangle: Shape{
  int xc, yc, w;
  Triangle(int _xc, int _yc, int _w, int _c): Shape(_c), xc(_xc), yc(_yc), w(_w){}; 
  ~Triangle(){};
  Interval getInterval(int x){
    if (xc <= x && x <= xc + (w - 1) / 2){
      int d = (w - 2 * abs(xc - x) - 1) / 2;
      return make_pair(yc - d, yc + d);
    }else{
      return invalid;
    }
  }
};
int n, m;
struct Line{
  int colored[MAX_M];
  int p[MAX_M];
  void init(){
    for (int i = 0; i < m; i++) p[i] = i, colored[i] = 0;
  }
  void debug(){
    //for (int i = 0; i < m; i++) printf("%d",          i); printf("\n");
    for (int i = 0; i < m; i++) printf("%d", colored[i]); printf("\n");
  }
  int find(int u){
    return p[u] == u ? u : p[u] = find(p[u]);
  }
  void join(int u, int v){
    int pu = find(u), pv = find(v);
    if (pv < pu) swap(pu, pv);
    p[pu] = pv;
  }
  int countZeroAndSet(Interval interval, int c){
    if (interval == invalid) return 0;
    interval.first = max(interval.first, 0);
    interval.second = min(interval.second, m - 1);
    int total = 0;
    for (int i = interval.first; i <= interval.second; i++){
      i = find(i);
      if (colored[i]) continue;
      total++;
      colored[i] = c;
      if (i - 1 >= 0 && colored[i - 1]) join(i, i - 1);
      if (i + 1 < m && colored[i + 1]) join(i, i + 1);
    }
    return total;
  }
};


Line line;
int TestNum;
int main(){
  int q;
  while (scanf("%d %d %d", &n, &m, &q) != EOF){
    vector<Shape*> shapes;
    for (int i = 0; i < q; i++){
      char type[32]; scanf("%s", type);
      if (!strcmp(type, "Circle")){
        int xc, yc, r, c; scanf("%d %d %d %d", &xc, &yc, &r, &c);
        shapes.push_back(new Circle(xc, yc, r, c));
      }else if (!strcmp(type, "Diamond")){
        int xc, yc, r, c; scanf("%d %d %d %d", &xc, &yc, &r, &c);
        shapes.push_back(new Diamond(xc, yc, r, c));
      }else if (!strcmp(type, "Rectangle")){
        int xc, yc, l, w, c; scanf("%d %d %d %d %d", &xc, &yc, &l, &w, &c);
        shapes.push_back(new Rectangle(xc, yc, l, w, c));
      }else if (!strcmp(type, "Triangle")){
        int xc, yc, w, c; scanf("%d %d %d %d", &xc, &yc, &w, &c);
        shapes.push_back(new Triangle(xc, yc, w, c));
      }else assert(0);
    }
    int total[10] = {0};
    memset(total, 0, sizeof(total));
    for (int x = 0; x < n; x++){
      line.init();
      for (int i = q - 1; i >= 0; i--){
        //printf("%d %d: \n", x, i);
        Interval interval = shapes[i]->getInterval(x);
        int c = shapes[i]->c; 
        total[c] += line.countZeroAndSet(interval, c);
      }
      //line.debug();
    }
    for (int i = 1; i <= 9; i++){
      if (i != 1) printf(" ");
      printf("%d", total[i]);
    }
    printf("\n");
  }
}

