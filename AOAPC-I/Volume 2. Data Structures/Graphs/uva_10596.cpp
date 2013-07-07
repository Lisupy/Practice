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

const int MAXN = 256;
int degree[MAXN];
int p[MAXN];
void reset(){
  memset(degree, 0, sizeof(degree));
  for (int i = 0; i < MAXN; i++){
    p[i] = i;
  }
}

int find(int u){
  return p[u] == u ? u : p[u] = find(p[u]);
}

void join(int u, int v){
  int pu = find(u);
  int pv = find(v);
  if (pu != pv){
    p[pu] = pv;
  }
}
int N, R;


bool isExistEulerCycle(){
  for (int i = 0; i < MAXN; i++){
    if (degree[i] % 2 == 1){
      return false;
    }
  }
  int id = -1;
  for (int i = 0; i < N; i++){
    //if (degree[i] != 0){
      if (id == -1){
        id = find(i);
      }
      if (id != find(i)){
        return false;
      }
    //}
  }
  return true;
}

int main(){
  while (scanf("%d %d", &N, &R) != EOF){
    reset();
    for (int i = 0; i < R; i++){
      int s, t;
      scanf("%d %d", &s, &t);
      degree[s]++;
      degree[t]++;
      join(s, t);
    }
    if (isExistEulerCycle()){
      printf("Possible\n");
    }else{
      printf("Not Possible\n");
    }
  }
}
