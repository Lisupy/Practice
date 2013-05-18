#include<cstdio>
#include<cstring>



int fib_cache[32];
int Fib(int n){
  if (fib_cache[n] != 0){
    return fib_cache[n];
  }
  return fib_cache[n] = Fib(n-1)+Fib(n-2);
}

void Fib_init(){
  fib_cache[1] = 1;
  fib_cache[2] = 1;
}

int main(){
  Fib_init();

  int n;
  scanf("%d", &n);
  
  while (n--){
    int a;
    scanf("%d", &a);
    printf("%d\n", Fib(a));
  }
}
