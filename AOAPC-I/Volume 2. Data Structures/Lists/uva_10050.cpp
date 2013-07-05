#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<cstdio>
using namespace std;



int T;
int N;
int P;
int h[128];

int main(){
  cin >> T;
  while (T--){
    cin >> N;
    cin >> P;
    for (int i = 0; i < P; i++){
      cin >> h[i];
    }

    int total = 0;
    for (int i = 1; i <= N; i++){
      int d = (i - 1) % 7 + 1;
      if (d == 6 || d == 7){
        continue;
      }
      for (int j = 0; j < P; j++){
        if (i % h[j] == 0){
          total++;
          break;
        }
      }
    }
    cout << total << endl;
  }
}

      
