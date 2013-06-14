/*
 * Algorithm: Brute-forces
 * Complexity:
 * Trick:
 * LayOut:
 *  reset();
 *  input();
 *  sol();
 *    try_gen_keys;
 *    decrypt;
 */


#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;


vector<string> lines;

string ori = "the quick brown fox jumps over the lazy dog";

void reset(){
  lines.clear();
}

bool try_gen_keys(string line, string& key){
  if (line.size() != ori.size()){
    return false;
  }
  key = string(256, ' ');
  for (size_t i = 0; i < line.size(); i++){
    char old_ch = ori[i];
    char new_ch = line[i];
    if (old_ch == ' ' && new_ch != ' '){
      return false;
    }
    if (old_ch != ' ' && new_ch == ' '){
      return false;
    }
    if (key[new_ch] == ' '){
      key[new_ch] = old_ch;
    }else{
      if (key[new_ch] != old_ch){
        return false;
      }
    }
  }
  return true;
}

bool gen_key(string &key){
  for (size_t i = 0; i < lines.size(); i++){
   // cout << "[" << lines[i] << "]" << endl;
    if (try_gen_keys(lines[i], key)){
      return true;
    }
  }
  return false;
}

string decrypt(string line, string key){
  string s;
  for (size_t i = 0; i < line.size(); i++){
    char ch = line[i];
    if (ch == ' '){
      s += ' ';
    }else{
      s += key[int(ch)];
    }
  }
  return s;
}

void sol(){
  string key;
  if (!gen_key(key)){
    cout << "No solution." << endl;
    return;
  }
  for (size_t i = 0; i < lines.size(); i++){
    cout << decrypt(lines[i], key) << endl;
  }
}

void input(){
  string line;
  while (getline(cin, line)){
   // cout << "#[" << line << "]" << endl;
    if (line.size() == 0){
      return;
    }
    lines.push_back(line);
  }
}

int main(){
  int T;
  cin >> T;
  cin.ignore();
  cin.ignore();
  while (T--){
    reset();
    input();
    sol();
    if (T){
      cout << endl;
    }
  }
}
