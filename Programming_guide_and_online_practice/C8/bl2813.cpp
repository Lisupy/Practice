#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 32;

struct Game{
  int n;
  char color[MAXN][MAXN];
  bool paint[MAXN][MAXN];
  int  paint_cnt;
  void read(){
    memset(paint, 0, sizeof(paint));
    paint_cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
      scanf("%s", color[i]);
    }
  }

  void __change(int x, int y){
    if (0 <= x && x < n && 0 <= y && y < n){
      if (color[x][y] == 'y'){
        color[x][y] = 'w';
      }else{
        color[x][y] = 'y';
      }
    }
  }

  void change(int x, int y){
    paint[x][y] = true;
    paint_cnt++;
    __change(x    , y);
    __change(x - 1, y);
    __change(x + 1, y);
    __change(x    , y - 1);
    __change(x    , y + 1);
  }

  bool all_yellow(){
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        if (color[i][j] != 'y'){
          return false;
        }
      }
    }
    return true;
  }
};

int main(){
  int t;
  scanf("%d", &t);

  while (t--){
    Game game;
    game.read();

    int n = game.n;
    int least_paint_cnt = n*n+1;
    for (int first_row = 0; first_row < 1<<n; first_row++){
      Game g(game);
      for (int i = 0; i < n; i++){
        if (first_row & (1<<i)){
          g.change(0, i);
        }
      }

      for (int i = 1; i < n; i++){
        for (int j = 0; j < n; j++){
          if (g.color[i-1][j] == 'w'){
            g.change(i, j);
          }
        }
      }

      if (g.all_yellow()){
        least_paint_cnt = min(least_paint_cnt, g.paint_cnt);
      }
    }
    if (least_paint_cnt == n*n+1){
      printf("inf\n");
    }else{
      printf("%d\n", least_paint_cnt);
    }
  }
}


