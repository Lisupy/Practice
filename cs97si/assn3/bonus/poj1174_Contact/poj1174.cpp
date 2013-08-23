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

typedef long long i64;
typedef unsigned long long u64;
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 */
const int MAXM = 1 << 14;
int cnt[MAXM];
int A, B;
int N;
int TestNum;
void insert(const char* s, int l){
  int pos = 1;
  for (int i = 0; i < l && s[i] != '2'; i++){
    if (s[i] == '0'){
      pos *= 2;
    }else{
      pos = pos * 2 + 1;
    }
    if (i + 1 >= A) cnt[pos]++;
  }
}
string text;
vector<pair<int, string> > res;
bool myless(const pair<int, string> &a, const pair<int, string> &b){
  if (a.first != b.first) return a.first < b.first;
  if (a.second.size() != b.second.size()) return a.second.size() < b.second.size();
  return a.second < b.second;
}
void dfs(int pos, int depth, string s){
  if (depth > B) return;
  if (A <= depth  && depth <= B){
    res.push_back(make_pair(cnt[pos], s)); 
  }
  dfs(pos * 2, depth + 1, s + "0");
  dfs(pos * 2 + 1, depth + 1, s + "1");
}
void output(){
  sort(res.begin(), res.end(), myless);
  reverse(res.begin(), res.end());
  int line_cnt = 0;
  for (size_t i = 0; i <= res.size(); i++) {
    if (i == 0 || i == res.size() || res[i].first != res[i - 1].first){
      if (line_cnt != 0) cout << endl;
      line_cnt++;
      if (line_cnt > N || i == res.size()) break;
      if (res[i].first == 0) break;
      cout << res[i].first;
    }
    cout << " " << res[i].second;
  }

}
int main(){
  scanf("%d", &A);
  scanf("%d", &B);
  scanf("%d", &N);
  cin >> text;
  for (size_t i = 0; i < text.size(); i++){
    insert(text.c_str() + i, B);
  }
  dfs(1, 0, "");
  output();
}

