#include<cstdio>

int main(){
  int n;
  scanf("%d", &n);

  while(n--){
    int a;
    scanf("%d", &a);
    if (a % 2 != 0){
      printf("0 0\n");
    }
    else{
      printf("%d %d\n", (a+2)/4, a/2);
    }
  }
}
