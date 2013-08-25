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
int best;
int pos;
void leastLeaf(vector<int> post_order, vector<int> in_order, int sum){
  if (post_order.size() == 0) return;
  if (post_order.size() == 1){
    sum += post_order[0]; 
    if (best > sum){
      best = sum;
      pos = post_order[0];
    }
    return;
  }
  int root = post_order.back();
  int lsz = find(in_order.begin(), in_order.end(), root) - in_order.begin();
  //int rsz = post_order.size() - lsz - 1;
  vector<int> l_post_order(post_order.begin(), post_order.begin() + lsz);
  vector<int> l_in_order(in_order.begin(), in_order.begin() + lsz);
  vector<int> r_post_order(post_order.begin() + lsz, post_order.end() - 1);
  vector<int> r_in_order(in_order.begin() + lsz + 1, in_order.end());
  leastLeaf(l_post_order, l_in_order, sum + root); 
  leastLeaf(r_post_order, r_in_order, sum + root);
}
  

int TestNum;
int main(){
  string line;
  while (getline(cin, line) && line.size()){
    
    stringstream iss(line);
    vector<int> in_order((istream_iterator<int>(iss)), istream_iterator<int>());
    getline(cin, line);
    iss.str(line);
    iss.clear();
    vector<int> post_order((istream_iterator<int>(iss)), istream_iterator<int>());
    best = 0xfffff; 
    leastLeaf(post_order, in_order, 0);
    cout << pos << endl;
  }
}


