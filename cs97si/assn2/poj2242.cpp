#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cassert>
#include<cmath>
using namespace std;

const double pi = 3.141592653589793;

//a*x+b*y=c
//d*x+e*y=f
void two_variable_linear_equation(double *x,double *y,
  double a,double b,double c,
  double d,double e,double f)
{
  *x = (c*e-b*f)/(a*e-b*d);
  *y = (c*d-a*f)/(b*d-a*e);
  //printf("a:%lf,b:%lf,c:%lf\n",a,b,c);
  //printf("d:%lf,e:%lf,f:%lf\n",d,e,f);
  //printf("x:%lf,y:%lf\n", *x,*y);
  //printf("ax+by:%lf\n", a* (*x)+b* (*y));
  //printf("dx+ey:%lf\n", d* (*x)+e* (*y));
}

double dis(double x1,double y1, double x2,double y2){
  return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main()
{
  double x1,y1,x2,y2,x3,y3;
  while(scanf("%lf%lf%lf%lf%lf%lf", &x1,&y1,&x2,&y2,&x3,&y3)!=EOF){
    double xm12 = (x1+x2)/2, ym12 = (y1+y2)/2;
    double xm23 = (x2+x3)/2, ym23 = (y2+y3)/2;
    double xm31 = (x3+x1)/2, ym31 = (y3+y1)/2;

    double x12 = (x2-x1)/2, y12 = (y2-y1)/2;
    double x23 = (x3-x2)/2, y23 = (y3-y2)/2;
    double x31 = (x1-x3)/2, y31 = (y1-y3)/2;

    double x0,y0;
    two_variable_linear_equation(&x0,&y0,
      x12,y12,x12*xm12+y12*ym12,
      x23,y23,x23*xm23+y23*ym23);
   // printf("%lf\n", (x0-xm23)*x23+(y0-ym23)*y23);
   // printf("%lf\n", (x0-xm12)*x12+(y0-ym12)*y12);
   // printf("%lf\n", (x0-xm31)*x31+(y0-ym31)*y31);
    double r = dis(x0,y0,x1,y1);
   // printf("%lf %lf %lf\n", dis(x0,y0,x1,y1),dis(x0,y0,x2,y2),dis(x0,y0,x3,y3));
    double circumference = 2*pi*r;
    printf("%.02f\n", circumference);
  }


}
