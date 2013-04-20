#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<iostream>
#include<climits>
using namespace std;

const int MAXM = 64;

int n;
int m;
int x[MAXM];
int y[MAXM];
int s[MAXM][MAXM][MAXM];
int dp_cache[MAXM][MAXM][MAXM];

int dp(int p0, int p1, int pn){
  if (p0 == p1 || p1 == pn || pn == p0){
    return 0;
  }
  if (dp_cache[p0][p1][pn] != -1){
    return dp_cache[p0][p1][pn];
  }
  int sol = INT_MAX;
  for (int pk = p1+1; pk <= pn; pk++){
    int k = -1;
    k = max(k, s[p0][p1][pk]);
    k = max(k, dp(p1,p1+1,pk));
    k = max(k, dp(p0,pk,pn));
    sol = min(k, sol);
  }
  return dp_cache[p0][p1][pn] = sol;
}
 



int triangle_area(int x1, int y1, int x2, int y2, int x3, int y3){
  int S = (x3-x1)*(y2-y1)-(x2-x1)*(y3-y1);
  return abs(S);
}

int main(){
  scanf("%d", &n);
  while (n--){
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
      scanf("%d %d", x+i, y+i);
    }

    for (int i = 0; i < m; i++){
      for (int j = 0; j < m; j++){
        for (int k = 0; k < m; k++){
          s[i][j][k] = triangle_area(x[i],y[i],x[j],y[j],x[k],y[k]);
        }
      }
    }

    for (int i = 0; i < m; i++){
      for (int j = 0; j < m; j++){
        for (int k = 0; k < m; k++){
          dp_cache[i][j][k] = -1;
        }
      }
    }
    int ans = dp(0,1,m-1);
    printf("%.01f\n", ans/2.0);
  }
}
