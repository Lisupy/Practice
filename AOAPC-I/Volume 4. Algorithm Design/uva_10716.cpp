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


int doSwap(string &s, int from, int to){
  int cnt = 0;
  while (to > from){
    swap(s[to], s[to - 1]);
    to--;
    cnt++;
  }
  return cnt;
}
int solve(string s){
  map<char, int> cnt;
  for (size_t i = 0; i < s.size(); i++){
    cnt[s[i]]++;
  }
  int odd_cnt = 0;
  char odd_ch = ' ';
  for (map<char, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
    if (it->second % 2 != 0){
      odd_cnt++;
      odd_ch = it->first;
    }
  }
  if (odd_cnt >= 2){
    return -1;
  }
  string target;
  map<char, int> used_cnt;
  for (size_t i = 0; i < s.size(); i++){
    char ch = s[i];
    if (used_cnt[ch] < cnt[ch] / 2){
      target += ch;
      used_cnt[ch]++;
    }
  }

  string tmp(target.rbegin(), target.rend());
  if (odd_cnt > 0){
    target += odd_ch;
  }
  target += tmp;
  //cout << target << endl;

  int total = 0;
  for (size_t i = 0; i < target.size(); i++){
    if (s[i] == target[i])
      continue;
    size_t pos = s.find(target[i], i);
    total += doSwap(s, i, pos);
  }
  return total;
}

int main(){
  int n;
  cin >> n;
  while (n--){
    string s;
    cin >> s;
    int ans = solve(s);
    if (ans < 0){
      cout << "Impossible" << endl;
    }else{
      cout << ans << endl;
    }
  }
}
