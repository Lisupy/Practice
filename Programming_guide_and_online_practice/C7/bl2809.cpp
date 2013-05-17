#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int BASE = 10*1000;

void bignum_pr(const vector<int> &a){
  for (int i = a.size() - 1; i >= 0; i--){
    if (i == int(a.size() - 1)){
      printf("%d", a[i]);
    }else{
      printf("%04d", a[i]);
    }
  }
  printf("\n");
}


vector<int> bignum_add(const vector<int> &a, const vector<int> &b){
  vector<int> c;

  int carry = 0;
  for (size_t i = 0; i < max(a.size(), b.size()); i++){
    int da = i < a.size()? a[i] : 0;
    int db = i < b.size()? b[i] : 0;
    int dc = da + db + carry;
    c.push_back(dc % BASE);
    carry = dc / BASE;
  }
  while (carry > 0){
    c.push_back(carry % BASE);
    carry /= BASE;
  }

  return c;
}

vector<int> bignum_times(const vector<int> &a, int times, int offset){
  vector<int> b(offset, 0);

  int carry = 0;
  for (size_t i = 0; i < a.size(); i++){
    int da = a[i];
    int db = da * times + carry;
    b.push_back(db % BASE);
    carry = db / BASE;
  }
  while (carry > 0){
    b.push_back(carry % BASE);
    carry /= BASE;
  }
  return b;
}

vector<int> bignum_mul(const vector<int> &a, const vector<int> &b){
  vector<int> c;

  for (size_t i = 0; i < a.size(); i++){
    int offset = i;
    vector<int> tmp = bignum_times(b, a[i], offset);
    c = bignum_add(c, tmp);
  }

  return c;
}

vector<int> bignum_pow(const vector<int> &a, int p){
  vector<int> res(1,1);
  vector<int> acc(a);

  while (p > 0){
    if (p % 2){
      res = bignum_mul(res, acc);
    }
    acc = bignum_mul(acc, acc);
    p /= 2;
  }

  return res;
}

int main(){
  vector<int> a(1, 2);

  int N;
  cin >> N;
  a = bignum_pow(a, N);

  bignum_pr(a);
}



