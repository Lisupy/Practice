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
struct Agency{
  string name;
  int A, B;
  long long cost;
  Agency():name(""), A(0), B(0), cost(0){};
};
const int MAXN = 100* 1024;
const long long INF = MAXN * 10000;
long long calc(int N, int M, int A, int B){
  static long long a[MAXN];
  fill(a + M, a + N + 1, INF); 
  a[M] = 0;
  for (int i = M; i <= N; i++){
    if (a[i] != INF){
      if (i + 1 <= N){
        a[i + 1] = min(a[i + 1], a[i] + A);
      }
      if (i * 2 <= N){
        a[i * 2] = min(a[i * 2], a[i] + B);
      }
      if (i * 2 + 1<= N){
        a[i * 2 + 1] = min(a[i * 2 + 1], a[i] + B);
      }
    }
  }
  return a[N];
}
bool operator<(const Agency &a, const Agency &b){
  if (a.cost != b.cost) return a.cost < b.cost;
  return a.name < b.name;
}
int N, M, L;
int main(){
  int TestNum;
  cin >> TestNum;
  for (int ti = 1; ti <= TestNum; ti++){
    cin >> N >> M >> L;
    cin.ignore();
    vector<Agency> ags(L);
    for (int i = 0; i < L; i++){
      string line;
      getline(cin, line);
      ags[i].name = line.substr(0, line.find(":"));
      ags[i].A = atoi(line.substr(line.find(":") + 1, line.find(",") - line.find(":") - 1).c_str());
      ags[i].B = atoi(line.substr(line.find(",") + 1).c_str());
      ags[i].cost = calc(N, M, ags[i].A, ags[i].B);
    }
    sort(ags.begin(), ags.end());
    printf("Case %d\n", ti);
    for (size_t i = 0; i < ags.size(); i++){
      cout << ags[i].name << " " << ags[i].cost << endl;
    }
  }
}
  
