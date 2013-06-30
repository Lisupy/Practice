#include<cstdio>
#include<algorithm>
#include<string>
#include<cstdio>
#include<vector>
#include<cctype>
#include<cstring>
#include<iostream>
using namespace std;


vector<string> records;

bool is_decodable(){
  for (size_t i = 0; i < records.size(); i++){
    for (size_t j = 0; j < records.size(); j++){
      if (i != j && records[i].compare(0, records[j].size(), records[j]) == 0){
        return false;
      }
    }
  }
  return true;
}
int TestNum;
int main(){
  string line;
  while (cin >> line){
    if (line == "9"){
      if (is_decodable()){
        cout << "Set " << ++TestNum << " is immediately decodable" << endl;
      }else{
        cout << "Set " << ++TestNum << " is not immediately decodable" << endl;
      }
      records.clear();
    }else{
      records.push_back(line);
    }
  }
}





