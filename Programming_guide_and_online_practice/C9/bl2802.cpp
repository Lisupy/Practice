#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
using namespace std;

const int MAXN = 128;
const int INF = 0xffffff;
int w, h;
int x1, Y1;
int x2, y2;

int dx[] = {-1, 1, 0, 0};
int dy[] = { 0, 0,-1, 1};

char Map[MAXN][MAXN];

int BFS(){
  int visited[MAXN][MAXN];
  queue< pair<int, int> > Q;
// fill_n(visited[0], MAXN*MAXN, INF);
  for (int i = 0; i < MAXN; i++){
    for (int j = 0; j < MAXN; j++){
      visited[i][j] = INF;
    }
  }
  visited[x1][Y1] = 0;
  Q.push(make_pair(x1, Y1));
  while (!Q.empty()){
    int sx = Q.front().first;
    int sy = Q.front().second;
    Q.pop();
    for (int i = 0; i < 4; i++){
      int tx = sx + dx[i];
      int ty = sy + dy[i];
      while (0 <= tx && tx <= h+1 && 0 <= ty && ty <= w+1){
        if (tx == x2 && ty == y2){
          return visited[sx][sy] + 1;
        }
        if (Map[tx][ty] == 'X') 
          break;

        if (visited[tx][ty] == INF){
          visited[tx][ty] = visited[sx][sy] + 1;
          Q.push(make_pair(tx, ty));
        }

        tx += dx[i];
        ty += dy[i];
      }
    }
  }
  return INF;
}

int main(){

  int BoardCnt = 0;

  while (scanf("%d %d", &w, &h) && w){

    scanf("\n");
    for (int i = 1; i <= h; i++){
      fgets(Map[i]+1, MAXN, stdin);
    }
    ++BoardCnt;
    printf("Board #%d:\n", BoardCnt);
    
    int PairCnt = 0;
    while ( scanf("%d %d %d %d", &x1, &Y1, &x2, &y2) && x1){
      ++PairCnt;
      swap(x1, Y1);
      swap(x2, y2);
      int bfs = BFS();
      if (bfs == INF){
        printf("Pair %d: impossible.\n", PairCnt);
      }else{
    //    if (bfs == 1){
     //     printf("Pair %d: %d segment.\n", PairCnt, bfs);
      //  }else{
          printf("Pair %d: %d segments.\n", PairCnt, bfs);
       // }
      }
    }
    printf("\n");
  }
}
