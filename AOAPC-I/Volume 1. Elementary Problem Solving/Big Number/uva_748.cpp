#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const long long BASE = 100 * 1000;


vector<long long> bignumTimes(vector<long long> a, long long n){
  vector<long long> c;
  long long carry = 0;
  for (size_t i = 0; i < a.size() || carry != 0; i++){
    long long da = i < a.size() ? a[i] : 0;
    long long dc = da * n + carry;
    carry = dc / BASE;
    c.push_back(dc % BASE);
  }
  return c;
}


long long llFromStr(string s){
  long long l;
  sscanf(s.c_str(), "%lld", &l);
  return l;
}

string strFromll(long long n, int ocu){
  char buf[32];
  sprintf(buf, "%0*lld", ocu, n);
  return buf;
}
void gao(string a, int n){
  size_t dot_pos = a.find(".");
  string s = a.substr(0, dot_pos) + a.substr(dot_pos + 1);
  long long R = llFromStr(s);
  vector<long long> S(1, 1);
  for (int i = 0; i < n; i++){
    S = bignumTimes(S, R);
  }
  reverse(S.begin(), S.end());
  s = strFromll(S[0], 0);
  for (size_t i = 1; i < S.size() ; i++){
    s += strFromll(S[i], 5);
  }
  dot_pos = (5 - dot_pos) * n;
  if (dot_pos > s.size()){
    s = "." + string(dot_pos - s.size(), '0') + s;
  }else{
    s = s.substr(0, s.size() - dot_pos) + "." + s.substr(s.size() - dot_pos);
  }
  //while (s.size() > 0 && s.back() == '0'){
  while (s.size() > 0 && *s.rbegin() == '0'){
    s.erase(s.end() - 1);
  }
  cout << s << endl;
}

int main(){
  string R;
  int n;
  while (cin >> R >> n){
    gao(R, n);
  }
}

