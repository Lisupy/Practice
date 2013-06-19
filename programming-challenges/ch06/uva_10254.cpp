/*
 * Algorithm : f(n) + 3  = 2 * (f(n) + 3)
 */

#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<cassert>
#include<vector>
using namespace std;


const int BASE = 10000;
vector<int> bignum_from_str(string s){
  vector<int> a;
  reverse(s.begin(), s.end());
  for (size_t i = 0; i < s.size(); i += 4){
    a.push_back(atoi(s.substr(i, 4).c_str()));
  }
  return a;
}

string str_from_int(int k, int n){
  char buf[20];
  sprintf(buf, "%0*d", k, n);
  return buf;
}

vector<int> bignum_from_int(int n){
  return bignum_from_str(str_from_int(0, n));
}

string str_from_bignum(vector<int> a){
  if (a.size() == 0) return "0";
  reverse(a.begin(), a.end());
  string s;
  s += str_from_int(0, a[0]);
  for (size_t i = 1; i < a.size(); i++){
    s += str_from_int(4, a[i]);
  }
  return s;
}

vector<int> bignum_add(vector<int> a, vector<int> b){
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

bool bignum_less(vector<int> a, vector<int> b){
  if (a.size() != b.size()) return a.size() < b.size();
  for (int i = a.size() - 1; i >= 0; i--){
    if (a[i] != b[i]) return a[i] < b[i];
  }
  return false;
}

const int MAXN = 10001;

vector<int> H3[MAXN];
vector<int> H4[MAXN];

void H3_init(){
  H3[0] = bignum_from_str("0");
  for (int i = 1; i < MAXN; i++){
    H3[i] = bignum_add(bignum_add(H3[i - 1], H3[i - 1]), bignum_from_str("1"));
  }
}

void H4_init(){
  H4[0] = bignum_from_str("0");
  H4[1] = bignum_from_str("1");
  H4[2] = bignum_from_str("3");
  int last_sel = 2;
  for (int i = 3; i < MAXN; i++){
    H4[i] = bignum_add(bignum_add(H4[0], H4[0]), H3[i]);
    for (int j = last_sel; j < i; j++){
      vector<int> tmp = bignum_add(bignum_add(H4[i - j], H4[i - j]), H3[j]);
      if (bignum_less(tmp, H4[i])){
        H4[i] = tmp;
        last_sel = j;
      }else{
        break;
      }
    }
  }
}


int main(){
  H3_init();
  H4_init();
  int n;
  while (cin >> n){
    vector<int> fn = H4[n];
    cout << str_from_bignum(fn) << endl;
  }
}


