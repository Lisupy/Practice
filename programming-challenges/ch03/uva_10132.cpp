/*
 * Algorithm:   enumeration and check
 * Complexity:  n*n%2
 * IndexBased:  0
 * Trick:       
 * LayOut:
 *    reset();
 *    input();
 *    is_valid(s);
 */

#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cassert>
#include<iostream>
#include<algorithm>
using namespace std;



vector<string> frags;


void reset(){
  frags.clear();
}

void input(){
  string line;
  while (getline(cin, line) && line.size() > 0){
  //  cout << "[" << line << "]" << endl;
    frags.push_back(line);
  }
}

bool is_valid(string s){
  vector<bool> used(frags.size(), false);
  for (size_t i = 0; i < frags.size(); i++){
    if (used[i]){
      continue;
    }
    used[i] = true;
    int pos = -1;
    string &a = frags[i];
    for (size_t j = 0; j < frags.size(); j++){
      if (used[j]){
        continue;
      }
      string &b = frags[j];
      if (a + b == s || b + a == s){
        pos = j;
        break;
      }
    }
    if (pos == -1){
      return false;
    }
    used[pos] = true;
  }
  return true;
}


string sol(){
  for (size_t i = 1; i < frags.size(); i++){
    string &a = frags[0];
    string &b = frags[i];
    string s = a + b;
    if (is_valid(s)){
      return s;
    }
    s = b + a;
    if (is_valid(s)){
      return s;
    }
  }
  assert(0);
}

int main(){
  int CASES;
  cin >> CASES;
  cin.ignore();
  cin.ignore();
  while (CASES--){
    reset();
    input();
    string ans = sol();
    cout << ans << endl;
    if (CASES != 0){
      cout << endl;
    }
  }
}

