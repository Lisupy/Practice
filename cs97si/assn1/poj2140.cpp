#include<cstdio>
#include<algorithm>
using namespace std;
int N;



bool check(int k, int N){
  if (2*N%(k+1) != 0)
    return false;
  int double_a1 = 2*N/(k+1)-k;
  if (double_a1 > 0 && double_a1 % 2 == 0)
    return true;
  return false;
}

int main(){
  scanf("%d", &N);
  int ways = 1;
  for (int k = 1; k < min(10000,N); k++){
    if (check(k,N))
      ways++;
  }
  printf("%d\n", ways);
}
