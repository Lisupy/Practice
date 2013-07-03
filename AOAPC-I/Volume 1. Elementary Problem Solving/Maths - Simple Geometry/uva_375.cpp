#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

double B, H;

int main(){
  double pi = atan(1.0) * 4.0;
  int TestNum;
  cin >> TestNum;
  while (TestNum--){
    cin >> B >> H;
    double L = 0;
    while (true){
      double area = B * H;
      double C = sqrt(B * B / 4 + H * H);
      double R = area / (C + C + B);
      if (R < 0.000001){
        break;
      }
      L += pi * 2 * R;
      B = B * (H - 2 * R) / H;
      H = H - 2 * R;
    }
    printf("%13.6lf\n", L);
    if (TestNum){
      printf("\n");
    }
  }
}
