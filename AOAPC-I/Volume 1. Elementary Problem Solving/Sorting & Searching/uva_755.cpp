//SE
//Total Submissions Users that tried it Users that solved it
//20884 3230  1887
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<cctype>
using namespace std;


map<string, int> cnt;


string tbl[] = {
  "0",
  "1",
  "2ABC",
  "3DEF",
  "4GHI",
  "5JKL",
  "6MNO",
  "7PRS",
  "8TUV",
  "9WXY",
};
string chFormat(char ch){
  for (int i = 0; i < 10; i++){
    if (tbl[i].find(ch) != string::npos){
      return string(1, tbl[i][0]);
    }
  }
  return "";
}
string phonenumFromat(string nums){
  string s;
  for (size_t i = 0; i < nums.size(); i++){
    s += chFormat(nums[i]);
  }
  s.insert(3, 1, '-');
  return s;
}


int main(){
  int TestNum = 0;
  cin >> TestNum;
  while (TestNum--){
    cnt.clear();
    int n;
    cin >> n;
    while (n--){
      string s;
      cin >> s;
      cnt[phonenumFromat(s)]++;
    }
    int dupCnt = 0;
    for (map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
      if (it->second != 1){
        cout << it->first << " " << it->second << endl;
        dupCnt++;
      }
    }
    if (dupCnt == 0){
      cout << "No duplicates." << endl;
    }
    if (TestNum){
      cout << endl;
    }
  }
}
