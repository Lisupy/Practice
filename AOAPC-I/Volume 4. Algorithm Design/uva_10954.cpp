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

int getMin(queue<int> &q1, queue<int> &q2){
  if (q1.empty()){
    int s = q2.front();
    q2.pop();
    return s;
  }
  if (q2.empty()){
    int s = q1.front();
    q1.pop();
    return s;
  }
  if (q1.front() < q2.front()){
    int s = q1.front();
    q1.pop();
    return s;
  }else{
    int s = q2.front();
    q2.pop();
    return s;
  }
}
int solve(vector<int> a){
  sort(a.begin(), a.end());
  queue<int> q1;
  for (size_t i = 0; i < a.size(); i++){
    q1.push(a[i]);
  }
  queue<int> q2;
  int total = 0;
  while (q1.size() + q2.size() > 1){
    int d1 = getMin(q1, q2);
    int d2 = getMin(q1, q2);
    //cout << d1 << ", " << d2 << endl;
    q2.push(d1 + d2);
    total += d1 + d2;
  }
  return total;
}

int main(){
  int N;
  while (cin >> N && N){
    vector<int> a(N);
    for (int i = 0; i < N; i++){
      cin >> a[i];
    }
    cout << solve(a) << endl;
  }
}
