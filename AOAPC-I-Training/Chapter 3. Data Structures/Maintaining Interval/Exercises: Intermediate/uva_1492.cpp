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
const int MAXN = 50100 * 2;
struct Rect{
  int x1, y1, x2, y2;
};
int W, H, N, M;
vector<int> xs;
vector<int> ys;
void compress(vector<Rect> &rects){
  xs.resize(0);ys.resize(0);
  xs.push_back(0), ys.push_back(0);
  xs.push_back(W), ys.push_back(H);
  for (size_t i = 0; i < rects.size(); i++){
    Rect &r = rects[i];
    xs.push_back(r.x1), xs.push_back(r.x2);
    ys.push_back(r.y1), ys.push_back(r.y2);
  }
  sort(xs.begin(), xs.end()), sort(ys.begin(), ys.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());
  for (size_t i = 0; i < rects.size(); i++){
    Rect &r = rects[i];
    r.x1 = lower_bound(xs.begin(), xs.end(), r.x1) - xs.begin();
    r.x2 = lower_bound(xs.begin(), xs.end(), r.x2) - xs.begin();
    r.y1 = lower_bound(ys.begin(), ys.end(), r.y1) - ys.begin();
    r.y2 = lower_bound(ys.begin(), ys.end(), r.y2) - ys.begin();
  }
}
const int maxnode = 1 << 20;
const int maxrange = maxnode - 1;
struct IntervalTree{
  struct Node{
    int o, L, R;
    int lo() const { return o * 2; }
    int ro() const { return o * 2 + 1; }
    Node lch() const { return Node(o * 2,     L,              (L + R) / 2);   }
    Node rch() const { return Node(o * 2 + 1, (L + R) / 2 + 1, R         ); }
    //int  sz()  const { return  R - L - 1; }
    int value() const { /*printf("value: %d, %d\n", L, R);*/ return xs[R + 1] - xs[L]; } 
    Node(): o(1), L(0), R(0){}
    Node(int _o, int _L, int _R): o(_o), L(_L), R(_R) {}
    explicit Node(int Max) :o(1), L(0), R(Max) { }
    void dbg() const {
      printf("Node: %2d= %d, %d\n", o, L, R);
    }
    bool valid() const { return o < maxnode && L <= R;}
  };
  int qL, qR;
  int cnt[maxnode];
  int delay[maxnode];
  void init(){
    memset(cnt, 0, sizeof(cnt));
    memset(delay, 0, sizeof(delay));
  }
  bool overlap(const Node no){
    return qL <= no.R && no.L <= qR;
  }
  bool contained(const Node no){
    return qL <= no.L && no.R <= qR;
  }
  void pushUp(const Node no){
    assert(no.o < maxnode);
    assert(delay[no.o] == 0);
    assert(no.valid()); 
    cnt[no.o] = cnt[no.lo()] + cnt[no.ro()];
  }
  void pushDown(const Node no){
    if (delay[no.o]){
      update(no.lch(), delay[no.o], true);
      update(no.rch(), delay[no.o], true);
      delay[no.o] = 0;
    }
    assert(no.L <= no.R);
    pushUp(no);
  }
  void update(const Node no, int v, bool push = false){
    //no.dbg();
    if (!push && !overlap(no))return;
    assert(no.valid());
    if (push || contained(no)){
      delay[no.o] += v;
      if (no.L == no.R) {
        assert(delay[no.o] >= 0);
        cnt[no.o] = delay[no.o] > 0 ? no.value() : 0;
      }else{
        if (delay[no.o] > 0){
          cnt[no.o] = no.value();
        }else{
          assert(no.L <= no.R);
          pushDown(no);
        }
      }
    }else{
      assert(no.L != no.R);
      assert(no.L <= no.R);
      pushDown(no);
      update(no.lch(), v);
      update(no.rch(), v);
      assert(no.L <= no.R);
      pushUp(no);
    }
  }
  int query(const Node no){
    if (!overlap(no)) return 0;
    //assert(no.valid());
    if (contained(no)){
      return cnt[no.o];
    }else{
      pushDown(no);
      return query(no.lch()) + query(no.rch());
    }
  }
  IntervalTree& gao(int L, int R){
    //printf("gao(%d, %d)\n", L, R);
    qL = L, qR = R;
    return *this;
  }
};
IntervalTree tree;
struct Event{
  int tick;
  int from, to, inc;
  void debug(){
    printf("%2d, %2d -%2d, %2d\n", tick, from, to, inc);
  }
};
bool operator<(const Event &a, const Event &b){
  return a.tick < b.tick;
}
vector<Event> eventsFromRect(vector<Rect> rs){
  vector<Event> evs;
  for (size_t i = 0; i < rs.size(); i++){
    Rect &r = rs[i]; 
    evs.push_back({r.y1, r.x1, r.x2, 1});
    evs.push_back({r.y2, r.x1, r.x2, -1});
  }
  sort(evs.begin(), evs.end());
  return evs;
}
i64 solve(vector<Rect> rs){
  W -= M - 1; 
  for (size_t i = 0; i < rs.size(); i++){
    Rect &r = rs[i]; 
    r.x1 -= M - 1;
    r.x2++;
    r.y2++;

    r.x1--;
    r.x2--;
    r.x1 = max(0, r.x1);
    r.x1 = min(W, r.x1);
    r.x2 = max(0, r.x2);
    r.x2 = min(W, r.x2);
    //printf("%lu : %d %d, %d %d\n", i, r.x1, r.y1, r.x2, r.y2); 
  }
  compress(rs);
  //for (size_t i = 0; i < rs.size(); i++){
    //Rect &r = rs[i]; 
    //printf("%lu : %d %d, %d %d\n", i, r.x1, r.y1, r.x2, r.y2); 
  //}
  //printf ("W: %d, H: %d\n", W, H); 
  //printf("xs: "); for (auto i : xs) printf("%d ", i); printf("\n");
  //printf("ys: "); for (auto i : ys) printf("%d ", i); printf("\n");
  i64 total = 0;
  tree.init();
  IntervalTree::Node root(xs.size() - 1);
  //root.dbg();
  vector<Event> evs = eventsFromRect(rs);
  for (size_t i = 0; i < evs.size(); i++){
    //evs[i].debug();
    if (i != 0){
      int s = tree.gao(0, xs.size() - 1).query(root); 
      total += s * (i64)(ys[evs[i].tick] - ys[evs[i - 1].tick]);
      //printf("%lu: %d %lld\n", i, s, total);
    }
    //printf("from: %d , to: %d\n", xs[evs[i].from], xs[evs[i].to]);
    tree.gao(evs[i].from, evs[i].to - 1).update(root, evs[i].inc);
  }
  total = i64(W) * i64(H)  - total;
  W += M - 1;
  return total;
}
int TestNum;
int main(){
  while (scanf("%d %d %d %d", &W, &H, &N, &M) != EOF){
    vector<Rect> rects(N);
    for (int i = 0; i < N; i++){
      Rect &r = rects[i];
      scanf("%d %d %d %d", &r.x1, &r.y1, &r.x2, &r.y2);
    }
    i64 total = solve(rects);
    //printf("%lld\n", total);
    for (int i = 0; i < N; i++){
      Rect &r = rects[i];
      swap(r.x1, r.y1), swap(r.x2, r.y2);
    }
    swap(W, H);
    total += solve(rects);
    printf("%lld\n", total);
  }
}
