#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


unsigned int string_to_unsigned_int(string s){
  int u = 0;
  int len = s.size();
  for (size_t i = 0; i < s.size(); i++){
    u += (s[i] - '0')*((1u<<(len-i)) - 1);
  }
  return u;
}

int main(){
  string n;
  while(cin>>n){
    unsigned int u = string_to_unsigned_int(n);
    if (u){
      cout<<u<<endl;
    }else{
      break;
    }
  }
}
