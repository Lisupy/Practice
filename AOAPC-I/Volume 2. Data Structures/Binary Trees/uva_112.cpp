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

bool dfs(int sum, bool &isLeaf){
  int n;
  char ch;
  cin >> ch; // '('
  assert(ch == '(');
  if (cin >> n){
    isLeaf = false;
    //cout << n << ", " << sum << endl;
    bool lIsLeaf, rIsLeaf;
    bool l = dfs(sum - n, lIsLeaf);
    bool r = dfs(sum - n, rIsLeaf);
    cin >> ch;
    if (lIsLeaf){
      return r;
    }
    if (rIsLeaf){
      return l;
    }
    return l || r;
  }else{
    isLeaf = true;
    cin.clear();
    cin >> ch; // ')'
    assert(ch == ')');
    //cout << sum << endl;
    return sum == 0;
  }
}


int main(){
  int I;
  while (cin >> I){
    bool isLeaf;
    if (dfs(I, isLeaf) && !isLeaf){
      cout << "yes" << endl;
    }else{
      cout << "no" << endl;
    }
  }
}
