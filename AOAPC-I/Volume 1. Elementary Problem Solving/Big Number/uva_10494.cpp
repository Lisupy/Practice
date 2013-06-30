#include<string>
#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;


string lhs;
long long rhs;
string op;

string strFromInt(int n){
  char buf[32];
  sprintf(buf, "%d", n);
  return buf;
}

int main(){
  while (cin >> lhs >> op >> rhs){
    if (op == "%"){
      long long res = 0;
      for (size_t i = 0; i < lhs.size(); i++){
        long long d = lhs[i] - '0';
        res = (res * 10 + d) % rhs;
      }
      cout << res << endl;
    }
    if (op == "/"){
      long long res = 0;
      bool find = false;
      for (size_t i = 0; i < lhs.size(); i++){
        long long d = lhs[i] - '0';
        int t = (res * 10 + d) / rhs;
        if (t != 0){
          cout << t;
          find = true;
        }else{
          if (find){
            cout << t;
          }
        }
        res = (res * 10 + d) % rhs;
      }
      if (!find){
        cout << 0 << endl;
      }else{
        cout << endl;
      }
    }
    if (op == "*"){
      string res;
      reverse(lhs.begin(), lhs.end());
      long long s = 0;
      for (size_t i = 0; i < lhs.size() || s; i++){
        long long d = i < lhs.size() ? lhs[i] - '0' : 0;
        s = d * rhs+ s;
        res.push_back(s % 10 + '0');
        s = s / 10;
      }
      while (res.size() > 1 && res[res.size() - 1] == '0'){
        res.erase(res.end() - 1);
      }
      reverse(res.begin(), res.end());
      cout << res << endl;
    }
    if (op == "+"){
      string a = lhs;
      string b = strFromInt(rhs);
      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());
      string c;
      int carry = 0;
      for (size_t i = 0; i < max(a.size(), b.size()) || carry; i++){
        int da = i < a.size() ? a[i] - '0' : 0;
        int db = i < b.size() ? b[i] - '0' : 0; 
        int dc = da + db + carry;
        carry = dc / 10;
        c.push_back(dc % 10 + '0');
      }
      while (c.size() > 1 && c[c.size() - 1] == '0'){
        c.erase(c.end() - 1);
      }
      reverse(c.begin(), c.end());
      cout << c << endl;
    }
    if (op == "-"){
      string a = lhs;
      string b = strFromInt(rhs);
      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());
      string c;
      int borrow = 0;
      for (size_t i = 0; i < max(a.size(), b.size()); i++){
        int da = i < a.size() ? a[i] - '0' : 0;
        int db = i < b.size() ? b[i] - '0' : 0; 
        int dc = da - db - borrow;
        if (dc < 0){
          borrow = 1;
          dc = dc + 10;
        }else{
          borrow = 0;
        }
        c.push_back(dc + '0');
      }
      while (c.size() > 1 && c[c.size() - 1] == '0'){
        c.erase(c.end() - 1);
      }
      reverse(c.begin(), c.end());
      cout << c << endl;
    }
  }
}



