/*
 * Algorithm:   brute-forces
 * Complexity:  O(N)
 * IndexBased:  0
 * Trick:       string
 * LayOut:
 *    reset();
 *    input(vector<string>);
 */


#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

const string WA = "Wrong Answer";
const string PE = "Presentation Error";
const string AC = "Accepted";

vector<string> A;
vector<string> B;

void reset(){
  A.clear();
  B.clear();
}

int input(vector<string> &lines){
  int n;
  if (cin>>n){
    cin.ignore();
    lines.resize(n);
    for (int i = 0; i < n; i++){
      getline(cin, lines[i]);
    }
    return n;
  }
  return 0;
}

bool equal(vector<string> &a, vector<string> &b){
  return a == b;
}

string get_all_digits(vector<string> &a){
  string s;
  for (size_t i = 0; i < a.size(); i++){
    for (size_t j = 0; j < a[i].size(); j++){
      char ch = a[i][j];
      if (isdigit(ch)){
        s += ch;
      }
    }
  }
  return s;
}

string check(){
  //if (A.size() != B.size()){
  //  return WA;
  //}
  if (equal(A, B)){
    return AC;
  }
  if (get_all_digits(A) == get_all_digits(B)){
    return PE;
  }
  return WA;
}

int main(){
  int run_id = 0;
  while (true){
    reset();
    if (!input(A)){
      break;;
    }
    input(B);
    string ans = check(); 
    cout << "Run #" << ++run_id << ": " << ans << endl;
  }
}

