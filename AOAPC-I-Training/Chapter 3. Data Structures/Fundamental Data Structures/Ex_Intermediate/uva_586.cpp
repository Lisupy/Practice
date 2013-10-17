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

vector<int> arr_add(vector<int> total, vector<int> a, int shift){
  if (shift) a.insert(a.begin(), 0);
  total.resize(max(a.size(), total.size()));
  for (size_t i = 0; i < a.size(); i++) total[i] += a[i];
  return total;
}
vector<int> arr_mul(vector<int> total, int k){
  for (size_t i = 0; i < total.size(); i++) total[i] *= k;
  return total;
}
vector<int> solve(){
  string cmd;
  vector<int> total(2);
  while (cin >> cmd){
    if (cmd == "BEGIN") continue;
    if (cmd == "END"){
      //for (auto i : total) cout << i << ", "; cout << endl;
      return total;
    }
    if (cmd == "OP"){
      string cost; cin >> cost;
      //cout << cost << endl;
      total[0] += atoi(cost.c_str());
    }
    if (cmd == "LOOP"){
      string cost; cin >> cost;
      if (cost == "n") total = arr_add(total, solve(), 1); 
      else total = arr_add(total, arr_mul(solve(), atoi(cost.c_str())), 0);
    }
  }
  return total;
}
void output(vector<int> a){
  cout << "Runtime = ";
  while (a.size() && a.back() == 0) a.pop_back();
  if (a.size() == 0) cout << "0";
  for (int i = a.size() - 1; i >= 0; i--){
    if (a[i]){
      if (i != (int)a.size() - 1) cout << "+";
      if (i == 0 || a[i] != 1) cout << a[i];
      if (i >= 1 && a[i] != 1) cout << "*";
      if (i >= 2) cout << "n^" << i;
      else if (i == 1) cout << "n"; 
    }
  }
  cout << endl;
}
int TestNum;
int main(){
  int T; cin >> T;
  while (T--){
    cout << "Program #" << ++TestNum << endl;
    output(solve());
    cout << endl;
  }
}

