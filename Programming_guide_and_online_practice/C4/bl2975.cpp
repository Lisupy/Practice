#include<cstdio>
#include<algorithm>
#include<string>
#include<cctype>
#include<iostream>
using namespace std;




char decode[256];

string input;

string decrypt(string s){
  string o;
  for (size_t i = 0; i < s.size(); i++){
    char c = s[i];
    o.push_back(decode[int(c)]);
  }
  return o;
}


int main(){
  for (int i = 0; i < 256; i++){
    decode[i] = i;
  }
  rotate(decode+'A', decode+'V', decode+'Z'+1);

  while(getline(cin, input)&&input=="START"){
    getline(cin, input);
    cout<<decrypt(input)<<endl;
    getline(cin, input);
  }
}
