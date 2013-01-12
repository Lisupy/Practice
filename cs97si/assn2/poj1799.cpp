#include<cstdio>
#include<cmath>

const double pi = acos(-1);//2*pi才是360度
int num_of_scearios;

int main()
{
  int n;
  double R;
  
  scanf("%d", &num_of_scearios);

  for (int sceario = 1; sceario <= num_of_scearios; sceario++){
    scanf("%lf%d", &R, &n);
    double sinx = sin(pi/n);
    double r = R*sinx/(1+sinx);
    printf("Scenario #%d:\n", sceario);
    printf("%.03f\n\n", (float)r);
  }
}
