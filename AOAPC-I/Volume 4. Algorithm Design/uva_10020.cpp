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
struct Seg{
  int L, R;
};

bool operator<(const Seg &a, const Seg &b){
  return a.L < b.L;
}



vector<Seg> minCover(vector<Seg> segs, int M){
  //cout << "minCover" << endl;
  int maxR = 0;
  vector<Seg> res;
  //for (size_t i = 0; i < segs.size(); i++) {
    //printf("%d %d\n", segs[i].L, segs[i].R);
  //}
  for (size_t l = 0, r = 0; l < segs.size() && maxR < M; l = r){
    int nMaxR = maxR;
    Seg s;
    while (r < segs.size() && segs[r].L <= maxR){
      if (segs[r].R > nMaxR){
        s = segs[r];
        nMaxR = segs[r].R;
      }
      r++;
    }
    if (maxR == nMaxR){
      break;
    }
    //printf("%d %d => %lu %lu\n", maxR, nMaxR, l, r);
    //getchar();
    maxR = nMaxR;
    res.push_back(s);
  }
  if (maxR < M){
    return vector<Seg>();
  }else{
    return res;
  }
}


int main(){
  int TestNum;
  cin >> TestNum;
  while (TestNum--){
    int M;
    cin >> M;
    vector<Seg> segs;
    int l, r;
    while (cin >> l >> r){
      if (l == 0 && r == 0){
        break;
      }
      segs.push_back({l, r});
    }
    sort(segs.begin(), segs.end());
    vector<Seg> ans = minCover(segs, M);
    cout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); i++) {
      cout << ans[i].L << " " << ans[i].R << endl;
    }
    if (TestNum){
      cout << endl;
    }
  }
}
