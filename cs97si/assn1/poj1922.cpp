#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<limits>
#include<cmath>
using namespace std;


int cal(int v, int t)
{
  return ceil(4.5*3600/v+t);
}

int main()
{
  int N;
  int v,t;
  while(scanf("%d", &N) &&N){
    int arrvial_time = numeric_limits<int>::max();
    for(int i =0; i < N; i++){
      scanf("%d%d", &v,&t);
      if (t < 0)continue;
      arrvial_time = min(arrvial_time, cal(v,t));
    }
    printf("%d\n", arrvial_time);
  }
}
