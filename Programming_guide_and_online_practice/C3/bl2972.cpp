#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int string_to_int(string s, int base){
  int c = 0;
  for (size_t i = 0; i < s.size(); i++){
    c *= base;
    c += s[i] - '0';
  }
  return c;
}

int string_check_base(string s, int base){
  for (size_t i = 0; i < s.size(); i++){
    if (s[i] - '0' >= base)
      return false;
  }
  return true;
}

int get_answer(string p, string q, string r){
  for (int base = 2; base <= 16; base++){
    if (string_check_base(p, base) && string_check_base(q, base) && string_check_base(r, base)){
      int pi = string_to_int(p, base);
      int qi = string_to_int(q, base);
      int ri = string_to_int(r, base);
   //   printf("%d:%d %d %d\n", base, pi, qi, ri);
      if (pi * qi == ri){
        return base;
      }
    }
  }
  return 0;
}

int main(){
  int T;
  scanf("%d", &T);

  while (T--){
    string p, q, r;
    cin >> p >> q >> r;
    cout << get_answer(p, q, r) << endl;
  }
}
