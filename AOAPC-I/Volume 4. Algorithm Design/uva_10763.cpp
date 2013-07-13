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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof
 */

struct Record{
  int A;
  int B;
};
bool operator<(const Record &a, const Record &b){
  Record a1 = a;
  Record b1 = b;
  if (a1.A > a1.B){
    a1.A = -a1.A;
    a1.B = -a1.B;
    swap(a1.A, a1.B);
  }
  if (b1.A > b1.B){
    b1.A = -b1.A;
    b1.B = -b1.B;
    swap(b1.A, b1.B);
  }
  if (a1.A != b1.A) return a1.A < b1.A;
  return a1.B < b1.B;
}

vector<Record> records;
int N;
bool isValid(){
  int l = 0, r = N - 1;
  if (N % 2 != 0){
    return false;
  }
  while (l < N){
    if (records[l].A == records[r].B && records[l].B == records[r].A){
      //printf("not Valid: %d %d\n", l, r);
      l++, r--;
    }else{
      return false;
    }
  }
  return true;
}
void debug(){
  for (int i = 0; i < N; i++){
    printf("(%d, %d) ", records[i].A, records[i].B);
  }
}
int main(){
  while (cin >> N && N){
    records.resize(N);
    for (int i = 0; i < N; i++){
      cin >> records[i].A >> records[i].B;
    }
    sort(records.begin(), records.end());
    //debug();
    if (isValid()){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}


