#include<cstdio>


int T;
int N;

int Z(int n){
  int s = 0;
  while(n != 0){
    s+=n/5;
    n/=5;
  }
  return s;
}

int main()
{
  scanf("%d", &T);
  while (T--){
    scanf("%d", &N);
    printf("%d\n", Z(N));
  }
}


