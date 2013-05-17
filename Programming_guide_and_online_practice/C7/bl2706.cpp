#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;



const int BASE = 10*1000;
const int BIGNUM_SIZE = 500/4;

void bignum_pr(const vector<int> &a){
 char buf[1000];
 int len = 0;

 for (int i = a.size() - 1 ; i >= 0; i--){
  len += sprintf(buf+len, "%04d", a[i]);
 }

 for (int i = 0; buf[i]; i++){
   printf("%c", buf[i]);
   if ((i+1) % 50 == 0){
     printf("\n");
   }
 }
}

vector<int> bignum_add(const vector<int> &a, const vector<int> &b){
  vector<int> c(BIGNUM_SIZE, 0);

  int carry = 0;
  for (size_t i = 0; i < a.size(); i++){
    int dc = a[i] + b[i] + carry;
    c[i] += dc % BASE;
    carry = dc / BASE;
  }

  return c;
}

vector<int> bignum_times(const vector<int> &a, int times, int offset){
  vector<int> b(BIGNUM_SIZE, 0);
  
  int carry = 0;
  for (size_t i = 0; i < a.size(); i++){
    size_t pos = i + offset;
    if (pos < b.size()){
      b[pos] = a[i] * times + carry;
      carry = b[pos] / BASE;
      b[pos] %= BASE;
    }
  }
  return b;
}

vector<int> bignum_mul(const vector<int> &a, const vector<int> &b){
  vector<int> c(BIGNUM_SIZE, 0);

  for (size_t i = 0; i < a.size(); i++){
    int offset = i;
    vector<int> tmp = bignum_times(b, a[i], offset);
    c = bignum_add(c, tmp);
  }
  return c;
}
vector<int> bignum_sub(const vector<int> &a, const vector<int> &b){
  vector<int> c(BIGNUM_SIZE, 0);

  int borrow = 0;
  for (size_t i = 0; i < a.size(); i++){
    int dc = a[i] - b[i] - borrow;
    if (dc < 0){
      dc += BASE;
      borrow = 1;
    }else{
      borrow = 0;
    }
    c[i] = dc;
  }

  return c;
}

vector<int> bignum_pow(const vector<int> &a, int p){
  vector<int> acc(BIGNUM_SIZE, 0);
  acc[0] = 1;
  vector<int> res(a);
  while(p > 0){
    //cout<<p<<endl;
    //bignum_pr(acc);
    //bignum_pr(res);
    if (p % 2 == 0){
      res = bignum_mul(res, res);
    }else if (p % 2 != 0){
      acc = bignum_mul(acc, res);
      res = bignum_mul(res, res);
    }
    p /= 2;
  }
  return acc;
}



int main(){
  int P;
  cin >> P;

  //PART 1
  int num = log(2)/log(10)*P + 1;
  cout << num << endl;

  //PART 2
  vector<int> a(BIGNUM_SIZE, 0);
  a[0] = 2;
  a = bignum_pow(a, P);

  vector<int> b(BIGNUM_SIZE, 0);
  b[0] = 1;

  a = bignum_sub(a, b);
  
  bignum_pr(a);
}
