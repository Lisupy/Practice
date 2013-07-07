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
int TestNum;

const int MAXN = 64;
int mat[MAXN][MAXN];
int degree[MAXN];
int from = 0;
vector<pair<int, int> > path;
int N;
void input(){
  memset(mat, 0, sizeof(mat));
  memset(degree, 0, sizeof(degree));
  cin >> N;
  for (int i = 0; i < N; i++){
    int s, t;
    cin >> s >> t;
    mat[s][t]++;
    mat[t][s]++;
    degree[s]++;
    degree[t]++;
    from = s;
  }
}

void euler_path(int s){
  for (int i = 0; i < MAXN; i++){
    if (mat[s][i]){
      mat[s][i]--;
      mat[i][s]--;
      euler_path(i);
      path.push_back(make_pair(i, s));
    }
  }
}

int main(){
  cin >> TestNum;
  for (int ti = 1; ti <= TestNum; ti++){
    if (ti != 1){
      printf("\n");
    }
    printf("Case #%d\n", ti);
    input();
    int oddCnt = 0;
    for (int i = 0; i < MAXN; i++){
      if (degree[i] % 2 != 0){
        oddCnt++;
      }
    }
    path.clear();
    euler_path(from);


    if (oddCnt == 0 && (int)path.size() == N && path.front().first == path.back().second){
      for (size_t i = 0; i < path.size(); i++){
        printf("%d %d\n", path[i].first, path[i].second);
      }
    }else{
      printf("some beads may be lost\n");
    }
  }
}
  
