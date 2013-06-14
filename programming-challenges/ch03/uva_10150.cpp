/*
 * Algorithm:   BFS
 * Complexity:  size(dict)*16*26
 * IndexBased:  0
 * Trick:       set
 * Layout:
 *  input_dict();
 *  sol(s, t);
 */

#include<vector>
#include<set>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<sstream>
using namespace std;

set<string> dict;

void input_dict(){
  string line;
  while (getline(cin, line) && line.size() != 0){
    dict.insert(line);
  }
}

void output(string s, string t, map<string, string> M){
  vector<string> res;
  while (t != s){
    res.push_back(t);
    t = M[t];
  }
  res.push_back(t);
  reverse(res.begin(), res.end());
  for (size_t i = 0; i < res.size(); i++){
    cout << res[i] << endl;
  }
}

void sol(string s, string t){
  queue<string> Q;
  map<string, string> M;
  Q.push(s);
  M[s] = "";
  while (!Q.empty()){
    string a = Q.front();
    Q.pop();
    for (size_t i = 0; i < a.size(); i++){
      string b = a;
      for (size_t ch = 'a'; ch <= 'z'; ch++){
        b[i] = ch;
        if (dict.find(b) == dict.end()){
          continue;
        }
      //  cout << a << "=>" << b << endl;
        if (M.find(b) != M.end()){
          continue;
        }
       // cout << "add" << endl;
        M.insert(make_pair(b, a));
        if (b == t){
          output(s, t, M);
          return;
        }
        Q.push(b);
      }
    }
  }
  cout << "No solution." << endl;
}


int main(){
  input_dict();
  string line;
  bool first = true;
  while (getline(cin, line) && line.size() > 0){
   // cout << "[" << line << "]" << endl;
    if (!first){
      cout << endl;
    }
    first = false;
    stringstream iss(line);
    string s, t;
    iss >> s >> t;
    sol(s, t);
  }
}



