/*
 * Algiorithm:  C(0, n) + C(2, N) + C(4, N);
 */

#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;

const int BASE = 10000;
vector<int> str_to_bignum(const string &s){
  vector<int> a;
  for (size_t i = 0; i < s.size(); i+=4){
    a.push_back(atoi(s.substr(i, 4).c_str()));
  }
  reverse(a.begin(), a.end());
  return a;
}


string bignum_to_str(const vector<int> &a){
  string s;
  for (size_t i = 0; i < a.size(); i++){
    char buf[20];
    int len = sprintf(buf, "%04d", a[i]);
    reverse(buf, buf+len);
    s += string(buf);
  }
  while (s.size() > 0 && s[s.size() - 1] == '0'){
    s.erase(s.size() - 1);
  }
  if (s.size() == 0) s = "0";
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
    carry = dc / BASE;
    c.push_back(dc % BASE);
  }
  if (carry) c.push_back(carry);
  return c;
}

vector<int> bignum_times(const vector<int> &a, size_t off, size_t times){
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

vector<int> bignum_mul(const vector<int> &a, const vector<int> &b){
  vector<int> c;
  for (size_t i = 0; i < a.size(); i++){
    int off = i;
    vector<int> t = bignum_times(b, off, a[i]);
    c = bignum_add(c, t);
  }
  return c;
}

vector<int> int_to_bignum(int n){
  vector<int> a;
  while (n){
    a.push_back(n % BASE);
    n /= BASE;
  }
  return a;
}

vector<int> bignum_binomial_coefficients(int n, int k){
  vector<int> a;
  for (int i = 0; i < k; i++){
    a.push_back(n - i);
  }
  for (int i = k; i >= 2; i--){
    for (int j = 0; j < k; j++){
      if (a[j] % i == 0){
        a[j] /= i;
        break;
      }
    }
  }
  vector<int> result = str_to_bignum("1");
  for (int i = 0; i < k; i++){
    vector<int> t = int_to_bignum(a[i]);
    result = bignum_mul(result, int_to_bignum(a[i]));
    string ss = bignum_to_str(result);
  }
  string ss = bignum_to_str(result);
  return result;
}

int main(){
  int s;
  cin >> s;
  while (s--){
    int n;
    cin >> n;
    vector<int> result = str_to_bignum("1");
    result = bignum_add(result, bignum_binomial_coefficients(n, 2)); 
    result = bignum_add(result, bignum_binomial_coefficients(n, 4)); 
    string ss = bignum_to_str(result);
    cout << ss << endl;
  }
}

