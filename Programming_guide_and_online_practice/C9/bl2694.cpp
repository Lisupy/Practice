#include<cstdio>
#include<sstream>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

enum ExpType{
  ExpValue,
  ExpOp
};

struct Exp{
  ExpType type;
  char op;
  double  value;
  Exp(){}
  Exp(string s){
    if (s.size() == 1 && !isdigit(s[0])){
      type = ExpOp;
      op = s[0];
    }else{
      type = ExpValue;
      sscanf(s.c_str(), "%lf", &value);
    }
  }
};

double cal(const vector<Exp> &exp){
  vector<Exp> S;
  for (size_t i = 0; i < exp.size(); i++){
    const Exp &e = exp[i];
    S.push_back(e);
    
    while (S.size() >= 3){ 
      int len = S.size();
      if (S[len-1].type != ExpValue || S[len-2].type != ExpValue){
        break;
      }
      double rhs = S[len-1].value;
      double lhs = S[len-2].value;
      char op    = S[len-3].op;
      S.pop_back(); 
      S.pop_back(); 
      S.pop_back(); 
      
      Exp t;
      t.type = ExpValue;
      switch (op){
      case '+': t.value = lhs + rhs; break; 
      case '-': t.value = lhs - rhs; break; 
      case '*': t.value = lhs * rhs; break; 
      case '/': t.value = lhs / rhs; break; 
      }
      S.push_back(t);
    }
  }
  return S[0].value;
}

int main(){
  string s;

  vector<Exp> exp;
  while (cin>>s){
    Exp e(s);
    exp.push_back(e);
  }

  printf("%.06lf\n", cal(exp));
}
