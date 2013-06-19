#include<algorithm>
#include<cstdio>
#include<vector>
#include<iostream>
#include<cstdlib>
#include<cctype>
#include<cassert>
using namespace std;

const int BASE = 10*1000;
const int WIDTH = 4;


string str_from_int(int width, int n){
  char buf[32];
  sprintf(buf, "%0*d", width, n);
  return buf;
}

string str_from_bignum(vector<int> a){
  if (a.size() == 0)return "0";
  reverse(a.begin(), a.end());
  string s = str_from_int(0, a[0]);
  for (size_t i = 1; i < a.size(); i++){
    s += str_from_int(WIDTH, a[i]);
  }
  return s;
}

vector<int> bignum_from_str(string s){
  reverse(s.begin(), s.end());
  vector<int> a;
  for (size_t i = 0;i < s.size(); i += WIDTH){
    a.push_back(atoi(s.substr(i, WIDTH).data()));
  }
  return a;
}

vector<int> bignum_times(vector<int> a, size_t off, size_t times){
  vector<int> b(off, 0);
  int carry = 0;
  for (size_t i = 0; i < a.size(); i++){
    int db = a[i] * times + carry;
    carry = db / BASE;
    b.push_back(db % BASE);
  }
  if (carry) b.push_back(carry);
  return b;
}

int sum_arit(int k, int d){
  int s = 1;
  for (int i = 0; i <= d; i++){
    s *= k;
  }
  return (1 - s) / (1 - k);
}

int gcd(int a, int b){
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

void reduce(vector<int> &a, int c){
 // cout << c << endl;
  for (size_t i = 0; i < a.size() && c != 1; i++){
    int g = gcd(a[i], c);
    a[i] /= g;
    c /= g;
  }
  assert(c == 1);
}

void p_vector(vector<int> a){
  for (size_t i = 0; i < a.size(); i++){
    cout << a[i] << " ";
  }
  cout << endl;
}
vector<int> F(int k, int d){
  int n = sum_arit(k, d);
  //cout << n << endl;
  vector<int> a;
  for (int i = 1; i < n; i++){
    a.push_back(i);
  }
 // p_vector(a);
  int kk = 1;
  for (int i = d - 1; i >= 0; i--){
    int m = sum_arit(k, i);
   // cout << "#" << m << endl;
    kk *= k;
    for (int j = 0; j < kk; j++){
     // for (int c = 1; c <= m; c++){
        reduce(a, m);
      //}
  //    p_vector(a);
    }
  }

  vector<int> result = bignum_from_str("1");
  for (size_t i = 0; i < a.size(); i++){
    result = bignum_times(result, 0, a[i]);
  }
  return result;
}

int main(){
  int k, d;
  while (cin >> k >> d){
    if (k == 1){
      cout << 1 << endl;
    }else{
      vector<int> res = F(k, d);
      cout << str_from_bignum(res) << endl;
    }
  }
}

