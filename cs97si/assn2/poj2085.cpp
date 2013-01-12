#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;


//1,2,3...n-p, n-(m-p*(p-1)/2), n,n-1,....n-p+1
//
int main(){
  int n,m;
  while(scanf("%d%d", &n, &m) && n!=-1){
    int p = 0;
    while(p*(p-1)/2<=m)
      p++;
    for (int i = 1; i <= n-p; i++){
      printf("%d ", i);
    }
    int l = n-p+1+(m-(p-1)*(p-2)/2); 
    if (l != 0) 
      printf("%d ", l);
    for (int i = n; i >= n-p+1; i--){
      if (i != l)
        printf("%d ", i);
    }
    printf("\n");
  }
}
