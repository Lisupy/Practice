/*
 * Algorithm:  f(n) = 2 * f(n - 1) + f(n - 2) + f(n - 3);
 */

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


vector<int> str_to_bignum(const string &s){
  vector<int> a;
  for (size_t i = 0; i < s.size(); i++){
    a.push_back(s[i] - '0');
  }
  reverse(a.begin(), a.end());
  return a;
}

string bignum_to_str(const vector<int> &a){
  string s;
  for (size_t i = 0; i < a.size(); i++){
    s.push_back(a[i] + '0');
  }
  reverse(s.begin(), s.end());
  return s;
}

vector<int> bignum_add(const vector<int> &a, const vector<int> &b){
  vector<int> c;
  int carry = 0;
  for (size_t i = 0; i < max(a.size(), b.size()); i++){
    int da = i < a.size() ? a[i] : 0;
    int db = i < b.size() ? b[i] : 0;
    int dc = da + db + carry;
    carry = dc / 10;
    c.push_back(dc % 10);
  }
  if (carry) c.push_back(carry);
  return c;
}

vector<int> f[1024];

void init(){
  f[0] = str_to_bignum("1");
  f[1] = str_to_bignum("2");
  f[2] = str_to_bignum("5");
  for (size_t i = 3; i < 1024; i++){
    f[i] = str_to_bignum("0");
    f[i] = bignum_add(f[i], f[i - 1]);
    f[i] = bignum_add(f[i], f[i - 1]);
    f[i] = bignum_add(f[i], f[i - 2]);
    f[i] = bignum_add(f[i], f[i - 3]);
  }
}

int main(){
  init();

  int n;
  while (cin >> n){
    string s = bignum_to_str(f[n]);
    cout << s << endl;
  }
}
