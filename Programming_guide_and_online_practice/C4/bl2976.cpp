#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


bool is_subsequence(string s, string t){
  size_t pos = 0;
  for (size_t i = 0; i < s.size(); i++){
    char c = s[i];
    pos = t.find_first_of(c, pos);
    if (pos == string::npos){
      return false;
    }
    pos++;
  }
  return true;
}


int main(){
  string s, t;
  while(cin>>s>>t){
    if (is_subsequence(s,t)){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
}


