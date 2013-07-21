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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof
 */

struct Pos{
  int x, y;
};


bool operator<(const Pos &a, const Pos &b){
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}
int TestNum;

int main(){
  int R, C;
  while (scanf("%d %d", &R, &C) && R != -1){
    int x, y;
    vector<Pos> ps;
    while (scanf("%d %d", &x, &y) && x){
      Pos p = {x, y};
      ps.push_back(p);
    }
    assert(ps.size() > 0); 
    sort(ps.begin(), ps.end());
    vector<int> lis(ps.size(), 1);
    vector<long long> ways(ps.size(), 1);
    vector<int> path(ps.size(), -1);
    for (int i = 0; i < (int)ps.size(); i++){
      int best = 0;
      long long best_cnt = 1;
      for (int j = 0; j < i; j++){
        if (ps[i].y >= ps[j].y){
          if (lis[j] == best){
            best_cnt += ways[j];
          }if (lis[j] > best){
            best_cnt = ways[j];
            best = lis[j];
            path[i] = j;
          }
        }
        ways[i] = best_cnt;
        lis[i] = best + 1;
      }
    }
    int longest_lis = *max_element(lis.begin(), lis.end());
    long long longest_cnt = 0;
    for (size_t i = 0; i < lis.size(); i++) if (lis[i] == longest_lis) longest_cnt += ways[i];
    int pos = find(lis.begin(), lis.end(), longest_lis) - lis.begin();
    vector<int> ans;
    for (int i = 0; i < longest_lis; i++){
      ans.push_back(pos);
      pos = path[pos];
    }
    reverse(ans.begin(), ans.end());
    printf("CASE#%d: %d %lld", ++TestNum, longest_lis, longest_cnt);
    for (size_t i = 0; i < ans.size(); i++) printf(" %d", (ps[ans[i]].x - 1)* C + ps[ans[i]].y);
    printf("\n");
  }
}


