#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;



int intFromSkewbinary(string s){
  reverse(s.begin(), s.end());
  int n = 0;
  for (size_t i = 0; i < s.size(); i++){
    int base = (1 << (i + 1) ) - 1;
    int d = s[i] - '0';
    n += base * d;
  }
  return n;
}


int main(){
  string s;

  while (cin >> s && s != "0"){
    cout << intFromSkewbinary(s) << endl;
  }
}
