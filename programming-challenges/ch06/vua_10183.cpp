/*
 * Algorithm: big_num
 */


#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


vector<int> str_to_bignum(const string &s){
  vector<int> a(s.size());
  for (size_t i = 0; i < s.size(); i++){
    a[i] = s[i] - '0';
  }
  reverse(a.begin(), a.end());
  return a;
}

string bignum_to_str(const vector<int> &a){
  string s(a.size(), '0');
  for (size_t i = 0; i < a.size(); i++){
    s[i] = a[i] + '0';
  }
  reverse(s.begin(), s.end());
  return s;
}

vector<int> bignum_add(const vector<int> &a, const vector<int> &b){
  vector<int> c(max(a.size(), b.size()));
  int carry = 0;
  for (size_t i = 0; i < max(a.size(), b.size()); i++){
    int da = i < a.size() ? a[i] : 0;
    int db = i < b.size() ? b[i] : 0;
    int dc = da + db + carry;
    if (dc >= 10){
      dc = dc - 10;
      carry = 1;
    }else{
      carry = 0;
    }
    c[i] = dc;
  }
  if (carry){
    c.push_back(carry);
  }
  return c;
}

bool bignum_less(const vector<int> &lhs, const vector<int> &rhs){
  if (lhs.size() != rhs.size()) return lhs.size() < rhs.size();
  for (int i = lhs.size() - 1; i >= 0; i--){
    if (lhs[i] != rhs[i]) return lhs[i] < rhs[i];
  }
  return false;
}

vector<vector<int> > fibs;

void init(){
  fibs.push_back(str_to_bignum("1"));
  fibs.push_back(str_to_bignum("2"));
  while (fibs.back().size() <= 101){
    fibs.push_back(bignum_add(fibs[fibs.size() - 1], fibs[fibs.size() - 2]));
  }
}


int main(){
  init();
  string a, b;
  while (cin >> a >> b && b != "0"){
    vector<int> bignum_a = str_to_bignum(a);
    vector<int> bignum_b = str_to_bignum(b);
    size_t pos_a = lower_bound(fibs.begin(), fibs.end(), bignum_a, bignum_less) - fibs.begin();
    size_t pos_b = upper_bound(fibs.begin(), fibs.end(), bignum_b, bignum_less) - fibs.begin();
   // cout << pos_a << " " << pos_b << endl;
    cout << pos_b - pos_a << endl;
  }
}
