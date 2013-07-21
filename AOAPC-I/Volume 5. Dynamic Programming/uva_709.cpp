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

vector<string> words;
int n;

int input(){
  words.clear();
  cin >> n;
  if (n == 0) return 0;
  cin.ignore();
  string line;
  while (getline(cin, line) && line.size()){ 
    istringstream iss(line);
    string s;
    while (iss >> s) words.push_back(s);
  }
  return n;
}
const int MAXN = 10 * 1024;
int l[MAXN];
int sl[MAXN];
int dp[MAXN];
int m;
int path[MAXN];
int sum(int from, int to){
  return sl[to] - sl[from - 1] + to - from;
}
int __cost(int total, int num){
  if (total == 0) return 0;
  if (num == 0) return 500;
  int tn = total / num;
  int tmod = total % num;
  int s = tn * tn * (num - tmod) + (tn + 1) * (tn + 1) * tmod;
  return s;
}
int cost(int from, int to){
  return __cost(n - sum(from, to), to - from);
}
void dfs_print(int from){
  int to = path[from];
  int total = n - sum(from, to - 1);
  int num = to - from - 1;
  int tn = num == 0? min(500, (n - l[from]) * (n - l[from])) : total / num;
  int tmod = num == 0? 0 : total % num;
  for (int i = from; i < to; i++){
    cout << words[i - 1];
    if (i == to - 1) break;
    if (i - from < num - tmod) cout << string(tn + 1, ' ');
    else cout << string(tn + 2, ' ');
  }cout << endl;
  if (to != m + 1){
    dfs_print(to);
  }
}

void gao(){
  m = words.size();
  for (int i = 1; i <= m; i++) l[i] = words[i - 1].size();
  partial_sum(l + 1, l + m + 1, sl + 1);
  memset(dp, 0x1f, sizeof(dp));
  dp[m + 1] = 0;
  for (int i = m; i >= 1; i--){
    //printf("##%d:\n", i);
    for (int j = i + 1; j <= m + 1; j++){
      if (sum(i, j - 1) > n) break;
      int s = dp[j] + cost(i, j - 1);
      if (s <= dp[i]){
        dp[i] = s;
        path[i] = j;
      }
    }
  }
  dfs_print(1);
}
int main(){
  while (input()){
    gao();
    cout << endl;
  }
}

