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
 * sizeof CLOCKS_PER_SEC
 */

const int MAXN = 20;
const int MAXM = 128;
int n, m;
struct Patch{
  int absent;
  int present;
  int fixed;
  int introduce;
  int time;
  int Fix(int st){
    if ((st & absent) != 0) return -1;
    if ((st & present) != present) return -1;
    st &= ((1 << n) - 1) ^ fixed;
    st |= introduce;
    return st;
  }
  Patch(int t, string s1, string s2): absent(0), present(0), fixed(0), introduce(0), time(t){
    for (int i = 0; i < n; i++){
      if (s1[i] == '+') present |= 1 << i;
      if (s1[i] == '-') absent |= 1 << i;
      if (s2[i] == '+') introduce |= 1 << i;
      if (s2[i] == '-') fixed |= 1 << i;
    }
  }
};

vector<Patch> patchs;

int timeNeed[1 << MAXN];
bool inQueue[1 << MAXN];
const int INF = 0x1f1f1f1f;
int solve(){
  memset(timeNeed, 0x1f, sizeof(timeNeed));
  memset(inQueue, 0, sizeof(inQueue));
  int start = (1 << n) - 1;
  timeNeed[start] = 0;
  queue<int> Q;
  Q.push(start);
  inQueue[start] = true;
  while (!Q.empty()){
    int s = Q.front(); 
    Q.pop();
    inQueue[s] = false;
    for (size_t i = 0; i < patchs.size(); i++) {
      Patch &p = patchs[i];
      int t = p.Fix(s);
      if (t != -1){
        if (timeNeed[t] > timeNeed[s] + p.time){
          timeNeed[t] = timeNeed[s] + p.time;
          if (!inQueue[t]){
            inQueue[t] = true;
            Q.push(t);
          }
        }
      }
    }
  }
  return timeNeed[0];
}
int TestNum;
int main(){
  while (cin >> n >> m && n){
    patchs.clear();
    for (int i = 0; i < m; i++){
      int t;
      string s1, s2;
      cin >> t >> s1 >> s2;
      patchs.push_back({t, s1, s2});
    }
    int ans = solve();
    printf("Product %d\n", ++TestNum);
    if (ans < INF){
      printf("Fastest sequence takes %d seconds.\n", ans);
    }else{
      printf("Bugs cannot be fixed.\n");
    }
    printf("\n");
  }
}



    
  
