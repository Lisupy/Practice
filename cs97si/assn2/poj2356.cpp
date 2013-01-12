#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cassert>
using namespace std;
const int MAXN = 10*1024;
int a[MAXN];
int s_idx[MAXN];
void output(int l, int r){
  printf("%d\n", r-l);
  for (int i = l+1; i <= r; i++){
    printf("%d\n", a[i]);
  }
}
int main(){
  int N;

  scanf("%d", &N);
  assert(N!=0);
  int s = 0;
  for (int i = 1; i <= N; i++){
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= N; i++){
    s += a[i];
    s %= N;
    if (s == 0){
      output(0,i);
      break;
    }
    if (s_idx[s] != 0){
      output(s_idx[s], i);
      break;
    }
    s_idx[s] = i;
  }
}

