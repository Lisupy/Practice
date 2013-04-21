#include<string>
#include<iostream>
#include<algorithm>
using namespace std;



string string_format(string s){
  string o;
  for (size_t i = 0; i < s.size(); i++){
    char c = toupper(s[i]);
    if (c != ' '){
      o.push_back(c);
    }
  }

  size_t start_pos = o.find_first_not_of(" ");
  size_t end_pos = o.find_last_not_of(" ");

  if (start_pos == string::npos){
    return "";
  }
  return o.substr(start_pos, end_pos-start_pos+1);
}


int main(){
  int n;
  string s1, s2;
  cin>>n;
  while(n--){
    getline(cin, s1);
    getline(cin, s1);
    getline(cin, s2);
    s1 = string_format(s1);
    s2 = string_format(s2);
    if (s1 == s2){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}
