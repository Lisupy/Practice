#include<string>
#include<iostream>
#include<limits>
#include<algorithm>
#include<cstdio>

using namespace std;


string s1, s2, s3;

bool is_too_big(string s){
  string t = "2147483647";
  if (s.size() == t.size()) return s > t;
  return s.size() > t.size();
}

int intFromStr(string s){
  int n;
  sscanf(s.c_str(), "%d", &n);
  return n;
}

bool is_result_too_big(){
  if (s2 == "+"){
    if (is_too_big(s1) || is_too_big(s3)){
      return true;
    }
    int t1 = intFromStr(s1);
    int t2 = intFromStr(s3);
    int t3 = t1 + t2;
    if (t3 <= 0){
      return true; 
    }
    return false;
  }else{
    if (s1 == "0" || s3 == "0"){
      return false;
    }
    if (is_too_big(s1) || is_too_big(s3)){
      return true;
    }
    int t1 = intFromStr(s1);
    int t2 = intFromStr(s3);
    int t3 = t1 * t2;
    if (t3 / t1 != t2){
      return true; 
    }
    return false;
  }
}
int main(){
  while (cin >> s1 >> s2 >> s3){
    cout << s1 << " " << s2 << " " << s3 << endl;
    if (s1.find_first_not_of("0") == string::npos){
      s1 = "0";
    }else{
      s1 = s1.substr(s1.find_first_not_of("0"));
    }
    if (s3.find_first_not_of("0") == string::npos){
      s3 = "0";
    }else{
      s3 = s3.substr(s3.find_first_not_of("0"));
    }
    if (s1 == "") s1 = "0";
    if (s3 == "") s3 = "0";
    if (is_too_big(s1)){
      cout << "first number too big" << endl;
    }
    if (is_too_big(s3)){
      cout << "second number too big" << endl;
    }
    if (is_result_too_big()){
      cout << "result too big" << endl;
    }
  }
}

        


