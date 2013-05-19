//Algorithm:  for, dp
//Complexity: N^3
//Trick:      add up all rows
//BaseIndex:  1 
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int MAXN = 128;

int N;
int a[MAXN][MAXN];
int b[MAXN];

int dp(){
  int s = 0;
  int res = *max_element(b+1, b+N+1);
  for (int i = 1; i <= N; i++){
    s += b[i];
    if (s < 0){
      s = 0;
    }else{
      res = max(res, s);
    }
  }
  return res;
}

int main(){
  scanf("%d", &N);

  for (int i = 1; i <= N; i++){
    for (int j = 1; j <= N; j++){
      scanf("%d", &a[i][j]);
    }
  }

  for (int i = 1; i <= N; i++){
    for (int j = 1; j <= N; j++){
      a[i][j] += a[i-1][j];
    }
  }

  int ans = -128;
  for (int i = 1; i <= N; i++){
    for (int j = i + 1; j <= N; j++){
      for (int k = 1; k <= N; k++){
        b[k] = a[j][k] - a[i-1][k];
      }
      ans = max(ans, dp());
    }
  }
  printf("%d\n", ans);
}
