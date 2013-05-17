#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct BigNum{
  vector<int> a;
  size_t offset;

  BigNum(){};

  BigNum(string s){
    offset = 0;
    for (int i = s.size() - 1; i >= 0; i--){
      if (s[i] == '.'){
        offset = s.size() - 1 - i;
      }else{
        a.push_back(s[i] - '0');
      }
    }
  }

  void set_offset(size_t new_offset){
    reverse(a.begin(), a.end());

    while (offset < new_offset){
      a.push_back(0);
      offset++;
    }

    while (offset > new_offset){
      a.push_back(0);
      offset--;
    }

    reverse(a.begin(), a.end());
  }

  BigNum times(int time_n, size_t more_offset) {
    BigNum b;
    for (size_t i = 0; i < more_offset; i++){
      b.a.push_back(0);
    }

    b.offset = offset;

    int carry = 0;
    for (size_t i = 0; i < a.size(); i++){
      int tmp = a[i] * time_n + carry;
      b.a.push_back(tmp % 10);
      carry = tmp / 10;
    }
    if (carry){
      b.a.push_back(carry);
    }

    return b;
  }

  BigNum add(const BigNum &crhs) const{
    BigNum lhs(*this);
    BigNum rhs(crhs);
    BigNum res;

    res.offset = max(lhs.offset, rhs.offset);
    lhs.set_offset(res.offset);
    rhs.set_offset(res.offset);

    int carry = 0;
    for (size_t i = 0; i < max(lhs.a.size(), rhs.a.size()); i++){
      int dl = i < lhs.a.size()? lhs.a[i] : 0;
      int dr = i < rhs.a.size()? rhs.a[i] : 0;
      int ds = dl + dr + carry;
      res.a.push_back(ds % 10);
      carry = ds / 10;
    }
    if (carry > 0){
      res.a.push_back(carry);
    }

    return res;
  }

  BigNum mul(const BigNum &crhs) const{
    BigNum lhs(*this);
    BigNum rhs(crhs);
    BigNum res("0");

    //cout << "\nMUL:" << endl;
    //cout << lhs.to_string() << endl;
    //cout << rhs.to_string() << endl;

    for (size_t i = 0; i < lhs.a.size(); i++){
      BigNum tmp = rhs.times(lhs.a[i], i);
      //cout << i << ":" << lhs.a[i] << "==>" << tmp.to_string() << endl;
      res = res.add(tmp);
    }
    res.offset += lhs.offset;

    return res;
  }

  string to_string(){
    string s;
    while (a.size() < offset){
      a.push_back(0);
    }
    for (size_t i = 0; i < a.size(); i++){
      if (i == offset){
        s.push_back('.');
      }
      s.push_back(a[i] + '0');
    }

    while (s.size() > 0 && s[s.size() - 1] == '0'){
      s.erase(s.end() - 1);
    }

    reverse(s.begin(), s.end());

    while (s.size() > 0 && s[s.size() - 1] == '0'){
      s.erase(s.end() - 1);
    }
    
    if (s.size() > 0 && s[s.size() - 1] == '.'){
      s.erase(s.end() - 1);
    }

    if (s.size() == 0){
      s.push_back('0');
    }

    return s;
  }
};

int main(){
  string R;
  int n;

  while (cin >> R >> n){
    BigNum bignum_R(R);
    //cout << bignum_R.to_string() << endl;
    BigNum bignum_S("1");

    for (int i = 0; i < n; i++){
    //  cout << "##" << bignum_S.to_string() << endl;
      bignum_S = bignum_S.mul(bignum_R);
     // cout << "==" << bignum_R.to_string() << endl;
    }

    cout << bignum_S.to_string() << endl;
  }
}

