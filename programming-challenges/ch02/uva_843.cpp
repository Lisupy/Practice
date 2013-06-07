/*
 * Algorithm:    DFS
 * Complexity:   ...
 * IndexBased:   0
 * Trick:        store by length
 * LayOut:       
 *    vector<vector<string> > dict;
 *    vector<string> text;
 *    bool try_encrypte(string word, char key[], string encrypted);
 *    string encrypte(string word, char key[]);
 *    bool DFS(int text_i, char key[]);
 */


#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cassert>
#include<set>
using namespace std;


const int MAXN = 1024;

vector<vector<string> > dicts(32);
vector<string> text;

bool try_encrypte(const string &word, const string &encrypted, string& key){
  string new_key(key);
  assert(word.size() == encrypted.size());
  for (size_t i = 0; i < word.size(); i++){
    char old_ch = word[i];
    char new_ch = encrypted[i];
    if (new_key[(int)old_ch] != '*' && new_key[(int)old_ch] != new_ch){
      return false;
    }
    new_key[(int)old_ch] = new_ch;
  }

  set<char> S;
  for (size_t old_ch = 'a'; old_ch <= 'z' ; old_ch++){
    char new_ch = new_key[old_ch];
    if (new_ch != '*' && S.find(new_ch) != S.end()){
      return false;
    }
    S.insert(new_ch);
  }

  key = new_key;
  return true;
}

string encrypte(const string &word, const string &key){
  string s(word);
  for (size_t i = 0; i < s.size(); i++){
    s[i] = key[int(s[i])];
  }
  return s;
}

bool DFS(int text_i, string &key){
  if (text_i == (int)text.size()){
    return true;
  }else{
    string bak_key(key);
    string &word = text[text_i];
    int len = word.size();
    vector<string>& dict = dicts[len]; 
    for (size_t i = 0; i < dict.size(); i++){
      string &encrypted = dict[i];
      if (try_encrypte(word, encrypted, key)){
        if (DFS(text_i + 1, key)){
          return true;
        }
        key = bak_key;
      }
    }
    return false;
  }
}

bool string_cmp_by_length(const string &a, const string &b){
  return a.size() > b.size();
}

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    string word;
    cin >> word;
    dicts[word.size()].push_back(word);
  }
  cin.get();
  string line;
  while (getline(cin, line) && line.size() > 0){
    istringstream iss(line);
    text.clear();
    string word;
    while (iss >> word){
      text.push_back(word);
    }
    vector<string> origin_text(text);
    sort(text.begin(), text.end(), string_cmp_by_length);

    string key(256, '*');
    DFS(0, key);

    for (size_t i = 0; i < origin_text.size(); i++){
      if (i > 0){
        cout << " ";
      }
      cout << encrypte(origin_text[i], key);
    }
    cout << endl;
  }
}



