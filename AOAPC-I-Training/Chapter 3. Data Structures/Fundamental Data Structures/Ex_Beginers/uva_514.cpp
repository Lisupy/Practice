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


bool isValid(vector<int> order){
  stack<int> S;
  for (size_t i = 0, l = 1; i < order.size(); i++){
    while(l <= order.size() && (S.empty() || S.top() != order[i])){
      S.push(l);
      l++;
    }
    if (S.top() == order[i]) S.pop();
    else return false;
  }
  return true;
}
int TestNum;
int main(){
  int N;
  while (cin >> N && N){
    //if (TestNum++) cout << endl;
    cin.ignore();
    string line;
    while(getline(cin, line) && line != "0"){
      stringstream iss(line);
      vector<int> order( (istream_iterator<int>(iss)), istream_iterator<int>() );
      //for (int i = 0; i < N; i++) iss >> order[i];
      if (isValid(order)) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    cout << endl;
  }
}

