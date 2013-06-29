#include<iostream>
#include<string>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;


vector<string> texts;


int main(){
  string line;
  while (getline(cin, line)){
    texts.push_back(line);
  }

  int max_len = 0;
  for (size_t i = 0; i < texts.size(); i++){
    max_len = max(max_len, (int)texts[i].size());
  }


  for (int l = 1; l <= max_len; l++){
    int up = 0;
    while ((int)texts[up].size() < l){
      up++;
    }
    for (int i = texts.size() - 1; i >= up; i--){
      char ch = l - 1 < (int)texts[i].size() ? texts[i][l - 1] : ' ';
      cout << ch;
    }
    cout << endl;
  }
}
