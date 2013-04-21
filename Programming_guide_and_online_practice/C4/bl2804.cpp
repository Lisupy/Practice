#include<string>
#include<map>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;


map<string, string> M;

int main(){
  string s;
  while(getline(cin, s) && s != ""){
    stringstream ss(s);
    string t;
    ss>>s>>t;
    M[t] = s;
  }

  while(cin>>s){
    if (M.find(s) == M.end()){
      cout << "eh" << endl;
    }else{
      cout << M[s] << endl;
    }
  }
}
