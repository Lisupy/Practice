/*
 * Algorithm:  
 */


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cmath>
#include<cassert>
using namespace std;


const int BASE = 10000;


vector<int> str_to_bignum(string s){
  reverse(s.begin(), s.end());
  vector<int> a;
  for (size_t i = 0; i < s.size(); i++){
    a.push_back(atoi(s.substr(i, 4).c_str()));
  }
  return a;
}

string int_to_str(int k, int n){
  char buf[32];
  sprintf(buf, "%0*d", k, n);
  return buf;
}

string bignum_to_str(vector<int> a){
  if (a.size() == 0){
    return "0";
  }
  reverse(a.begin(), a.end());
  string s;
  s += int_to_str(0, a[0]);
  for (size_t i = 1; i < a.size(); i++){
    s += int_to_str(4, a[i]);
  }
  if (s.size() == 0) s = "0";
  return s;
}

vector<int> bignum_add(const vector<int> &a, const vector<int> &b){
  vector<int> c(max(a.size(), b.size()));
  int carry = 0;
  for (size_t i = 0; i < max(a.size(), b.size()); i++){
    int da = i < a.size() ? a[i] : 0;
    int db = i < b.size() ? b[i] : 0;
    int dc = da + db + carry;
    carry = dc / BASE;
    c[i] = dc % BASE;
  }
  if (carry) c.push_back(carry);
  return c;
}

vector<int> bignum_times(const vector<int> &a, size_t off, size_t times){
  vector<int> c(off + a.size(), 0);
  int carry = 0;
  for (size_t i = 0; i < a.size(); i++){
    int dc = a[i] * times + carry;
    carry = dc / BASE;
    c[i + off] = dc % BASE;
  }
  if (carry) c.push_back(carry);
  return c;
}

vector<int> bignum_mul(const vector<int> &a, const vector<int> &b){
  vector<int> c;
  for (size_t i = 0; i < a.size(); i++){
    size_t off = i;
    vector<int> tmp = bignum_times(b, off, a[i]);
    c = bignum_add(c, tmp);
  }
  return c;
}

vector<int> bignum_sub(const vector<int> &a, const vector<int> &b){
  vector<int> c(max(a.size(), b.size()));
  int borrow = 0;
  for (size_t i = 0; i < max(a.size(), b.size()); i++){
    int da = i < a.size() ? a[i] : 0;
    int db = i < b.size() ? b[i] : 0;
    int dc = da - db - borrow;
  //  printf("%d %d %d\n", da, db, dc);
    borrow = dc < 0 ? 1 : 0;
    c[i] = dc < 0 ? dc + BASE : dc;
  }
  assert(borrow == 0);
  while (c.size() && c.back() == 0) c.erase(c.end() - 1);
  return c;
}


const int MAXN = 301;
const int MAXD = 151;
vector<int> f[MAXN][MAXD];
void init_f(){
  for (int n = 0; n < MAXN; n += 2){
    for (int d = 0; d < MAXD; d++){
      vector<int> &res = f[n][d];
      if (n == 0){
        res = str_to_bignum("1");
        continue;
      }
      if (d == 0) continue;
      for (int k = 2; k <= n; k += 2){
        vector<int> tmp;
        tmp = bignum_mul(f[n - k][d], f[k - 2][d - 1]);
        res = bignum_add(res, tmp);
      }
  //    cout << n << ", " << d << "=> " << bignum_to_str(res) << endl;
    }
  //  cout << n << endl;
  }

  for (int n = 0; n < MAXN; n += 2){
    for (int d = MAXD - 1; d >= 1; d--){
   //   cout << n << ", " << d << "=> "; 
    //  cout << bignum_to_str(f[n][d]) << " - ";
     // cout << bignum_to_str(f[n][d - 1]) << endl;
      f[n][d] = bignum_sub(f[n][d], f[n][d - 1]);
      //cout << " = " << bignum_to_str(f[n][d]) << endl;
    }
  }
  
}


int main(){
//  cout << int_to_str(0, 20) << endl;
 // cout << int_to_str(3, 2) << endl;
  init_f();
 // cout << int_to_str(3, 2) << endl;
  int n, d;
  while (cin >> n >> d){
   // cout << int_to_str(3, 2) << endl;
    vector<int> &res = f[n][d];
    string s = bignum_to_str(res);
    cout << s << endl;
  }
}


