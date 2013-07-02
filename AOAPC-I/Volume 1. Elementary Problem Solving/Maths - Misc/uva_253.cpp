#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;


int rotated[24][3] = {
  {1, 2, 3},
  {1, 4, 2},
  {1, 5, 4},
  {1, 3, 5},
  {2, 6, 3},
  {2, 3, 1},
  {2, 1, 4},
  {2, 4, 6},
  {3, 2, 6},
  {3, 6, 5},
  {3, 5, 1},
  {3, 1, 2},
  {4, 5, 6},
  {4, 6, 2},
  {4, 2, 1},
  {4, 1, 5},
  {5, 4, 1},
  {5, 6, 4},
  {5, 3, 6},
  {5, 1, 3},
  {6, 2, 4},
  {6, 4, 5},
  {6, 5, 3},
  {6, 3, 2},
};


bool __cmp(int rt[], string a, string b){
  string s;
  for (int i = 0; i < 6; i++){
    s += b[rt[i] - 1];
  }
  return s == a;
}
bool cmp(int idx, string a, string b){
  int rt[6];
  memcpy(rt, rotated[idx], sizeof(rotated[idx]));
  memcpy(rt + 3, rotated[idx], sizeof(rotated[idx]));
  reverse(rt + 3, rt + 6);
  for (int i = 3; i < 6; i++){
    rt[i] = 7 - rt[i];
  }
  if (__cmp(rt, a, b)){
    return true;
  }
  return false;
}

bool issame(string a, string b){
  for (int i = 0; i < 24; i++){
    if (cmp(i, a, b)){
      return true;
    }
  }
  return false;
}
int main(){
  string s;
  while (cin >> s){
    if (issame(s.substr(0, 6), s.substr(6))){
      cout << "TRUE" << endl;
    }else{
      cout << "FALSE" << endl;
    }
  }
}
