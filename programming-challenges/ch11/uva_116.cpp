
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;


const int MAXN = 128;
int m, n;
int a[MAXN][MAXN];
int nxt[MAXN][MAXN];



int main(){
  while (scanf("%d %d", &m, &n) != EOF){
    if (m == 0 || n == 0){
      cout << 0 << endl;
      continue;
    }
    for (int i = 1; i <= m; i++){
      for (int j = 1; j <= n; j++){
        scanf("%d", &a[i][j]);
      }
    }
    memset(nxt, 0, sizeof(nxt));


    for (int i = n - 1; i >= 1; i--){
      for (int j = 1; j <= m; j++){
        int s = a[j][i] + a[j][i + 1];
        nxt[j][i] = j;
        int poss[] = {(j - 1 + m - 1) % m + 1, (j + 1 + m - 1) % m + 1};
        for (int k = 0; k < 2; k++){
          int pos = poss[k];
          int d = a[j][i] + a[pos][i + 1];
          if (s > d){
            s = d;
            nxt[j][i] = pos;
          }
          if (s == d && nxt[j][i] > pos){
            nxt[j][i] = pos;
          }
        }
        a[j][i] = s;
      }
    }
/*
    for (int i = 1; i <= m; i++){
      for (int j = 1; j <= n; j++){
        printf("%2d:%d ", a[i][j], nxt[i][j]);
      }
      cout << endl;
    }
*/
    int pos = 1;
    for (int i = 1; i <= m; i++){
      if (a[pos][1] > a[i][1]){
        pos = i;
      }
    }
    int max_l = a[pos][1];
    for (int i = 1; i <= n; i++){
      cout << pos;
      if (i == n){
        cout << endl;
      }else{
        cout << " ";
      }
      
//      printf("%2d:%d(%d), ", a[i][pos], nxt[i][pos],i);
      pos = nxt[pos][i];
    }
    cout << max_l << endl;
  }
}
        
