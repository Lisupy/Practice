#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

long long S[5][128];
long long R[5][128];

int main(){
  for (int d = 0; d < 5; d++){
    for (int i = 1; i <= 100; i++){
      S[d][i] = S[d][i - 1] + pow(i, d);
      R[d][i] = pow((i + 1) * i / 2, d) - S[d][i];
    }
  }
  int N;
  while (cin >> N){
    int cnt = 0;
    for (int i = 2; i <= 4; i++){
      if (cnt++){
        cout << " ";
      }
      cout << S[i][N] << " " << R[i][N];
    }
    cout << endl;
  }
}


