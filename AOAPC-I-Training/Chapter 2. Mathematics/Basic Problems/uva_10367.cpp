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
 * sizeof CLOCKS_PER_SEC
 */


int gcd(int a, int b){
  return b == 0 ? a : gcd(b, a % b);
}
struct Equation{
  int a, b, c;
  void display(){
    cout << a << ", " << b << ", " << c << endl;
  }
  void neg(){
    a = -a, b = -b, c = -c;
  }
  void format(){
    int g = gcd(gcd(abs(a), abs(b)), abs(c));
    a /= g, b /= g, c/= g;
  }
};
Equation eqs[2];
struct Res{
  int type;
  int upper, lower;
};
Res res[2];
int intFromStr(string s){
  if (s == "") return 1;
  if (s == "-") return -1;
  return atoi(s.c_str());
}
void input(){
  for (int i = 0; i < 2; i++) {
    Equation &e = eqs[i];
    e.a = e.b = e.c = 0;
    string line; getline(cin, line);
    istringstream iss(line);
    string s;
    while (iss >> s && s != "=") {
      if (s.back() == 'x')      e.a += intFromStr(s.substr(0, s.size() - 1)); 
      else if (s.back() == 'y') e.b += intFromStr(s.substr(0, s.size() - 1));
      else                      e.c -= intFromStr(s); 
    }
    while (iss >> s && s != "=") {
      if (s.back() == 'x')      e.a -= intFromStr(s.substr(0, s.size() - 1)); 
      else if (s.back() == 'y') e.b -= intFromStr(s.substr(0, s.size() - 1)); 
      else                      e.c += intFromStr(s);  
    }
    e.display();
  }
  cin.ignore();
}
bool valid;
void solve(){
  valid = true;
  for (int i = 0; i < 2; i++){
    if (eqs[0].a == eqs[0].b
  eqs.format();
  if (eqs[0].b < 0) eqs[0].neg();
  if (eqs[1].b < 0) eqs[1].neg();
  eqs[0].display(), eqs[1].display();
  if (eqs[0].b == 0 && eqs[0].a != 0){
    res[0].upper = eqs[0].c, res[0].lower = eqs[0].a;
  }else if (eqs[1].b == 0){
    res[0].upper = eqs[1].c, res[0].lower = eqs[1].a;
  }else{
    res[0].upper = eqs[0].c * eqs[1].b - eqs[1].c * eqs[0].b;
    res[0].lower = eqs[0].a * eqs[1].b - eqs[1].a * eqs[0].b;
  }
  if (eqs[0].a < 0) eqs[0].neg();
  if (eqs[1].a < 0) eqs[1].neg();
  if (eqs[0].a == 0 && eqs[0].b != 0){
    res[1].upper = eqs[0].c, res[1].lower = eqs[0].b;
  }else if (eqs[1].a == 0){
    res[0].upper = eqs[1].c, res[0].lower = eqs[1].a;
  }else{
    res[1].upper = eqs[0].c * eqs[1].a - eqs[1].c * eqs[0].a;
    res[1].lower = eqs[0].b * eqs[1].a - eqs[1].b * eqs[0].a;
  }
  int g0 = gcd(abs(res[0].upper), abs(res[0].lower));
  if (g0 != 0) res[0].upper /= g0, res[0].lower /= g0;
  int g1 = gcd(abs(res[1].upper), abs(res[1].lower));
  if (g1 != 0) res[1].upper /= g1, res[1].lower /= g1;
  if (res[0].lower < 0) res[0].lower = -res[0].lower, res[0].upper = -res[0].upper;
  if (res[1].lower < 0) res[1].lower = -res[1].lower, res[0].upper = -res[1].upper;
}

void output(){
  cout << "[";
  for (int i = 0; i < 2; i++) {
    Res &r = res[i];
    if (r.lower == 0) printf("don't know\n");
    else if (r.upper == 0 && r.lower == 0) printf("0\n");
    else if (r.lower == 1) printf("%d\n", r.upper);
    else printf("%d/%d\n", r.upper, r.lower);
  }
  cout << "]" << endl;
}
int TestNum;
int main(){
  int N; cin >> N; cin.ignore();
  while (N--){
    input();
    solve();
    output();
  }

}

