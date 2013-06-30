#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<iostream>
using namespace std;

const int BASE = 10 * 1000;

string strFromInt(int n, int occ){
  char buf[32];
  sprintf(buf, "%0*d", occ, n);
  return buf;
}

vector<int> bignumFromStr(string s){
  reverse(s.begin(), s.end());
  vector<int> a;
  for (size_t i = 0; i < s.size(); i += 4){
    string t = s.substr(i, 4);
    reverse(t.begin(), t.end());
    a.push_back(atoi(t.data()));
  }
  return a;
}

string strFromBignum(vector<int> a){
  while (a.size() > 0 && a.back() == 0){
    a.pop_back();
  }
  reverse(a.begin(), a.end());
  if (a.size() == 0){
    return "0";
  }
  string s;
  s += strFromInt(a[0], 0);
  for (size_t i = 1; i < a.size(); i++){
    s += strFromInt(a[i], 4);
  }
  return s;
}

vector<int> bignumAdd(vector<int> a, vector<int> b){
  vector<int> c;
  int carry = 0;
  for (size_t i = 0; i < max(a.size(), b.size()) || carry; i++){
    int da = i < a.size() ? a[i] : 0;
    int db = i < b.size() ? b[i] : 0;
    int dc = da + db + carry;
    carry = dc / BASE;
    c.push_back(dc % BASE);
  }
  return c;
}


vector<int> bignumTimes(vector<int> a, size_t off, size_t n){
  vector<int> c(off);
  int carry = 0;
  for (size_t i = 0; i < a.size() || carry; i++){
    int da = i < a.size() ? a[i] : 0;
    int dc = da * n + carry;
    carry = dc / BASE;
    c.push_back(dc % BASE);
  }
  return c;
}

vector<int> bignumMul(vector<int> a, vector<int> b){
  vector<int> c;
  for (size_t i = 0; i < a.size(); i++){
    int off = i;
    int n = a[i];
    vector<int> t = bignumTimes(b, off, n);
    c = bignumAdd(c, t);
  }
  return c;
}


int main(){
  string X, Y;
  while (cin >> X >> Y){
    cout << strFromBignum(bignumMul(bignumFromStr(X), bignumFromStr(Y))) << endl;
  }
}


