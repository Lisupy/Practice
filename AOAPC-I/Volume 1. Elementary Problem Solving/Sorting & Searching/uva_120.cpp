#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<cstdio>
using namespace std;



vector<int> flapjacks;

void dbg(){
  cout << "dbg: " << endl;
  for (size_t i = 0; i < flapjacks.size(); i++){
    cout << flapjacks[i] << " ";
  }
  cout << endl;
}

void flip(size_t pos){
  reverse(flapjacks.begin() + pos, flapjacks.end());
}


void gao(){
  reverse(flapjacks.begin(), flapjacks.end());

  size_t N = flapjacks.size();
  for (size_t cur = 0; cur < N; cur++){
    size_t pos = max_element(flapjacks.begin() + cur, flapjacks.end()) - flapjacks.begin();
    if (pos == cur){
      continue;
    }else{
      if (pos != N - 1){
        printf("%lu ", pos + 1);
        flip(pos);
    //    dbg();
      }
      printf("%lu ", cur + 1);
      flip(cur);
    }
  }
  printf("0\n");
 // dbg();
}

int main(){
  string line;
  while (getline(cin, line) && line.size() > 0){
    cout << line << endl;
    istringstream iss(line);
    flapjacks.clear();
    int t;
    while (iss >> t){
      flapjacks.push_back(t);
    }
    gao();
  }
}
