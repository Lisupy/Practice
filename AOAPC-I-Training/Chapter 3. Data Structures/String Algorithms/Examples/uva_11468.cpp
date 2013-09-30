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
const double PI = acos(-1);
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
const int sigma_size = 26 + 26 + 10;
const int maxnode = 512;
const int maxl = 128;
struct AhoCorsickAutomata{
  int ch[maxnode][sigma_size];
  int val[maxnode];
  int fail[maxnode];
  bool match[maxnode];
  bool vis[maxnode][maxl];
  double dp[maxnode][maxl];
  double prob[sigma_size];
  int sz;
  void reset(){
    sz = 1;
    memset(ch, 0, sizeof(ch));
    memset(val, 0, sizeof(val));
    memset(fail, 0, sizeof(fail));
    memset(match, 0, sizeof(match));
    memset(vis, 0, sizeof(vis));
    memset(dp, 0, sizeof(dp));
    memset(prob, 0, sizeof(prob));
  }
  AhoCorsickAutomata(): sz(1){ reset();}
  int idx(char x) {
    //if (islower(c)) return c - 'a';
    //if (isupper(c)) return c - 'A' + 26;
    //if (isdigit(c)) return c - '0' + 52;
    if('0'<=x&&x<='9')return x-'0';  
    else if('a'<=x&&x<='z')return x-'a'+10;  
    else return x-'A'+36;  
    assert(0);
    return -1;
  }
  int newNode() { assert(sz < maxnode); return sz++;}
  void insert(const char *s, int v = 1, int len = 0){
    if (len == 0) len = strlen(s);
    int u = 0;
    for (int i = 0; i < len; i++){
      int c = idx(s[i]);
      if (!ch[u][c]) ch[u][c] = newNode();
      u = ch[u][c];
    }
    val[u] = v;
    match[u] = true;
  }
  void getFail(){
    queue<int> q;
    for (int c = 0; c < sigma_size; c++){
      int u = ch[0][c];
      if (u) q.push(u);
    }
    while (q.size()){
      int r = q.front(); q.pop();
      for (int c = 0; c < sigma_size; c++){
        int u = ch[r][c];
        if (!u) {
          ch[r][c] = ch[fail[r]][c];
          continue;
        }
        q.push(u);
        int v = fail[r];
        while (v && !ch[v][c]) v = fail[v];
        fail[u] = ch[v][c];
        if (!match[u]) match[u] = match[fail[u]];
      }
    }
  }
  double getProb(int u, int L){
    if (L == 0) return 1.0;
    double &ans = dp[u][L];
    if (vis[u][L]) return ans;
    vis[u][L] = true, ans = 0.0;
    for (int i = 0; i < sigma_size; i++){
      int c = ch[u][i];
      if (prob[i] == 0) continue;
      if (!match[c]) ans += prob[i] * getProb(c, L - 1);
    }
    return ans;
  }
};
AhoCorsickAutomata ac;
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int T; cin >> T;
  while (T--) {
    ac.reset();
    int K; cin >> K;
    while (K--) {
      string s; cin >> s;
      ac.insert(s.c_str());
    }
    ac.getFail();
    int N; cin >> N;
    for (int i = 0; i < N; i++){
      char ch; cin >> ch;
      //string s; cin >> s;
      //char ch = s[0];
      cin >> ac.prob[ac.idx(ch)];
    }
    int L; cin >> L;
    //cout << "Case " << ++TestNum << ": " << ac.getProb(0, L) << endl;
    printf("Case #%d: %.06lf\n", ++TestNum, ac.getProb(0, L));
  }
}

