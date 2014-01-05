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


int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  double a;
  while (cin >> a){
    double DE = sqrt(3) / 2 * a;
    double EC = a - DE;
    //cout << EC << endl;
    //cout << PI << endl;
    double S4 = PI * a * a / 4 / 3 - a * a /4.0;
    //cout << S4 << endl;
    double S3 = EC * a / 2 - S4 * 2;
    double S2 = a * a - PI * a * a / 4 - 2 * S3;
    double S1 = a * a - 4 * (S2 + S3);
    printf("%.3lf %.3lf %.3lf\n", S1, S2 * 4, S3 * 4);
  }
}

