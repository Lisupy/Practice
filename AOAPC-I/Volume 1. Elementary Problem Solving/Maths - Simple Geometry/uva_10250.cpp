#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
  double x1, y1, x2, y2;

  while (cin >> x1 >> y1 >> x2 >> y2){
    double x0 = (x1 + x2) / 2;
    double y0 = (y1 + y2) / 2;
    double x3 = x0 + (y1 - y0);
    double y3 = y0 - (x1 - x0);
    double x4 = x0 - (y1 - y0);
    double y4 = y0 + (x1 - x0);

    printf("%.10lf %.10lf %.10lf %.10lf\n", x3, y3, x4, y4);
  }
}
