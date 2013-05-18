#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 32;

struct UnionFind{
  int p[MAXN*MAXN];
  
  void init(){
    for (int i = 0; i < MAXN*MAXN; i++){
      p[i] = i;
    }
  }

  int find(int x){
    if (p[x] == x){
      return p[x];
    }else{
      return p[x] = find(p[x]);
    }
  }
  
  void join(int x, int y){
    int px = find(x);
    int py = find(y);
    if (px != py){
      p[px] = py;
    }
  }

};

int main(){
  int W, H;
  char map[MAXN][MAXN];
  
  while (scanf("%d %d", &W, &H) && W && H){
    UnionFind uf;
    uf.init();
    for (int i = 0; i < H; i++){
      scanf("%s", map[i]);
    }

    int start = 0;
    for (int i = 0; i < H; i++){
      for (int j = 0; j < W; j++){
        if (map[i][j] == '#') continue;
        if (map[i + 1][j] == '.' || map[i + 1][j] == '@'){
          uf.join(i * W + j, (i + 1) * W + j);
        }
        if (map[i][j + 1] == '.' || map[i][j + 1] == '@'){
          uf.join(i * W + j, i * W + j + 1);
        }
        if (map[i][j] == '@'){
          start = i * W + j;
        }
      }
    }

    int count = 0;
    for (int i = 0; i < H; i++){
      for (int j = 0; j < W; j++){
        if (uf.find(i * W + j) == uf.find(start)){
          count++;
        }
      }
    }
    printf("%d\n", count);
  }
}
