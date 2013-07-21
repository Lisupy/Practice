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
struct Record{
  int W;
  int S;
  int idx;
};
vector<Record> records;
bool operator<(const Record &a, const Record &b){
  return a.W < b.W;
}
bool iq_bigger(const Record &a, const Record &b){
  return a.S > b.S;
}
int main(){
  int W, S;
  while (cin >> W >> S)records.push_back({W, S, (int)records.size()});

  sort(records.begin(), records.end());
  vector<int> last(records.size(), -1);
  vector<int> length(records.size(), 1);
  for (size_t i = 0; i < records.size(); i++){
    //printf("%d,  %d %d\n", records[i].idx, records[i].W, records[i].S); 
    for (size_t j = 0; j < i; j++){
      if (records[i].W > records[j].W && records[i].S < records[j].S){
        if (length[i] < length[j] + 1){
          length[i] = length[j] + 1;
          last[i] = j;
        }
      }
    }
  }
  int maxPos = max_element(length.begin(), length.end()) - length.begin();
  cout << length[maxPos] << endl;
  vector<int> res;
  while (maxPos != -1){
    res.push_back(maxPos);
    maxPos = last[maxPos];
  }
  reverse(res.begin(), res.end());
  for (size_t i = 0; i < res.size(); i++) {
    cout << records[res[i]].idx + 1 << endl;
  }
}
