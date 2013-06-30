#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


vector<string> finds;
vector<string> replaceBys;
int N;


string str_replace(string s, string find, string replaceBy){
  while (true){
    size_t pos = s.find(find);
    if (pos == string::npos){
      break;
    }
    s.replace(pos, find.size(), replaceBy);
//    cout << s << endl;
  }
  return s;
}


int main(){
  while (cin >> N && N){
    cin.ignore();
    finds.resize(N);
    replaceBys.resize(N);
    for (int i = 0; i < N; i++){
      getline(cin, finds[i]);
      getline(cin, replaceBys[i]);
    }
    string text;
    getline(cin, text);
    for (int i = 0; i < N; i++){
      text = str_replace(text, finds[i], replaceBys[i]);
    }
    cout << text << endl;
  }
}
