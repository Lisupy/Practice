#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;

int n;
map<string, int> countryCnt;

int main(){
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++){
    string line;
    getline(cin, line);
    istringstream iss(line);
    string country;
    iss >> country;
    countryCnt[country]++;
  }
  
  for (map<string, int>::iterator it = countryCnt.begin(); it != countryCnt.end(); it++){
    cout << it->first << " " << it->second << endl;
  }
}

