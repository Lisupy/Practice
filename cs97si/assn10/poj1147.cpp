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

typedef long long               ll;
typedef long double             ld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef pair<int, int>          pii;
typedef vector<pii>             vii; // vector of integer pairs
typedef set<int>                si;
typedef map<string, int>        msi;

const double PI = acos(-1);

/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */


int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  int N; cin >> N;
  vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];
  int num_of_zeros = count(A.begin(), A.end(), 0);
  int num_of_ones = N - num_of_zeros;
  vector<int> B(N);
  for (int i = num_of_ones; i < N; i++) B[i] = 1;
  int l0 = 0, l1 = num_of_zeros;
  vector<int> next(N);
  for (int i = 0; i < N; i++) {
    if (A[i] == 0) next[i] = l0++;
    else next[i] = l1++;
  }
  int s = 0;
  vector<int> ans(N);
  for (int i = 0; i < N; i++) {
    ans[i] = A[s];
    s = next[s];
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < N; i++) {
    if (i != 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}

