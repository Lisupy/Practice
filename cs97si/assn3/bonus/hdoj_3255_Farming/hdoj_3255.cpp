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
const int maxnode = 1 << 18;
int n, m;
int p[4];
vector<int> sortedP;
vector<int> xs;
vector<int> ys;
struct IntervalTree{
  struct Node{
    int o, L, R;
    int m() const { return (L + R) / 2; }
    int lo() const { return o * 2; }
    int ro() const { return o * 2 + 1; }
    //int sz() const { return R - L + 1; }
    int value() const { return ys[R + 1] - ys[L];}
    Node(int _o, int _L, int _R) : o(_o), L(_L), R(_R) {}
    Node lch() const { return Node(lo(), L, m()); }
    Node rch() const { return Node(ro(), m() + 1, R); }
    bool isLeaf() const { return L == R; }
  };
  int qL, qR;
  int color_cnt[maxnode][4];
  int color[maxnode][4];
  bool overlap(const Node &no){
    return qL <= no.R && no.L <= qR;
  }
  bool contain(const Node &no){
    return qL <= no.L && no.R <= qR;
  }
  i64 query(){
    i64 total = 0;
    for (int i = 0; i <= 3; i++){
      //printf("%d==>%d\n", i, color_cnt[1][i]);
      total += (i64)sortedP[i] * color_cnt[1][i];
    }
    return total;
  }
  void pushUp(const Node &no){
    if (no.isLeaf()){
      color_cnt[no.o][0] = no.value();
      for (int i = 1; i <= 3; i++) color_cnt[no.o][i] = 0;
    }else{
      for (int i = 0; i <= 3; i++){
        color_cnt[no.o][i] = color_cnt[no.lo()][i] + color_cnt[no.ro()][i];
      }
    }
    for (int i = 3; i >= 0; i--){
      if (color[no.o][i]){
        for (int j = i - 1; j >= 0; j--){
          color_cnt[no.o][i] += color_cnt[no.o][j];
          color_cnt[no.o][j] = 0;
        }
        break;
      }
    }
  }
  void add(const Node &no, int c, int v){
    if (!overlap(no)) return;
    if (contain(no)){
      color[no.o][c] += v;
      pushUp(no);
    }else{
      add(no.lch(), c, v);
      add(no.rch(), c, v);
      pushUp(no);
    }
  }
  void _init(const Node &no){
    color[no.o][0] = no.value();
    color_cnt[no.o][0] = no.value();
    if (no.isLeaf()) return;
    _init(no.lch());
    _init(no.rch());
  }
  void init(const Node &no){
    memset(color, 0, sizeof(color));
    memset(color_cnt, 0, sizeof(color_cnt));
    _init(no);
  }
  IntervalTree& gao(int L, int R){
    qL = L, qR = R;
    return *this;
  }
};
struct Rect{
  int x1, y1, x2, y2, c;
};
vector<Rect> rects;
void input(){
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d", p + i);
  rects.resize(n);
  for (int i = 0; i < n; i++) {
    Rect &r = rects[i];
    scanf("%d %d %d %d %d", &r.x1, &r.y1, &r.x2, &r.y2, &r.c);
    if (r.x1 > r.x2) swap(r.x1, r.x2);
    if (r.y1 > r.y2) swap(r.y1, r.y2);
    r.x2--; r.y2--;
    assert(r.x1 <= r.x2);
    assert(r.y1 <= r.y2);
  }
}
struct Event{
  int x, y1, y2, color, inc;
  Event(int _x, int _y1, int _y2, int _c, int _i): x(_x), y1(_y1), y2(_y2), color(_c), inc(_i){}
};
bool operator<(const Event &a, const Event &b){
  return a.x < b.x;
}
vector<Event> events;
void eventsInit(){
  events.clear();
  sortedP.clear(); sortedP.resize(4);
  for (int i = 1; i <= m; i++) sortedP[i] = p[i];
  sort(sortedP.begin(), sortedP.end());

  for (int i = 0; i < n; i++) {
    Rect &r = rects[i];
    r.c = lower_bound(sortedP.begin(), sortedP.end(), p[r.c]) - sortedP.begin();
    events.push_back(Event(r.x1,     r.y1, r.y2 + 1, r.c,  1));
    events.push_back(Event(r.x2 + 1, r.y1, r.y2 + 1, r.c, -1)); 
  }
  xs.clear();
  ys.clear();
  for (size_t i = 0; i < events.size(); i++){
    Event &e = events[i];
    xs.push_back(e.x);
    ys.push_back(e.y1);
    ys.push_back(e.y2);
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());
  for (size_t i = 0; i < events.size(); i++){
    Event &e = events[i];
    e.x = lower_bound(xs.begin(), xs.end(), e.x) - xs.begin();
    e.y1 = lower_bound(ys.begin(), ys.end(), e.y1) - ys.begin();
    e.y2 = lower_bound(ys.begin(), ys.end(), e.y2) - ys.begin();
  }
  sort(events.begin(), events.end());
}
IntervalTree tree;
i64 solve(){
  i64 total = 0;
  //[0, 1, 2, 3]  ==> [0, 1, 2]  // len - 2; 
  //printf("xs: "); for (auto x : xs) printf("%3d", x); printf("\n");
  //printf("ys: "); for (auto y : ys) printf("%3d", y); printf("\n");
  IntervalTree::Node root(1, 0, ys.size() - 2); 
  tree.init(root);
  for (size_t i = 0; i < events.size(); i++){
    Event &e = events[i];
    if (i != 0){
      i64 s = tree.query();
      total += s * (xs[events[i].x] - xs[events[i - 1].x]);
      //printf("%lu: %lld %lld\n", i, s, total);
    }
    //printf("%lu: %d , %d - %d, color: %d %d\n", i, e.x, e.y1, e.y2, e.color, e.inc);
    tree.gao(e.y1, e.y2 - 1).add(root, e.color, e.inc);
  }
  return total;
}


int TestNum;
int main(){
  int T; scanf("%d", &T);
  while (T--){
    input();
    eventsInit();
    i64 ans = solve();
    //printf("Case %d: %I64d\n", ++TestNum, ans);
    //For hdoj(Win32,mingw?), the i64 format is %I64d, but get a compile error on linux
    cout << "Case " << ++TestNum << ": " << ans << endl;
  }
}

