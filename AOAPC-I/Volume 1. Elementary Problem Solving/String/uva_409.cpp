#include<string>
#include<algorithm>
#include<iostream>
#include<cctype>
#include<cstdio>
#include<vector>
using namespace std;


int K, E;

vector<string> keywords;
vector<string> execuses;
vector<int>    occurs;

int keyword_occurs(string execuse, string kw){
  transform(execuse.begin(), execuse.end(), execuse.begin(), ::tolower);
  transform(kw.begin(), kw.end(), kw.begin(), ::tolower);
  execuse = " " + execuse + " ";
  for (size_t i = 0; i < execuse.size(); i++){
    if (!isalpha(execuse[i])){
      execuse[i] = ' ';
    }
  }
  kw = " " + kw + " ";
  int cnt = 0;
  size_t pos = 0;
 // cout << "[" << execuse << "]" << endl;
  //cout << "[" << kw << "]" << endl;

  while (true){
    size_t new_pos = execuse.find(kw, pos);
    if (new_pos == string::npos){
      break;
    }
    pos = new_pos + 1;
    cnt++;
  }
  return cnt;
}


int execuse_contains_keywors(string execuse){
  int cnt = 0;
  for (size_t i = 0; i < keywords.size(); i++){
    cnt += keyword_occurs(execuse, keywords[i]);
  }
  return cnt;
}

void process(){
  occurs.resize(execuses.size());
  for (size_t i = 0; i < occurs.size(); i++){
    occurs[i] = execuse_contains_keywors(execuses[i]);
  }
  int max_occur = *max_element(occurs.begin(), occurs.end());
  
  for (size_t i = 0; i < occurs.size(); i++){
//    cout << occurs[i] << endl;
    if (occurs[i] == max_occur){
      cout << execuses[i] << endl;
    }
  }
}

int TestNum = 0;
int main(){
  while (cin >> K >> E){
    keywords.resize(K);
    execuses.resize(E);
    for (int i = 0; i < K; i++){
      cin >> keywords[i];
    }
    cin.ignore();
    for (int i = 0; i < E; i++){
      getline(cin, execuses[i]);
    }
    cout << "Excuse Set #" << ++TestNum << endl;
    process();
    cout << endl;
  }
}
