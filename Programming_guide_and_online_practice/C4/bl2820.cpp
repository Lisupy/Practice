#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


string s1,s2;
vector<int> c1,c2;

bool check(){
  c1.resize(256);
  for (size_t i = 0; i < s1.size(); i++){
    c1[s1[i]]++;
  }
  c2.resize(256);
  for (size_t i = 0; i < s2.size(); i++){
    c2[s2[i]]++;
  }

  sort(c1.begin(), c1.end());
  sort(c2.begin(), c2.end());

  if(c1 == c2){
    return true;
  }

  return false;
}

int main(){
  cin>>s1>>s2;
  if (check()){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
