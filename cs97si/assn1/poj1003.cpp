#include<cstdio>

int main()
{
  double c;
  while(scanf("%lf",&c)&& c != 0.00){
    double s = 0;
    int n = 1;
    while (s < c){
      n++;
      s += 1.0/n;
    }
    printf("%d card(s)\n", n-1);
  }
}
