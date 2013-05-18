#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


int main(){
  int x, y;
  cin >> x >> y;
  
  vector<int> v;
  while (x){
    v.push_back(x);
    x /= 2;
  }

  while (y){
    if (find(v.begin(), v.end(), y) != v.end()){
      break;
    }
    y /= 2;
  }
  printf("%d\n", y);
}


