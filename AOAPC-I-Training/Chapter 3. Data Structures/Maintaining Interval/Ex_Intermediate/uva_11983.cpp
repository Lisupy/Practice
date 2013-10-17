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

const int maxnode = 1 << 17;
int k;
vector<int> xs;
vector<int> ys;
struct IntervalTree{
  struct Node{
    int o, L, R;
    int m()  const   { return (L + R) / 2; }
    int lo() const   { return o * 2; }
    int ro() const   { return o * 2 + 1; }
    Node lch() const { return {lo(), L,       m()}; }
    Node rch()  const{ return {ro(), m() + 1, R}; }
    int value()const { return xs[R + 1] - xs[L]; }
    bool isLeaf() const { return L == R; }
  };
  int cover[maxnode];
  int cnt[maxnode][11];
  int qL, qR;
  void init(const Node& no){
    memset(cnt[no.o], 0, sizeof(cnt[no.o]));
    cover[no.o] = 0;
    cnt[no.o][0] = no.value();
    if (no.isLeaf()){
      return;
    }else{
      init(no.lch());
      init(no.rch());
    }
  }
  bool overlap(const Node& no){
    return qL <= no.R && no.L <= qR;
  }
  bool contain(const Node& no){
    return qL <= no.L && no.R <= qR;
  }
  void pushUp(const Node& no){
    //assert(cover[no.o] == 0);
    for (int i = 0; i <= 10; i++){ 
      cnt[no.o][i] = cnt[no.lo()][i] + cnt[no.ro()][i];
    }
    for (int i = 10; i >= 0; i--){
      cnt[no.o][i] = i - cover[no.o] >= 0 ? cnt[no.o][i - cover[no.o]] : no.value();
    }
  }
  void pushDown(const Node& no){
    assert(0);
    if (cover[no.o]){
      add(no.lch(), cover[no.o], true);
      add(no.rch(), cover[no.o], true);
      cover[no.o] = 0;
      pushUp(no);
    }
  }
  void add(const Node& no, int v, bool push = false){
    //assert(v == 1 || v == -1);
    if (!push && !overlap(no)) return;
    if (push || contain(no)){
      cover[no.o] += v;
      if (no.isLeaf()){
        assert(cover[no.o] >= 0);
        for (int i = 0; i <= min(cover[no.o], 10); i++) cnt[no.o][i] = no.value();
        for (int i = max(0, cover[no.o] + 1); i <= 10; i++) cnt[no.o][i] = 0;
        return;
      }else if (cover[no.o] >= 0){
        pushUp(no);
      }else{
        assert(0);
        //pushDown(no);
      }
    }else{
      //assert(!no.isLeaf());
      //pushDown(no);
      add(no.lch(), v);
      add(no.rch(), v);
      pushUp(no);
    }
  }
  int query(const Node& no, int atLeast){
    if (!overlap(no)) return 0;
    if (contain(no)){
      if (atLeast <= 0) return no.value();
      //printf("%d: %d %d, %d\n", no.o, no.L, no.R, cnt[no.o][atLeast]);
      return cnt[no.o][atLeast];
    }else{
      //pushDown(no);
      assert(cover[no.o] >= 0);
      int total = 0;
      total += query(no.lch(), atLeast - cover[no.o]);
      total += query(no.rch(), atLeast - cover[no.o]);
      //printf("%d: %d %d, %d\n", no.o, no.L, no.R, total);
      return total;
    }
  }
  IntervalTree& gao(int L, int R){
    qL = L, qR = R;
    return *this;
  }
};

struct Rect{
  int x1, x2, y1, y2;
};
void compress(vector<Rect> &rects){
  xs.clear(); ys.clear();
  for (size_t i = 0; i < rects.size(); i++){
    Rect &r = rects[i];
    r.x2++, r.y2++;
    xs.push_back(r.x1), xs.push_back(r.x2);
    ys.push_back(r.y1), ys.push_back(r.y2);
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
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

struct Event{
  int tick, from, to, inc;
  void debug() const {
    printf ("tick: %d, %d - %d, %d\n", tick, from, to, inc);
  }
};
bool operator<(const Event &a, const Event &b){
  return a.tick < b.tick;
}
vector<Event> eventsFromRect(vector<Rect> rects){
  vector<Event> evs;
  for (size_t i = 0; i < rects.size(); i++){
    Rect &r = rects[i];
    evs.push_back({r.y1, r.x1, r.x2 - 1,  1});
    evs.push_back({r.y2, r.x1, r.x2 - 1, -1});
  }
  sort(evs.begin(), evs.end());
  return evs;
}

IntervalTree tree;
i64 solve(vector<Rect> rects){
  compress(rects);
  vector<Event> evs = eventsFromRect(rects);
  i64 total = 0;
  IntervalTree::Node root = {1, 0, (int)xs.size() - 2};
  tree.init(root);
  for (size_t i = 0; i < evs.size(); i++){
    Event &e = evs[i];
    if (i != 0){
      i64 s = tree.gao(0, (int)xs.size() - 2).query(root, k);
      //printf("%lld\n", s);
      total += s * (ys[evs[i].tick] - ys[evs[i - 1].tick]);
    }
    //e.debug();
    //printf("%lu: %lld\n", i, total); 
    tree.gao(e.from, e.to).add(root, e.inc);
  }
  return total;
}

int TestNum;
int main(){
  int T; scanf("%d", &T);
  while (T--){
    int n; scanf("%d %d", &n, &k);
    vector<Rect> rects(n);
    for (int i = 0; i < n; i++){
      Rect &r = rects[i];
      scanf("%d %d %d %d", &r.x1, &r.y1, &r.x2, &r.y2);
    }
    i64 ans = solve(rects);
    printf("Case %d: %lld\n", ++TestNum, ans);
  }
}

