#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cctype>
#include<cstdio>
#include<sstream>
using namespace std;

string ananagramFromStr(string s){
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  sort(s.begin(), s.end());
  return s;
}

bool ananagram_less(const string& a, const string &b){
  return ananagramFromStr(a) < ananagramFromStr(b);
}

vector<string> words;
int main(){
  string line;
  while (getline(cin, line) && line != "#"){
    istringstream iss(line);
    string w;
    while (iss >> w){
      words.push_back(w);
    }
  }


  sort(words.begin(), words.end(), ananagram_less);

  vector<string> res;
  for (size_t l = 0, r = 0; l < words.size(); l = r){
    while (r < words.size() && ananagramFromStr(words[l]) == ananagramFromStr(words[r])){
      r++;
    }
    if (r - l == 1){
      res.push_back(words[l]);
    }
  }

  sort(res.begin(), res.end());
  for (size_t i = 0; i < res.size(); i++){
    cout << res[i] << endl;
  }
}
