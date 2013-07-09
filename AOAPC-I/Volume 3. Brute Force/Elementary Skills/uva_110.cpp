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

void p(string s){
  for (size_t i = 0; i < s.size(); i++){
    if (i != 0){
      printf(",");
    }
    printf("%c", s[i]);
  }
}

void ps(int n){
  while (n--){
    printf(" ");
  }
}
void meta_sort(string s, int pos, string cur){
  if (pos == (int)s.size()){
    ps(pos * 2);
    printf("writeln(");
    p(cur);
    printf(")\n");
  }else{
    //cout << "[" << cur << "]" << endl;
    for (int i = cur.size() - 1; i >= 0; i--){
      ps(pos * 2);
      if ((size_t)i != cur.size() - 1){
        printf("else ");
      }
      printf("if %c < %c then\n", cur[i], s[pos]);
      string tmp(cur);
      tmp.insert(i + 1, 1, s[pos]);
      meta_sort(s, pos + 1, tmp);
    }
    ps(pos * 2);
    printf("else\n");
    meta_sort(s, pos + 1, string(1, s[pos]) + cur);
  }
}
int main(){
  int M;
  cin >> M;
  while (M--){
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++){
      s += 'a' + i;
    }
    printf("program sort(input,output);\n");
    printf("var\n");
    p(s);
    printf(" : integer;\n");
    printf("begin\n");
    printf("  readln(");
    p(s);
    printf(");\n");
    meta_sort(s, 1, "a");
    printf("end.\n");
    if (M){
      printf("\n");
    }
  }
}
