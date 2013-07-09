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
int h;

map<pair<vector<int>, pair<int, int> >, bool> cache;
bool isValid(vector<int> a, int k, int m){
  //cout << a.size() << ": " << k << ", " << m << endl;
  //pair<vector<int>, pair<int, int> > p = make_pair(a, make_pair(m, k));
  //if (cache.count(p)){
    //return cache[p];
  //}
  //bool &s = cache[p];
  bool s = false;
  if (m <= k){
    return s = true;
  }
  if (k == 0){
    return s = false;
  }
  for (int i = a.size() - 1; i > 0; i--){
    if (a[i] <= m && isValid(a, k - 1, m - a[i])){
      return s = true;
    }
  }
  return s = false;
}
    
int minNot(vector<int> a, int k){
  int i = 0;
  while (isValid(a, k, i)){
    i++;
  }
  return i;
}
int best;
vector<int> bestA;
int k;
void dfs(int cur, vector<int> a){
  int leastNot = minNot(a, k);
  //cout << "#" << cur << ", " <<  leastNot << endl;
  if (cur == h){
    if (leastNot > best){
      best = leastNot;
      bestA = a;
    }
  }else{
    a.push_back(a.back());
    for (int t = a.back() + 1; t <= leastNot; t++){
      a.back() = t;
      dfs(cur + 1, a);
    }
  }
}


int main(){
  while (cin >> k >> h && h){
    best = 0;
    vector<int> a(1, 1);
    dfs(1, a);
    for (size_t i = 0; i < bestA.size(); i++){
      printf("%3d", bestA[i]);
    }
    printf(" ->%3d\n", best - 1);
  }
}
