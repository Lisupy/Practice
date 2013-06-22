/* 
 * Algorithm:   build_graph, union-find
 * Complexity:  w*h
 * IndexBased:  1
 * Trick:       the way to rebuild the graph
 * LayOut:
 */


#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std;


const int MAXW = 512;
const int MAXH = 512;
const int MAXN = 512 * 512;

int p[MAXN];
int size[MAXN];
void p_init(){
  for (int i = 0; i < MAXN; i++){
    p[i] = i;
    size[i] = 1;
  }
}

int find(int u){
  int pu = u;
  while (p[pu] != pu){
    pu = p[pu];
  }
  while (u != pu){
    int next = p[u];
    p[u] = pu;
    u = next;
  }
  return u;
}

void join(int u, int v){
  int pu = find(u);
  int pv = find(v);
  if (pu != pv){
    p[pu] = pv;
    size[pv] += size[pu];
  }
}

int w, h;
int maze[MAXH][MAXW];

void maze_print(){
  for (int i = 0; i < 3*h; i++){
    for(int j = 0; j < 3*w; j++){
      cout << maze[i][j];
    }
    cout << endl;
  }
}
int main(){
  int TestCnt = 0;
  while (cin >> w >> h && (w != 0 || h != 0)){
    p_init();
    memset(maze, 0, sizeof(maze));
    for (int i = 0; i < h; i++){
      if (w == 0){continue;}
      string s;
      cin >> s;
      for (int j = 0; j < w; j++){
        if (s[j] == '/'){
          maze[i * 3 + 0][j * 3 + 2] = 1;
          maze[i * 3 + 1][j * 3 + 1] = 1;
          maze[i * 3 + 2][j * 3 + 0] = 1;
        }else if (s[j] == '\\'){
          maze[i * 3 + 0][j * 3 + 0] = 1;
          maze[i * 3 + 1][j * 3 + 1] = 1;
          maze[i * 3 + 2][j * 3 + 2] = 1;
        }
      }
    }
 //   maze_print();
    for (int i = 0; i < 3 * h; i++){
      for (int j = 0; j < 3 * w; j++){
        if (maze[i][j] == 1){
          continue;
        }
        int di[] = {0, 0, -1, 1};
        int dj[] = {1,-1,  0, 0};
        for (int k = 0; k < 4; k++){
          int i1 = i + di[k];
          int j1 = j + dj[k];
          if (0 <= i1 && i1 < 3 * h && 0 <= j1 && j1 < 3* w){
            if (maze[i1][j1] == 0){
              join(i*3*w + j, i1*3*w + j1);
            }
          }else{
            join(i*3*w + j, 3*h*3*w);
          }
        }
      }
    }

    cout << "Maze #" << ++TestCnt << ":" << endl;
    int out = find(3*h*3*w);
    int longest = -1;
    int cycle_cnt = 0;
    for (int i = 0; i < 3*h*3*w; i++){
      int pi = find(i);
      if (pi != out && size[pi] != 1 && size[pi] > longest){
        longest = size[pi];
      }
      if (pi != out && size[pi] != 1 && pi == i){
        cycle_cnt++;
      }
    }
    if (longest == -1){
      cout << "There are no cycles." << endl;
    }else{
      if (cycle_cnt == 1){
        cout << "1 Cycles; ";
      }else{
        cout << cycle_cnt << " Cycles; ";
      }
      cout << "the longest has length " << longest/3 << "." << endl;
    }
    cout << endl;
  }
}

