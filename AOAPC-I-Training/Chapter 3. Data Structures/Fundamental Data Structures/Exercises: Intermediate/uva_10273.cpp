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

int N;
int T[1024];
int M[1024][16];

void input(){
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> T[i];
    for (int j = 0; j < T[i]; j++){
      cin >> M[i][j];
    }
  }
}

typedef pair<int, int> PII;

void solve(){
  priority_queue<PII, vector<PII>, greater<PII> > P[16][16];
  vector<bool> eaten(N);
  for (int i = 0; i < N; i++){
    for (int j = 0; j < T[i]; j++){
      P[T[i]][j].push(make_pair(M[i][j], i));
    }
  }
  int last_eaten = -1;
  for (int ndays = 0; ndays <= last_eaten + 7*8*9*10; ndays++){
    int least_milk = 0xffffff;
    int eaten_cow = -1;
    for (size_t cycle = 1; cycle <= 10; cycle++){
      priority_queue<PII, vector<PII>, greater<PII> > &p = P[cycle][ndays % cycle];
      while (p.size() && eaten[p.top().second]) p.pop();
      if (p.size()){
        if (p.top().first < least_milk){
          least_milk = p.top().first;
          eaten_cow = p.top().second;
          p.pop();
          while (p.size() && eaten[p.top().second]) p.pop();
          if (p.size() && least_milk == p.top().first){
            p.push(make_pair(least_milk, eaten_cow));
            eaten_cow = -1;
          }else{
            p.push(make_pair(least_milk, eaten_cow));
          }
        }else if (p.top().first == least_milk){
          eaten_cow = -1;
        }
      }
    }
    //printf("ndays: %d, eaten: %d, milk: %d\n", ndays, eaten_cow, least_milk);
    //getchar();
    if (eaten_cow != -1){
      eaten[eaten_cow] = true;
      last_eaten = ndays;
    }
  }
  cout << count(eaten.begin(), eaten.end(), false) << " " << last_eaten + 1 << endl;
}
int TestNum;
int main(){
  cin >> TestNum;
  while (TestNum--){
    input();
    solve();
  }
}

