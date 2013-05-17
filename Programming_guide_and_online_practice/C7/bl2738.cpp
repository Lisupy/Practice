#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


struct BigNum{
  vector<int> a;
  size_t offset;

  BigNum(){}

  BigNum(const string &s){
    offset = 0;
    for (int i = s.size() - 1; i >= 0; i--){
      if (s[i] == '.'){
        offset = s.size() - i - 1;
      }else{
        a.push_back(s[i] - '0');
      }
    }
  }
  
  void set_offset(size_t newoffset){
    reverse(a.begin(), a.end());
    while (newoffset > offset) {
      a.push_back(0);
      offset++;
    }
    
    while (newoffset < offset) {
      a.pop_back();
      offset--;
    }
    reverse(a.begin(), a.end());
  }

  string to_str(){
    string s;
    for (size_t i = 0; i < max(a.size(), offset); i++){
      if (i == offset){
        s.push_back('.');
      }
      int da = i < a.size()? a[i] : 0; 
      s.push_back(da + '0');
    }
    if (a.size() <= offset){
      s.push_back('.');
      s.push_back('0');
    }
    reverse(s.begin(), s.end());

    while (s.size() > 0 && s[s.size() - 1] == '0'){
      s.erase(s.end() - 1);
    }
    while (s.size() > 0 && s[s.size() - 1] == '.'){
      s.erase(s.end() - 1);
    }
    return s;
  }

  BigNum add(const BigNum &crhs){
    BigNum rhs(crhs);
    BigNum lhs(*this);
    BigNum res;
    res.offset = max(lhs.offset, rhs.offset);
    rhs.set_offset(res.offset);
    lhs.set_offset(res.offset);
    
    int carry = 0;
    for (size_t i = 0; i < max(lhs.a.size(), rhs.a.size()); i++){
      int dl = i < lhs.a.size()? lhs.a[i] : 0;
      int dr = i < rhs.a.size()? rhs.a[i] : 0;
      int ds = dl + dr + carry;
      res.a.push_back(ds % 10);
      carry = ds / 10;
    }
    if (carry > 0){
      res.a.push_back(1);
    }
    return res;
  }
};

int main(){
  int n;
  cin >> n;
  while (n--){
    string a, b, c;
    cin >> a >> b;

    BigNum bignum_a(a);
    BigNum bignum_b(b);
    BigNum bignum_c = bignum_a.add(bignum_b);
    
    c = bignum_c.to_str();
    cout << c << endl;
  }
}


