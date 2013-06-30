#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;


vector<int> bignumFromStr(string s){
  reverse(s.begin(), s.end());
  vector<int> a;
  for (size_t i = 0; i < s.size(); i++){
    a.push_back(s[i] - '0');
  }
  return a;
}


string strFromBignum(vector<int> a){
  reverse(a.begin(), a.end());
  if (a.size() == 0){
    return "0";
  }
  string s;
  for (size_t i = 0; i < a.size(); i++){
    s += a[i] + '0';
  }
  return s;
}


vector<int> bignumAdd(vector<int> a, vector<int> b){
  vector<int> c;
  int carry = 0;
  for (size_t i = 0; i < max(a.size(), b.size()) || carry != 0; i++){
    int da = i < a.size() ? a[i] : 0;
    int db = i < b.size() ? b[i] : 0;
    int dc = da + db + carry;
    carry = dc / 10;
    c.push_back(dc % 10);
  }
  return c;
}


int main(){
  string s;
  vector<int> acc;
  while (cin >> s && s != "0"){
    acc = bignumAdd(acc, bignumFromStr(s));
  }
  cout << strFromBignum(acc) << endl;
}



