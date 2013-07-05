#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<cstdio>
#include<iostream>
using namespace std;

struct Matrix{
  string name;
  int R, C;
  int total;
  Matrix(string _name, int _R, int _C, int _total):name(_name), R(_R), C(_C), total(_total){};
  Matrix():name(""), R(0), C(0), total(0){};
};

Matrix MatrixMul(Matrix &a, Matrix &b){
  return Matrix(a.name + b.name, a.R, b.C, a.total + b.total + a.R * b.R * b.C);
}

bool isMulValid(Matrix &a, Matrix &b){
  return a.C == b.R;
}

int n;
map<string, Matrix> mats;

void doMul(string s){
  vector<Matrix> S;
  for (size_t i = 0; i < s.size(); i++){
    string  ch = string(1, s[i]);
   // string ch = s[i];
    if (ch == "(" ){
      continue;
    }
    if (ch == ")"){
      Matrix b = S.back();
      S.pop_back();
      if (!isMulValid(S.back(), b)){
        cout << "error" << endl;
        return;
      }
      S.back() = MatrixMul(S.back(), b);
    }else{
      S.push_back(mats[ch]);
    }
  }
  cout << S[0].total << endl;
}

    
int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    string s;
    int r, c;
    cin >> s >> r >> c;
    mats[s] = Matrix(s, r, c, 0);
  }
//  cin.ignore();
  string line;
  while (cin >> line){
    doMul(line);
  }
}
  

