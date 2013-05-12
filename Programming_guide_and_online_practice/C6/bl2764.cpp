#include<iostream>
#include<string>
#include<numeric>
#include<sstream>
using namespace std;


string int_to_string(int n){
  stringstream ss;
  ss<<n;
  string o;
  ss>>o;
  return o;
}

string num_root(string s){
  while(s.size()>1){
    int n = 0;
    for (size_t i = 0; i < s.size(); i++){
      n+=s[i]-'0';
    }
    s = int_to_string(n);
  }
  return s;
}

int main(){
  string str;
  while (cin >>str && str != "0"){
    cout << num_root(str) << endl;
  }
}

