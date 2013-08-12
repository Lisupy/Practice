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

void solve(int n){
  vector<int> valid(3, true);
  queue<int> C0; // 0
  priority_queue<int> C1; 
  stack<int> C2;
  while (n--) {
    int op, x;
    cin >> op >> x;
    if (op == 1){
      C0.push(x);
      C1.push(x);
      C2.push(x);
    }else{
      if (!C0.empty()){
        int t = C0.front(); C0.pop();
        if (t != x) valid[0] = false;
      }else{
        valid[0] = false;
      }
      if (!C1.empty()){
        int t = C1.top(); C1.pop();
        if (t != x) valid[1] = false;
      }else{
        valid[1] = false;
      }
      if (!C2.empty()){
        int t = C2.top(); C2.pop();
        if (t != x) valid[2] = false;
      }else{
        valid[2] = false;
      }
    }
  }
  if (count(valid.begin(), valid.end(), true) >= 2){
    cout << "not sure" << endl;
  }else if (count(valid.begin(), valid.end(), true) == 0){
    cout << "impossible" << endl;
  }else if (valid[0]){
    cout << "queue" << endl;
  }else if (valid[1]){
    cout << "priority queue" << endl;
  }else if (valid[2]){
    cout << "stack" << endl;
  }
}


int TestNum;
int main(){
  int n;
  while (cin >> n) {
    solve(n);
  }

}

