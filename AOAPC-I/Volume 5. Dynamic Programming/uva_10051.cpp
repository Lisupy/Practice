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

const int MAXN = 512 * 6;

vector<vector<int> > cubes;
int TestNum;
int N;
int M;
vector<int> links[MAXN]; 
string faces_str[] = {"front", "back", "left", "right", "top", "bottom"};
void solve(){
  M = N * 6;
  for (int i = 0; i < MAXN; i++){
    links[i].clear();
  }
  for (int i1 = 0; i1 < N; i1++){
    for (int j1 = 0; j1 < 6; j1++){
      int opj1 = j1 ^ 1;
      int v1 = i1 * 6 + j1; 
      //printf("%d %d\n", j1, opj1);
      for (int i2 = i1 + 1; i2 < N; i2++){
        for (int j2 = 0; j2 < 6; j2++){
          int v2 = i2 * 6 + j2;
          if (cubes[i1][opj1] == cubes[i2][j2]){
            links[v1].push_back(v2);
          }
        }
      }
    }
  }
  vector<int> hight(M);
  vector<int> path(M, -1);
  for (int i = 0; i < M; i++){
    int s = i;
    for (size_t j = 0; j < links[s].size(); j++){
      int t = links[s][j];
      if (hight[t] < hight[s] + 1){
        hight[t] = hight[s] + 1;
        path[t] = s;
      }
    }
    //printf("%d(%d) ", hight[i], path[i]);
  }
  //printf("\n");
  int pos = distance(hight.begin(), max_element(hight.begin(), hight.end()));
  //cout << pos << endl;
  vector<int> ans;
  while (pos != -1){
    ans.push_back(pos);
    pos = path[pos];
  }
  reverse(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (size_t i = 0; i < ans.size(); i++){
    cout << (ans[i] / 6 + 1)<< " " << faces_str[ans[i]%6] << endl;
  }
}



int main(){
  while (cin >> N && N){
    cubes.resize(N);
    for (int i = 0; i < N; i++){
      cubes[i].resize(6);
      for (int j = 0; j < 6; j++){
        cin >> cubes[i][j];
      }
    }
    if (TestNum) printf("\n");
    printf("Case #%d\n", ++TestNum);
    solve();
  }
}



