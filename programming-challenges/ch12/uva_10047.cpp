#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

const int MAXN = 32;
const int MAXC = 5;
const int INF = 0xffffff;
struct State{
  int x, y;
  int dx, dy;
  int color;
  void display(){
    printf("(%d, %d), (%d, %d), %d\n", x, y, dx, dy, color);
  }
};

int step[MAXN][MAXN][3][3][MAXC];
char grid[MAXN][MAXN];

int M, N;

int solve(int sx, int sy, int tx, int ty){
  queue<State> Q;
  fill(&step[0][0][0][0][0], &step[MAXN - 1][MAXN - 1][2][2][MAXC - 1] + 1, INF);
  State start = {sx, sy, -1, 0, 0};
  Q.push(start);
  step[sx][sy][0][1][0] = 0;
  while (!Q.empty()){
    State s = Q.front();
    Q.pop();
   // cout << "pop" << endl;
   // s.display();
   // cout << step[s.x][s.y][s.dx + 1][s.dy + 1][s.color] << endl;
    State ts[3] = {s, s, s};
    ts[0].x = s.x + s.dx;
    ts[0].y = s.y + s.dy;
    ts[0].color = (s.color + 1) % MAXC;
    if (s.dx != 0){
      ts[1].dx = 0;
      ts[1].dy = -1;
      ts[2].dx = 0;
      ts[2].dy = 1;
    }else{
      ts[1].dx = 1;
      ts[1].dy = 0;
      ts[2].dx = -1;
      ts[2].dy = 0;
    }
    for (int i = 0; i < 3; i++){
      State &t = ts[i];
     // t.display();
      if (1 <= t.x && t.x <= M && 1 <= t.y && t.y <= N){
        if (grid[t.x][t.y] != '#' && step[t.x][t.y][t.dx + 1][t.dy + 1][t.color] == INF){
          step[t.x][t.y][t.dx + 1][t.dy + 1][t.color] = step[s.x][s.y][s.dx + 1][s.dy + 1][s.color] + 1;
          Q.push(t);
    //      cout << "push" << endl;
        }
      }
    }
  }
  int res = INF;
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      res = min(res, step[tx][ty][i][j][0]);
    }
  }
  return res;
}


int main(){
  int TestNum = 0;
  while (scanf("%d %d", &M, &N) && M){
    for (int i = 1; i <= M; i++){
      scanf("%s", grid[i] + 1);
    }
    int sx, sy, tx, ty;
    for (int x = 1; x <= M; x++){
      for (int y = 1; y <= N; y++){
        if (grid[x][y] == 'S'){
          sx = x, sy = y;
        }
        if (grid[x][y] == 'T'){
          tx = x, ty = y;
        }
      }
    }
    int res = solve(sx, sy, tx, ty);
    if (TestNum){
      cout << endl;
    }
    cout << "Case #" << ++TestNum << endl;
    if (res == INF){
      cout << "destination not reachable" << endl;
    }else{
      cout << "minimum time = " << res << " sec" << endl;
    }
  }
}
    
    

