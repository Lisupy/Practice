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
int lines[12][20] = {
  {4,  5, 6, 7, 8, 9,10,11,12,13,14,-1},
  {15,16,17,18,19,20,21,22,23,-1},
  {24,25,26,27,28,29,30,31,32,-1},
  {33,34,35,36,37,38,39,40,41,42,43,-1},

  { 0, 1, 2, 7, 8,16,17,24,25,33,34,-1},
  { 3, 9,10,18,19,26,27,35,36,-1},
  {11,12,20,21,28,29,37,38,44,-1},
  {13,14,22,23,30,31,39,40,45,46,47,-1},

  { 4, 5,15,16,25,26,36,37,44,45,47,-1},
  { 6, 7,17,18,27,28,38,39,46,-1},
  { 1, 8, 9,19,20,29,30,40,41,-1},
  { 0, 2, 3,10,11,21,22,31,32,42,43,-1},
};
vector<int> links[48];
void linksInit(){
  for (int i = 0; i < 12; i++){
    for (int j = 0; lines[i][j] != -1; j++){
      int v = lines[i][j];
      links[v].push_back(i);
    }
  }
  for (int i = 0; i < 48; i++){
    sort(links[i].begin(), links[i].end());
  }
}
vector<int> lineMax(12);
vector<int> a(48);
bool isValid(){
  vector<int> tmpMax(12);
  for (int i = 0; i < 48; i++){
    for (size_t j = 0; j < links[i].size(); j++){
      tmpMax[links[i][j]] = max(tmpMax[links[i][j]], a[i]);
    }
  }
  return tmpMax == lineMax;
}
vector<bool> used(12);
void reset(){
  fill(a.begin(), a.end(), 0);
  fill(used.begin(), used.end(), false);
}

void gaoMax(){
  reset();
  for (int i = 0; i < 48; i++){
    a[i] = 9;
    for (size_t j = 0; j < links[i].size(); j++){
      int li = links[i][j];
      a[i] = min(a[i], lineMax[li]);
    }
  }
}
void tryGao(vector<int> tmp, int curMax){
  for (int i = 0; i < 48; i++){
    vector<int> &link = links[i];
    vector<int> ntmp;
    for (size_t j = 0; j < link.size(); j++) if (!used[link[j]]){
      ntmp.push_back(link[j]);
    }
    if (tmp == ntmp){
      a[i] = curMax;
      for (size_t k = 0; k < tmp.size(); k++) used[tmp[k]] = true;
      return;
    }
  }
  for (size_t i = 0; i < tmp.size(); i++){
    vector<int> q(1, tmp[i]);
    tryGao(q, curMax);
  }
}
int dp[1<<12];
int gaoMin(){
  memset(dp, 0x3f, sizeof(dp));
  dp[0] = 0;
  for (int mask = 1; mask < (1 << 12); mask++){
    for (int i = 0; i < 48; i++){
      vector<int> &link = links[i];
      int m = 0;
      int Min = 9;
      for (size_t j = 0; j < link.size(); j++){
        int line = link[j];
        Min = min(Min, lineMax[line]);
      }
      for (size_t j = 0; j < link.size(); j++){
        int line = link[j];
        if (Min == lineMax[line]) m |= 1 << line;
      }
      for (int sub = m; sub != 0; sub = (sub - 1) & m){
        if ((mask & sub) == sub){
          dp[mask] = min(dp[mask], dp[mask ^ sub] + Min);
        }
      }
    }
  }
  return dp[(1<<12) - 1];
}
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  linksInit();
  string line;
  while (getline(cin, line)){
    istringstream ss(line);
    for (int i = 0; i < 12; i++) ss >> lineMax[i];
    gaoMax();
    if (!isValid()){
      cout << "NO SOLUTION" << endl;
      continue;
    }
    int largestSum = accumulate(a.begin(), a.end(), 0);
    int smallestSum = gaoMin();
    cout << smallestSum << " " << largestSum << endl;
  }
}

