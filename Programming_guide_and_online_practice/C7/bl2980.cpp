#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

vector<int> str_to_bignum(const string &s){
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

string bignum_to_str(const vector<int> &bignum){
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

vector<int> bignum_add(const vector<int> &a, const vector<int> &b){
  vector<int> c;
  int carry = 0;
  for (size_t i = 0; i < max(a.size(), b.size()); i++){
    int da = i < a.size() ? a[i] : 0;
    int db = i < b.size() ? b[i] : 0;
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

vector<int> bignum_times(const vector<int> &a, int times, int offset){
  vector<int> b(offset, 0);
  int carry = 0;
  for (size_t i = 0; i < a.size(); i++){
    int da = a[i];
    int db = da * times + carry;
    carry = db / 10;
    db %= 10;
    b.push_back(db);
  }
  while (carry > 0){
    int db = carry % 10;
    carry = carry / 10;
    b.push_back(db);
  }

  while(b.size() > 0 && b.back() == 0){
    b.pop_back();
  }

  return b;
}

vector<int> bignum_mul(const vector<int> &a, vector<int> &b){
  vector<int> c;
  for (size_t i = 0; i < a.size(); i++){
    int da = a[i];
    int offset = i;
    vector<int> tmp = bignum_times(b, da, offset);
    c = bignum_add(c, tmp);
  }
  return c;
}

int main(){
  string a,b,c;
  cin >> a >> b;

  vector<int> bignum_a, bignum_b, bignum_c;

  bignum_a = str_to_bignum(a);
  bignum_b = str_to_bignum(b);
  bignum_c = bignum_mul(bignum_a, bignum_b);

  c = bignum_to_str(bignum_c);

  cout << c;
}

