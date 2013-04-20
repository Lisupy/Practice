#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
  int a[7];

  while(scanf("%d%d%d%d%d%d", a+1, a+2, a+3, a+4, a+5, a+6)){
    if (a[1]+a[2]+a[3]+a[4]+a[5]+a[6] == 0)
      break;
    int sum = 0;

    sum += a[6];

    sum += a[5];
    a[1] -= a[5]*11;

    sum += a[4];
    a[2] -= a[4]*5;

    sum += (a[3]+3)/4;
    switch(a[3]%4){
    case 0:
      break;
    case 1:
      a[2] -= 5;
      a[1] -= 7;
     break;
    case 2:
      a[2] -= 3;
      a[1] -= 6;
      break;
    case 3:
      a[2] -= 1;
      a[1] -= 5;
      break;
    }

    if (a[2] < 0){
      a[1] -= -a[2]*4;
      a[2] = 0;
    }

    if (a[1] < 0){
      a[1] = 0;
    }

    sum += (a[1]+a[2]*4+35)/36;
    printf("%d\n", sum);
  }
}
