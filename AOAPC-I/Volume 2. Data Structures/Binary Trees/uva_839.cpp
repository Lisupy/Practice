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
vector<int> wl;
vector<int> dl;
vector<int> wr;
vector<int> dr;


void input(){
  wl.clear();
  dl.clear();
  wr.clear();
  dr.clear();
  string line;
  while (getline(cin, line) && line.size()){
    int a, b, c, d;
    istringstream iss(line);
    iss >> a >> b >> c >> d;
    wl.push_back(a);
    dl.push_back(b);
    wr.push_back(c);
    dr.push_back(d);
  }
}

int pos;
bool valid;
int dfs(){
  int w1 = wl[pos];
  int d1 = dl[pos];
  int w2 = wr[pos];
  int d2 = dr[pos];
  pos++;
  if (w1 == 0){
    w1 = dfs();
  }
  if (w2 == 0){
    w2 = dfs();
  }
  if (w1 * d1 != w2 * d2){
 //   printf("%d %d %d %d\n", w1, d1, w2, d2);
    valid = false;
  }
  return w1 + w2;
}
int main(){
  cin >> TestNum;
  cin.ignore();
  cin.ignore();
  while (TestNum--){
    input();
    pos = 0;
    valid = true;
    dfs();
    if (valid){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
    if (TestNum){
      cout << endl;
    }
  }
}

