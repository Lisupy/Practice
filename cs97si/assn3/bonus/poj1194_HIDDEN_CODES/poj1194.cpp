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
const int MAXN = 128;
const int MAXM = 1024 * 1024;
int N;
char words[MAXN][MAXN];
int len[MAXN];
char text[MAXM];
int text_len;
int dp[MAXM];
int mat[MAXN][MAXN];
int TestNum;
vector<pair<int, int> > tbl[128];
int idFromChar(char c){
  if (islower(c)) return c - 'a';
  return c - 'A' + 26;
}
int main(){
  memset(mat, -1, sizeof(mat));
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%s\n", words[i]);
    len[i] = strlen(words[i]);
    reverse(words[i], words[i] + len[i]);
    for (int j = 0; j < len[i]; j++){
      tbl[(int)words[i][j]].push_back(make_pair(j, i));
    }
  }
  for (int i = 0; i < 128; i++){
    reverse(tbl[i].begin(), tbl[i].end());
  }
  scanf("%s", text);
  text_len = strlen(text);
  reverse(text, text + text_len);
  for (int i = 1; i <= text_len; i++){
    char ch = text[i - 1];
    dp[i] = max(dp[i], dp[i - 1]);
    for (size_t ii = 0; ii < tbl[(int)ch].size(); ii++){
      int j = tbl[(int)ch][ii].second;
      int k = tbl[(int)ch][ii].first;
      if (k == 0) mat[j][k] = i;
      else mat[j][k] = mat[j][k - 1];
    }
    for (int j = 0; j < N; j++){
      int pos = mat[j][len[j] - 1];
      if (pos != -1 && i - pos <= 1000){
        dp[i] = max(dp[i], dp[pos - 1] + len[j]);
      }
    }
  }
  //cout << text_len << endl;
  cout << dp[text_len] << endl;
}

