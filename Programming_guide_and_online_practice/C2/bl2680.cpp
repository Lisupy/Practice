#include<cstdio>
#include<cstring>

using namespace std;

int main(){
  int k;
  char sexual[32];
  double a[6];
  scanf("%d", &k);
  while(k--){
    scanf("%s %lf %lf %lf %lf %lf", sexual, a+0, a+1, a+2, a+3, a+4);
    int s = 0;
    if (4.0 <= a[0] && a[0] <= 10.0)
      s++;
    if (3.5 <= a[1] && a[1] <= 5.5)
      s++;
    if (sexual[0] == 'm' && 120 <= a[2] && a[2] <= 160)
      s++;
    if (sexual[0] == 'f' && 110 <= a[2] && a[2] <= 150)
      s++;
    
    if (sexual[0] == 'm' && 42 <= a[3] && a[3] <= 48)
      s++;
    if (sexual[0] == 'f' && 36 <= a[3] && a[3] <= 40)
      s++;

    if (100 <= a[4] && a[4] <= 300)
      s++;
    s = 5 - s;
    if (s == 0)
      printf("normal\n");
    else
      printf("%d\n", s);
  }
}
