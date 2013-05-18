#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>


const int MAXN = 128;

int k;
int n;
int ha,la,hb,lb;
char map[MAXN][MAXN];

int p[MAXN*MAXN];

void Init(){
  for (int i = 0; i < MAXN*MAXN; i++){
    p[i] = i;
  }
}

int Find(int x){
  if (p[x] == x){
    return x;
  }else{
    return p[x] = Find(p[x]);
  }
}

void Join(int x, int y){
  int px = Find(x);
  int py = Find(y);
  if (px != py){
    p[px] = py;
  }
}

int Get(int x, int y){
  return x * n + y;
}

int main(){
  scanf("%d", &k);

  while (k--){
    scanf("%d", &n);
    Init();

    for (int i = 0; i < n; i++){
      scanf("%s", map[i]);
    }

    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        if (map[i][j] == '#')
          continue;

        int s = Get(i, j);

        if (map[i + 1][j] == '.'){
          int t = Get(i + 1, j);
          Join(s, t);
        }

        if (map[i][j + 1] == '.'){
          int t = Get(i, j + 1);
          Join(s, t);
        }
      }
    }

    scanf("%d %d %d %d", &ha, &la, &hb, &lb);
    int start = Get(ha, la);
    int end = Get(hb, lb);
    if (Find(start) == Find(end)){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
}
