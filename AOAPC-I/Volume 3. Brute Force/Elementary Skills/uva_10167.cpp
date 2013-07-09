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

int x[100];
int y[100];
int N;

bool isValid(int A, int B){
  int posCnt = 0, negCnt = 0;
  for (int i = 0; i < N; i++){
    int s = A * x[i] + B * y[i];
    if (s == 0){
      return false;
    }else if (s < 0) {
      negCnt++;
    }else if (s > 0) {
      posCnt++;
    }
  }
  return posCnt == negCnt;
}

void solve(){
  for (int A = -500; A <= 500; A++){
    for (int B = -500; B <= 500; B++){ 
      if (isValid(A, B)){
        printf("%d %d\n", A, B);
        return; 
      }
    }
  }
}

int main(){
  while (scanf("%d", &N) && N) {
    N = 2 * N;
    for (int i = 0; i < N; i++) {
      scanf("%d %d", x + i, y + i);
    }
    solve();
  }
}
