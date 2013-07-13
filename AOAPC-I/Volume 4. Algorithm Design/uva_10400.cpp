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
int TestNum;
const int MAXN = 32000;
int p;
int num[128];
int target;
char op[128];
bool visited[128][MAXN * 2 + 1];
bool dfs(int cur, int val){
  //printf("dfs(%d,%d)\n", cur, val);
  if (abs(val) >= 32000){
    return false;
  }
  if (cur == p + 1){
    if (val == target){
      printf("%d", num[1]);
      for (int i = 2; i <= p; i++){
        printf("%c%d", op[i], num[i]);
      }
      printf("=%d\n", target);
      return true;
    }else{
      return false;
    }
  }
  if (visited[cur][val + MAXN]){
    return false;
  }
  op[cur] = '+';
  if (dfs(cur + 1, val + num[cur])){
    return true;
  }
  op[cur] = '*';
  if (dfs(cur + 1, val * num[cur])){
    return true;
  }
  op[cur] = '-';
  if (dfs(cur + 1, val - num[cur])){
    return true;
  }
  op[cur] = '/';
  if (val % num[cur] == 0 && dfs(cur + 1, val / num[cur])){
    return true;
  }
  visited[cur][val + MAXN] = true;
  return false;
}

int main(){
  scanf("%d", &TestNum);
  while (TestNum--){
    scanf("%d", &p);
    for (int i = 1; i <= p; i++){
      scanf("%d", &num[i]);
    }
    scanf("%d", &target);
    memset(visited, 0, sizeof(visited));
    if (!dfs(2, num[1])){
      printf("NO EXPRESSION\n");
    }
  }
}

