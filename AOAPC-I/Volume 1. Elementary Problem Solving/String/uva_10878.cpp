#include<string>
#include<iostream>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;

int main(){
  string line;
  while(getline(cin, line) && line.size()){
    if (line == "___________"){
      continue;
    }
    string s = line.substr(2, 4) + line.substr(7, 3);
    int ord = 0;
    for (size_t i = 0; i < s.size(); i++){
      if (s[i] == 'o'){
        ord = ord * 2 + 1;
      }else{
        ord = ord * 2;
      }
    }
    cout << (char)ord;
  }
}
