#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double a, b, s, m, n;


const double pi = acos(-1.0);
int main(){
  while (cin >> a >> b >> s >> m >> n){
    if (a == 0 && b == 0 && s == 0 && m == 0 && n == 0){
      break;
    }
    double A = atan((n * b) / (m * a)) / pi  * 180;
    double v = sqrt((n*b)*(n*b) + (m*a)*(m*a)) / s;
    printf("%.2lf %.2lf\n", A, v);
  }
}
