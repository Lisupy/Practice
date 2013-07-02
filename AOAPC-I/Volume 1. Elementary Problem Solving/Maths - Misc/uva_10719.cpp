#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;

void gao(vector<int> as, int k){
  cout << "q(x):";
  for (size_t i = 0; i + 1 < as.size(); i++){
    cout << " " << as[i] ;
    as[i + 1] += as[i] * k;
    as[i] = 0;
  }
  cout << endl;
  cout << "r = " << as.back() << endl;
}


int main(){
  int k;
  while (cin >> k){
    vector<int> as;
    string line;
    cin.ignore();
    getline(cin, line);
    int t;
    istringstream iss(line);
    while (iss >> t){
      as.push_back(t);
    }
    gao(as, k);
    cout << endl;
  }
}
