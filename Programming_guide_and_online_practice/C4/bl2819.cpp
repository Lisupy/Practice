#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;


int k[4];

int get_k_by_char(char c){
  if ('a' <= c && c <= 'i'){
    return 1;
  }else if ('j' <= c && c<= 'r'){
    return 2;
  }else if (c == '_' || ( 's' <= c && c <= 'z') ){
    return 3;
  }
  return 0;
}

string decrypt(string s){
  string t;
  vector<char> v[4];
  for (size_t i = 0; i < s.size(); i++){
    char c = s[i];
    int ktype = get_k_by_char(c);
    v[ktype].push_back(c);
  }

  for (int i = 0; i < 4; i++) {
    if (v[i].size() > 0){
      rotate(v[i].begin(), v[i].end() - k[i]%v[i].size(), v[i].end());
    }
  }
  vector<char>::iterator vs[4];
  for (int i = 0; i < 4; i++) {
    vs[i] = v[i].begin();
  }

  for (size_t i = 0; i < s.size(); i++){
    char c = s[i];
    int ktype = get_k_by_char(c);
    t.push_back(*vs[ktype]);
    vs[ktype]++;
  }
  return t;
}

int main(){
  while (cin>>k[1]>>k[2]>>k[3]){
    if (k[1] == 0 && k[2] == 0 && k[3] == 0){
      break;
    }
    string s;
    getline(cin, s);
    getline(cin, s);
    string t = decrypt(s);
    cout << t << endl;
  }
}

