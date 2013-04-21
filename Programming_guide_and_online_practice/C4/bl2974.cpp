#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;



int n;
map<string,int> M;

string dial_to_nums(string dial){
  string s;
  for(size_t i = 0; i < dial.size(); i++){
    char c = dial[i];

    string t;
    switch(c){
    case 'A': case 'B': case 'C':
      t = "2";
      break;
    case 'D': case 'E': case 'F':
      t = "3";
      break;
    case 'G': case 'H': case 'I':
      t = "4";
      break;
    case 'J': case 'K': case 'L':
      t = "5";
      break;
    case 'M': case 'N': case 'O':
      t = "6";
      break;
    case 'P': case 'R': case 'S':
      t = "7";
      break;
    case 'T': case 'U': case 'V':
      t = "8";
      break;
    case 'W': case 'X': case 'Y':
      t = "9";
      break;
    }
    if ('0' <= c && c<= '9')
      t += c;
    s += t;
  }
  return s;
}


int main(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++){ 
    string dial;
    cin>>dial;
    M[dial_to_nums(dial)]++;
  }
  if (M.size() == size_t(n)){
    printf("No duplicates.\n");
  }
  for (map<string, int>::iterator it = M.begin(); it != M.end(); it++){
    string s = it->first;
    if(it->second>1){
      printf("%s-%s %d\n", s.substr(0,3).c_str(), s.substr(3, 4).c_str(), it->second);
    }
  }
}
