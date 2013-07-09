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

struct Exp{
  int type; // 0 = value, 1 = op;
  int val;
  char op;
};

int a[5];
bool used[5];
Exp exps[10];

const char ops[] = "+-*";

int expCalc(){
  stack<int> S;
  for (int i = 0; i < 9; i++){
    Exp &e = exps[i];
    if (e.type == 0){
      S.push(e.val);
    }else{
      int v1 = S.top(); S.pop();
      int v2 = S.top(); S.pop();
      int v3 = 0; 
      switch(e.op){
      case '+':
        v3 = v1 + v2;
        break;
      case '-':
        v3 = v1 - v2;
        break;
      case '*':
        v3 = v1 * v2;
        break;
      }
      S.push(v3);
    }
  }
  return S.top();
}
        

bool dfs(int valueCnt, int opCnt){
  if (valueCnt == 5 && opCnt == 4){
    return expCalc() == 23;
  }else{
    if (valueCnt <= opCnt + 1){
      for (int i = 0; i < 5; i++){
        if (!used[i]){
          Exp e;
          e.type = 0;
          e.val = a[i];
          exps[valueCnt + opCnt] = e;
          used[i] = true;
          if (dfs(valueCnt + 1, opCnt)){
            return true;
          }
          used[i] = false;
        }
      }
    }else{
      for (int i = 0; i < 3; i++){
        Exp e;
        e.type = 1;
        e.op = ops[i];
        exps[valueCnt + opCnt] = e;
        if (dfs(valueCnt, opCnt + 1)){
          return true;
        }
      }
    }
    return false;
  }
}

bool dfs2(int cur, int val){
  if (cur == 5){
    return val == 23;
  }else{
    for (int i = 0; i < 5; i++){
      if (!used[i]){
        used[i] = true;
        if (dfs2(cur + 1, val + a[i])) return true;
        if (dfs2(cur + 1, val * a[i])) return true;
        if (dfs2(cur + 1, val - a[i])) return true;
        used[i] = false;
      }
    }
  }
  return false; 
}
bool solve(){
  memset(used, 0, sizeof(used));
  for (int i = 0; i < 5; i++){
    used[i] = true;
    if(dfs2(1, a[i])) return true;
    used[i] = false;
  }
  return false;
}
int main(){
  while (true){
    for (int i = 0 ; i < 5; i++){
      scanf("%d", a + i);
    }
    if (!(a[0] || a[1] || a[2] || a[3] || a[4])){
      break;
    }
    if (solve()){
      cout << "Possible" << endl;
    }else{
      cout << "Impossible" << endl;
    }
  }
}

