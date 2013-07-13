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
int n;
vector<int> a;
map<int, int> cnt;

vector<vector<int> > b;
int TestNum;
int main(){
  while (scanf("%d", &n) && n){
    if (TestNum++){
      cout << endl;
    }
    a.resize(n);
    cnt.clear();
    int k = 0;
    for (int i = 0; i < n; i++){
      cin >> a[i];
      cnt[a[i]]++;
      k = max(k, cnt[a[i]]);
    }
    sort(a.begin(), a.end());
    b.clear();
    b.resize(k);
    for (size_t i = 0; i < a.size(); i++){
      b[i % k].push_back(a[i]);
    }
    cout << k << endl;
    for (size_t i = 0; i < b.size(); i++){
      for (size_t j = 0; j < b[i].size(); j++){
        if (j != 0) cout << " ";
        cout << b[i][j];
      }
      cout << endl;
    }
  }
}
