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
vector<string> a;
vector<string> b;

void solve(){
  //cout << "LCS" << endl;
  vector<vector<int> > pathi(a.size() + 1);
  vector<vector<int> > pathj(a.size() + 1);
  vector<vector<int> > lcs(a.size() + 1);
  for (size_t i = 0; i <= a.size(); i++){
    pathi[i].resize(b.size() + 1);
    pathj[i].resize(b.size() + 1);
    lcs[i].resize(a.size() + 1);
  }
  for (size_t i = 1; i <= a.size(); i++){
    for (size_t j = 1; j <= b.size(); j++){
      if (a[i - 1] == b[j - 1]){
        lcs[i][j] = lcs[i - 1][j - 1] + 1;
        pathi[i][j] = i - 1;
        pathj[i][j] = j - 1;
      }else{
        if (lcs[i][j - 1] > lcs[i - 1][j]){
          pathi[i][j] = i;
          pathj[i][j] = j - 1;
          lcs[i][j] = lcs[i][j - 1];
        }else{
          pathi[i][j] = i - 1;
          pathj[i][j] = j;
          lcs[i][j] = lcs[i - 1][j];
        }
      }
    }
  }
  size_t posi = a.size();
  size_t posj = b.size();
  vector<string> ans;
  while (posi != 0){
    //cout << posi << ", " << posj << endl;
    size_t nexti = pathi[posi][posj], nextj = pathj[posi][posj];
    if (lcs[posi][posj] != lcs[nexti][nextj]){
      ans.push_back(b[posj - 1]);
    }
    posi = nexti, posj = nextj;
  }
  reverse(ans.begin(), ans.end());
  for (size_t i = 0; i < ans.size(); i++){
    if (i != 0) cout << " ";
    cout << ans[i];
  }cout << endl;
}

int input(){
  a.clear();
  b.clear();
  string t;
  if (cin >> t){
    if (t != "#"){
      a.push_back(t);
      while (cin >> t && t != "#"){
        a.push_back(t);
      }
      while (cin >> t && t != "#"){
        b.push_back(t);
      }
    }
    return 1;
  }
  return 0;
}

int main(){
  while (input()){
    solve();
  }
}
