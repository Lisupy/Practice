#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

const double EPS = 1e-8; 
const int MAXN = 256;
const double D = 5.0;
const double r = D/2;



struct Point{
  double x,y;
  Point(){};
  Point(double _x,double _y):x(_x),y(_y){};
};

int n = 0;
Point p[MAXN];

Point midPoint(const Point &a, const Point &b){
  return Point((a.x+b.x)/2, (a.y+b.y)/2);
}

double disPower(const Point &a, const Point &b){
  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
double dis(const Point &a, const Point &b){
  return sqrt(disPower(a,b));
}

double inCircle(const Point &c, double r, const Point &p){
  return dis(c,p)<=r+EPS;
}

int countInCircle(const Point &C, double r){
  int cnt = 0; 
  for (int k = 0; k < n; k++){
    if (inCircle(C,r,p[k]))
      cnt++;
  }
  return cnt;
}
int main(){
  while(scanf("%lf%lf",&p[n].x,&p[n].y)!=EOF)
    n++;
  int ans = 1;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (i == j)continue;
      const Point &A = p[i];
      const Point &B = p[j];
      double disAB = dis(A,B);
      if (disAB > D+EPS) continue;
      if (disAB < EPS) continue;
      Point midAB = midPoint(A,B);
      double l = sqrt(r*r - disPower(A,midAB));
      double dx = l*(A.y-B.y)/disAB;
      double dy = -l*(A.x-B.x)/disAB;
      Point C(midAB.x+dx, midAB.y+dy);
      ans = max(ans, countInCircle(C, r));  
    }
  }
  printf("%d\n", ans);
}
