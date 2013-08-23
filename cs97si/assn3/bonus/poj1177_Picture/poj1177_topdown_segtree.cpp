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

const int MAXN = (1 << 15 ) * 2;
const int RANGE = MAXN / 2 - 1; // [0, RANGE]
const int SHIFT = 10000;
//static_assert(MAXN > 20000, "MAXN");
int n;

struct Rect{
  int x1, x2;
  int y1, y2;
};

int tree_cover[MAXN];
int tree_count[MAXN];
void init(){
  memset(tree_cover, 0, sizeof(tree_cover));
  memset(tree_count, 0, sizeof(tree_count));
}

void update_tree_cover(int rt, int s, int t){
  if (tree_count[rt] > 0){
    tree_cover[rt] = t - s + 1;
  }else if (tree_count[rt] == 0){
    if (s == t) tree_cover[rt] = 0;
    else tree_cover[rt] = tree_cover[rt * 2] + tree_cover[rt * 2 + 1];
  }else{ // tree_count[rt] < 0
    assert(0);
  }
}
void add(int rt, int s, int t, int l, int r, int inc){
  assert(1 <= rt && rt < MAXN);
  if (l > t || r < s) return;
  if (l <= s && t <= r){
    tree_count[rt] += inc;
    update_tree_cover(rt, s, t);
    return;
  }
  int mid = (s + t) / 2;
  add(rt * 2,     s,     mid, l, r, inc);
  add(rt * 2 + 1, mid + 1, t, l, r, inc);
  update_tree_cover(rt, s, t);
}

int query(int rt, int /*s*/, int /*t*/, int /* l */ , int /* r */){
  assert(1 == rt);
  return tree_cover[rt];
}
struct Event{
  int inc;
  int l, r;
  int tick;
};

bool operator<(const Event &a, const Event &b){
  if (a.tick != b.tick ) return a.tick < b.tick;
  return a.inc > b.inc;
}

int solve(vector<Rect> rects){
  vector<Event> evs;
  for (size_t i = 0; i < rects.size(); i++){
    Rect &r = rects[i];
    evs.push_back({1, r.x1, r.x2 - 1, r.y1});
    evs.push_back({-1, r.x1, r.x2 - 1, r.y2});
  }
  sort(evs.begin(), evs.end());
  int total = 0;
  int cover = 0;
  init();
  for (size_t i = 0; i < evs.size(); i++){
    add(1, 0, RANGE, evs[i].l, evs[i].r, evs[i].inc); 
    int new_cover = query(1, 0, RANGE, 0, RANGE);
    //cout << new_cover << endl;
    total += abs(new_cover - cover);
    cover = new_cover;
  }
  //cout << endl;
  return total;
}

int TestNum;
int main(){
  //cout << MAXN << endl;
  while (cin >> n){ // for hdu1828
    vector<Rect> rects(n);
    for (int i = 0; i < n; i++){
      scanf("%d%d%d%d", &rects[i].x1, &rects[i].y1, &rects[i].x2, &rects[i].y2);
      if (rects[i].x1 > rects[i].x2) swap(rects[i].x1, rects[i].x2);
      if (rects[i].y1 > rects[i].y2) swap(rects[i].y1, rects[i].y2);
      rects[i].x1 += SHIFT;
      rects[i].y1 += SHIFT;
      rects[i].x2 += SHIFT;
      rects[i].y2 += SHIFT;
    }
    int total = 0;
    total += solve(rects);
    for (int i = 0; i < n; i++){
      swap(rects[i].x1, rects[i].y1);
      swap(rects[i].x2, rects[i].y2);
    }
    total += solve(rects);
    printf("%d\n", total);
  }
}



