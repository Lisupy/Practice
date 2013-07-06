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


const int MAXN = 10 * 1024;
int in_order[MAXN];
int post_order[MAXN];
int min_node;
int min_path_value;
void dfs(int in_from, int in_to, int post_from, int post_to, int value){
  if (in_from > in_to){
    return;
  }
  value += post_order[post_to];
  if (in_from == in_to){
    if (value < min_path_value){
      min_node = post_order[post_to];
      min_path_value = value;
    }
  }else{
    int left_size = find(in_order + in_from, in_order + in_to, post_order[post_to]) - (in_order + in_from);
    dfs(in_from, in_from + left_size - 1, post_from, post_from + left_size - 1, value);
    dfs(in_from + left_size + 1, in_to, post_from + left_size, post_to - 1, value);
  }
}


int main(){
  string line;
  while (getline(cin, line) && line.size()){
    istringstream iss(line);
    int n = 0;
    while (iss >> in_order[n]){
      n++;
    }
    for (int i = 0; i < n; i++){
      cin >> post_order[i];
    }
    getline(cin, line);
    min_path_value = 0xffffff;
    dfs(0, n - 1, 0, n - 1, 0);
    cout << min_node << endl;
  }
}
