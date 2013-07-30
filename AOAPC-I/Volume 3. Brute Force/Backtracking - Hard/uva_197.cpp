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

struct Cube{
  char c[32];
  int  used;
  void fix_used(){
    used = 0;
    for (int i = 0; i < 27; i++){
      if (c[i] != 0){
        used |= 1 << i;
      }
    }
  }
};
bool operator<(const Cube &a, const Cube &b){
  return memcmp(a.c, b.c, 27);
}
bool operator==(const Cube &a, const Cube &b){
  return memcmp(a.c, b.c, 27) == 0;
}
vector<Cube> figure;

char RX[] = {7,8,9,16,17,18,25,26,27,4,5,6,13,14,15,22,23,24,1,2,3,10,11,22,19,20,12};
char RY[] = {7,4,1,8,5,2,9,6,3,16,13,10,17,14,11,18,15,12,25,22,19,26,23,20,27,24,21};
char RZ[] = {3,12,21,6,15,24,9,18,27,2,11,20,5,14,23,8,17,26,1,10,19,4,13,22,7,16,25};
vector<Cube> RS;
vector<Cube> solutions;
vector<Cube> figures[128];
Cube rot(Cube a, char r[]){
  Cube b;
  for (int i = 0; i < 27; i++){
    b.c[i] = a.c[(int)r[i]];
  }
  b.fix_used();
  return b;
}

void RS_init(){
  Cube a;
  for (int i = 0; i < 27; i++){
    a.c[i] = i + 1;
  }
  RS.push_back(a);
  for (int x = 0; x < 4; x++, a = rot(a, RX)){
    for (int y = 0; y < 4; y++, a = rot(a, RY)){
      for (int z = 0; z < 4; z++, a = rot(a, RZ)){
        if (find(RS.begin(), RS.end(), a) != RS.end()){
          RS.push_back(a);
        }
      }
    }
  }
}

Cube cubeAdd(Cube a, Cube b){
  Cube c;
  for (int i = 0; i < 27; i++){
    assert((a.c[i] & b.c[i]) == 0);
    c.c[i] = a.c[i] | b.c[i];
  }
  c.fix_used();
  return c;
}

    
void dfs(int fn, Cube a){
  if (fn == 'h'){
    solutions.push_back(a);
    return;
  }
  Cube c;
  for (size_t i = 0; i < figures[fn].size(); i++){
    Cube &f = figures[fn][i];
    if ((f.used & a.used) == 0){
      c = cubeAdd(a, f);
      dfs(fn, c);
    }
  }
}

bool trans(Cube &a, int dx, int dy, int dz){
  Cube b;
  memset(&b, 0, sizeof(b));
  for (int x = 0; x < 3; x++){
    for (int y = 0; y < 3; y++){
      for (int z = 0; z < 3; z++){
        int c = a.c[9*y + 3*z + x];
        if (c == 0){
          continue;
        }
        int nx = x + dx, ny = y + dy, nz = z + dz;
        if (0 <= nx && nx < 3 && 0 <= ny && ny < 3 && 0 <= nz && nz < 3){
          b.c[9 * ny + 3 * z + x] = 1;
        }else{
          return false;
        }
      }
    }
  }
  b.fix_used();
  a = b;
  return true;
}
const char* pieces = "aababbadcggeffcddcgeegfedfc";
int main(){
  RS_init();
  for (char fig = 'b'; fig <= 'g'; fig++){
    set<Cube> S;
    for (int r = 0; r < 24; r++){
      for (int dx = -2; dx <= 2; dx++){
        for (int dy = -2; dy <= 2; dy++){
          for (int dz = -2; dz <= 2; dz++){
            Cube c;
            memset(&c, 0, sizeof(c));
            for (int i = 0; i < 27; i++){
              if (pieces[i] == fig){
                c.c[i] = fig;
              }
            }
            c = rot(c, RS[r].c);
            if (!trans(c, dx, dy, dz)){
              continue;
            }
            c.fix_used();
            S.insert(c);
          }
        }
      }
    }
    for (set<Cube>::iterator it = S.begin(); it != S.end(); it++){
      figures[(int)fig].push_back(*it);
    }
  }
  Cube a;
  for (int i = 0; i < 27; i++){
    if (pieces[i] == 'a'){
      a.c[i] = 'a';
    }
  }
  a.fix_used();

  for (int dx = -2; dx <= 2; dx++){
    for (int dy = -2; dy <= 2; dy++){
      for (int dz = -2; dz <= 2; dz++){
        Cube b = a;
        if (trans(b, dx, dy, dz)){
          dfs('b', b);
        }
      }
    }
  }

  





