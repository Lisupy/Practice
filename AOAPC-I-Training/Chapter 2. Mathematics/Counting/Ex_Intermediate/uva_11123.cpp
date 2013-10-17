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
i64 C(i64 n, i64 k){
  if (n < k) return 0;
  i64 total = 1;
  for (i64 i = 0; i < k; i++) {
    total *= n - i;
    total /= i + 1;
  }
  return total;
}
i64 __solve(vector<pair<int, int> > ps){
  i64 total = 0;
  sort(ps.begin(), ps.end());
  //for (auto i : ps) cout << i.first << ", " << i.second << endl;
  for (size_t i1 = 0, i2 = 0; i1 < ps.size(); i1 = i2){
    while (i2 < ps.size() && ps[i1].first == ps[i2].first) i2++;
    for (size_t j1 = i2, j2 = i2; j1 < ps.size(); j1 = j2) {
      while (j2 < ps.size() && ps[j1].first == ps[j2].first) j2++;
      //printf("%lu %lu, %lu %lu\n", i1, i2, j1, j2);
      for (size_t k1 = i1; k1 < i2; k1++){
        for (size_t k2 = k1 + 1; k2 < i2; k2++){
          for (size_t k3 = j1; k3 < j2; k3++){
            size_t cnt = j2 - k3 - 1;
            if (cnt == 0) continue;
            pair<int, int> p(ps[j1].first, ps[k2].second - ps[k1].second + ps[k3].second);
            if (binary_search(ps.begin() + j1, ps.end() + j2, p)){
              cnt--;
            }
            //printf("%lu %lu %lu: %lu\n", k1, k2, k3, cnt);
            total += cnt;
          }
        }
      }
    }
  }
  return total;
}

i64 solve1(vector<pair<int, int> > ps){
  i64 total = 0;
  total += __solve(ps); 
  for (size_t i = 0; i < ps.size(); i++) {
    swap(ps[i].first, ps[i].second);
  }
  total += __solve(ps);
  return total;
}
bool isParallel(pair<int, int> a, pair<int, int> b, pair<int, int> c,pair<int, int> d){
  int x1 = a.first - b.first;
  int y1 = a.second - b.second;
  int x2 = c.first - d.first;
  int y2 = c.second - d.second;
  return y1 * x2 == x1 * y2;
}
int parallelCount(pair<int, int> a, pair<int, int> b, pair<int, int> c,pair<int, int> d){
  return  isParallel(a, b, c, d)
        + isParallel(a, c, b, d)
        + isParallel(a, d, b, c);
}
//AC 2.9559s
i64 solve2(vector<pair<int, int> > ps){
  i64 total = 0;
  sort(ps.begin(), ps.end());
  for (size_t i = 0; i < ps.size(); i++){
    for (size_t j = i + 1; j < ps.size(); j++){
      for (size_t k = j + 1; k < ps.size(); k++){
        for (size_t l = k + 1; l < ps.size(); l++){
          if (parallelCount(ps[i], ps[j], ps[k], ps[l]) == 1){
            total++;
          }
        }
      }
    }
  }
  return total;
}
int TestNum;
int main(){
  //cout << C(2, 2) << endl;
  int N;
  while (cin >> N && N) {
    vector<pair<int, int> > ps(N); 
    for (int i = 0; i < N; i++) {
      cin >> ps[i].first >> ps[i].second;
    }
    printf("Case %d: %lld\n", ++TestNum, solve2(ps));
  }
}

