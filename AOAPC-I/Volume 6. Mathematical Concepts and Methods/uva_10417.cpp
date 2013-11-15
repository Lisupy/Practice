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
 * (1 << (31 - __builtin_clz(100) ) == 64;
 */
const int STSZ = 13 * 13 * 13 * 13 * 13;
int n;
int giftNum[5];
double p[16][5];
void input(){
  cin >> n;
  for (int i = 0; i < 5; i++) cin >> giftNum[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) cin >> p[i][j];
  }
}

bool visited[STSZ];
double cache[STSZ]; 

int IDFromST(vector<int> st){
  int s = 0;
  for (size_t i = 0; i < st.size(); i++){
    s = s * 13 + st[i];
  }
  return s;
}

vector<int> STFromID(int id){
  vector<int> st(5);
  for (size_t i = 0; i < st.size(); i++){
    st[i] = id % 13;
    id /= 13;
  }
  reverse(st.begin(), st.end());
  return st;
}

void reset(){
  memset(visited, 0, sizeof(visited));
  memset(cache, 0, sizeof(cache));
}

double f(vector<int> st, int k){
  for (int i = 0; i < 5; i++){
    if (st[i] == -1) return 0;
  }
  if (k == n) return 1;
  int id = IDFromST(st);
  double &res = cache[id];
  if (visited[id]) return res;
  visited[id] = true;
  res = 0;
  for (int i = 0; i < 5; i++){
    vector<int> nst = st;
    nst[i]--;
    res += p[k][i] * f(nst, k + 1);
  }
  return res;
}

void solve(){
  reset();
  vector<int> st(giftNum, giftNum + 5);
  double maxProbaility = 0;
  int bestChoice = 0;
  double totalPro = 0;
  for (int i = 0; i < 5; i++){
    vector<int> nst = st;
    nst[i]--;
    double pro = f(nst, 1) * p[0][i];
    //cout << i << ": " << pro << endl;
    totalPro += pro;
    if (giftNum[i] == 0) continue;
    pro /= giftNum[i];
    if (pro > maxProbaility){
      maxProbaility = pro;
      bestChoice = i;
    }
  }
  //cout << maxProbaility << endl;
  //cout << totalPro << endl;
  printf("%d %.03lf\n", bestChoice + 1, maxProbaility / totalPro);
}
int TestNum;
int main(){
  int id = 30;
  assert( id == IDFromST(STFromID(id)));
  cin >> TestNum;
  while (TestNum--) {
    input();
    solve();
  }

}

