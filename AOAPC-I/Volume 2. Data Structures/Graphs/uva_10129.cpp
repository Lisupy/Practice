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

int mat[32][32];
int p[32];
int in_degree[32];
int out_degree[32];
void init(){
  memset(mat, 0, sizeof(mat));
  memset(in_degree, 0, sizeof(in_degree));
  memset(out_degree, 0, sizeof(out_degree));
  for (int i = 0; i < 32; i++){
    p[i] = i;
  }
}

int find(int x){
  return p[x] == x ? x : p[x] = find(p[x]);
}

void join(int x, int y){
  int px = find(x);
  int py = find(y);
  if (px != py){
    p[px] = py;
  }
}

void input(){
  int N;
  cin >> N;
  while (N--){
    string str;
    cin >> str;
    int s = str[0] - 'a', t = str[str.size() - 1] - 'a';
    mat[s][t]++;
    mat[t][s]++;
    in_degree[s]++;
    out_degree[t]++;
    join(s, t);
  }
}

bool isvalid(){
  int oddCnt = 0;
  for (int i = 0; i < 32; i++){
    //cout << degree[i] << endl;
    oddCnt += abs(in_degree[i] - out_degree[i]);
  }
  if (oddCnt > 2){
    return false;
  }
  int id = -1;
  for (int i = 0; i < 32; i++){
    if (in_degree[i] != 0 || out_degree[i] != 0){
      if (id == -1){
        id = find(i);
      }
      if (id != find(i)){
        return false;
      }
    }
  }
  return true;
}
int main(){
  int T;
  cin >> T;
  while (T--){
    init();
    input();
    if (isvalid()){
      printf("Ordering is possible.\n");
    }else{
      printf("The door cannot be opened.\n");
    }
  }
}
