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
const int MAX_K = 1024;
int k;
int A[MAX_K];
int B[MAX_K];

void combineToA(int *a, int *b){
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >  > Q;  
  for (int i = 0; i < k; i++) {
    Q.push(make_pair(a[i] + b[0], 0)); 
  }
  
  for (int i = 0; i < k; i++) {
    pair<int, int> e = Q.top(); Q.pop();
    a[i] = e.first;
    e.first = e.first - b[e.second] + b[e.second + 1];
    e.second++;
    Q.push(e);
  }
}
int TestNum;
int main(){
  while (cin >> k) {
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        scanf("%d", &B[j]); 
      }
      sort(B, B + k);
      if (i == 0) copy(B, B + k, A);
      else combineToA(A, B);
    }
    for (int i = 0; i < k; i++) {
      if (i != 0) cout << " ";
      cout << A[i];
    }cout << endl;
  }
}

