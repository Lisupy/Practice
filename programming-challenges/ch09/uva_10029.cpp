#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

vector<string> dict;
vector<int> steps;
int main(){
  string s;
  while (cin >> s){
    dict.push_back(s);
  }
  steps.resize(dict.size(), 1);

  for (size_t di = 0; di < dict.size(); di++){
    string &word = dict[di]; 
    vector<string> words;
    words.reserve(1000);
    for (size_t i = 0; i < word.size(); i++){
      for (char ch = word[i] + 1; ch <= 'z'; ch++){
        s = word;
        s[i] = ch;
        if (binary_search(dict.begin() + di, dict.end(), s))
          words.push_back(s);
      }
    }

    for (size_t i = 0; i <= word.size(); i++){
      for (char ch = 'z'; ch >= 'a'; ch--){
        s = word.substr(0, i) + ch + word.substr(i);
        if (s <= word){
          break;
        }
        if (binary_search(dict.begin() + di, dict.end(), s))
          words.push_back(s);
      }
    }

    for (size_t i = 0; i + 1 < word.size(); i++){
      s = word.substr(0, i) + word.substr(i + 1);
      if (s <= word){
        continue;
      }
      words.push_back(s);
    }

    for (size_t i = 0; i < words.size(); i++){
      string &w = words[i];
      if (w <= word){
        continue;
      }
      vector<string>::iterator it = lower_bound(dict.begin() + di, dict.end(), w);
      if (it == dict.end() || *it != w){
        continue;
      }
//      cout << word << "=> " << w << endl;
      size_t pos = it - dict.begin();
      if (pos < di){
        continue;
      }
 //     cout << dict[pos] << endl;
      steps[pos] = max(steps[pos], steps[di] + 1);
    }
  }
  cout << *max_element(steps.begin(), steps.end()) << endl;
}




