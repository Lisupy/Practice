#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

int dx[]={0,-1, 0, 1,-1, 0, 1,-1, 0, 1};
int dy[]={0,-1,-1,-1, 0, 0, 0, 1, 1, 1};

long long double_area(long long x0, long long y0,
                      long long x1, long long y1,
                      long long x2, long long y2){
  return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--){
    long long x,y,tx,ty,S;
    int d;
    x=y=tx=ty=S=d=0;
    while(d!= 5 && scanf("%1d", &d)){
      x += dx[d];
      y += dy[d];
      S += double_area(0,0,x,y,tx,ty);
      tx = x;
      ty = y;
    }
    S = llabs(S);
    if (S%2==0)
      printf("%lld\n",S/2); 
    else
      printf("%.1f\n", 0.5*S);
  }
}
