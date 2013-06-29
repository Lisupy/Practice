#include<iostream>
#include<cstdio>
using namespace std;



void printTriangle(int N){
  for (int i = 1; i < 2 * N; i++){
    int t = min(i, 2 * N - i);
    for (int j = 1; j <= t; j++){
      cout << t;
    }
    cout << endl;
  }
}


int main(){
  int T;
  cin >> T;
  while (T--){
    int N, F;
    cin >> N >> F;
    while (F--){
      printTriangle(N);
      if (F){
        cout << endl;
      }
    }
    if (T){
      cout << endl;
    }
  }
}
