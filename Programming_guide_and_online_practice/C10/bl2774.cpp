//Algorithm:  binary_sercch, check_function
//Complexity: log(max(a))*N
//Trick:      how to write binary_serach
//IndexBase:  0


#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

const int MAXN = 10*1024;

int N, K;
int a[MAXN];

bool check(int k){
  int total = 0;
  for (int i = 0; i < N; i++){
    total += a[i] / k;
  }
  return total >= K;
}

int main(){
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++){
    scanf("%d", &a[i]);
  }
  
  int l = 1; 
  int r = *max_element(a, a+N);
  while (l < r){
    int m = (l + r) / 2; 
    if (check(m)){
      l = m + 1;
    }else{
      r = m - 1;
    }
  }
  if (check(l)){
    if (check(l+1)){
      printf("%d\n", l+1);
    }else{
      printf("%d\n", l);
    }
  }else{
    printf("%d\n", l-1);
  }

}
