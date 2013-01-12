#include<cstdio>
#include<map>
#include<cstring>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

map<string,int> M;
int main(){
  int n=0;
  string name;
  while(getline(cin,name)){
    M[name]+=1;
    n++;
  }
  for (map<string,int>::iterator it = M.begin(); it != M.end(); it++){
    printf("%s %.4f\n", it->first.c_str(), (100.0*it->second)/n);
  }
}
