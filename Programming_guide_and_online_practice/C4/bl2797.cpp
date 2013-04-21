#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;


vector<string> words;
map<string, string> words_to_abbr;

size_t prefix_match(string a, string b){
  size_t len = min(a.size(), b.size());
  for (size_t i = 0; i < len; i++){
    if (a[i] != b[i])
      return i;
  }
  return len;
}


string find_abbr(string word, size_t idx){
  size_t max_match = 0;
  for (size_t i = 0; i < words.size(); i++){
    if (i == idx)
      continue;
    max_match = max(max_match, prefix_match(word, words[i]));
  }
  size_t len = min(max_match+1, word.size());
  return word.substr(0, len);
}

int main(){
  string s;
  while (cin>>s){
    words.push_back(s);
  }

  for (size_t i = 0; i < words.size(); i++){
    string word = words[i];
    cout << word << " " << find_abbr(word, i) << endl;
  }
}
