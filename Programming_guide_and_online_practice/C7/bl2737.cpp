#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cassert>
using namespace std;

vector<int> str_to_bignum(const string &s){
  vector<int> bignum;

  for (size_t i = 0; i < s.size(); i++){
    bignum.push_back(s[i] - '0');
  }

  reverse(bignum.begin(), bignum.end());

  while (bignum.size() > 0 && bignum.back() == 0){
    bignum.pop_back();
  }

  return bignum;
}

string bignum_to_str(const vector<int> &bignum){
  string s;

  for (size_t i = 0; i < bignum.size(); i++){
    s.push_back(bignum[i] + '0');
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
    int da = i < a.size()? a[i] : 0;
    int db = i < b.size()? b[i] : 0;
    int dc = da + db + carry;
    carry = dc / 10;
    dc %= 10;
    c.push_back(dc);
  }
  while (carry > 0){
    c.push_back(carry % 10);
    carry /= 10;
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
    b.push_back(carry % 10);
    carry /= 10;
  }

  while (b.size() > 0 && b.back() == 0){
    b.pop_back();
  }

  return b;
}

int bignum_cmp(const vector<int> &a, const vector<int> &b){
  if (a.size() > b.size()){
    return 1;
  }else if(a.size() < b.size()){
    return -1;
  }

  int len = a.size() - 1;
  for (size_t i = 0; i < a.size(); i++){
    if (a[len - i] > b[len - i]){
      return 1;
    }else if (a[len - i] < b[len - i]){
      return -1;
    }
  }
  return 0;
}

vector<int> bignum_sub(const vector<int> &lhs, const vector<int> &rhs){
  assert(bignum_cmp(lhs, rhs) >= 0);

  vector<int> res;
  int borrow = 0;

  for (size_t i = 0; i < lhs.size(); i++){
    int dl = i < lhs.size()? lhs[i] : 0;
    int dr = i < rhs.size()? rhs[i] : 0; 
    int ds = dl - dr - borrow;
    if (ds < 0){
      ds += 10;
      borrow = 1;
    }else{
      borrow = 0;
    }
    res.push_back(ds);
  }
  while (res.size() > 0 && res.back() == 0){
    res.pop_back();
  }
  return res;
}

vector<int> bignum_div(const vector<int> &clhs, const vector<int> &rhs){
  vector<int> res(clhs.size(), 0);
  vector<int> lhs(clhs);
  int offset = clhs.size() - 1;

  if (bignum_cmp(lhs, rhs) >= 0){
    while (offset >= 0){
      int try_i = 0;
      for (try_i = 0; try_i < 10; try_i++){
        vector<int> tmp = bignum_times(rhs, try_i, offset);
       // cout << offset << "," << try_i << ":" << bignum_to_str(tmp) << endl;
       // cout << bignum_to_str(lhs) << endl;
       // cout<<bignum_cmp(lhs, tmp) << endl;
        if (bignum_cmp(lhs, tmp) < 0){
          break;
        }
      }
      try_i--;
      res[offset] = try_i;
      vector<int> tmp = bignum_times(rhs, try_i, offset);
    //  cout << "==" << offset << "," << try_i << ":" << bignum_to_str(tmp) << endl;
    //  cout << bignum_to_str(lhs) << endl;
      lhs = bignum_sub(lhs, tmp);
     // cout << bignum_to_str(lhs) << endl;
      offset--;
    }
  }

  while (res.size() > 0 && res.back() == 0){
    res.pop_back();
  }
  return res;
}

int main(){
  int n;
  cin >> n;

  while (n--){
    string lhs,rhs,res;
    cin >> lhs >> rhs;

    vector<int> bignum_lhs, bignum_rhs, bignum_res;
    bignum_lhs = str_to_bignum(lhs);
    bignum_rhs = str_to_bignum(rhs);
    bignum_res = bignum_div(bignum_lhs, bignum_rhs);

    res = bignum_to_str(bignum_res);
    cout << res << endl;
  }
}
