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
const int MAXN = 256;
const int maxnode = 156 * 70;
const int sigma_size = 26;
struct AhoCorasick{
  int ch[maxnode][sigma_size];
  int val[maxnode];
  int last[maxnode];
  int fail[maxnode];
  int cnt[MAXN];
  int sz;
  //void debug(){

  void reset(){
    sz = 1;
    memset(ch, 0, sizeof(ch));
    memset(val, 0, sizeof(val));
    memset(last, 0, sizeof(last));
    memset(fail, 0, sizeof(fail));
    memset(cnt, 0, sizeof(cnt));
  }
  AhoCorasick():sz(1){}
  int idx(char c){ return c - 'a';}
  int newNode() { return sz++;}
  void insert(const char* s, int v = 1, int len = 0){
    if (len == 0) len = strlen(s);
    //printf("insert, %s\n", s);
    int u = 0;
    for (int i = 0; i < len; i++){
      int c = idx(s[i]);
      if (!ch[u][c]) ch[u][c] = newNode();
      u = ch[u][c];
    }
    val[u] = v;
  }
  void getFail(){
    queue<int> q;
    for (int c = 0; c < sigma_size; c++){
      int  u = ch[0][c];
      if (u) q.push(u);
    }
    while (!q.empty()) {
      int r = q.front(); q.pop();
      for (int c = 0; c < sigma_size; c++){
        int u = ch[r][c];
        if (!u){ 
          ch[r][c] = ch[fail[r]][c]; 
          continue; 
        }
        q.push(u);
        int v = fail[r];
        while (v && !ch[v][c]) v = fail[v];
        fail[u] = ch[v][c];
        last[u] = val[fail[u]] ? fail[u] : last[fail[u]];
      }
    }
  }
  void find(const char* T, int len = 0){
    if (len == 0) len = strlen(T);
    int j = 0;
    for (int i = 0; i < len; i++){
      int c = idx(T[i]);
      j = ch[j][c];
      if (val[j]) print(j);
      else if (last[j]) print(last[j]);
    }
  }
  void print(int j){
    if (j){
      cnt[val[j]]++;
      print(last[j]);
    }
  }
};
AhoCorasick ac;
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int N;
  while (cin >> N && N) {
    ac.reset();
    vector<string> words(N);
    map<string, int> ms;
    for (int i = 0; i < N; i++) cin >> words[i];
    for (int i = 0; i < N; i++) {
      ac.insert(words[i].c_str(), i + 1); 
      ms[words[i]] = i + 1;
    }
    ac.getFail();
    string text; cin >> text;
    ac.find(text.c_str());
    int best = *max_element(ac.cnt, ac.cnt + N + 1);
    cout << best << endl; 
    for (int i = 0; i < N; i++){
      if (ac.cnt[ms[words[i]]] == best){
        cout << words[i] << endl;
      }
    }
  }
}

