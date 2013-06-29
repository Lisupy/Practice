#include<algorithm>
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;


void output(vector<int> as){
  for (size_t i = 0; i < as.size(); i++){
    int a = as[i];
    const char* trans = " .xW";
    cout << trans[a];
  }
  cout << endl;
}


vector<int> populate(vector<int> dishes, vector<int> DNA){
  vector<int> news(dishes.size());
  for (size_t i = 0; i < news.size(); i++){
    int t = 0;
    int ii = (int)i;
    int d[] = {ii - 1, ii, ii + 1};
    for (int j = 0; j < 3; j++){
      int n = d[j];
      if (0 <= n && n < 40){
        t += dishes[n];
      }
    }
    news[i] = DNA[t];
  }
  return news;
}

void gao(){
  vector<int> DNA(10);
  for (int i = 0; i < 10; i++){
    cin >> DNA[i];
  }
  vector<int> dishes(40, 0);
  dishes[19] = 1;
  for (int i = 0; i < 50; i++){
    output(dishes);
    dishes = populate(dishes, DNA);
  }
}

int main(){
  int TestNum = 0;
  cin >> TestNum;
  while (TestNum--){
    gao();
    if (TestNum){
      cout << endl;
    }
  }
}
