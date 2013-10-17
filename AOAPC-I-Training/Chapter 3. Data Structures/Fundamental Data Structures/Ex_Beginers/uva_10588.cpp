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
const int MAXN = 1024;
int n, m;
int t[MAXN];
queue<int> g[MAXN];
queue<int> qs[MAXN];
struct Event{
  int time;
  int type; //0 doctor, 1 visitor
  int visitor;
  int doctor;
  void dbg(){
    printf("%d %d, %d %d\n", time, type, visitor, doctor);
  }
};

bool operator<(const Event &a, const Event &b){
  if (a.time != b.time) return a.time > b.time;
  return a.visitor > b.visitor;
}

void input(){
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++){
    int k; scanf("%d %d", &t[i], &k);
    while (k--){
      int tmp; scanf("%d", &tmp);
      g[i].push(tmp);
    }
  }
}

void gao(){
  priority_queue<Event> Q;
  for (int i = 0; i < n; i++){
    //printf("%d\n", t[i]);
    Q.push({t[i], 1, i, 0});
  }
  int last_tick = 0;
  while (!Q.empty()){
    Event e = Q.top(); Q.pop();
    //e.dbg();
    int tick = e.time;
    last_tick = tick;
    if (e.type == 1){
      if (!g[e.visitor].empty()){
        int doctor = g[e.visitor].front(); g[e.visitor].pop();
        bool isEmpty = qs[doctor].empty();
        qs[doctor].push(e.visitor);
        if (isEmpty){
          Q.push({tick + 1, 0, e.visitor, doctor});
        }
      }
    }else{
      int visitor = qs[e.doctor].front();qs[e.doctor].pop();
      assert(visitor == e.visitor);
      if (!qs[e.doctor].empty()){
        Q.push({tick + 1, 0, qs[e.doctor].front(), e.doctor});
      }
      if (!g[e.visitor].empty()){
        int doctor = g[e.visitor].front(); g[e.visitor].pop();
        bool isEmpty = qs[doctor].empty();
        qs[doctor].push(e.visitor);
        if (isEmpty){
          Q.push({tick + 1, 0, e.visitor, doctor});
        }
      }
    }
  }
  cout << last_tick << endl;
}
int TestNum;
int main(){
  cin >> TestNum;
  while (TestNum--) {
    input();
    gao();
  }
}

