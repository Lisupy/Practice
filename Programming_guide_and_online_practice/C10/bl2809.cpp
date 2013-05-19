#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


vector<int> string_to_bignum(string s){
  vector<int> bignum(s.size());
  for (size_t i = 0; i < s.size(); i++){
    bignum[i] = s[i] - '0';
  }
  reverse(bignum.begin(), bignum.end());
  return bignum;
}

string bignum_to_string(vector<int> bignum){
  string s(bignum.size(), '0');
  for (size_t i = 0; i < bignum.size(); i++){
    s[i] = bignum[i] + '0';
  }
  reverse(s.begin(), s.end());
  return s;
}

vector<int> bignum_add(vector<int> a, vector<int> b){
  vector<int> c;
  
  int carry = 0;
  for (size_t i = 0; i < max(a.size(), b.size()); i++){
    int da = i < a.size()? a[i] : 0;
    int db = i < b.size()? b[i] : 0;
    int dc = da + db + carry;
    c.push_back(dc % 10);
    carry = dc / 10;
  }
  if (carry != 0){
    c.push_back(carry);
  }

  return c;
}

vector<int> bignum_times(vector<int> a, int times, int off){
  vector<int> b(off, 0);
  
  int carry = 0;
  for (size_t i = 0; i < a.size(); i++){
    int da = i < a.size()? a[i] : 0;
    int db = da * times + carry;
    b.push_back(db % 10);
    carry = db / 10;
  }
  if (carry != 0){
    b.push_back(carry);
  }

  return b;
}

vector<int> bignum_mul(vector<int> a, vector<int> b){
  vector<int> c;
  for (size_t i = 0; i < a.size(); i++){
    int times = a[i];
    int off = i;
    vector<int> tmp = bignum_times(b, times, off);
    c = bignum_add(c, tmp);
  }
  return c;
}

vector<int> bignum_pow(vector<int> a, int pow){
  vector<int> s(1, 1);
  vector<int> acc(a);
  for (int i = 0; i < 7; i++){
    if (pow & (1 << i)){
      s = bignum_mul(s, acc);
    }
    acc = bignum_mul(acc, acc);
 //   printf("%d\n", i);
  }
  return s;
}

int main(){
  int N;
  scanf("%d", &N);
  vector<int> a(1, 2);
  a = bignum_pow(a, N);
  //printf("FUCK\n");
  cout << bignum_to_string(a) << endl;
}
