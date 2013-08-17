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


void solve(){
  int M, N; cin >> M >> N;
  vector<int> A(M); for (int i = 0; i < M; i++) cin >> A[i];
  vector<int> u(N); for (int i = 0; i < N; i++) cin >> u[i];
  priority_queue<int, vector<int>, less<int> > q1;
  priority_queue<int, vector<int>, greater<int> > q2;
  int j = 0;
  for (int i = 0; i < N; i++){
    int k = u[i];
    for (; j < k; j++){
      int x = A[j];
      if (q2.empty()) q1.push(x);
      else if (q2.top() <= x) q2.push(x);
      else q1.push(x);
    }
    while ((int)q1.size() > i) q2.push(q1.top()), q1.pop();
    while ((int)q1.size() < i) q1.push(q2.top()), q2.pop();
    cout << q2.top() << endl;
  }
}


int TestNum;
int main(){
  cin >> TestNum;
  while (TestNum--){
    solve();
    if (TestNum) cout << endl;
  }

}

