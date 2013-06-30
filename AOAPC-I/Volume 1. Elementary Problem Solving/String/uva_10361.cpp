#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;


struct Sch{
  string s1, s2, s3, s4, s5;
  Sch():s1(""), s2(""), s3(""), s4(""), s5(""){};
  void from_str(string s){
    s1 = s.substr(0, s.find('<'));
    s2 = s.substr(s.find('<') + 1, s.find('>') - s.find('<') - 1);
    s3 = s.substr(s.find('>') + 1, s.rfind('<') - s.find('>') - 1);
    s4 = s.substr(s.rfind('<') + 1, s.rfind('>') - s.rfind('<') - 1);
    s5 = s.substr(s.rfind('>') + 1);
//    cout << s1 << endl;
//    cout << s2 << endl;
//    cout << s3 << endl;
//    cout << s4 << endl;
//    cout << s5 << endl;
  }
  string to_str(){
    return s4 + s3 + s2 + s5;
  }
};


string sch_replace(string s, string pattern, string replace){
  while (true){
    size_t pos = s.find(pattern);
    if (pos == string::npos){
      break;
    }
    s.replace(pos, pattern.size(), replace);
  }
  return s;
}



int main(){
  int n;
  cin >> n;
  cin.ignore();
  while (n--){
    Sch sch;
    string l1, l2;
    string c1, c2;
    getline(cin, l1);
    getline(cin, l2);
    sch.from_str(l1);
    string replace = sch.to_str();
    c1 = sch_replace(l1, "<", "");
    c1 = sch_replace(c1, ">", "");
    c2 = sch_replace(l2, "...", replace);
    cout << c1 << endl;
    cout << c2 << endl;
  }
}


