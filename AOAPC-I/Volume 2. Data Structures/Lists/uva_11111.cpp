#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstdio>
#include<sstream>
using namespace std;


struct Toy{
  char sign;
  int value;
};

vector<int> a;
typedef vector<Toy>::iterator VTIT;
typedef vector<Toy>::reverse_iterator RVTIT;

bool isValid(){
  //cout << "isValid" << endl;
  vector<Toy> S;
  for (size_t i = 0; i < a.size(); i++){
    //cout << "#" << i << endl;
    //for (size_t k = 0; k < S.size(); k++){
      //cout << S[k].sign << S[k].value << ", ";
    //}
    //cout << endl;
    int n = a[i];
    Toy t;
    if (n < 0){
      t.sign = '-';
      t.value = -n;
    }else{
      t.sign = '+';
      t.value = n;
    }
    if (t.sign == '+'){
      int total = 0;
      while (!S.empty()){
        if (S.back().value != t.value){
          if (S.back().sign == ' '){
            total += S.back().value;
            S.pop_back();
          }else{
            return false;
          }
        }else{
          if (S.back().sign == '-'){
            break;
          }else{
            return false;
          }
        }
      }
      if (total >= t.value){
        return false;
      }
      if (S.empty()){
        return false;
      }
      S.back().sign = ' ';
    }else{
      S.push_back(t);
    }
  }
  for (size_t i = 0; i < S.size(); i++){
    if (S[i].sign == '-'){
      return false;
    }
  }
  return true;
}

int main(){
  string line;
  while (getline(cin, line) && line.size()){
    a.clear();
    istringstream iss(line);
    int t;
    while (iss >> t){
      a.push_back(t);
    }
    if (isValid()){
      cout << ":-) Matrioshka!" << endl;
    }else{
      cout << ":-( Try again." << endl;
    }
  }
}

