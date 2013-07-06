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

int TestNum;
vector<int> a;
map<int, int> cnt;
int len;

void dfs(int pos){
  int node = a[len++];
  if (node == -1){
    return;
  }
  cnt[pos] += node;
  dfs(pos - 1);
  dfs(pos + 1);
}

int main(){
  while (true){
    a.clear();
    cnt.clear();
    int t;
    int negCnt = 0;
    while (cin >> t){
      a.push_back(t);
      if (t < 0){
        negCnt++;
      }else{
        negCnt--;
      }
      if (negCnt > 0){
        break;
      }
    }
    if (a.size() == 1){
      break;
    }
    cout << "Case " << ++TestNum << ":" << endl;
    len = 0;
    dfs(0);
    for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
      if (it != cnt.begin()){
        cout << " ";
      }
      cout << it->second;
    }
    cout << endl;
    cout << endl;
  }
}
