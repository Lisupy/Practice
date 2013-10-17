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



int TestNum;
int main(){
  int t; 
  while (cin >> t && t){
    cout << "Scenario #" << ++TestNum << endl;
    map<int, int> M;
    for (int i = 0; i < t; i++){
      int n; cin >> n;
      while (n--){
        int x; cin >> x;
        M[x] = i;
      }
    }
    vector<queue<int> > que;
    int head = 0;
    vector<int> pos(t, -1);
    string cmd;
    while (cin >> cmd){
      //cout << "[ "  << cmd  << "]" << endl;;
      if (cmd == "STOP")break; 
      if (cmd == "ENQUEUE"){
        int x; cin >> x;
        int tx = M[x];
        if (pos[tx] == -1){
          pos[tx] = que.size();
          que.push_back(queue<int>());
        }
        que[pos[tx]].push(x);
      }else{
        int n = que[head].front(); que[head].pop();
        cout << n << endl;
        if (que[head].empty()) pos[M[n]] = -1, head++;
      }
    }
    cout << endl;
  }
}

