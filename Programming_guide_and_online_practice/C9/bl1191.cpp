#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
#include<numeric>
using namespace std;

const int MAXN = 8;
const double INF = 1e20;
double a[MAXN][MAXN];
double sum[MAXN][MAXN];
double mean;
double cache[MAXN][MAXN][MAXN][MAXN][16];
int n;

static inline double __get_sum(int x, int y){
  if (x >= 0 && y >= 0){
    return sum[x][y];
  }else{
    return 0;
  }
}

static inline double get_sum(int x1, int y1, int x2, int y2){
  return __get_sum(x2, y2) - __get_sum(x2, y1 - 1) - __get_sum(x1 - 1, y2) + __get_sum(x1 - 1, y1 - 1);
}

static inline
double square(double x){
  return x * x;
}
bool is_valid(int x1, int y1, int x2, int y2, int remain){
  return x2 - x1 + y2 - y1 + 1 >= remain;
}

double dfs(int x1, int y1, int x2, int y2, int remain){
  double &s = cache[x1][y1][x2][y2][remain];
  if (cache[x1][y1][x2][y2][remain] != INF){
    return cache[x1][y1][x2][y2][remain];
  }
  if (remain == 1){
    s = square(get_sum(x1, y1, x2, y2) - mean);
    return s ;
  }else{
    for (int x = x1; x < x2; x++){
      if (is_valid(x1, y1, x, y2, remain-1)&&is_valid(x+1, y1, x2, y2, 1)){
        s = min(s, dfs(x1, y1, x, y2, remain-1) + dfs(x+1, y1, x2, y2, 1));
      } 
      if (is_valid(x1, y1, x, y2, 1)&&is_valid(x+1, y1, x2, y2, remain-1)){
        s = min(s, dfs(x1, y1, x, y2, 1) + dfs(x+1, y1, x2, y2, remain-1));
      }
    }
    for (int y = y1; y < y2; y++){
      if (is_valid(x1, y1, x2, y, remain-1) && is_valid(x1, y+1, x2, y2, 1)){
        s = min(s, dfs(x1, y1, x2, y, remain-1) + dfs(x1, y+1, x2, y2, 1) );
      }
      if (is_valid(x1, y1, x2, y, 1) && is_valid(x1, y+1, x2, y2, remain-1)){
        s = min(s, dfs(x1, y1, x2, y, 1) + dfs(x1, y+1, x2, y2, remain-1) );
      }
    }

    return s;
  }
}

int main(){
  scanf("%d", &n);
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      scanf("%lf", &a[i][j]);
    }
  }

  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      if (j == 0){
        sum[i][j] = a[i][j];
      }else{
        sum[i][j] = sum[i][j-1] + a[i][j];
      }
    }
  }

  for (int i = 1; i < 8; i++){
    for (int j = 0; j < 8; j++){
      sum[i][j] += sum[i-1][j];
    }
  }
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      for (int k = 0; k < 8; k++){
        for (int l = 0; l < 8; l++){
          for (int m = 0; m < 16; m++){
            cache[i][j][k][l][m] = INF;
          }
        }
      }
    }
  }
  mean = sum[7][7] / n;
  double ans = dfs(0, 0, 7, 7, n);
  printf("%.03lf\n", sqrt(ans/n));
}

