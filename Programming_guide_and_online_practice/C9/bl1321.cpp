#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;


const int MAXN = 16;

int n, k;

int cnt = 0;

bool used[MAXN];
char map[MAXN][MAXN];


void dfs(int depth, int place_cnt){
  if (depth == n){
    if (place_cnt == k){
      cnt++;
    }
  }else{
    for (int i = 0; i < n; i++){
      if (map[depth][i] == '#'){
        if (!used[i]){
          used[i] = true;
          dfs(depth+1, place_cnt+1);
          used[i] = false;
        }
      }
    }
    dfs(depth + 1, place_cnt);
  }
}
  

int main(){
  while (scanf("%d %d", &n, &k) && n != -1){
    scanf("\n");
    for (int i = 0; i < n; i++){
      fgets(map[i], MAXN, stdin);
    }
    cnt = 0;
    memset(used, 0, sizeof(used));
    dfs(0, 0);
    printf("%d\n", cnt);
  }
}
