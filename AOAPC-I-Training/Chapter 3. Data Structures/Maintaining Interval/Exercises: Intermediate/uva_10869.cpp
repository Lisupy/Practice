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
const int INF = 0x1f1f1f1f;
const int MAXN = 200010;
int n;
int y_max;
int x_max;
//bool Less(const pair<int, int> &a, const pair<int, int> &b){
  //if (a.first != b.first) return a.first < b.first;
  //return a.second > b.second;
//}
void compress(vector<pair<int, int> > &points){
  vector<int> xs;
  vector<int> ys;
  xs.push_back(-INF);
  ys.push_back(-INF);
  for (size_t i = 0; i < points.size(); i++){
    xs.push_back(points[i].first);
    ys.push_back(points[i].second);
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());
  for (size_t i = 0; i < points.size(); i++){
    points[i].first = lower_bound(xs.begin(), xs.end(), points[i].first) - xs.begin(); 
    points[i].second = lower_bound(ys.begin(), ys.end(), points[i].second) - ys.begin(); 
  }
  x_max = xs.size();
  y_max = ys.size();
  sort(points.begin(), points.end());
}

struct FenwickTree{
  int cnt[MAXN];
  int sz;
  void reset(int len){
    sz = len;
    memset(cnt, 0, sizeof(cnt));
  }
  int lowbit(int x) { return x & -x; }
  int sum(int pos){
    int total = 0;
    while (pos){
      total += cnt[pos];
      pos -= lowbit(pos);
    }
    return total;
  }
  void add(int pos, int x){
    while (pos <= sz){
      cnt[pos] += x;
      pos += lowbit(pos);
    }
  }
  int sumRange(int l, int r){
    return sum(r) - sum(l - 1);
  }
};
FenwickTree tree;
int TestNum;
int main(){
  while (cin >> n && n){
    vector<pair<int, int> > points(n);
    vector<pair<int, int> > cnt(n);
    for (int i = 0; i < n; i++) cin >> points[i].first >> points[i].second;
    //for (int i = 0; i < n; i++) swap(points[i].first, points[i].second);
    compress(points);
    //for (auto p : points) cout << p.first << ", " << p.second << endl;
    tree.reset(y_max);
    for (int l = 0, r = 0; l < n; l = r){
      while (r < n && points[r].first == points[l].first) r++;
      for (int i = l; i < r; i++){
        cnt[i].first += tree.sumRange(1, points[i].second - 1);
        cnt[i].second += tree.sumRange(points[i].second + 1, y_max);
        //printf("%d : %d %d\n", i, cnt[i].first, cnt[i].second);
      }
      for (int i = l; i < r; i++) tree.add(points[i].second, 1);
    }
    tree.reset(y_max);
    for (int l = n - 1, r = l; r >= 0; r = l){
      while (l >= 0 && points[r].first == points[l].first) l--;
      for (int i = r; i > l; i--){
        cnt[i].first += tree.sumRange(points[i].second + 1, y_max);
        cnt[i].second += tree.sumRange(1, points[i].second - 1);
        //printf("%d : %d %d\n", i, cnt[i].first, cnt[i].second);
      }
      for (int i = r; i > l; i--) tree.add(points[i].second, 1);
    }
    vector<pair<int, int> > cnt2(x_max + 1, make_pair(INF, 0));
    for (int i = 0; i < n; i++){
      int x = points[i].first;
      if (cnt[i].first < cnt2[x].first){
        cnt2[x].first = cnt[i].first;
        cnt2[x].second = cnt[i].second;
      }else if (cnt[i].first == cnt2[x].first){
        cnt2[x].second = max(cnt2[x].second, cnt[i].second);
      }
      //printf("%d : %d %d, %d %d\n", i, cnt[i].first, cnt[i].second, cnt2[x].first, cnt2[x].second);
    }
    for (size_t i = 0; i < cnt2.size(); i++) if (cnt2[i].first == INF) cnt2[i].first = -1;
    int StanMax = 0;
    for (size_t i = 0; i < cnt2.size(); i++) StanMax = max(StanMax, cnt2[i].first); 
    vector<int> Ollie;
    for (size_t i = 0; i < cnt2.size(); i++) if (cnt2[i].first == StanMax) Ollie.push_back(cnt2[i].second);
    sort(Ollie.begin(), Ollie.end());
    Ollie.erase(unique(Ollie.begin(), Ollie.end()), Ollie.end());
    printf("Stan: %d; Ollie:", StanMax);
    for (size_t i = 0; i < Ollie.size(); i++){
      printf(" %d", Ollie[i]);
    }printf(";\n");
  }
}

