#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;


int N;
int a[128][128];

bool is_tumour(int i, int j){
  return a[i][j]<=50;
}

bool is_boundary(int i, int j){
  if (!is_tumour(i,j))
    return false;
  if(i == 0 || j == 0 || i == N-1 || j == N-1)
    return true;
  if (!is_tumour(i-1,j)||!is_tumour(i+1,j)
    ||!is_tumour(i,j-1)||!is_tumour(i,j+1)){
    return true;
  }
  return false;
}

int main(){
  scanf("%d", &N);
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      scanf("%d", &a[i][j]);
    }
  }
  int tumour_cnt = 0;
  int boundary_cnt = 0;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      if (is_tumour(i,j))
        tumour_cnt++;
      if (is_boundary(i, j))
        boundary_cnt++;
    }
  }
  printf("%d %d\n", tumour_cnt, boundary_cnt);
}
