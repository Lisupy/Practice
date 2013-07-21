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
vector<vector<int> > boxs;

int k, n;

void reset(){
  boxs.clear();
}

int input(){
  if (cin >> k >> n){
    boxs.resize(k);
    for (size_t i = 0; i < boxs.size(); i++){
      vector<int> &box = boxs[i];
      box.resize(n);
      for (size_t j = 0; j < box.size(); j++){
        cin >> box[j];
      }
      sort(box.begin(), box.end());
    }
    return 1;
  }
  return 0;
}
bool rank_less(const int a, const int b){
  for (int i = 0; i < n; i++){
    if (boxs[a][i] >= boxs[b][i]) return false;
  }
  return true;
}
void solve(){
  vector<vector<int> > links(k);
  vector<int> indgs(k);
  for (int i = 0; i < k; i++){
    for (int j = 0; j < k; j++){
      if (rank_less(j, i)){
        links[i].push_back(j);
        indgs[j]++;
      }
    }
  }
  vector<int> length(k, 1);
  vector<int> father(k, -1);
  queue<int> Q;
  for (int i = 0; i < k; i++){
    if (indgs[i] == 0){
      Q.push(i);
    }
  }
  while (!Q.empty()){
    int s = Q.front(); Q.pop();
    for (size_t i = 0; i < links[s].size(); i++){
      int t = links[s][i];
      if (length[t] < length[s] + 1){
        length[t] = length[s] + 1;
        father[t] = s;
      }
      indgs[t]--;
      if (indgs[t] == 0){
        Q.push(t);
      }
    }
  }
  int pos = max_element(length.begin(), length.end()) - length.begin();
  vector<int> res;
  while (pos != -1){
    res.push_back(pos);
    pos = father[pos];
  }
  cout << res.size() << endl;
  for (size_t i = 0; i < res.size(); i++){
    if (i != 0) cout << " ";
    cout << res[i] + 1;
  }cout << endl;
}

    
int main(){
  while (input()){
    solve();
    reset();
  }
}


