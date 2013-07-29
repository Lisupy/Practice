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

int gcd(int a, int b){
  return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b){
  return a * b / gcd(a, b);
}
const int MAXD = lcm(lcm(10, 9), lcm(8, 7));
set<pair<int, int> > S[11][11];

int N;
const int MAXN = 1024;
bool dead[MAXN];
int T[1024];
int M[MAXN][11];

int cycle = 1;
void reset(){
  memset(T, 0, sizeof(T));
  memset(dead, 0, sizeof(dead));
  for (int i = 0; i <= 10; i++){
    for (int j = 0; j <= 10; j++){
      S[i][j].clear();
    }
  } 
}

void input(){
  scanf("%d", &N);
  cycle = 1;
  for (int i = 1; i <= N; i++){
    scanf("%d", &T[i]);
    for (int j = 0; j < T[i]; j++){
      scanf("%d", &M[i][j]);
    }
  }
}
void solve(){
  int lastKillDay = -1;
  cycle = 1; 
  int killNum = 0;
  for (int i = 1; i <= N; i++) cycle = lcm(cycle, T[i]);
  for (int i = 1; i <= N; i++){
    for (int j = 0; j < T[i]; j++){
      S[T[i]][j].insert(make_pair(M[i][j], i));
    }
  }
  for (int day = 0; day - lastKillDay <= cycle; day++){
    //getchar();
    //cout << "Day " << day << endl;
    int lessMilk = 0xffff;
    int canCow = -1;
    for (int i = 1; i <= 10; i++){
      //cout << "Cycle " << i << endl;
      set<pair<int, int> > &s  = S[i][i];
      set<pair<int, int> >::iterator it = s.begin();
      //while (it != s.end() && dead[it->second]) it = s.erase(it);
      if (it != s.end()){
        //cout << it->first << ", " << it->second << endl;
        if (it->first == lessMilk){
          canCow = -1;
        }else if (it->first < lessMilk){
          lessMilk = it->first;
          canCow = it->second;
          it++;
          //while (it != s.end() && dead[it->second]) it = s.erase(it);
          if (it != s.end() && it->first == lessMilk){
            canCow = -1;
          }
        }
      }
    }
    //cout << lessMilk << ", " << canCow << endl;
    if (canCow != -1){
      lastKillDay = day;
      for (int j = 0; j < T[canCow]; j++){
        S[T[canCow]][j].erase(make_pair(M[canCow][j], canCow));
      }
      killNum++;
    }  
  }
  cout << N - killNum << " " << lastKillDay + 1 << endl;
}

int main(){
  int TestNum; cin >> TestNum;
  while (TestNum--){
    reset();
    input();
    solve();
  }
}
