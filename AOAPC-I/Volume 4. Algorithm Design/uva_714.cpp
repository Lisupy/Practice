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

long long getNeed(vector<long long> p, long long sum, bool print, long long k){
  long long total = 0;
  long long s = 0;
  //cout << sum << endl;
  //cout << k << endl;
  vector<vector<long long> > ps(1);
  if (print){
    reverse(p.begin(), p.end());
  }
  for (size_t l = 0; l < p.size(); l++){
    if (print){
      //cout << k - ps.size() << ", " << p.size() - l << endl;
    }
    if (s + p[l] > sum || k - ps.size() == p.size() - l){
      if (print){
        ps.push_back(vector<long long>());
      }
      s = 0;
      total++;
    }
    if (print){
      ps.back().push_back(p[l]);
    }
    s += p[l];
  }
  if (print){
    reverse(ps.begin(), ps.end());
    for (size_t i = 0; i < ps.size(); i++){
      reverse(ps[i].begin(), ps[i].end());
      if (i != 0){
        printf(" /");
      }
      //cout << ps[i].size();
      for (size_t j = 0; j < ps[i].size(); j++){
        if (i != 0 || j != 0){printf(" ");}
        printf("%lld", ps[i][j]);
      }
    }
  }
  return total + 1;
}


long long findMin(vector<long long> p, long long k){
  long long l = *max_element(p.begin(), p.end()), r = accumulate(p.begin(), p.end(), 0ll);
  while (l < r){
    long long mid = (l + r) / 2;

    long long partNum = getNeed(p, mid, false, 0);
    //printf("%d %d\n", mid, partNum);
    if (partNum > k){
      l = mid + 1;
    }else{
      r = mid;
    }
  }
  return r;
}


int main(){
  long long N;
  cin >> N;
  while (N--){
    long long m, k;
    cin >> m >> k;
    vector<long long> p(m);
    for (long long i = 0; i < m; i++) {
      cin >> p[i];
    }
    long long upper = findMin(p, k);
    //printf("[");
    getNeed(p, upper, true, k);
    //printf("]");
    cout << endl;
  }
}
      

