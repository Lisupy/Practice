#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> bignum_add(const vector<int> &a, const vector<int> &b){
  int carry = 0;
  vector<int> c;
  for (size_t i = 0; i < max(a.size(), b.size()); i++){
    int da = i<a.size() ? a[i] : 0;
    int db = i<b.size() ? b[i] : 0;
    int dc = da + db + carry;
    if (dc >= 10){
      dc -= 10;
      carry = 1;
    }else{
      carry = 0;
    }
    c.push_back(dc);
  }
  if (carry != 0){
    c.push_back(carry);
  }
  return c;
}

vector<int> str_to_bignum(const string& s){
  vector<int> bignum;
  for (size_t i = 0; i < s.size(); i++){
    bignum.push_back(s[i]-'0');
  }
  reverse(bignum.begin(), bignum.end());
  while(bignum.size() > 0 && bignum.back() == 0){
    bignum.pop_back();
  }
  return bignum;
}

string bignum_to_str(const vector<int>& bignum){
  string s;
  for (size_t i = 0; i < bignum.size(); i++){
    s.push_back(bignum[i]+'0');
  }
  if (s.size() == 0){
    s.push_back('0');
  }
  reverse(s.begin(), s.end());
  return s;
}

int main(){
  string a;
  string b;
  cin >> a >> b;
  vector<int> big_a = str_to_bignum(a);
  vector<int> big_b = str_to_bignum(b);
  vector<int> big_c = bignum_add(big_a, big_b);
  string c = bignum_to_str(big_c);
  cout << c << endl;
}


