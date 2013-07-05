#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string s){
  stack<char> S;
  for (size_t i = 0; i < s.size(); i++){
    char ch = s[i];
    if (ch == '(' || ch == '['){
      S.push(ch);
    }else{
      char opch;
      if (ch == ')') opch = '(';
      if (ch == ']') opch = '[';
      if (!S.empty() && S.top() == opch){
        S.pop();
      }else{
        return false;
      }
    }
  }
  return S.size() == 0;
}

int main(){
  int n;
  cin >> n;
  cin.ignore();
  while (n--){
    string s;
    getline(cin, s);
    if (isValid(s)){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}


  
