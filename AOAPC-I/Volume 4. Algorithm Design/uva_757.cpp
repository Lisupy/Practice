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
int n;
vector<int> f;
vector<int> d;
vector<int> t;

int calc(int i, vector<int> &plan){
  plan.clear();
  plan.resize(n);
  vector<int> f1 = f;
  int remain = h * 12 - t[i];
  //printf("###%d %d\n", i, remain);
  int s = 0;
  while (remain > 0){
    int pos = max_element(f1.begin(), f1.begin() + i + 1) - f1.begin();
    plan[pos]++;
    s += f1[pos];
    f1[pos] -= d[pos];
    if (f1[pos] < 0) f1[pos] = 0;
    remain--;
  }
  //printf("%d\n", s);
  return s;
}


void solve(){
  vector<int> bestPlan;
  int best = -1;
  for (int i = 0; i < n; i++){
    vector<int> plan;
    int expect = calc(i, plan);
    if (best < expect){
      best = expect;
      bestPlan = plan;
    }
  }
  for (size_t i = 0; i < bestPlan.size(); i++){
    if (i != 0)printf(", ");
    printf("%d", bestPlan[i] * 5);
  }
  printf("\n");
  printf("Number of fish expected: %d\n", best);
}
int main(){
  int TestNum = 0;
  while (cin >> n && n){
    if (TestNum++){
      cout << endl;
    }
    cin >> h;
    f.resize(n);
    d.resize(n);
    t.resize(n);
    for (int i = 0; i < n; i++){
      cin >> f[i];
    }
    for (int i = 0; i < n; i++){
      cin >> d[i];
    }
    for (int i = 1; i < n; i++){
      cin >> t[i];
    }
    partial_sum(t.begin(), t.end(), t.begin());
    solve();
  }
}

