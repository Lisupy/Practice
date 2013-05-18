#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 64*64;
int p[MAXN];
int cnt[MAXN];

void init(){
  for (int i = 0; i < MAXN; i++){
    p[i] = i;
    cnt[i] = 1;
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
    cnt[py] += cnt[px];
  }
}

int r, c;
int Get(int x, int y){
  return x * c + y;
}

int main(){
  scanf("%d %d", &r, &c);

  int map[64][64];
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      scanf("%d", &map[i][j]);
    }
  }

  init();

  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      int s = Get(i, j);
      if ((map[i][j] & 8) == 0){
        int d = Get(i + 1, j);
        Join(s, d);
      }
      if ((map[i][j] & 4) == 0){
        int t = Get(i, j + 1);
        Join(s, t);
      }
    }
  }

  set<int> S;
  int max_room = 0;;
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      int s = Get(i, j);
      int ps = Find(s);
      S.insert(ps);
      max_room = max(max_room, cnt[ps]);
    }
  }
  printf("%lu\n", S.size());
  printf("%d\n", max_room);
}




