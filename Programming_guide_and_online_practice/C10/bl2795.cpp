#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int MAXW = 10001;
const int MAXS = 101;


int k;
int w;
int s;

struct T{
  int n;
  int v;
};

bool operator<(const T &a, const T& b){
  return a.v * b.n < b.v * a.n;
}

T a[MAXS];

int main(){
  scanf("%d", &k);
  
  while (k--){
    scanf("%d%d", &w, &s);

    for (int i = 1; i <= s; i++){
      scanf("%d %d", &a[i].n, &a[i].v);
    }
    sort(a+1, a+s+1);
    reverse(a+1, a+s+1);

    double total_w = 0;
    double total_s = 0;
    for (int i = 1; i <= s; i++){
      if (total_w == w){
        break;
      }
      if (w - total_w < a[i].n){
        total_s += 1.0*a[i].v/a[i].n * (w - total_w);
        total_w += w - total_w;
      }else if (w - total_w >= a[i].n){
        total_s += a[i].v;
        total_w += a[i].n;
      }
    }
    printf("%.2lf\n", total_s);
  }
}

