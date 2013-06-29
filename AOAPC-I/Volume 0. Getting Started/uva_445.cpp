#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<cctype>

using namespace std;

vector<string> maze;



void build_maze(string s){
  string tmp;
  int cnt = 0;
  for (size_t i = 0; i < s.size(); i++){
    char ch = s[i];
    if (ch == '!'){
      maze.push_back(tmp);
      tmp = "";
    }else if (ch == 'b'){
      tmp += string(cnt, ' ');
      cnt = 0;
    }else if (isdigit(ch)){
      cnt += ch - '0';
    }else{
      tmp += string(cnt, ch);
      cnt = 0;
    }
  }
  maze.push_back(tmp);
}

void output_maze(){
  for (size_t i = 0; i < maze.size(); i++){
    cout << maze[i] << endl;
  }
}

int main(){
  string s;
  //bool first = true;
  while (getline(cin, s) && !cin.eof()){
    if (s.size() == 0){
      cout << endl;
    }else{
      maze.clear();
      build_maze(s);
      output_maze();
    }
  }
}
