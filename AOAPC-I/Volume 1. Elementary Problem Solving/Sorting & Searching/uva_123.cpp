#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<sstream>
#include<cctype>
#include<cstdio>
#include<cassert>
#include<set>
using namespace std;


struct KWIC{
  string keyword;
  string text;
  int idx;
  KWIC(string kw, string tx, int i):keyword(kw), text(tx), idx(i){};
};

bool operator<(const KWIC &a, const KWIC &b){
  if (a.keyword != b.keyword) return a.keyword < b.keyword;
  return a.idx < b.idx;
}

vector<KWIC> records;
set<string> ignores;
vector<KWIC> kwicsFromLine(string line){
  vector<KWIC> res;
  transform(line.begin(), line.end(), line.begin(), ::tolower);
  //line += ' ';
  size_t begin_pos = 0;
  while (begin_pos < line.size()){
    size_t end_pos = line.find(" ", begin_pos);
    if (end_pos == string::npos) end_pos = line.size();

    string keyword = line.substr(begin_pos, end_pos - begin_pos);
    if (ignores.count(keyword) == 0){
      KWIC a(keyword, line, records.size());
      transform(a.keyword.begin(), a.keyword.end(), a.keyword.begin(), ::toupper);
      transform(a.text.begin() + begin_pos, a.text.begin() + end_pos, a.text.begin() + begin_pos, ::toupper);
      records.push_back(a);
    }
    begin_pos = end_pos + 1;
  }
  return res;
}

int main(){
  string line;
  while (getline(cin, line) && line != "::"){
    ignores.insert(line);
  }
  while (getline(cin, line) && line.size()){
    vector<KWIC> a = kwicsFromLine(line);
    records.insert(records.end(), a.begin(), a.end());
  }
  sort(records.begin(), records.end());
  for (size_t i = 0; i < records.size(); i++){
    cout << records[i].text << endl;
  }
}
