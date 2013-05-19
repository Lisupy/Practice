#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;


enum TFileType{
  TFILE,
  TDIR,
};
struct TFile{
  TFileType type;
  string name;
  vector<struct TFile> dirs;
  vector<struct TFile> files; 
};

bool operator<(const TFile &a, const TFile &b){
  return a.name < b.name;
}

void input(TFile &current){
  string s;
  while (cin >> s){
    if (s == "]"){
      sort(current.files.begin(), current.files.end());
      return;
    }
    if (s[0] == 'd'){
      TFile f;
      f.type = TDIR;
      f.name = s;
      current.dirs.push_back(f);
      input(current.dirs.back());
    }
    if (s[0] == 'f'){
      TFile f;
      f.type = TFILE;
      f.name = s;
      current.files.push_back(f);
    }
    if (s == "*"){
      sort(current.files.begin(), current.files.end());
      return;
    }
    if (s == "#"){
      exit(0);
    }
  }
}

void pr(TFile &current, string prefix){
  cout << prefix << current.name << endl;
  for (size_t i = 0; i < current.dirs.size(); i++){
    pr(current.dirs[i], prefix+"|     ");
  }
  for (size_t i = 0; i < current.files.size(); i++){
    cout << prefix << current.files[i].name << endl;
  }
}

int main(){
  int TEST_CASE = 0;

  while (true){
    TFile root;
    root.type = TDIR;
    root.name = "ROOT";
    input(root);
    cout << "DATA SET " << ++TEST_CASE << ":" << endl;
    pr(root, "");
    cout << endl;
  }
}

