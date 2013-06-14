/*
 * Algorithm:   
 * Complexity:
 * IndexBased:
 * Trick:
 * LayOut:
 *    reset();
 *    input();
 *    process();
 */

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;


vector<string> lines;
vector<string> words;

int reset(){
  lines.clear();
  words.clear();
  return 1;
}

bool is_blank_line(string line){
  for (size_t i = 0; i < line.size(); i++){
    if (line[i] != ' ' && line[i] != '\t'){
      return false;
    }
  }
  return true;
}

void sol(){
  string output_line;
  if (lines.size() > 0){
    while (lines[0].size() > 0 && (lines[0][0] == ' ' || lines[0][0] == '\t')) {
      output_line.push_back(lines[0][0]);
      lines[0].erase(0, 1);
    }
  }

  for (size_t i = 0; i < lines.size(); i++){
    string &line = lines[i];
    size_t l = 0, r = 0;
    for (l = 0; l < line.size(); l = r){
      if (line[l] == ' '){
        while (r < line.size() && line[r] == ' '){
          r++;
        }
      }else{
        while (r < line.size() && line[r] != ' '){
          r++;
        }
      }
      string word = line.substr(l, r - l);
      words.push_back(word);
    }
    if (!is_blank_line(words.back())){
      words.push_back(" ");
    }
  }
  for (size_t i = 0; i < words.size(); i++){
    string word = words[i];
    if (output_line.size() + word.size() > 72){
      while (output_line[output_line.size() - 1] == ' '){
        output_line.erase(output_line.size() - 1);
      }
      cout << output_line << endl;
      output_line = "";
    }
    if (output_line.size() == 0 && word.size() >= 72){
      cout << word << endl;
      continue;
    }
    if (output_line.size() == 0 && is_blank_line(word)){
      continue;
    }
    output_line += word;
  }
  while (output_line[output_line.size() - 1] == ' '){
    output_line.erase(output_line.size() - 1);
  }
  if (output_line.size() > 0){
    cout << output_line << endl;
  }
}

int main(){
  reset();
  string line;
  while (getline(cin, line)){
    if (is_blank_line(line)){
      sol();
      cout << endl;
      reset();
    }else if (line.size() > 0 && line[0] == ' '){
      sol();
      reset();
      lines.push_back(line);
    }else{
      lines.push_back(line);
    }
  }
  sol();
}


