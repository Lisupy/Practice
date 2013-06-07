//Alogrithm:  simulation
//Complexity: O(N*M)
//IndexBased: 1
//Trick:      



#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<cassert>
#include<queue>
#include<utility>
using namespace std;

const int MAXN = 256;

struct GraphicalEditor{
  int M, N;
  char pixels[MAXN][MAXN];

  void display(){
    for (int i = 1; i <= N; i++){
      printf("%s\n", pixels[i] + 1);
    }
  }

  
  void draw(int x1, int y1, int x2, int y2, char c){
    for (int i = y1; i <= y2; i++){
      for (int j = x1; j <= x2; j++){
        pixels[i][j] = c;
      }
    }
  }

  GraphicalEditor(int m, int n): M(m),N(n){
    memset(pixels, 0, sizeof(pixels));
    draw(0, 0, m, n, 'O');
  }
  
  void flood_fill(int x, int y, char new_color){
    char old_color = pixels[y][x];
    if (new_color == old_color){
      return;
    }
    queue<pair<int, int> > Q;

    pixels[y][x] = new_color;
    Q.push(make_pair(x, y));

    while (!Q.empty()){
      int sx = Q.front().first;
      int sy = Q.front().second;
      Q.pop();
      static int dx[] = {-1, 1,  0, 0};
      static int dy[] = { 0, 0, -1, 1}; 
      for (int i = 0; i < 4; i++){
        int tx = sx + dx[i];
        int ty = sy + dy[i];
        if (1 <= tx && tx <= M && 1 <= ty && ty <= N){
          if (pixels[ty][tx] == old_color){
            pixels[ty][tx] = new_color;
            Q.push(make_pair(tx, ty));
          }
        }
      }
    }
  }
};

GraphicalEditor *graph;
int main(){
  string cmd;
  while (cin>>cmd){
    switch(cmd[0]){
    case 'I':{
               int M, N;
               cin >> M >> N;

               graph = new GraphicalEditor(M, N);
               break;
             }
    case 'C':{
               graph->draw(0, 0, graph->M, graph->N, 'O');
               break;
             }
    case 'L':{
               int X, Y;
               string color;
               cin >> X >> Y >> color;
               graph->draw(X, Y, X, Y, color[0]);
               break;
             }
    case 'V':{
               int X, Y1, Y2;
               string color;
               cin >> X >> Y1 >> Y2 >> color;
               if (Y1 > Y2) swap(Y1, Y2);
               graph->draw(X, Y1, X, Y2, color[0]);
               break;
             }
    case 'H':{
               int X1, X2, Y;
               string color;
               cin >> X1 >> X2 >> Y >> color;
               if (X1 > X2) swap(X1, X2);
               graph->draw(X1, Y, X2, Y, color[0]);
               break;
             }
    case 'K':{
               int X1, Y1, X2, Y2;
               string color;
               cin >> X1 >> Y1 >> X2 >> Y2 >> color;
               if (X1 > X2) swap(X1, X2);
               if (Y1 > Y2) swap(Y1, Y2);
               graph->draw(X1, Y1, X2, Y2, color[0]);
               break;
             }
    case 'F':{
               int X, Y;
               string color;
               cin >> X >> Y >> color;
               graph->flood_fill(X, Y, color[0]);
               break;
             }
    case 'S':{
               string file_name;
               cin >> file_name;
               cout << file_name << endl;
               graph->display();
               break;
             }
    case 'X':{
               exit(0);
               if (graph == NULL){
                 delete graph;
                 graph = NULL;
               }
               break;
             }
    default: {
               string tmp;
               getline(cin, tmp);
               break;
             }
    }
//    graph->display();
  }
}


    

