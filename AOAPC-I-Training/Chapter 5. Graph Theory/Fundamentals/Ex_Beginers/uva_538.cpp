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
const double PI = acos(-1);
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
int n, t;
vector<string> person;
map<string, int> ms;
vector<int> account;
void reset(){
  person.clear();
  ms.clear();
  account.clear();
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (cin >> n >> t && n){
    reset();
    for (int i = 0; i < n; i++){
      string s; cin >> s;
      person.push_back(s);
      ms[s] = i;
    }
    account.resize(n);
    for (int i = 0; i < t; i++){
      string name1, name2;
      int amount;
      cin >> name1 >> name2 >> amount;
      account[ms[name1]] -= amount;
      account[ms[name2]] += amount;
    }
    cout << "Case #" << ++TestNum << endl;
    int total = 0;
    int start = -1;
    for (int i = 0; i < n; i++){
      if (account[i] > 0){
        if (start == -1) start = i;
        else cout << person[start] << " " << person[i] << " " << total << endl;
        start = i;
        total += account[i]; 
      }
    }
    for (int i = 0; i < n; i++){
      if (account[i] < 0){
        cout << person[start] << " " << person[i] << " " << -account[i] << endl;
      }
    }
    cout << endl;
  }
}

