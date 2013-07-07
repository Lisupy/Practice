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
const int MAXR = 1024;
const int MAXC = 1024;
int R, C;
int grid[MAXR][MAXC];
int indegree[MAXR][MAXC];
struct Pos{
  int r, c;
};
vector<Pos> links[MAXR][MAXC];
void reset(){
  for (int i = 0; i <= R; i++){
    for (int j = 0; j <= C; j++){
      grid[i][j] = 0;
      indegree[i][j] = 0;
      links[i][j].clear();
    }
  }
}
Pos __get(string s){
  //cout << "[" << s <, "]" << endl;
  assert(isalpha(s[0]));
  int c = 0;
  int r = 0;
  for (size_t i = 0; i < s.size(); i++){
    char ch = s[i];
    if (isalpha(ch)){
      r = r * 26 + ch - 'A' + 1;
    }
    if (isdigit(ch)){
      c = c * 10 + ch - '0';
    }
  }
  //printf("%s => (%d, %d)\n", s.c_str(), r, c);
  return {c, r};
}

int calc(int r, int c, string s){
  if (s[0] == '='){
    int total = 0;
    size_t pos = 1;
    while (pos < s.size()){
      size_t new_pos = s.find('+', pos);
      if (new_pos == string::npos) new_pos = s.size();
      Pos p = __get(s.substr(pos, new_pos - pos));
      indegree[r][c]++;
      links[p.r][p.c].push_back({r, c});
      pos = new_pos + 1;
    }
    return total;
  }else{
    return atoi(s.c_str());
  }
}
void dfs(int r, int c){
  for (size_t i = 0; i < links[r][c].size(); i++){
    Pos p = links[r][c][i];
    grid[p.r][p.c] += grid[r][c];
    indegree[p.r][p.c]--;
    if (indegree[p.r][p.c] == 0){
      dfs(p.r, p.c);
    }
  }
  indegree[r][c]--;
}
int main(){
  cin >> TestNum;
  while (TestNum--){
    cin >> C >> R;
    assert(R < MAXR && C < MAXC);
    reset();
    for (int i = 1; i <= R; i++){
      for (int j = 1; j <= C; j++){
        string s;
        cin >> s;
        grid[i][j] = calc(i, j, s);
      }
    }
    for (int i = 0; i <= R; i++){
      for (int j = 0; j <= C; j++){
        //printf("%d %d\n", i, j);
        if (indegree[i][j] == 0 ){
          dfs(i, j);
        }
      }
    }
    for (int i = 1; i <= R; i++){
      for (int j = 1; j <= C; j++){
        if (j != 1) cout << " ";
        cout << grid[i][j];
      }
      cout << endl;
    }
    reset();
    //if (TestNum){
      //cout << endl;
    //}
  }
}
