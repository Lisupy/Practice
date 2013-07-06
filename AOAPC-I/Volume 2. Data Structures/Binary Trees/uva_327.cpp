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


bool available[128];
int  value[128];
int total = 0;
void calc(string expression){
  memset(available, 0, sizeof(available));
  total = 0;
  size_t len = expression.size();
  for (size_t ch = 'a'; ch <= 'z'; ch++){
    int n = ch - 'a' + 1;
    size_t pos = expression.find(ch);
    if (pos == string::npos){
      continue;
    }
    available[ch] = true;
    value[ch] = n;
    size_t sign_pos = pos - 1;
    if (pos - 1 < len && pos - 2 < len){
      if (expression[pos - 1] == '-' && expression[pos - 2] == '-'){
        value[ch]--;
        sign_pos = pos - 3;
      }
      if (expression[pos - 1] == '+' && expression[pos - 2] == '+'){
        value[ch]++;
        sign_pos = pos - 3;
      }
    }
    if (sign_pos >= len || expression[sign_pos] == '+'){
      total += value[ch];
    }else if (expression[sign_pos] == '-'){
      total -= value[ch];
    }
    if (pos + 1 < len && pos + 2 < len){
      if (expression[pos + 1] == '-' && expression[pos + 2] == '-'){
        value[ch]--;
      }
      if (expression[pos + 1] == '+' && expression[pos + 2] == '+'){
        value[ch]++;
      }
    }
  }
}

void output(){
  printf("    value = %d\n", total);
  for (size_t ch = 'a'; ch <= 'z'; ch++){
    if (available[ch]){
      printf("    %c = %d\n", (char)ch, value[ch]);
    }
  }
}


int main(){
  string line;
  while (getline(cin, line) && line.size()){
    printf("Expression: %s\n", line.c_str());
    size_t pos = 0;
    while ((pos = line.find(" ")) != string::npos){
      line.replace(pos, 1, "");
    }
    //printf("[%s]\n", line.c_str());
    calc(line);
    output();
  }
}
