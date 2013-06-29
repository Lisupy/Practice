#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;


int countWords(string text){
  int cnt = 0;
  for (size_t i = 0; i < text.size(); i++){
    if (isalpha(text[i])){
      if (i == 0 || !isalpha(text[i - 1])){
        cnt++;
      }
    }
  }
  return cnt;
}

int main(){
  string s;
  while (getline(cin, s)){
    cout << countWords(s) << endl;
  }
}

