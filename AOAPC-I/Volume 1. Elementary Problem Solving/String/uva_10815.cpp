#include<cstdio>
#include<string>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;


set<string> dict;


int main(){
  string s;
  char ch;
  while (scanf("%c", &ch) != EOF){
    if (isalpha(ch)){
      s += ch;
    }else{
      if (s != ""){
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        dict.insert(s);
        s = "";
      }
    }
  }
  for (set<string>::iterator it = dict.begin(); it != dict.end(); it++){
    cout << *it << endl;
  }
}
