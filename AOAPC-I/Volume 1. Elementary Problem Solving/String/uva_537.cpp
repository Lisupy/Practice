#include<algorithm>
#include<string>
#include<cstdio>
#include<iostream>
#include<sstream>
using namespace std;

double doubleFromStr(string s){
  //cout << "[" << s << "]" << endl;
  stringstream iss(s);
  double d;
  iss >> d;
  return d;
}


struct DataField{
  string concept;
  double realnum;
  DataField(): concept(""), realnum(0){};
  void from(string s){
    concept = s[0];
    int prefixPos = s.find_first_not_of("0123456789.", 2); 
    char prefix = s[prefixPos];
    realnum = doubleFromStr(s.substr(2, prefixPos - 2));
    if (prefix == 'm'){
      realnum *= 0.001;
    }else if (prefix == 'k'){
      realnum *= 1000;
    }else if (prefix == 'M'){
      realnum *= 1000 * 1000;
    };
  }
  void dbg(){
    cout << concept << " = " << realnum << endl;
  }
};


void gao(){
  string line;
  getline(cin, line);
  //cout << "[" << line << "]" << endl;
  DataField P, I, U;
  size_t p_pos = line.find("P=");
  size_t i_pos = line.find("I=");
  size_t u_pos = line.find("U=");
  //cout << p_pos << ", "  << i_pos << ", " << u_pos << endl;
  if (p_pos != string::npos){
    P.from(line.substr(p_pos));
  } 
  if (i_pos != string::npos){
    I.from(line.substr(i_pos));
  } 
  if (u_pos != string::npos){
    U.from(line.substr(u_pos));
  } 
  //P.dbg();
  //I.dbg();
  //U.dbg();
  if (p_pos == string::npos){
    printf("P=%.02lfW\n", U.realnum * I.realnum);
  }
  if (i_pos == string::npos){
    printf("I=%.02lfA\n", P.realnum / U.realnum);
  }
  if (u_pos == string::npos){
    printf("U=%.02lfV\n", P.realnum / I.realnum);
  }
}

int main(){
  int testNum;
  cin >> testNum;
  cin.ignore();
  for (int i = 1; i <= testNum; i++){
    printf("Problem #%d\n", i);
    gao();
    printf("\n");
  }
}
